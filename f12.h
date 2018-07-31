#define BIGSTRSIZE 1024
typedef char bigstr[BIGSTRSIZE];

typedef void (*vvf)( void );
typedef int (*ivf)( void );

// This represents the "interface f12" at run-time.
// It's a container of SLOTS for the f12 functions..
typedef struct
{
	vvf   f1;
	ivf   f2;
} *f12;

extern f12 f12_bind( char * basename, char * errmsg );
