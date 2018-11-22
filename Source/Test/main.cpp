// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

// Core lib
#include "Core/Base.h"

// App lib
#include "App/Application.h"

//-----------------------------------------------------------------------------
#if SE_COMPILER_MSVC
#	if SE_ARCH_32BIT
#		pragma comment(lib, "Core_Win32.lib")
#		pragma comment(lib, "App_Win32.lib")
#		pragma comment(lib, "3rdparty_Win32.lib")
#	elif SE_ARCH_64BIT
#		pragma comment(lib, "Core_x64.lib")
#		pragma comment(lib, "App_x64.lib")
#		pragma comment(lib, "3rdparty_x64.lib")
#	endif
#endif
//-----------------------------------------------------------------------------
SE_DECLARE_MAIN(1);
//-----------------------------------------------------------------------------