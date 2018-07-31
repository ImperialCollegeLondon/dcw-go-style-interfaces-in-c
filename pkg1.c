/*
 *	pkg1: a collection of C functions, that may accidentally satisfy
 *	      one or more interfaces that don't yet exist..
 */

#include <stdio.h>
#include <stdlib.h>

void pkg1_f1( void )
{
	printf( "pkg1::f1\n" );
}

int pkg1_f2( void )
{
	printf( "pkg1::f2, returning 1\n" );
	return 1;
}

void pkg1_f3( char *s, int x )
{
	printf( "pkg1::f3, s='%s', x=%d\n", s, x );
}

void *pkg1_f4( int n )
{
	printf( "pkg1::f4, x=%d, returning NULL\n", n );
	return NULL;
}

// attempt at checking function signatures.  Could munge the function
// name itself, as in C++ type munging, but I wondered if this flag
// variable per function [never used] is a neater approach, at least
// when normal use (not via the interface) is concerned
char pkg1_f1_void_void;
char pkg1_f2_int_void;
char pkg1_f3_void_charstar_int;
char pkg1_f4_voidstart_int;
