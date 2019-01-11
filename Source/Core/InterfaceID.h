#pragma once

//=============================================================================
SE_NAMESPACE_BEGIN

/// Describes unique identifier
struct INTERFACE_ID
{
	bool operator==(const INTERFACE_ID &rhs) const
	{
		return 
			Data1 == rhs.Data1 &&
			Data2 == rhs.Data2 &&
			Data3 == rhs.Data3 &&
			std::memcmp(Data4, rhs.Data4, sizeof(Data4)) == 0;
	}

	Uint32 Data1;
	Uint16 Data2;
	Uint16 Data3;
	Uint8  Data4[8];
};

/// Unknown interface
static constexpr INTERFACE_ID IID_Unknown = { 0, 0, 0,{ 0, 0, 0, 0, 0, 0, 0, 0 } };

SE_NAMESPACE_END
//=============================================================================