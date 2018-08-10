/*
 *	pkg2: a second collection of C functions, that may accidentally satisfy
 *	      one or more interfaces that don't yet exist..
 */

#include <stdio.h>
#include <stdlib.h>

char pkg2_f1_void_void;	// f1 signature variable:
void f1( void )	// f1 function:
{
	printf( "pkg2::f1\n" );
}

//%func int f2( int n )
char pkg2_f2_int_void;	// f2 signature variable:
int f2( void )	// f2 function:
{
	printf( "pkg2::f2, returning %d\n", 17 );
	return 17;
}

char pkg2_f3_void_charstar_int;	// f3 signature variable:
void f3( char *s, int x )	// f3 function:
{
	printf( "pkg2::f3, s='%s', x=%d\n", s, x );
}

static int hello = 3;

char pkg2_f4_voidstar_int;	// f4 signature variable:
void *f4( int n )	// f4 function:
{
	printf( "pkg2::f4, x=%d, returning &hello\n", n );
	return (void *)&hello;
}

// function signature checking variables will be automatically generated.
