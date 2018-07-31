/*
 *	usef12threepkgs: let's try to access ALL THREE packages,
 *		pkg1, pkg2 and pkg3 via interface "f12"
 */

#include <stdio.h>
#include <stdlib.h>

#include "f12.h"


int main( void )
{
	bigstr errmsg;
	f12 pkg1 = f12_bind( "pkg1", errmsg );
	int n;
	if( pkg1 == NULL )
	{
		printf( "%s\n", errmsg );
	} else
	{
		pkg1->f1();
		n = pkg1->f2();
		printf( "pkg1->f2 returned %d\n", n );
	}

	f12 pkg2 = f12_bind( "pkg2", errmsg );
	if( pkg2 == NULL )
	{
		printf( "%s\n", errmsg );
	} else
	{
		pkg2->f1();
		n = pkg2->f2();
		printf( "pkg2->f2 returned %d\n", n );
	}

	f12 pkg3 = f12_bind( "pkg3", errmsg );
	if( pkg3 == NULL )
	{
		printf( "%s\n", errmsg );
	} else
	{
		pkg3->f1();
		n = pkg3->f2();
		printf( "pkg3->f2 returned %d\n", n );
	}

	return 0;
}
