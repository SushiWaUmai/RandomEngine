#pragma once

#ifdef RE_DYNAMIC_LINK
	#ifdef RE_PLATFORM_WINDOWS
		#ifdef RE_BUILD_DLL
			#define RE_API __declspec(dllexport)
		#else 
			#define RE_API __declspec(dllimport)
		#endif
	#else
		#error Random Engine only support Windows.
	#endif
#else
	#define EXD_API
#endif