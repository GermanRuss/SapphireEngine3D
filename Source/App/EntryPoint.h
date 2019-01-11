#pragma once

#include "Application.h"

//=============================================================================
SE_NAMESPACE_BEGIN

template <typename T>
SE_FORCE_INLINE int Main(int argc, const char *argv[])
{
#if SE_DEBUG && SE_PLATFORM_WINDOWS
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	T app;
	return app.Run(argc, argv);
}

SE_NAMESPACE_END
//=============================================================================

#define SE_DECLARE_MAIN(_className)                        \
    int main(int argc, const char *argv[])                 \
    {                                                      \
        return SE_NAMESPACE::Main<_className>(argc, argv); \
    }