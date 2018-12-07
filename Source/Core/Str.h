#pragma once

//=============================================================================
SE_NAMESPACE_BEGIN

template <int size> 
class StaticString
{
public:
	StaticString() { m_data[0] = '\0'; }

	bool Empty() const { return m_data[0] == '\0'; }

	operator const char*() const { return m_data; }

private:
	char m_data[size];
};

SE_NAMESPACE_END
//=============================================================================