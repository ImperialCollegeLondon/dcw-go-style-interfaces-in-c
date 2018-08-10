#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <dlfcn.h>

#include "f34.h"
#include "bindsym.h"



/*
 * f34 x = f34_bind( char *module, char *errmsg );
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
 *	we return an newly malloc()d f34 object with the function
 *	pointers bound to the corresponding functions in lib<module>.so
 */
f34 f34_bind( char * module, char * errmsg )
{
	char libname[1024];
	assert( strlen(module) < 1000 );
	sprintf( libname, "lib%s.so", module );
	void *dl = dlopen( libname, RTLD_NOW );
	if( dl == NULL )
	{
		sprintf( errmsg, "f34_bind: dlopen of %s failed", libname );
		return NULL;
	}

	f34 r = malloc(sizeof(*r));
	if( r == NULL )
	{
		strcpy( errmsg, "f34_bind: malloc() failed" );
		return NULL;
	}

	bindsym_info   info;
	info.dl        = dl;
	info.interface = "f34";
	info.module    = module;
	info.libname   = libname;
	info.errmsg    = errmsg;

	r->f3 = (f34_void_charstar_int_f) bindsym( &info, "f3", "f3_void_charstar_int" );
	if( r->f3 == NULL )
	{
		free(r);
		return NULL;
	}

	r->f4 = (f34_voidstar_int_f) bindsym( &info, "f4", "f4_voidstar_int" );
	if( r->f4 == NULL )
	{
		free(r);
		return NULL;
	}


	return r;
}
