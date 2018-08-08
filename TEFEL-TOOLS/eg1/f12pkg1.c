/*
 *	f12pkg1: let's try to access pkg1 via interface "f12"
 */

#include <stdio.h>
#include <stdlib.h>

#include "bigstr.h"
#include "f12.h"


int main( void )
{
	bigstr errmsg;
	f12 pkg1 = f12_bind( "pkg1", errmsg );
	if( pkg1 == NULL )
	{
		printf( "%s\n", errmsg );
	} else
	{
		pkg1->f1();
		int n = pkg1->f2();
		printf( "pkg1->f2 returned %d\n", n );
	}

	return 0;
}
