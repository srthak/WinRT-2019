#include<Windows.h>
BOOL WINAPI DllMain(HINSTANCE hDll, DWORD dwReason, LPVOID lpReaserved) {
	switch (dwReason) {
	case DLL_PROCESS_ATTACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return (TRUE);
}
extern "C" int makesquare(int NUM) {
	return (NUM*NUM);
}
extern "C" BOOL IsNumberNegative(int NUM) {
	if (NUM < 0)
		return TRUE;
	else
		return FALSE;
}
