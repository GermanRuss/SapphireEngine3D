#pragma once

#include "Application.h"

//=============================================================================
SE_NAMESPACE_BEGIN

template <typename T>
SE_FORCE_INLINE int Main(int argc, const char *argv[])
{
	int ret = 0;
#if SE_ENABLE_EXCETION
	try
#endif // SE_ENABLE_EXCETION
	{		
		T app;
		ret = app.Run(argc, argv);
	}
#if SE_ENABLE_EXCETION
	catch ( ... )
	{
	}
#endif // SE_ENABLE_EXCETION
	return ret;
}

SE_NAMESPACE_END
//=============================================================================

#define SE_DECLARE_MAIN(_className)                        \
    int main(int argc, const char *argv[])                 \
    {                                                      \
        return SE_NAMESPACE::Main<_className>(argc, argv); \
    }