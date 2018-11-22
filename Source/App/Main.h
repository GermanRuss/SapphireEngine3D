#pragma once

#include "Application.h"

extern se::ApplicationSettings SetAppSetting();

//=============================================================================
SE_NAMESPACE_BEGIN

template <typename T>
SE_FORCE_INLINE int Main(int argc, const char *argv[])
{
#if SE_ENABLE_EXCETION
	try
#endif // SE_ENABLE_EXCETION
	{
		T app;
		return app.Run(SetAppSetting(), argc, argv);
	}
#if SE_ENABLE_EXCETION
	catch ( ... )
	{
		return 0;
	}
#endif // SE_ENABLE_EXCETION
}

SE_NAMESPACE_END
//=============================================================================

#define SE_DECLARE_MAIN(_className)                        \
    int main(int argc, const char *argv[])                 \
    {                                                      \
        return SE_NAMESPACE::Main<_className>(argc, argv); \
    }