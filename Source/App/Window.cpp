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
void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	Window *win = (Window*)glfwGetWindowUserPointer(window);
	win->m_keys[key] = action != GLFW_RELEASE;
}
//-----------------------------------------------------------------------------
void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods)
{
	Window *win = (Window*)glfwGetWindowUserPointer(window);
	win->m_mouseButtons[button] = action != GLFW_RELEASE;
}
//-----------------------------------------------------------------------------
void cursorPositionCallback(GLFWwindow *window, double xpos, double ypos)
{
	Window *win = (Window*)glfwGetWindowUserPointer(window);
	win->m_x = xpos;
	win->m_y = ypos;
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
	for ( int i = 0; i < SE_MAX_KEYS; i++ )
		m_keys[i] = false;
	for ( int i = 0; i < SE_MAX_BUTTONS; i++ )
		m_mouseButtons[i] = false;

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
	glfwSetWindowUserPointer(m_window, this);
	glfwSetWindowSizeCallback(m_window, windowResize);
	glfwSetKeyCallback(m_window, keyCallback);
	glfwSetMouseButtonCallback(m_window, mouseButtonCallback);
	glfwSetCursorPosCallback(m_window, cursorPositionCallback);

	if ( glewInit() != GLEW_OK )
	{
		SE_LOG_ERROR("Could not initialize GLEW!");
		return false;
	}

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
bool Window::IsKeyPressed(unsigned int keycode) const
{
	return m_keys[keycode];
}
//-----------------------------------------------------------------------------
bool Window::IsMouseButtonPressed(unsigned int button) const
{
	return m_mouseButtons[button];
}
//-----------------------------------------------------------------------------
void Window::GetMousePosition(double &x, double &y) const
{
	x = m_x;
	y = m_y;
}
//-----------------------------------------------------------------------------

SE_NAMESPACE_END
//=============================================================================