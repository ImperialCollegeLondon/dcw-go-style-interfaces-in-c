#define BIGSTRSIZE 1024
typedef char bigstr[BIGSTRSIZE];

// vvf: a pointer to a void->void function
typedef void (*vvf)( void );

// ivf: a pointer to a void->int function, mnemonic; "int-returning void func"
typedef int (*ivf)( void );

// This represents the "interface f12" at run-time.
// It's a container of SLOTS for the f12 functions..
typedef struct
{
	vvf   f1;
	ivf   f2;
} *f12;

// the bind function
// f12 x = f12_bind( basename, char *errmsg );
//	locate "lib<basename>.so", and attempt to locate the
//	required symbols f1 and f2 (or basename_f1 and basename_f2...),
//	to "bind" lib<basename>.so to the f12 interface.
//	If we fail: strcpy an error message into errmsg and return NULL
//	If we succeed: return an newly malloc()d f12 object
//	with the function pointers bound to the corresponding
//	functions in lib<basename>.so
extern f12 f12_bind( char * basename, char * errmsg );
