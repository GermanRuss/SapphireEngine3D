#pragma once

//=============================================================================
SE_NAMESPACE_BEGIN

struct IAllocator;

bool CopyString(char *destination, size_t length, const char *source);

bool CatString(char *destination, int length, const char *source);

template <int size>
bool CopyString(char(&destination)[size], const char *source)
{
	return CopyString(destination, size, source);
}

template <int size>
bool CatString(char(&destination)[size], const char *source)
{
	return CatString(destination, size, source);
}

template <int size> 
class StaticString
{
public:
	StaticString() { m_data[0] = '\0'; }
	explicit StaticString(const char *str) { CopyString(data, size, str); }

	void operator=(const char *str) { CopyString(data, str); }

	bool Empty() const { return m_data[0] == '\0'; }

	operator const char*() const { return m_data; }

private:
	char m_data[size];
};

class String
{
public:
	explicit String(IAllocator &allocator);
	~String();

	IAllocator &allocator;
private:
	i32 m_size = 0;
	char *m_cstr = nullptr;
};

SE_NAMESPACE_END
//=============================================================================