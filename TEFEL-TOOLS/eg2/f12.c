#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <dlfcn.h>

#include "f12.h"
#include "bindsym.h"



/*
 * f12 x = f12_bind( char *module, char *errmsg );
 *	locate "lib<module>.so", and attempt to locate all the
 *	required function symbols (and their ancillary signature variables
 *	to guarantee they are match the parameter signatures) inside
 *	the library.  For each function called <fname>, we look first for
 *	a symbol "module_fname", and second for a symbol "fname".
 *
 *	If we fail to find any of the required functions: strcpy an error
 *	message into errmsg and return NULL.
 *
 *	If we succeed then we say we have "bound" the library to the interface:
 *	we return an newly malloc()d f12 object with the function
 *	pointers bound to the corresponding functions in lib<module>.so
 */
f12 f12_bind( char * module, char * errmsg )
{
	char libname[1024];
	assert( strlen(module) < 1000 );
	sprintf( libname, "lib%s.so", module );
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

	bindsym_info   info;
	info.dl        = dl;
	info.interface = "f12";
	info.module    = module;
	info.libname   = libname;
	info.errmsg    = errmsg;

	r->f1 = (f12_void_void_f) bindsym( &info, "f1", "f1_void_void" );
	if( r->f1 == NULL )
	{
		free(r);
		return NULL;
	}

	r->f2 = (f12_int_void_f) bindsym( &info, "f2", "f2_int_void" );
	if( r->f2 == NULL )
	{
		free(r);
		return NULL;
	}


	return r;
}
