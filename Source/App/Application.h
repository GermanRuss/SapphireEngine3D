#pragma once

#include "Window.h"

//=============================================================================
SE_NAMESPACE_BEGIN

struct ApplicationSetting
{
	WindowConfig window;
};

class Application
{
public:
	virtual ~Application() = default;

	int Run(int argc, const char *argv[]);

	virtual ApplicationSetting InitSetting() = 0;
	virtual bool OnInit() = 0;
	virtual void OnFrame() = 0;
	virtual void OnClose() = 0;

protected:
	Window m_window;
};

SE_NAMESPACE_END
//=============================================================================