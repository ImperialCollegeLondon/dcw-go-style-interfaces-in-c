typedef void (*f34_vcsif)( char *s, int x );
typedef void *(*f34_vsif)( int x );

// This represents the "interface f34" at run-time.
// It's a container of SLOTS for the f34 functions..
typedef struct
{
	f34_vcsif f3;
	f34_vsif  f4;
} *f34;

extern f34 f34_bind( char * basename, char * errmsg );
