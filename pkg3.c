/*
 *	pkg3: a third collection of C functions, that DOESN'T
 *	      satisfy f12 or f34..
 */

#include <stdio.h>
#include <stdlib.h>

void f1( void )
{
	printf( "pkg3::f1\n" );
}

int f3( char *s, int n )
{
	printf( "pkg3::f3, s='%s', n=%d\n", s, n );
	return 3;
}

// attempt at checking function signatures.  Could munge the function
// name itself, as in C++ type munging, but that makes ordinary use
// of the modules really hard.  So I wondered if this flag variable per
// function [never used] is a neater approach?
char pkg3_f1_void_void;
char pkg3_f3_int_charstar_int;
