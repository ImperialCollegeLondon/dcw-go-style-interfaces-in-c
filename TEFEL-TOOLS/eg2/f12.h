/*
 *	interface f12: a collection of C functions, in TEFEL form
 */

typedef void (*f12_void_void_f)(  );
typedef int (*f12_int_void_f)(  );

// This represents the "interface f12" at run-time.
// It's a container of SLOTS for the f12 functions..
typedef struct
{
	f12_void_void_f f1;
	f12_int_void_f f2;
} *f12;

	
/*
 * f12 x = f12_bind( char *module, char *errmsg );
 *	locate "lib<module>.so", and attempt to locate all the
 *	required function symbols (and their ancillary signature variables
 *	to guarantee they are match the parameter signatures) inside
 *	the library.  For each function called <fname>, we look first for
 *	a symbol "module_fname", and second for a symbol "fname".
 *
 *	If we fail to find any of the required functions: strcpy an error
 *	message into errmsg and return NULL.
 *
 *	If we succeed then we say we have "bound" the library to the interface:
 *	we return an newly malloc()d f12 object with the function
 *	pointers bound to the corresponding functions in lib<module>.so
 */
extern f12 f12_bind( char * module, char * errmsg );
