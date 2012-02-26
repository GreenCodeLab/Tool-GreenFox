#include "clGreenFox.h"

#include <nsIClassInfoImpl.h>
#include <nsMemory.h>
#include <nsCOMPtr.h>

#include <windows.h>
#undef GetCurrentTime /* CAUTION! Use GetTickCount instead of GetCurrentTime*/
#undef AddMonitor /* CAUTION! Use AddMonitorW instead */
#define FILETIME_TO_UINT64(v) (v.dwLowDateTime + ((UINT64)v.dwHighDateTime << 32))

/* Implementation file */
//NS_IMPL_ISUPPORTS1(clGreenFox, clIGreenFox)

clGreenFox::clGreenFox()
{
  /* member initializers and constructor code */
}

clGreenFox::~clGreenFox()
{
  /* destructor code */
}


//relatif à l'API _GetHelper...
NS_IMPL_ISUPPORTS2_CI(clGreenFox,
                      clIGreenFox,
                      nsISecurityCheckedComponent)


/* void start (); */
NS_IMETHODIMP clGreenFox::Start()
{

	FILETIME creationTime, exitTime, kernelTime, userTime;

	HANDLE process;
	process = GetCurrentProcess();
	GetProcessTimes(process, &creationTime, &exitTime, &kernelTime, &userTime);


    mPreviousUserTime = FILETIME_TO_UINT64(userTime);
    mPreviousSystemTime = FILETIME_TO_UINT64(kernelTime);

	return NS_OK;

}

/* double stop (); */
NS_IMETHODIMP clGreenFox::Stop(double *_retval NS_OUTPARAM)
{

	FILETIME creationTime, exitTime, kernelTime, userTime;

	HANDLE process;
	process = GetCurrentProcess();
	GetProcessTimes(process, &creationTime, &exitTime, &kernelTime, &userTime);

    UINT64 user = FILETIME_TO_UINT64(userTime) - mPreviousUserTime;
    UINT64 kernel = FILETIME_TO_UINT64(kernelTime) - mPreviousSystemTime;

	*_retval = (double)(user + kernel);

    return NS_OK;
}
