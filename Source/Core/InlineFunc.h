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

template <typename T>
inline void Unused(T &&arg) noexcept { (void)arg; }

SE_NAMESPACE_END
//=============================================================================