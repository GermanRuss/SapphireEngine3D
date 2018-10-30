#pragma once

#if SE_PLATFORM_WINDOWS

#	if SE_WIN32_CONSOLE
#		define SapphireMain(cl) \
			int main(int argc, const char **argv) \
			{                \
				se::cl app;  \
				app.Start(); \
				return 0;    \
			}
#	else
#		include <Windows.h>
#		define SapphireMain(cl) \
			int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nShowCmd) \
			{                \
				se::cl app;  \
				app.Start(); \
				return 0;    \
			}
#	endif
#endif