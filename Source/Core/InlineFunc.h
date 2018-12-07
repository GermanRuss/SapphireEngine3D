#pragma once

//=============================================================================
SE_NAMESPACE_BEGIN

template <typename T>
inline void SafeDelete(T *&resource)
{
	delete resource;
	resource = nullptr;
}

template <typename T>
inline void SafeDeleteArray(T *&resource)
{
	delete[] resource;
	resource = nullptr;
}

template <typename T, int count> 
constexpr int LengthOf(const T(&)[count])
{
	return count;
};

SE_NAMESPACE_END
//=============================================================================