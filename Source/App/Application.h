#pragma once

#include "Context.h"

//=============================================================================
SE_NAMESPACE_BEGIN

struct ApplicationSettings
{
	ApplicationSettings() = default;
	ApplicationSettings(uint32_t w, uint32_t h)
		: width(w)
		, height(h)
	{
	}

	uint32_t width = 800;
	uint32_t height = 600;
};

class Application
{
public:
	// Run method. Command line arguments passed in.
	int Run(const ApplicationSettings &setting, int argc, const char *argv[]);

private:
	ApplicationSettings m_setting;
	Context m_context;
};

SE_NAMESPACE_END
//=============================================================================