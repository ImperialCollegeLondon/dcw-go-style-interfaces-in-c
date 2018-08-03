/*
 *	pkg2: a second collection of C functions, that may accidentally satisfy
 *	      one or more interfaces that don't yet exist..
 */

#include <stdio.h>
#include <stdlib.h>

void f1( void )
{
	printf( "pkg2::f1\n" );
}

int f2( int n )
{
	printf( "pkg2::f2, returning %d\n", n );
	return n;
}

void f3( char *s, int x )
{
	printf( "pkg2::f3, s='%s', x=%d\n", s, x );
}

static int hello = 3;

void *f4( int n )
{
	printf( "pkg2::f4, x=%d, returning &hello\n", n );
	return (void *)&hello;
}

// attempt at checking function signatures.  Could munge the function
// name itself, as in C++ type munging, but that makes ordinary use
// of the modules really hard.  So I wondered if this flag variable per
// function [never used] is a neater approach?
char pkg2_f1_void_void;
char pkg2_f2_int_int;
char pkg2_f3_void_charstar_int;
char pkg2_f4_voidstar_int;
