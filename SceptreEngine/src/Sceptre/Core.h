#pragma once

#ifdef SC_PLATFORM_WINDOWS
	#ifdef SC_BUILD_DLL
		#define SCEPTRE_API __declspec(dllexport)
		#define SC_EXPORT_API __declspec(dllexport)
	#else
		#define SCEPTRE_API __declspec(dllimport)
		#define SC_EXPORT_API 
	#endif
#else
	#error Sceptre only supports Windows!
#endif

#define BIT(x) (1 << x)