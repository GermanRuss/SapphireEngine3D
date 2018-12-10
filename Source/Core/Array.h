#pragma once

#include "IAllocator.h"

//=============================================================================
SE_NAMESPACE_BEGIN

template <typename T> 
class Array
{
public:
	explicit Array(IAllocator &allocator) : m_allocator(allocator) {}
	~Array()
	{
		callDestructors(m_data, m_data + m_size);
		m_allocator.DeallocateAligned(m_data);
	}

	void Push(const T &value)
	{
		int size = m_size;
		if (size == m_capacity)
			grow();

		new (NewPlaceholder(), (char*)(m_data + size)) T(value);
		++size;
		m_size = size;
	}

	bool Empty() const { return m_size == 0; }

private:
	void grow()
	{
		int new_capacity = m_capacity == 0 ? 4 : m_capacity * 2;
		m_data = (T*)m_allocator.ReallocateAligned(m_data, new_capacity * sizeof(T), alignof(T));
		m_capacity = new_capacity;
	}

	void callDestructors(T *begin, T *end)
	{
		for (; begin < end; ++begin)
			begin->~T();
	}

	IAllocator &m_allocator;
	int m_capacity = 0;
	int m_size = 0;
	T *m_data = nullptr;
};

SE_NAMESPACE_END
//=============================================================================