// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "stdafx.h"
#include "Application.h"

//=============================================================================
SE_NAMESPACE_BEGIN

//-----------------------------------------------------------------------------
int Application::Run(const ApplicationSettings &setting, int argc, const char *argv[])
{
	SE_UNUSED(argc);
	SE_UNUSED(argv);

	m_setting = setting;

	if ( !m_context.Init() )
		return 1;

	while ( m_context.Frame() );

	m_context.Close();

	return 0;
}
//-----------------------------------------------------------------------------

SE_NAMESPACE_END
//=============================================================================