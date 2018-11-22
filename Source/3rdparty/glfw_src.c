#if _MSC_VER
#	pragma warning( disable : 4710 ) // Suppress 'function ... not inlined' for Release builds
#	pragma warning( push, 0 )
#	define _CRT_SECURE_NO_WARNINGS
#endif

#if _WIN32
#	define _GLFW_WIN32 1
#	include "GLFW/src/context.c"
#	include "GLFW/src/egl_context.c"
#	include "GLFW/src/init.c"
#	include "GLFW/src/input.c"
#	include "GLFW/src/monitor.c"
#	include "GLFW/src/osmesa_context.c"
#	include "GLFW/src/vulkan.c"
#	include "GLFW/src/wgl_context.c"
#	include "GLFW/src/win32_init.c"
#	include "GLFW/src/win32_joystick.c"
#	include "GLFW/src/win32_monitor.c"
#	include "GLFW/src/win32_thread.c"
#	include "GLFW/src/win32_time.c"
#	include "GLFW/src/win32_window.c"
#	include "GLFW/src/window.c"
#else
#	error "TODO:"
#endif

#if _MSC_VER
#	undef _CRT_SECURE_NO_WARNINGS
#	pragma warning( pop )
#endif