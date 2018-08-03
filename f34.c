/*
 *	interface f34: a collection of C functions.
 *	manually translated into plain C, using libdl
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <dlfcn.h>

#include "bigstr.h"
#include "bindsym.h"
#include "f34.h"


/*
 * f34 x = f34_bind( module, char *errmsg );
 *	locate "lib<module>.so", and attempt to locate the
 *	required symbols f3 and f4 (or module_f3...),
 *	to "bind" lib<module>.so to the f34 interface.
 *	If we fail: strcpy an error message into errmsg and return NULL
 *	If we succeed: return an newly malloc()d f34 object
 *	with the function pointers bound to the corresponding
 *	functions in lib<module>.so
 */
f34 f34_bind( char *module, char *errmsg )
{
	bigstr libname;
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

	r->f3 = (f34_vcsif) bindsym( &info,
			"f3", "f3_void_charstar_int" );
	if( r->f3 == NULL )
	{
		free(r);
		return NULL;
	}

	r->f4 = (f34_vsif) bindsym( &info, "f4", "f4_voidstar_int" );
	if( r->f4 == NULL )
	{
		free(r);
		return NULL;
	}

	return r;
}
