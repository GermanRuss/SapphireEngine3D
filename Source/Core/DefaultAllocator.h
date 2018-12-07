#pragma once

#include "IAllocator.h"

//=============================================================================
SE_NAMESPACE_BEGIN

class DefaultAllocator final : public IAllocator
{
public:
	void* Allocate(size_t n) final;
	void Deallocate(void *p) final;
	void* Reallocate(void *ptr, size_t size) final;
	
	void* AllocateAligned(size_t size, size_t align) final;
	void DeallocateAligned(void *ptr) final;
	void* ReallocateAligned(void *ptr, size_t size, size_t align) final;
};

SE_NAMESPACE_END
//=============================================================================