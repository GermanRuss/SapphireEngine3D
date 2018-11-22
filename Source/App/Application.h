#pragma once

#define SE_DECLARE_MAIN(_className)        \
    int main(int argc, const char *argv[]) \
    {                                      \
        SE_NAMESPACE::_className app;      \
        return app.Run(argc, argv);        \
    }

//=============================================================================
SE_NAMESPACE_BEGIN

class Application
{
public:
	// Run method. Command line arguments passed in.
	int Run(int argc, const char* argv[]);
};

SE_NAMESPACE_END
//=============================================================================