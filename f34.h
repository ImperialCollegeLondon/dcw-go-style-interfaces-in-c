#define BIGSTRSIZE 1024
typedef char bigstr[BIGSTRSIZE];

typedef void (*vvf)( void );
typedef void (*vcsif)( char *s, int x );
typedef void *(*vsif)( int x );

// This represents the "interface f34" at run-time.
// It's a container of SLOTS for the f34 functions..
typedef struct
{
	vcsif f3;
	vsif  f4;
} *f34;

extern f34 f34_bind( char * basename, char * errmsg );
