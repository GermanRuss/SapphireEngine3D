// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "stdafx.h"
#include "Application.h"

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

	return true;
}
//-----------------------------------------------------------------------------
void Application::frame()
{
}
//-----------------------------------------------------------------------------
void Application::shutdown()
{

}
//-----------------------------------------------------------------------------

SE_NAMESPACE_END
//=============================================================================