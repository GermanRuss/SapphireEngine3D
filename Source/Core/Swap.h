#pragma once

//=============================================================================
SE_NAMESPACE_BEGIN

class String;

template<typename T> 
inline void Swap(T &first, T &second)
{
	T temp = first;
	first = second;
	second = temp;
}

template<> void Swap<String>(String &first, String &second);

SE_NAMESPACE_END
//=============================================================================