// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "stdafx.h"
#include "DefaultAllocator.h"

//=============================================================================
SE_NAMESPACE_BEGIN

//-----------------------------------------------------------------------------
void* DefaultAllocator::Allocate(size_t n)
{
	return ::malloc(n);
}
//-----------------------------------------------------------------------------
void DefaultAllocator::Deallocate(void *p)
{
	::free(p);
}
//-----------------------------------------------------------------------------
void* DefaultAllocator::Reallocate(void *ptr, size_t size)
{
	return ::realloc(ptr, size);
}
//-----------------------------------------------------------------------------
void* DefaultAllocator::AllocateAligned(size_t size, size_t align)
{
#if SE_PLATFORM_WINDOWS
	return _aligned_malloc(size, align);
#else
	return aligned_alloc(align, size);
#endif
}
//-----------------------------------------------------------------------------
void DefaultAllocator::DeallocateAligned(void *ptr)
{
#if SE_PLATFORM_WINDOWS
	_aligned_free(ptr);
#else
	free(ptr);
#endif
}
//-----------------------------------------------------------------------------
void* DefaultAllocator::ReallocateAligned(void *ptr, size_t size, size_t align)
{
#if SE_PLATFORM_WINDOWS
	return _aligned_realloc(ptr, size, align);
#else
	// POSIX and glibc do not provide a way to realloc with alignment preservation
	if (size == 0)
	{
		free(ptr);
		return nullptr;
	}
	void *newptr = aligned_alloc(align, size);
	if (newptr == nullptr)
		return nullptr;

	memcpy(newptr, ptr, malloc_usable_size(ptr));
	free(ptr);
	return newptr;
#endif
}
//-----------------------------------------------------------------------------

SE_NAMESPACE_END
//=============================================================================