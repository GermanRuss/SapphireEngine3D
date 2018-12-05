#pragma once

#include "CompilationOptions.h"

#include "Platform.h"
#include "MinStdConfig.h"
#include "MinWindowsConfig.h"
#include "Macros.h"
#include "InlineFunc.h"
#include "Global.h"

#include "Version.h"

// DOC: https://azrael.digipen.edu/~mmead/www/docs/CompilingWarningLevel4.html
#ifdef SE_COMPILER_MSVC
#	pragma warning(disable: 4290) // Suppress 'C++ Exception Specification ignored'
#	pragma warning(disable: 4514) // Suppress '... unreferenced inline function has been removed'
#	pragma warning(disable: 4710) // Suppress 'function ... not inlined' for Release builds
#	pragma warning(disable: 4786) // Suppress '... truncated to 255 chars in debug'
#endif

// включение доступности основного пространства имен в пользовательском
SE_NAMESPACE_PRIVATE_BEGIN
using namespace SE_NAMESPACE;
SE_NAMESPACE_PRIVATE_END