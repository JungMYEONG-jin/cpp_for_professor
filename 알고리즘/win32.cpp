#ifndef UNICODE
#define UNICODE
#define interface struct

#endif
#include <Windows.h>
#include <ShObjIdl.h>




int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
	HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);


	if (SUCCEEDED(hr))
	{
		IFileOpenDialog* pFileOpen;


		hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL, IID_IFileOpenDialog, reinterpret_cast<void**>(&pFileOpen));


		if (SUCCEEDED(hr))
		{
			//Show the open Dialog Box

			hr = pFileOpen->Show(NULL);

			//GET the filename frome the box

			if (SUCCEEDED(hr))
			{
				IShellItem* pItem;
				hr = pFileOpen->GetResult(&pItem);

				if (SUCCEEDED(hr))
				{
					PWSTR pszFilePath;
					hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);

					if (SUCCEEDED(hr))
					{
						MessageBox(NULL, pszFilePath, L"File Path", MB_OK);
						CoTaskMemFree(pszFilePath);
					}
					pItem->Release();

				}
				
			}
			pFileOpen->Release();
			

		}
		CoUninitialize();
		
	}
	return 0;

}
