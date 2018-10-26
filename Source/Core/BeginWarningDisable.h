// DOC: https://azrael.digipen.edu/~mmead/www/docs/CompilingWarningLevel4.html
#ifdef SE_COMPILER_MSVC
#	pragma warning(disable: 4290)   // Suppress 'C++ Exception Specification ignored'
#	pragma warning(disable: 4710)   // Suppress 'function ... not inlined' for Release builds
#	pragma warning(disable: 4514)   // Suppress '... unreferenced inline function has been removed'
#	pragma warning(disable: 4786)   // Suppress '... truncated to 255 chars in debug'

#	pragma warning(push, 3)         // Set warning levels to a quieter level for the STL
#endif