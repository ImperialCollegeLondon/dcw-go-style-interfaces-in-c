#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <dlfcn.h>

#include "bigstr.h"
#include "bindsym.h"

boundf bindsym( bindsym_info *info, char *symbol, char *sig )
{
	bigstr sigsym;
	sprintf( sigsym, "%s_%s", info->module, sig );

	boundf r = dlsym( info->dl, symbol );
	if( r == NULL )
	{
		bigstr s;
		sprintf( s, "%s_%s", info->module, symbol );
		r = dlsym( info->dl, s );
		if( r == NULL )
		{
			sprintf( info->errmsg,
				"%s_bind: No symbol '%s' or '%s' in %s",
				info->interface, symbol, s, info->libname );
			return r;
		}
	}

	// if the signature symbol doesn't exist, fail..
	if( dlsym( info->dl, sigsym ) == NULL )
	{
		sprintf( info->errmsg, "%s_bind: No sig symbol '%s' in %s",
			info->interface, sigsym, info->libname );
		return NULL;
	}

	return r;
}
