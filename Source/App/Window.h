#pragma once

//=============================================================================
SE_NAMESPACE_BEGIN

struct WindowConfig
{
	uint32_t width = 800;
	uint32_t height = 600;
	const char *title = "Sapphire";
};

class Window
{
public:
	
private:
	WindowConfig m_config;
};

SE_NAMESPACE_END
//=============================================================================