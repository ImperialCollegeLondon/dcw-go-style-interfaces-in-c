/*
 *	interface f12: a collection of C functions.
 *	manually translated into plain C, using libdl
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <dlfcn.h>

#include "f12.h"


static vvf bindsym( void *dl, char *modulename, char *symbol )
{
	vvf r = dlsym( dl, symbol );
	if( r == NULL )
	{
		bigstr s;
		sprintf( s, "%s_%s", modulename, symbol );
		r = dlsym( dl, s );
	}
	return r;
}


/*
 * f12 x = f12_bind( modulename, char *errmsg );
 *	locate "lib<modulename>.so", and attempt to locate the
 *	required symbols f1 and f2 (or modulename_f1 and modulename_f2...),
 *	to "bind" lib<modulename>.so to the f12 interface.
 *	If we fail: strcpy an error message into errmsg and return NULL
 *	If we succeed: return an newly malloc()d f12 object
 *	with the function pointers bound to the corresponding
 *	functions in lib<modulename>.so
 */
f12 f12_bind( char *modulename, char *errmsg )
{
	bigstr libname;
	sprintf( libname, "lib%s.so", modulename );
	void *dl = dlopen( libname, RTLD_NOW );
	if( dl == NULL )
	{
		sprintf( errmsg, "f12_bind: dlopen of %s failed", libname );
		return NULL;
	}

	f12 r = malloc(sizeof(*r));
	if( r == NULL )
	{
		strcpy( errmsg, "f12_bind: malloc() failed" );
		return NULL;
	}

	r->f1 = bindsym( dl, modulename, "f1" );
	if( r->f1 == NULL )
	{
		free(r);
		sprintf( errmsg, "f12_bind: No symbol 'f1' in %s", libname );
		return NULL;
	}

	r->f2 = (ivf) bindsym( dl, modulename, "f2" );
	if( r->f2 == NULL )
	{
		free(r);
		sprintf( errmsg, "f12_bind: No symbol 'f2' in %s", libname );
		return NULL;
	}

	return r;
}
