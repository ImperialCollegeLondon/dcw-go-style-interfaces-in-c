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

//
// dobind( char *module );
//	Attempt to bind module to f34, call functions.
void dobind( char *module )
{
	bigstr errmsg;
	f34 p = f34_bind( module, errmsg );
	if( p == NULL )
	{
		printf( "%s\n", errmsg );
	} else
	{
		printf( "calling %s->f3( 'hello', 42 )\n", module );
		p->f3( "hello", 42 );
		printf( "calling %s->f4( 42 )\n", module );
		void *vp = p->f4( 42 );
		printf( "%s->f4(42) returned %lx\n",
			module, (unsigned long)vp );
	}
}


int main( int argc, char **argv )
{
	if( argc > 1 )
	{
		for( int i=1; argv[i] != NULL; i++ )
		{
			dobind( argv[i] );
		}
	} else
	{
		for( int i=0; module[i] != NULL; i++ )
		{
			dobind( module[i] );
		}
	}

	return 0;
}
