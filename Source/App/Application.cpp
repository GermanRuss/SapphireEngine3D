// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "stdafx.h"
#include "Application.h"

#if SE_COMPILER_MSVC
#	pragma comment(lib, "OpenGL32.lib")
#endif
#if SE_COMPILER_MSVC
#	if SE_ARCH_32BIT
#		pragma comment(lib, "glew/lib/Win32/glew32s.lib")
#	elif SE_ARCH_64BIT
#		pragma comment(lib, "glew/lib/x64/glew32s.lib")
#	endif
#endif

//=============================================================================
SE_NAMESPACE_BEGIN

//-----------------------------------------------------------------------------
int Application::Run(int argc, const char *argv[])
{
	SE_UNUSED(argc);
	SE_UNUSED(argv);

	//-------------------------------------------------------------------------
	// INIT
	{
		const ApplicationSetting setting = InitSetting();

		if ( !m_window.Init(setting.window) )
			return 1;

		if ( !OnInit() )
			return 1;
	}	

	//-------------------------------------------------------------------------
	// RUN
	while ( !m_window.IsClosed() )
	{
		m_window.BeginFrame();
		OnFrame();		
		m_window.EndFrame();
	}

	//-------------------------------------------------------------------------
	// Close
	OnClose();
	m_window.Close();
	return 0;
}
//-----------------------------------------------------------------------------

SE_NAMESPACE_END
//=============================================================================