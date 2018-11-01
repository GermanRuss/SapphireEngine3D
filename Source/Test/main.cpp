// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "Core/Base.h"

#include "Core/BeginWarningDisable.h"
#pragma warning(disable: 4548)
#include "Core/EndWarningDisable.h"

#if SE_ARCHITECTURE_X86
#	pragma comment(lib, "Core_Win32.lib")
#	pragma comment(lib, "App_Win32.lib")
#elif SE_ARCHITECTURE_X64
#	pragma comment(lib, "Core_x64.lib")
#	pragma comment(lib, "App_x64.lib")
#endif

int main()
{
	return 0;
}