// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "stdafx.h"
#include "Window.h"

//=============================================================================
SE_NAMESPACE_BEGIN

//-----------------------------------------------------------------------------
void windowResize(GLFWwindow *window, int width, int height)
{
	glViewport(0, 0, width, height);
}
//-----------------------------------------------------------------------------
Window::~Window()
{
	Close();
}
//-----------------------------------------------------------------------------
bool Window::Init(const WindowConfig &config)
{
	m_config = config;

	if ( !glfwInit() )
	{
		SE_LOG_ERROR("Failed to initialize GLFW!");
		return false;
	}

	m_window = glfwCreateWindow(m_config.width, m_config.height, m_config.title, NULL, NULL);
	if ( !m_window )
	{
		SE_LOG_ERROR("Failed to create GLFW window!");
		return false;
	}
	glfwMakeContextCurrent(m_window);
	glfwSetWindowSizeCallback(m_window, windowResize);

	return true;
}
//-----------------------------------------------------------------------------
void Window::BeginFrame()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
//-----------------------------------------------------------------------------
void Window::EndFrame()
{
	glfwPollEvents();
	glfwSwapBuffers(m_window);
}
//-----------------------------------------------------------------------------
void Window::Close()
{
	glfwTerminate();
}
//-----------------------------------------------------------------------------
bool Window::IsClosed() const
{
	return glfwWindowShouldClose(m_window) == 1;
}
//-----------------------------------------------------------------------------

SE_NAMESPACE_END
//=============================================================================