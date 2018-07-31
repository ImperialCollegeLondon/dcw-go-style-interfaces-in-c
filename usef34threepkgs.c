/*
 *	usef34threepkgs: let's try to access ALL THREE packages,
 *		pkg1, pkg2 and pkg3 via interface "f34"
 */

#include <stdio.h>
#include <stdlib.h>

#include "f34.h"


int main( void )
{
	bigstr errmsg;
	f34 pkg1 = f34_bind( "pkg1", errmsg );
	if( pkg1 == NULL )
	{
		printf( "%s\n", errmsg );
	} else
	{
		pkg1->f3( "hello", 42 );
		void *p = pkg1->f4( 42 );
		printf( "pkg1->f4(42) returned %lu\n", (unsigned long)p );
	}

	f34 pkg2 = f34_bind( "pkg2", errmsg );
	if( pkg2 == NULL )
	{
		printf( "%s\n", errmsg );
	} else
	{
		pkg2->f3( "hello", 42 );
		void *p = pkg2->f4( 42 );
		printf( "pkg2->f4(42) returned %lu\n", (unsigned long)p );
	}

	f34 pkg3 = f34_bind( "pkg3", errmsg );
	if( pkg3 == NULL )
	{
		printf( "%s\n", errmsg );
	} else
	{
		pkg3->f3( "hello", 42 );
		void *p = pkg3->f4( 42 );
		printf( "pkg3->f4(42) returned %lu\n", (unsigned long)p );
	}

	return 0;
}
