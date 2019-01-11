#pragma once

#include "Window.h"
#include "ApplicationEvent.h"

//=============================================================================
SE_NAMESPACE_BEGIN

struct ApplicationSetting
{
	WindowConfig window;
};

class Application : NonCopyable
{
public:
	virtual ~Application() = default;

	int Run(int argc, const char *argv[]);

	virtual ApplicationSetting InitSetting() = 0;
	virtual bool OnInit() = 0;
	virtual void OnFrame() = 0;
	virtual void OnShutdown() = 0;

	void Exit();
	
protected:
	bool init();
	void frame();
	void shutdown();

	void onEvent(Event &e);
	bool onWindowClose(WindowCloseEvent &e);
	
	std::unique_ptr<Window> m_Window;

	bool m_finished = false;
};

SE_NAMESPACE_END
//=============================================================================