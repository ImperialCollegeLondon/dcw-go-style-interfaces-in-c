/*
 *	usef12threepkgs: let's try to access ALL THREE packages,
 *		pkg1, pkg2 and pkg3 via interface "f12"
 */

#include <stdio.h>
#include <stdlib.h>

#include "bigstr.h"
#include "f12.h"


static char *module[] =
{
	"pkg1",
	"pkg2",
	"pkg3",
	NULL,
};

int main( void )
{
	for( int i=0; module[i] != NULL; i++ )
	{
		bigstr errmsg;
		f12 p = f12_bind( module[i], errmsg );
		int n;
		if( p == NULL )
		{
			printf( "%s\n", errmsg );
		} else
		{
			p->f1();
			n = p->f2();
			printf( "%s->f2 returned %d\n", module[i], n );
		}
	}

	return 0;
}
