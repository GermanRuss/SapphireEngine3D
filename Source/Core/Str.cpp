// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "stdafx.h"
#include "Str.h"
#include "IAllocator.h"

//=============================================================================
SE_NAMESPACE_BEGIN

//-----------------------------------------------------------------------------
bool CopyString(char *destination, size_t length, const char *source)
{
	if (!source || length < 1)
		return false;

	while (*source && length > 1)
	{
		*destination = *source;
		--length;
		++destination;
		++source;
	}
	*destination = 0;
	return *source == '\0';
}
//-----------------------------------------------------------------------------
bool CatString(char *destination, int length, const char *source)
{
	while (*destination && length)
	{
		--length;
		++destination;
	}
	return CopyString(destination, length, source);
}
//-----------------------------------------------------------------------------
String::String(IAllocator &alloc)
	: allocator(alloc)
{
}
//-----------------------------------------------------------------------------
String::~String() { allocator.Deallocate(m_cstr); }
//-----------------------------------------------------------------------------

SE_NAMESPACE_END
//=============================================================================