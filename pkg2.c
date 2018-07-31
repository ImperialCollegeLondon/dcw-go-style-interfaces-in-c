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

int f2( void )
{
	printf( "pkg2::f2, returning 2\n" );
	return 2;
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
