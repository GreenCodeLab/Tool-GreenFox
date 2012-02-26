#include<windows.h>

#define FILETIME_TO_UINT64(v) (v.dwLowDateTime + ((UINT64)v.dwHighDateTime << 32))

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
  return TRUE;
}

/* DEBUG METHOD : add */
int add(int a,int b)
{
    return(a+b);
}

/* start */
int start()
{
	FILETIME creationTime, exitTime, kernelTime, userTime;

    HANDLE process;
	process = GetCurrentProcess();
	GetProcessTimes(process, &creationTime, &exitTime, &kernelTime, &userTime);
	
	int mPreviousUserTime = FILETIME_TO_UINT64(userTime);
    int mPreviousSystemTime = FILETIME_TO_UINT64(kernelTime);
	
	return 1;
}

/* stop */
// int stop()
// {
    // TODO
	
	// return 1;
// }
