#ifndef UNICODE
#define UNICODE
#endif
#pragma comment(lib, "netapi32.lib")


#include <stdio.h>
#include <Windows.h>
#include <LM.h>
#include <iostream>
#include <ostream>
#include <filesystem>

using namespace std;


// 파일 수정된날짜 변경시키키
int main() {
	std::cout << "a new project";
	
	//creates a file as varuntest.txt
	

	SYSTEMTIME thesystemtime;
	GetSystemTime(&thesystemtime);

	thesystemtime.wDay = 07;//changes the day
	thesystemtime.wMonth = 04;//changes the month
	thesystemtime.wYear = 2099;//changes the year

	//creation of a filetimestruct and convert our new systemtime
	FILETIME thefiletime;

	SystemTimeToFileTime(&thesystemtime, &thefiletime);

	//getthe handle to the file
	HANDLE filename = CreateFile(L"C:\\Users\\MJ_SSD\\Downloads\\as2.png",
		FILE_WRITE_ATTRIBUTES, FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, NULL);

	//set the filetime on the file
	SetFileTime(filename, (LPFILETIME)NULL, (LPFILETIME)NULL, &thefiletime);

	//close our handle.
	CloseHandle(filename);


	return 0;
}







