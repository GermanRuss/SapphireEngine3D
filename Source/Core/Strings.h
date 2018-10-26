#pragma once

#include "Iterator.h"

//=============================================================================
SE_NAMESPACE_BEGIN

class WString;
class StringHash;

class String
{
	static char END_ZERO;	// End zero for empty strings.
public:
	using Iterator = RandomAccessIterator<char>;
	using ConstIterator = RandomAccessConstIterator<char>;

	static constexpr uint32_t NPOS = 0xffffffff;// Position for "not found."
	static constexpr uint32_t MIN_CAPACITY = 8;	// Initial dynamic allocation size.
	static const String Empty;					// Empty string.

	String() : m_buffer(&END_ZERO) {}
	String(char *str) : m_buffer(&END_ZERO) { *this = (const char*)str; }
	String(const char *str) : m_buffer(&END_ZERO) { *this = str; }	
	String(const String &str) : m_buffer(&END_ZERO) { *this = str; }
	String(String &&str) : m_buffer(&END_ZERO) { Swap(str); }
	
	String(const char *str, uint32_t length) : m_buffer(&END_ZERO)
	{
		Resize(length);
		copyChars(m_buffer, str, length);
	}

	explicit String(int value);
	explicit String(short value);
	explicit String(long value);
	explicit String(long long value);
	explicit String(unsigned value);
	explicit String(unsigned short value);
	explicit String(unsigned long value);
	explicit String(unsigned long long value);
	explicit String(float value);
	explicit String(double value);
	explicit String(bool value);
	explicit String(char value);
	explicit String(char value, uint32_t length);
	
	~String()
	{
		if ( m_capacity )
			SafeDeleteArray(m_buffer);
	}

	String& operator=(const char *rhs)
	{
		const uint32_t rhsLength = strlen(rhs);
		Resize(rhsLength);
		copyChars(m_buffer, rhs, rhsLength);

		return *this;
	}

	String& operator=(const String &rhs)
	{
		if ( &rhs != this )
		{
			Resize(rhs.m_length);
			copyChars(m_buffer, rhs.m_buffer, rhs.m_length);
		}

		return *this;
	}

	String& operator=(String &&rhs) noexcept
	{
		Assert(&rhs != this);
		Swap(rhs);
		return *this;
	}

	String& operator+=(const String &rhs)
	{
		const uint32_t oldLength = m_length;
		Resize(m_length + rhs.m_length);
		copyChars(m_buffer + oldLength, rhs.m_buffer, rhs.m_length);

		return *this;
	}

	String& operator+=(const char *rhs)
	{
		const uint32_t rhsLength = strlen(rhs);
		const uint32_t oldLength = m_length;
		Resize(m_length + rhsLength);
		copyChars(m_buffer + oldLength, rhs, rhsLength);

		return *this;
	}

	String& operator+=(char rhs)
	{
		const uint32_t oldLength = m_length;
		Resize(m_length + 1);
		m_buffer[oldLength] = rhs;

		return *this;
	}

	String& operator+=(int rhs);
	String& operator+=(short rhs);
	String& operator+=(long rhs);
	String& operator+=(long long rhs);
	String& operator+=(unsigned rhs);
	String& operator+=(unsigned short rhs);
	String& operator+=(unsigned long rhs);
	String& operator+=(unsigned long long rhs);
	String& operator+=(float rhs);
	String& operator+=(bool rhs);

	String operator+(const String &rhs) const
	{
		String ret;
		ret.Resize(m_length + rhs.m_length);
		copyChars(ret.m_buffer, m_buffer, m_length);
		copyChars(ret.m_buffer + m_length, rhs.m_buffer, rhs.m_length);

		return ret;
	}

	String operator+(const char *rhs) const
	{
		const uint32_t rhsLength = strlen(rhs);
		String ret;
		ret.Resize(m_length + rhsLength);
		copyChars(ret.m_buffer, m_buffer, m_length);
		copyChars(ret.m_buffer + m_length, rhs, rhsLength);

		return ret;
	}

	bool operator==(const String &rhs) const { return strcmp(CString(), rhs.CString()) == 0; }
	bool operator!=(const String &rhs) const { return strcmp(CString(), rhs.CString()) != 0; }
	bool operator<(const String &rhs) const { return strcmp(CString(), rhs.CString()) < 0; }
	bool operator>(const String &rhs) const { return strcmp(CString(), rhs.CString()) > 0; }

	bool operator==(const char *rhs) const { return strcmp(CString(), rhs) == 0; }
	bool operator!=(const char *rhs) const { return strcmp(CString(), rhs) != 0; }
	bool operator<(const char *rhs) const { return strcmp(CString(), rhs) < 0; }
	bool operator>(const char *rhs) const { return strcmp(CString(), rhs) > 0; }

	char& operator[](uint32_t index)
	{
		Assert(index < m_length);
		return m_buffer[index];
	}

	const char& operator[](uint32_t index) const
	{
		Assert(index < m_length);
		return m_buffer[index];
	}

	char& At(uint32_t index)
	{
		Assert(index < m_length);
		return m_buffer[index];
	}

	const char& At(uint32_t index) const
	{
		Assert(index < m_length);
		return m_buffer[index];
	}

	void Resize(uint32_t newLength);

	void Swap(String &str);

	const char* CString() const { return m_buffer; }

private:
	static void copyChars(char *dest, const char *src, size_t count)
	{
#if SE_COMPILER_MSVC
		if ( count )
		{
			memcpy(dest, src, count);
		}
#else
		char *end = dest + count;
		while ( dest != end )
		{
			*dest = *src;
			++dest;
			++src;
		}
#endif
	}

	uint32_t m_length = 0;
	uint32_t m_capacity = 0;
	char *m_buffer;
};

SE_NAMESPACE_END
//=============================================================================