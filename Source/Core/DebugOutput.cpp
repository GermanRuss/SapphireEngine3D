// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "stdafx.h"
#include "DebugOutput.h"

//=============================================================================
SE_NAMESPACE_BEGIN

//-----------------------------------------------------------------------------
void SetDebugMessageCallback(DebugMessageCallbackType DbgMessageCallback)
{
	// DebugMessageCallback variable is defined in every platform-specific implementation file and initialized with the platform-specific callback
	DebugMessageCallback = DbgMessageCallback;
}

//-----------------------------------------------------------------------------

SE_NAMESPACE_END
//=============================================================================