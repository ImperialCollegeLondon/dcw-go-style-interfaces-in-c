/*
 *	interface f34: a collection of C functions.
 *	manually translated into plain C, using libdl
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <dlfcn.h>

#include "f34.h"


static vvf bindsym( void *dl, char *basename, char *symbol )
{
	vvf r = dlsym( dl, symbol );
	if( r == NULL )
	{
		bigstr s;
		sprintf( s, "%s_%s", basename, symbol );
		r = dlsym( dl, s );
	}
	return r;
}


/*
 * f34 x = f34_bind( basename, char *errmsg );
 *	locate "lib<basename>.so", and attempt to locate the
 *	required symbols f3 and f4 (or basename_f3...),
 *	to "bind" lib<basename>.so to the f34 interface.
 *	If we fail: strcpy an error message into errmsg and return NULL
 *	If we succeed: return an newly malloc()d f34 object
 *	with the function pointers bound to the corresponding
 *	functions in lib<basename>.so
 */
f34 f34_bind( char *basename, char *errmsg )
{
	bigstr soname;
	sprintf( soname, "lib%s.so", basename );
	void *dl = dlopen( soname, RTLD_NOW );
	if( dl == NULL )
	{
		sprintf( errmsg, "f34_bind: dlopen of %s failed", soname );
		return NULL;
	}

	f34 r = malloc(sizeof(*r));
	if( r == NULL )
	{
		strcpy( errmsg, "f34_bind: malloc() failed" );
		return NULL;
	}

	r->f3 = (vcsif) bindsym( dl, basename, "f3" );
	if( r->f3 == NULL )
	{
		free(r);
		sprintf( errmsg, "f34_bind: No symbol 'f3' in %s", soname );
		return NULL;
	}

	r->f4 = (vsif) bindsym( dl, basename, "f4" );
	if( r->f4 == NULL )
	{
		free(r);
		sprintf( errmsg, "f34_bind: No symbol 'f4' in %s", soname );
		return NULL;
	}

	return r;
}
