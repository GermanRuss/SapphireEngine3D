#pragma once

//=============================================================================
SE_NAMESPACE_BEGIN

typedef float       Float32;

typedef int64_t     Int64;
typedef int32_t     Int32;
typedef int16_t     Int16;
typedef int8_t      Int8;

typedef uint64_t    Uint64;
typedef uint32_t    Uint32;
typedef uint16_t    Uint16;
typedef uint8_t     Uint8;

typedef size_t      SizeType;
typedef void*       PVoid;

typedef bool        Bool;
static constexpr Bool False = false;
static constexpr Bool True = true;

typedef char        Char;
typedef std::basic_string<Char> String;

SE_NAMESPACE_END
//=============================================================================