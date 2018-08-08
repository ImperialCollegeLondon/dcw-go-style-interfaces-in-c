/*
 *	f12pkg2: let's try to access pkg2 via interface "f12"
 */

#include <stdio.h>
#include <stdlib.h>

#include "bigstr.h"
#include "f12.h"


int main( void )
{
	bigstr errmsg;
	f12 pkg2 = f12_bind( "pkg2", errmsg );
	if( pkg2 == NULL )
	{
		printf( "%s\n", errmsg );
	} else
	{
		pkg2->f1();
		int n = pkg2->f2();
		printf( "pkg2->f2 returned %d\n", n );
	}
	return 0;
}
