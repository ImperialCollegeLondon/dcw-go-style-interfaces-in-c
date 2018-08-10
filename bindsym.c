#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <dlfcn.h>

#include "bigstr.h"
#include "bindsym.h"

boundf bindsym( bindsym_info *info, char *fname, char *sig )
{
	boundf r = dlsym( info->dl, fname );
	if( r == NULL )
	{
		bigstr m_s;
		sprintf( m_s, "%s_%s", info->module, fname );
		r = dlsym( info->dl, m_s );
		if( r == NULL )
		{
			sprintf( info->errmsg,
				"%s_bind: No symbol '%s' or '%s' in %s",
				info->interface, fname, m_s, info->libname );
			return NULL;
		}
	}

	bigstr sigsym;
	sprintf( sigsym, "%s_%s", info->module, sig );

	// if the signature symbol doesn't exist, fail..
	if( dlsym( info->dl, sigsym ) == NULL )
	{
		sprintf( info->errmsg, "%s_bind: No sig symbol '%s' in %s",
			info->interface, sigsym, info->libname );
		return NULL;
	}

	return r;
}
