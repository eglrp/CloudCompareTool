
//by duans 2018.6.14

#ifdef DPX_MAP_USE_AS_DLL

// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the DPX_MAP_LIB_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// DPX_MAP_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef DPX_MAP_LIB_EXPORTS

	#define DPX_MAP_API __declspec(dllexport)
		#else //NOT QCC_DB_LIB_EXPORTS
	#define DPX_MAP_API __declspec(dllimport)
	#endif //NOT QCC_DB_LIB_EXPORTS

#else //NOT DPX_MAP_USE_AS_DLL

#define DPX_MAP_API

#endif //NOT DPX_MAP_USE_AS_DLL
