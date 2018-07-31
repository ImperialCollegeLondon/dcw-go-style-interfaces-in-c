/*
 *	usepkg1: let's play with pkg1, in an ordinary way
 */

#include <stdio.h>
#include <stdlib.h>

#include "pkg1.h"


int main( void )
{
	pkg1_f1();
	int n = pkg1_f2();
	printf( "pkg1::f2 returned %d\n", n );
	pkg1_f3( "hello", n );
	void *p = pkg1_f4( n );
	p++;

	return 0;
}
