#pragma once

SE_NAMESPACE_BEGIN
struct NewPlaceholder {};
SE_NAMESPACE_END

inline void* operator new(size_t, SE_NAMESPACE::NewPlaceholder, void *where)
{
	return where;
}

inline void operator delete(void*, SE_NAMESPACE::NewPlaceholder, void*)
{
}

#define SE_NEW(_alloc, ...) new (  \
	SE_NAMESPACE::NewPlaceholder(), \
	(_alloc).AllocateAligned(sizeof(__VA_ARGS__), alignof(__VA_ARGS__)) \
	) __VA_ARGS__

#define SE_DELETE(_allocator, _var) (_allocator).DeleteObject(_var);

//=============================================================================
SE_NAMESPACE_BEGIN

class IAllocator
{
public:
	virtual ~IAllocator() = default;

	virtual void* Allocate(size_t size) = 0;
	virtual void Deallocate(void *ptr) = 0;
	virtual void* Reallocate(void *ptr, size_t size) = 0;

	virtual void* AllocateAligned(size_t size, size_t align) = 0;
	virtual void DeallocateAligned(void *ptr) = 0;
	virtual void* ReallocateAligned(void *ptr, size_t size, size_t align) = 0;

	template <class T> 
	void DeleteObject(T *ptr)
	{
		if (ptr)
		{
			ptr->~T();
			DeallocateAligned(ptr);
		}
	}
};

SE_NAMESPACE_END
//=============================================================================