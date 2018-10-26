#pragma once

//=============================================================================
SE_NAMESPACE_BEGIN

template <typename T>
inline void SafeDelete(T *&resource)
{
	delete resource;
	resource = nullptr;
}

template <class T>
inline void Unused(T const&){}

SE_NAMESPACE_END
//=============================================================================