#pragma once

//=============================================================================
SE_NAMESPACE_BEGIN

/// Base interface for a raw memory allocator
class IMemoryAllocator
{
public:
	/// Allocates block of memory
	virtual void* Allocate(size_t Size, const Char* dbgDescription, const char* dbgFileName, const Int32 dbgLineNumber) = 0;

	/// Releases memory
	virtual void Free(void *Ptr) = 0;
};

SE_NAMESPACE_END
//=============================================================================