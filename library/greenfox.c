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

#ifdef __linux__
#include <unistd.h>
#include <sys/times.h>
#elif defined _WIN32 || _WIN64
#include <windows.h>
#endif

// Macro to convert FILETIME to Uint64
#ifdef __linux__
#define LINUX_TIME_TO_MS(v) (v * 1000)
#elif defined _WIN32 || _WIN64
#define FILETIME_TO_UINT64(v) (v.dwLowDateTime + ((UINT64)v.dwHighDateTime << 32))
#endif

#if defined _WIN32 || _WIN64
//To be used with Firefox extension
//see http://stackoverflow.com/questions/9348604/build-a-dll-to-be-used-by-mozilla-js-ctypes
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
  return TRUE;
}
#endif

/* start */
int start()
{
#ifdef __linux__
	struct tms start;
	times(&start);           
	clock_t user_time = start.tms_utime;
	clock_t system_time = start.tms_stime;
	clock_t user_children_time = start.tms_cutime;
	clock_t system_children_time = start.tms_cstime;
	return LINUX_TIME_TO_MS(user_time) + LINUX_TIME_TO_MS(system_time) + LINUX_TIME_TO_MS(user_children_time) + LINUX_TIME_TO_MS(system_children_time);
#elif defined _WIN32 || _WIN64
	FILETIME creationTime, exitTime, kernelTime, userTime;
	HANDLE process = GetCurrentProcess();
	GetProcessTimes(process, &creationTime, &exitTime, &kernelTime, &userTime);
	return FILETIME_TO_UINT64(userTime) + FILETIME_TO_UINT64(kernelTime);
#endif
}

/* stop */
int stop(int previousTime)
{
#ifdef __linux__
	struct tms stop;
	times(&stop);
	clock_t user_time = stop.tms_utime;
	clock_t system_time = stop.tms_stime;
	clock_t user_children_time = stop.tms_cutime;
	clock_t system_children_time = stop.tms_cstime;
	return LINUX_TIME_TO_MS((int)user_time) + LINUX_TIME_TO_MS((int)system_time) + LINUX_TIME_TO_MS((int)user_children_time) + LINUX_TIME_TO_MS((int)system_children_time) - previousTime;
// 	return previousTime;
#elif defined _WIN32 || _WIN64
	FILETIME creationTime, exitTime, kernelTime, userTime;
	HANDLE process = GetCurrentProcess();
	GetProcessTimes(process, &creationTime, &exitTime, &kernelTime, &userTime);
	return FILETIME_TO_UINT64(userTime) + FILETIME_TO_UINT64(kernelTime) - previousTime;
#endif
}
