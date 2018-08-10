/*
 *	pkg3: a third collection of C functions, that DOESN'T
 *	      satisfy f12 or f34..
 */

#include <stdio.h>
#include <stdlib.h>

char pkg3_f1_void_void;	// f1 signature variable:
void f1( void )	// f1 function:
{
	printf( "pkg3::f1\n" );
}

char pkg3_f3_int_charstar_int;	// f3 signature variable:
int f3( char *s, int n )	// f3 function:
{
	printf( "pkg3::f3, s='%s', n=%d\n", s, n );
	return 3;
}
