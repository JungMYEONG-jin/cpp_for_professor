#ifndef UNICODE
#define UNICODE
#endif
#pragma comment(lib, "netapi32.lib")


#include <stdio.h>
#include <Windows.h>
#include <LM.h>
#include <iostream>
#include <ostream>
#include <io.h>
#include <string>
#include <filesystem>

using namespace std;



wstring s2ws(const string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}



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



	string path = "C:\\Users\\MJ_SSD\\Downloads\\test\\*.*";

	struct _finddata_t fd;
	intptr_t hand;
	if ((hand = _findfirst(path.c_str(), &fd)) == -1L)
	{
		cout << "No File Existed in DIrectory" << endl;
	}

	

	//getthe handle to the file
	while (_findnext(hand, &fd) == 0)
	{
		
		string fdpath = fd.name;
		cout << fdpath << endl;
		string temp = "C:\\Users\\MJ_SSD\\Downloads\\test\\" + fdpath;
		cout << temp << endl;
		wstring stemp = s2ws(temp);
		LPCWSTR res = stemp.c_str();
		
		HANDLE filename = CreateFile(res,
			FILE_WRITE_ATTRIBUTES, FILE_SHARE_READ | FILE_SHARE_WRITE,
			NULL, OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL, NULL);

		//set the filetime on the file
		SetFileTime(filename, (LPFILETIME)NULL, (LPFILETIME)NULL, &thefiletime);

		//close our handle.
		CloseHandle(filename);
	}

	return 0;
}
