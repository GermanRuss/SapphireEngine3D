// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

// Core lib
#include "Core/stdafx.h"

// App lib
#include "App/stdafx.h"
#include "App/Main.h"

#include <iostream>

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
		glClearColor(0.2f, 0.4f, 0.9f, 1.0f);

		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);
		return true;
	}
	void OnFrame() final
	{
		double x, y;
		m_window.GetMousePosition(x, y);
		std::cout << x << ", " << y << std::endl;

		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
	}
	void OnClose() final
	{
	}

	GLuint vao;
};
//-----------------------------------------------------------------------------
SE_DECLARE_MAIN(MyApp);
//-----------------------------------------------------------------------------