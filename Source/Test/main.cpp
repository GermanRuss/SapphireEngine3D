// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

// Core lib
#include "Core/stdafx.h"

// App lib
#include "App/stdafx.h"
#include "App/Main.h"

#include <iostream>
#include <cassert>

//-----------------------------------------------------------------------------
#if SE_COMPILER_MSVC
#	if SE_ARCH_32BIT
#		pragma comment(lib, "Core_Win32.lib")
#		pragma comment(lib, "App_Win32.lib")
//#		pragma comment(lib, "3rdparty_Win32.lib")
#	elif SE_ARCH_64BIT
#		pragma comment(lib, "Core_x64.lib")
#		pragma comment(lib, "App_x64.lib")
//#		pragma comment(lib, "3rdparty_x64.lib")
#	endif
#endif

//-----------------------------------------------------------------------------
class MyApp : public se::Application
{
public:
	se::ApplicationSetting InitSetting() final
	{
		se::ApplicationSetting setting;
		setting.window.width = 800;
		setting.window.height = 600;
		setting.window.title = "Test Sapphire";
		return setting;
	}

	bool OnInit() final
	{
		return true;
	}
	void OnFrame() final
	{		
	}
	void OnClose() final
	{
	}
};
//-----------------------------------------------------------------------------
SE_DECLARE_MAIN(MyApp);
//-----------------------------------------------------------------------------