#pragma once

//=============================================================================
SE_NAMESPACE_BEGIN

template <typename T> 
struct RandomAccessIterator
{
	RandomAccessIterator() = default;
	explicit RandomAccessIterator(T *p) : ptr(p) {}

	T* operator->() const { return ptr; }
	T& operator*() const { return *ptr; }

	RandomAccessIterator<T>& operator++()
	{
		++ptr;
		return *this;
	}

	//RandomAccessIterator<T> operator++(int)
	//{
	//	RandomAccessIterator<T> it = *this;
	//	++ptr;
	//	return it;
	//}

	RandomAccessIterator<T>& operator--()
	{
		--ptr;
		return *this;
	}

	//RandomAccessIterator<T> operator--(int)
	//{
	//	RandomAccessIterator<T> it = *this;
	//	--ptr;
	//	return it;
	//}

	RandomAccessIterator<T>& operator+=(int value)
	{
		ptr += value;
		return *this;
	}

	RandomAccessIterator<T>& operator-=(int value)
	{
		ptr -= value;
		return *this;
	}

	RandomAccessIterator<T> operator+(int value) const { return RandomAccessIterator<T>(ptr + value); }

	RandomAccessIterator<T> operator-(int value) const { return RandomAccessIterator<T>(ptr - value); }

	int operator-(const RandomAccessIterator &rhs) const { return (int)(ptr - rhs.ptr); }

	bool operator==(const RandomAccessIterator &rhs) const { return ptr == rhs.ptr; }
	bool operator!=(const RandomAccessIterator &rhs) const { return ptr != rhs.ptr; }

	bool operator<(const RandomAccessIterator &rhs) const { return ptr < rhs.ptr; }
	bool operator>(const RandomAccessIterator &rhs) const { return ptr > rhs.ptr; }

	bool operator<=(const RandomAccessIterator &rhs) const { return ptr <= rhs.ptr; }
	bool operator>=(const RandomAccessIterator &rhs) const { return ptr >= rhs.ptr; }
	
	T *ptr = nullptr;
};

template <typename T>
struct RandomAccessConstIterator
{
	RandomAccessConstIterator() = default;
	explicit RandomAccessConstIterator(const T *p) : ptr(p) {}
	RandomAccessConstIterator(const RandomAccessIterator<T> &rhs) :ptr(rhs.ptr) {}
	
	RandomAccessConstIterator<T>& operator=(const RandomAccessIterator<T> &rhs)
	{
		ptr = rhs.ptr;
		return *this;
	}

	const T* operator->() const { return ptr; }
	const T& operator*() const { return *ptr; }

	RandomAccessConstIterator<T>& operator++()
	{
		++ptr;
		return *this;
	}

	//RandomAccessConstIterator<T> operator++(int)
	//{
	//	RandomAccessConstIterator<T> it = *this;
	//	++ptr;
	//	return it;
	//}

	RandomAccessConstIterator<T>& operator--()
	{
		--ptr;
		return *this;
	}

	//RandomAccessConstIterator<T> operator--(int)
	//{
	//	RandomAccessConstIterator<T> it = *this;
	//	--ptr;
	//	return it;
	//}

	RandomAccessConstIterator<T>& operator+=(int value)
	{
		ptr += value;
		return *this;
	}

	RandomAccessConstIterator<T>& operator-=(int value)
	{
		ptr -= value;
		return *this;
	}

	RandomAccessConstIterator<T> operator+(int value) const { return RandomAccessConstIterator<T>(ptr + value); }

	RandomAccessConstIterator<T> operator-(int value) const { return RandomAccessConstIterator<T>(ptr - value); }

	int operator-(const RandomAccessConstIterator &rhs) const { return (int)(ptr - rhs.ptr); }

	bool operator==(const RandomAccessConstIterator &rhs) const { return ptr == rhs.ptr; }

	bool operator!=(const RandomAccessConstIterator &rhs) const { return ptr != rhs.ptr; }

	bool operator<(const RandomAccessConstIterator &rhs) const { return ptr < rhs.ptr; }

	bool operator>(const RandomAccessConstIterator &rhs) const { return ptr > rhs.ptr; }

	bool operator<=(const RandomAccessConstIterator &rhs) const { return ptr <= rhs.ptr; }

	bool operator>=(const RandomAccessConstIterator &rhs) const { return ptr >= rhs.ptr; }

	const T *ptr = nullptr;
};

SE_NAMESPACE_END
//=============================================================================