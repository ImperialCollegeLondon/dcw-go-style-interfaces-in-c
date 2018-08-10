/*
 *	interface f34: a collection of C functions, in TEFEL form
 */

typedef void (*f34_void_charstar_int_f)( char *, int  );
typedef void * (*f34_voidstar_int_f)( int  );

// This represents the "interface f34" at run-time.
// It's a container of SLOTS for the f34 functions..
typedef struct
{
	f34_void_charstar_int_f f3;
	f34_voidstar_int_f f4;
} *f34;

	
/*
 * f34 x = f34_bind( char *module, char *errmsg );
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
 *	we return an newly malloc()d f34 object with the function
 *	pointers bound to the corresponding functions in lib<module>.so
 */
extern f34 f34_bind( char * module, char * errmsg );
