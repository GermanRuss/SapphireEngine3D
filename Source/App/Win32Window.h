#pragma once

#include "Window.h"

//=============================================================================
SE_NAMESPACE_BEGIN

class WindowsWindow : public Window
{
public:
	WindowsWindow(const WindowConfig &config);
	virtual ~WindowsWindow();

	void OnUpdate() override;

	inline unsigned int GetWidth() const override { return m_Data.Width; }
	inline unsigned int GetHeight() const override { return m_Data.Height; }

	// Window attributes
	inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
	void SetVSync(bool enabled) override;
	bool IsVSync() const override;
private:
	virtual void Init(const WindowConfig &config);
	virtual void Shutdown();

	GLFWwindow *m_Window;

	struct WindowData
	{
		std::string Title;
		unsigned int Width, Height;
		bool VSync;

		EventCallbackFn EventCallback;
	};

	WindowData m_Data;
};

SE_NAMESPACE_END
//=============================================================================