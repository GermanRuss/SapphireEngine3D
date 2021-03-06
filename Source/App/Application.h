﻿#pragma once

//=============================================================================
SE_NAMESPACE_BEGIN

struct ApplicationSetting
{
};

class Application
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

	bool m_finished = false;
};

SE_NAMESPACE_END
//=============================================================================