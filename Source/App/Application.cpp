// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "stdafx.h"
#include "Application.h"

#if SE_COMPILER_MSVC
#	pragma comment(lib, "OpenGL32.lib")
#endif

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

//=============================================================================
SE_NAMESPACE_BEGIN

//-----------------------------------------------------------------------------
int Application::Run(int argc, const char *argv[])
{
	SE_UNUSED(argc);
	SE_UNUSED(argv);

	//-------------------------------------------------------------------------
	// INIT
	if (!init() || !OnInit() )
		return 1;

	//-------------------------------------------------------------------------
	// RUN MAIN THREAD
	while (!m_finished)
	{
		OnFrame();
		frame();
	}

	//-------------------------------------------------------------------------
	// SHUTDOWN
	OnShutdown();
	shutdown();
	return 0;
}
//-----------------------------------------------------------------------------
void Application::Exit()
{
	m_finished = true;
}
//-----------------------------------------------------------------------------
bool Application::init()
{
	const ApplicationSetting setting = InitSetting();
	TODO("setting хранить в объектах, и get брать из них же");

	Log::Init();
	SE_CORE_WARN("Initialized Log!");

	m_Window = std::unique_ptr<Window>(Window::Create(setting.window));
	m_Window->SetEventCallback(BIND_EVENT_FN(onEvent));
	
	return true;
}
//-----------------------------------------------------------------------------
void Application::frame()
{
	glClearColor(0.3, 0.3, 0.9, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	m_Window->OnUpdate();
}
//-----------------------------------------------------------------------------
void Application::shutdown()
{

}
//-----------------------------------------------------------------------------
void Application::onEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClose));

	//...
}
//-----------------------------------------------------------------------------
bool Application::onWindowClose(WindowCloseEvent &)
{
	m_finished = true;
	return true;
}
//-----------------------------------------------------------------------------

SE_NAMESPACE_END
//=============================================================================