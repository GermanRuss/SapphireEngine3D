#if _MSC_VER
#	pragma warning( disable : 4710 ) // Suppress 'function ... not inlined' for Release builds
#	pragma warning( push, 0 )
#	define _CRT_SECURE_NO_WARNINGS
#endif

#if _WIN32
#	define _GLFW_WIN32 1
#	include "GLFW/context.c"
#	include "GLFW/egl_context.c"
#	include "GLFW/init.c"
#	include "GLFW/input.c"
#	include "GLFW/monitor.c"
#	include "GLFW/osmesa_context.c"
#	include "GLFW/vulkan.c"
#	include "GLFW/wgl_context.c"
#	include "GLFW/win32_init.c"
#	include "GLFW/win32_joystick.c"
#	include "GLFW/win32_monitor.c"
#	include "GLFW/win32_thread.c"
#	include "GLFW/win32_time.c"
#	include "GLFW/win32_window.c"
#	include "GLFW/window.c"
#else
#	error "TODO:"
#endif

#if _MSC_VER
#	undef _CRT_SECURE_NO_WARNINGS
#	pragma warning( pop )
#endif