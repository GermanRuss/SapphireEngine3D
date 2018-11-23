#pragma once

//=============================================================================
SE_NAMESPACE_BEGIN

struct WindowConfig
{
	uint32_t width = 800;
	uint32_t height = 600;
	const char *title = "Sapphire";
};

class Window
{
public:
	~Window();

	bool Init(const WindowConfig &config);
	void BeginFrame();
	void EndFrame();
	void Close();

	bool IsClosed() const;
private:
	WindowConfig m_config;
	GLFWwindow *m_window = nullptr;
	bool m_closed = false;
};

SE_NAMESPACE_END
//=============================================================================