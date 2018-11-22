// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "Core/Base.h"
//-----------------------------------------------------------------------------
#if SE_ARCH_32BIT
#	pragma comment(lib, "Core_Win32.lib")
#	pragma comment(lib, "App_Win32.lib")
#elif SE_ARCH_64BIT
#	pragma comment(lib, "Core_x64.lib")
#	pragma comment(lib, "App_x64.lib")
#endif
//-----------------------------------------------------------------------------
int main()
{
	return 0;
}
//-----------------------------------------------------------------------------