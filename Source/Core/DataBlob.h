#pragma once

#include "Object.h"

//=============================================================================
SE_NAMESPACE_BEGIN

// {F578FF0D-ABD2-4514-9D32-7CB454D4A73B}
static constexpr INTERFACE_ID IID_DataBlob =
{ 0xf578ff0d, 0xabd2, 0x4514,{ 0x9d, 0x32, 0x7c, 0xb4, 0x54, 0xd4, 0xa7, 0x3b } };

/// Base interface for a file stream
class IDataBlob : public IObject
{
public:
	/// Sets the size of the internal data buffer
	virtual void Resize(size_t NewSize) = 0;

	/// Returns the size of the internal data buffer
	virtual size_t GetSize() = 0;

	/// Returns the pointer to the internal data buffer
	virtual void* GetDataPtr() = 0;
};

SE_NAMESPACE_END
//=============================================================================