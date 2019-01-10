#pragma once

#include "Event.h"

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
	using EventCallbackFn = std::function<void(Event&)>;

	virtual ~Window() = default;	

	static Window* Create(const WindowConfig &config);
	
	virtual void OnUpdate() = 0;

	virtual uint32_t GetWidth() const = 0;
	virtual uint32_t GetHeight() const = 0;

	virtual void SetEventCallback(const EventCallbackFn &callback) = 0;
	virtual void SetVSync(bool enabled) = 0;
	virtual bool IsVSync() const = 0;
	
protected:
	//WindowConfig m_config;
};

SE_NAMESPACE_END
//=============================================================================