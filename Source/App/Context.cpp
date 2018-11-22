// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "stdafx.h"
#include "Context.h"


//=============================================================================
SE_NAMESPACE_BEGIN

//-----------------------------------------------------------------------------
bool Context::Init()
{
	const int majorOGLVer = 4;
	const int minorOGLVer = 3;

	if ( glfwInit() != GLFW_TRUE )
	{
		SE_LOG_FATAL("Failed to initialize GLFW");
		return false;
	}

	glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
	glfwWindowHint(GLFW_RESIZABLE, false);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, majorOGLVer);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minorOGLVer);
	glfwWindowHint(GLFW_MAXIMIZED, false);
	glfwWindowHint(GLFW_REFRESH_RATE, 60);

	m_window = glfwCreateWindow(800, 600, "se", nullptr, nullptr);
	if ( !m_window )
	{
		SE_LOG_FATAL("Failed to create GLFW window!");
		return false;
	}

	glfwMakeContextCurrent(m_window);

	return true;
}
//-----------------------------------------------------------------------------
bool Context::Frame()
{
	glfwPollEvents();
	if ( glfwWindowShouldClose(m_window) )
		return false;

	glfwSwapBuffers(m_window);
	return true;
}
//-----------------------------------------------------------------------------
void Context::Close()
{
	// Shutdown GLFW.
	glfwDestroyWindow(m_window);
	glfwTerminate();
}
//-----------------------------------------------------------------------------

SE_NAMESPACE_END
//=============================================================================