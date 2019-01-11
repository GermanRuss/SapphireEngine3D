#pragma once

#include "Object.h"
#include "DataBlob.h"

//=============================================================================
SE_NAMESPACE_BEGIN

/// IFileStream interface unique identifier
// {E67F386C-6A5A-4A24-A0CE-C66435465D41}
static constexpr INTERFACE_ID IID_FileStream =
{ 0xe67f386c, 0x6a5a, 0x4a24,{ 0xa0, 0xce, 0xc6, 0x64, 0x35, 0x46, 0x5d, 0x41 } };

/// Base interface for a file stream
class IFileStream : public IObject
{
public:
	/// Reads data from the stream
	virtual bool Read(void *Data, size_t BufferSize) = 0;

	virtual void Read(IDataBlob *pData) = 0;

	/// Writes data to the stream
	virtual bool Write(const void *Data, size_t Size) = 0;

	virtual size_t GetSize() = 0;

	virtual bool IsValid() = 0;
};

SE_NAMESPACE_END
//=============================================================================