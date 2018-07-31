/*
 *	usepkg2: let's play with pkg2, in an ordinary way
 */

#include <stdio.h>
#include <stdlib.h>

#include "pkg2.h"


int main( void )
{
	f1();
	int n = f2();
	printf( "f2 returned %d\n", n );
	f3( "hello", n );
	void *p = f4( n );
	p++;

	return 0;
}
