// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "stdafx.h"
#include "Win32Window.h"
#include "MouseEvent.h"
#include "KeyEvent.h"
#include "ApplicationEvent.h"
#include <glad/glad.h>

//=============================================================================
SE_NAMESPACE_BEGIN

//-----------------------------------------------------------------------------
static bool s_GLFWInitialized = false;
//-----------------------------------------------------------------------------
static void GLFWErrorCallback(int error, const char* description)
{
	SE_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
}
//-----------------------------------------------------------------------------
Window* Window::Create(const WindowConfig &config)
{
	return new WindowsWindow(config);
}
//-----------------------------------------------------------------------------
WindowsWindow::WindowsWindow(const WindowConfig &config)
{
	Init(config);
}
//-----------------------------------------------------------------------------
WindowsWindow::~WindowsWindow()
{
	Shutdown();
}
//-----------------------------------------------------------------------------
void WindowsWindow::Init(const WindowConfig &config)
{
	m_Data.Title = config.title;
	m_Data.Width = config.width;
	m_Data.Height = config.height;

	SE_CORE_INFO("Creating window {0} ({1}, {2})", config.title, config.width, config.height);

	if (!s_GLFWInitialized)
	{
		// TODO: glfwTerminate on system shutdown
		int success = glfwInit();
		AssertMsg(success, "Could not intialize GLFW!");
		glfwSetErrorCallback(GLFWErrorCallback);
		s_GLFWInitialized = true;
	}

	m_Window = glfwCreateWindow((int)config.width, (int)config.height, m_Data.Title.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(m_Window);
	int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	AssertMsg(status, "Failed to initialize Glad!");
	glfwSetWindowUserPointer(m_Window, &m_Data);
	SetVSync(true);

	// Set GLFW callbacks
	glfwSetWindowSizeCallback(m_Window, 
		[](GLFWwindow *window, int width, int height)
		{
			WindowData &data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;

			WindowResizeEvent event(width, height);
			data.EventCallback(event);
		}
	);

	glfwSetWindowCloseCallback(m_Window,
		[](GLFWwindow *window)
		{
			WindowData &data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.EventCallback(event);
		}
	);

	glfwSetKeyCallback(m_Window, 
		[](GLFWwindow *window, int key, int scancode, int action, int mods)
		{
			WindowData &data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
			case GLFW_PRESS:
			{
				KeyPressedEvent event(key, 0);
				data.EventCallback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				KeyReleasedEvent event(key);
				data.EventCallback(event);
				break;
			}
			case GLFW_REPEAT:
			{
				KeyPressedEvent event(key, 1);
				data.EventCallback(event);
				break;
			}
			}
		}
	);

	glfwSetMouseButtonCallback(m_Window, 
		[](GLFWwindow *window, int button, int action, int mods)
		{
			WindowData &data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
			case GLFW_PRESS:
			{
				MouseButtonPressedEvent event(button);
				data.EventCallback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				MouseButtonReleasedEvent event(button);
				data.EventCallback(event);
				break;
			}
			}
		}
	);

	glfwSetScrollCallback(m_Window, 
		[](GLFWwindow* window, double xOffset, double yOffset)
		{
			WindowData &data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			data.EventCallback(event);
		}
	);

	glfwSetCursorPosCallback(m_Window, 
		[](GLFWwindow *window, double xPos, double yPos)
		{
			WindowData &data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMovedEvent event((float)xPos, (float)yPos);
			data.EventCallback(event);
		}
	);
}
//-----------------------------------------------------------------------------
void WindowsWindow::Shutdown()
{
	glfwDestroyWindow(m_Window);
}
//-----------------------------------------------------------------------------
void WindowsWindow::OnUpdate()
{
	glfwPollEvents();
	glfwSwapBuffers(m_Window);
}
//-----------------------------------------------------------------------------
void WindowsWindow::SetVSync(bool enabled)
{
	if (enabled)
		glfwSwapInterval(1);
	else
		glfwSwapInterval(0);

	m_Data.VSync = enabled;
}
//-----------------------------------------------------------------------------
bool WindowsWindow::IsVSync() const
{
	return m_Data.VSync;
}
//-----------------------------------------------------------------------------

SE_NAMESPACE_END
//=============================================================================