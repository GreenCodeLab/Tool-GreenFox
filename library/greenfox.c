/*
	greenfox.c
	Description: Interface between the Firefox plugin 
		and the operating system to measure the CPU time 
		consumed between 2 points
	
	Author: Green Code Lab
	Website: http://greencodelab.fr
	Version: 1.0
	Supports: MS Windows XP +
*/

#include <windows.h>

#define FILETIME_TO_UINT64(v) (v.dwLowDateTime + ((UINT64)v.dwHighDateTime << 32))

/* To be used with Firefox extension */
//see http://stackoverflow.com/questions/9348604/build-a-dll-to-be-used-by-mozilla-js-ctypes
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
  return TRUE;
}

/* start */
int start()
{
	FILETIME creationTime, exitTime, kernelTime, userTime;

	HANDLE process = GetCurrentProcess();
	GetProcessTimes(process, &creationTime, &exitTime, &kernelTime, &userTime);
	
    return FILETIME_TO_UINT64(userTime) + FILETIME_TO_UINT64(kernelTime);
}

/* stop */
int stop(int previousTime)
{
    FILETIME creationTime, exitTime, kernelTime, userTime;

	HANDLE process = GetCurrentProcess();
	GetProcessTimes(process, &creationTime, &exitTime, &kernelTime, &userTime);

	return FILETIME_TO_UINT64(userTime) + FILETIME_TO_UINT64(kernelTime) - previousTime;
}
