#pragma once

//=============================================================================
SE_NAMESPACE_BEGIN

struct WindowConfig
{
	uint32_t width = 800;
	uint32_t height = 600;
	const char *title = "Sapphire";
};

#define SE_MAX_KEYS    1024
#define SE_MAX_BUTTONS 32

class Window
{
	friend static void keyCallback(GLFWwindow *, int, int, int, int);
	friend static void mouseButtonCallback(GLFWwindow*, int, int, int);
	friend static void cursorPositionCallback(GLFWwindow*, double, double);
public:
	~Window();

	bool Init(const WindowConfig &config);
	void BeginFrame();
	void EndFrame();
	void Close();

	bool IsClosed() const;

	bool IsKeyPressed(unsigned int keycode) const;
	bool IsMouseButtonPressed(unsigned int button) const;
	void GetMousePosition(double &x, double &y) const;
private:
	WindowConfig m_config;
	GLFWwindow *m_window = nullptr;
	bool m_closed = false;

	bool m_keys[SE_MAX_KEYS];
	bool m_mouseButtons[SE_MAX_BUTTONS];
	double m_x = 0.0;
	double m_y = 0.0;
};

SE_NAMESPACE_END
//=============================================================================