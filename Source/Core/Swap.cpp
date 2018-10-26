// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "stdafx.h"
#include "Swap.h"
#include "Strings.h"

//=============================================================================
SE_NAMESPACE_BEGIN

//-----------------------------------------------------------------------------
template<> void Swap<String>(String &first, String &second)
{
	first.Swap(second);
}
//-----------------------------------------------------------------------------

SE_NAMESPACE_END
//=============================================================================