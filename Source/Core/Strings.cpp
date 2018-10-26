// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "stdafx.h"
#include "Strings.h"
#include "Swap.h"

//=============================================================================
SE_NAMESPACE_BEGIN

//-----------------------------------------------------------------------------
static constexpr size_t CONVERSION_BUFFER_LENGTH = 21;
//-----------------------------------------------------------------------------
char String::END_ZERO = 0;
const String String::Empty;
//-----------------------------------------------------------------------------
String::String(int value) : m_buffer(&END_ZERO)
{
	char tempBuffer[CONVERSION_BUFFER_LENGTH];
	int len = sprintf_s(tempBuffer, CONVERSION_BUFFER_LENGTH, "%d", value);
	*this = tempBuffer;

	TODO("вместо оператора = использовать прямую команду в которую передавать len");
}
//-----------------------------------------------------------------------------
String::String(short value) : m_buffer(&END_ZERO)
{
	char tempBuffer[CONVERSION_BUFFER_LENGTH];
	int len = sprintf_s(tempBuffer, CONVERSION_BUFFER_LENGTH, "%d", value);
	*this = tempBuffer;
}
//-----------------------------------------------------------------------------
String::String(long value) : m_buffer(&END_ZERO)
{
	char tempBuffer[CONVERSION_BUFFER_LENGTH];
	int len = sprintf_s(tempBuffer, CONVERSION_BUFFER_LENGTH, "%ld", value);
	*this = tempBuffer;
}
//-----------------------------------------------------------------------------
String::String(long long value) : m_buffer(&END_ZERO)
{
	char tempBuffer[CONVERSION_BUFFER_LENGTH];
	int len = sprintf_s(tempBuffer, CONVERSION_BUFFER_LENGTH, "%lld", value);
	*this = tempBuffer;
}
//-----------------------------------------------------------------------------
String::String(unsigned value) : m_buffer(&END_ZERO)
{
	char tempBuffer[CONVERSION_BUFFER_LENGTH];
	int len = sprintf_s(tempBuffer, CONVERSION_BUFFER_LENGTH, "%u", value);
	*this = tempBuffer;
}
//-----------------------------------------------------------------------------
String::String(unsigned short value) : m_buffer(&END_ZERO)
{
	char tempBuffer[CONVERSION_BUFFER_LENGTH];
	int len = sprintf_s(tempBuffer, CONVERSION_BUFFER_LENGTH, "%u", value);
	*this = tempBuffer;
}
//-----------------------------------------------------------------------------
String::String(unsigned long value) : m_buffer(&END_ZERO)
{
	char tempBuffer[CONVERSION_BUFFER_LENGTH];
	int len = sprintf_s(tempBuffer, CONVERSION_BUFFER_LENGTH, "%lu", value);
	*this = tempBuffer;
}
//-----------------------------------------------------------------------------
String::String(unsigned long long value) : m_buffer(&END_ZERO)
{
	char tempBuffer[CONVERSION_BUFFER_LENGTH];
	int len = sprintf_s(tempBuffer, CONVERSION_BUFFER_LENGTH, "%llu", value);
	*this = tempBuffer;
}
//-----------------------------------------------------------------------------
String::String(float value) : m_buffer(&END_ZERO)
{
	char tempBuffer[CONVERSION_BUFFER_LENGTH];
	int len = sprintf_s(tempBuffer, CONVERSION_BUFFER_LENGTH, "%g", value);
	*this = tempBuffer;
}
//-----------------------------------------------------------------------------
String::String(double value) : m_buffer(&END_ZERO)
{
	char tempBuffer[CONVERSION_BUFFER_LENGTH];
	int len = sprintf_s(tempBuffer, CONVERSION_BUFFER_LENGTH, "%.15g", value);
	*this = tempBuffer;
}
//-----------------------------------------------------------------------------
String::String(bool value) : m_buffer(&END_ZERO)
{
	if ( value ) *this = "true";
	else *this = "false";
}
//-----------------------------------------------------------------------------
String::String(char value) : m_buffer(&END_ZERO)
{
	Resize(1);
	m_buffer[0] = value;
}
//-----------------------------------------------------------------------------
String::String(char value, uint32_t length) : m_buffer(&END_ZERO)
{
	Resize(length);
	for ( uint32_t i = 0; i < length; ++i )
		m_buffer[i] = value;
}
//-----------------------------------------------------------------------------
String& String::operator+=(int rhs)
{
	return *this += String(rhs);
}
//-----------------------------------------------------------------------------
String& String::operator+=(short rhs)
{
	return *this += String(rhs);
}
//-----------------------------------------------------------------------------
String& String::operator+=(long rhs)
{
	return *this += String(rhs);
}
//-----------------------------------------------------------------------------
String& String::operator+=(long long rhs)
{
	return *this += String(rhs);
}
//-----------------------------------------------------------------------------
String& String::operator+=(unsigned rhs)
{
	return *this += String(rhs);
}
//-----------------------------------------------------------------------------
String& String::operator+=(unsigned short rhs)
{
	return *this += String(rhs);
}
//-----------------------------------------------------------------------------
String& String::operator+=(unsigned long rhs)
{
	return *this += String(rhs);
}
//-----------------------------------------------------------------------------
String& String::operator+=(unsigned long long rhs)
{
	return *this += String(rhs);
}
//-----------------------------------------------------------------------------
String& String::operator+=(float rhs)
{
	return *this += String(rhs);
}
//-----------------------------------------------------------------------------
String& String::operator+=(bool rhs)
{
	return *this += String(rhs);
}
//-----------------------------------------------------------------------------
void String::Resize(uint32_t newLength)
{
	if ( !m_capacity )
	{
		// If zero length requested, do not allocate buffer yet
		if ( !newLength ) return;

		// Calculate initial capacity
		m_capacity = std::max(newLength + 1, MIN_CAPACITY);

		m_buffer = new char[m_capacity];
	}
	else
	{
		if ( newLength && m_capacity < newLength + 1 )
		{
			// Increase the capacity with half each time it is exceeded
			while ( m_capacity < newLength + 1 )
				m_capacity += (m_capacity + 1) >> 1u;

			auto *newBuffer = new char[m_capacity];
			// Move the existing data to the new buffer, then delete the old buffer
			if ( m_length )
				copyChars(newBuffer, m_buffer, m_length);

			delete[] m_buffer;

			m_buffer = newBuffer;
		}
	}

	m_buffer[newLength] = 0;
	m_length = newLength;
}
//-----------------------------------------------------------------------------
void String::Swap(String &str)
{
	se::Swap(m_length, str.m_length);
	se::Swap(m_capacity, str.m_capacity);
	se::Swap(m_buffer, str.m_buffer);
}
//-----------------------------------------------------------------------------

SE_NAMESPACE_END
//=============================================================================