/*
 *	f12namedpkgs: let's try to access all packages named on the
 *		command line (or, if no arguments given) pkg1, pkg2 and pkg3,
 *		via interface "f12"
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

//
// dobind( char *module );
//	Attempt to bind module to f12, call functions.
void dobind( char *module )
{
	bigstr errmsg;
	f12 p = f12_bind( module, errmsg );
	int n;
	if( p == NULL )
	{
		printf( "%s\n", errmsg );
	} else
	{
		p->f1();
		n = p->f2();
		printf( "%s->f2 returned %d\n", module, n );
	}
	printf( "\n" );
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
