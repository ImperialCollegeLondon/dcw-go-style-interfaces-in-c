/*
 *	usef34threepkgs: let's try to access ALL THREE packages,
 *		pkg1, pkg2 and pkg3 via interface "f34"
 */

#include <stdio.h>
#include <stdlib.h>

#include "bigstr.h"
#include "f34.h"


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
		f34 p = f34_bind( module[i], errmsg );
		if( p == NULL )
		{
			printf( "%s\n", errmsg );
		} else
		{
			printf( "calling %s->f3( 'hello', 42 )\n", module[i] );
			p->f3( "hello", 42 );
			printf( "calling %s->f4( 42 )\n", module[i] );
			void *vp = p->f4( 42 );
			printf( "%s->f4(42) returned %lx\n",
				module[i], (unsigned long)vp );
		}
	}

	return 0;
}
