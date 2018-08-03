// bindsym_info: information record about what we're binding to/from..
typedef struct
{
	char *interface;	// name of the interface we're binding to
	char *module;		// name of the module we're binding to
	char *libname;		// name of the library we're binding to
	char *errmsg;		// pointer to where we write an error msg to
	void *dl;		// result of dlopen on libname
} bindsym_info;

// boundf: a pointer to a void->void function
typedef void (*boundf)( void );

extern boundf bindsym( bindsym_info *info, char *symbol, char *sig );
