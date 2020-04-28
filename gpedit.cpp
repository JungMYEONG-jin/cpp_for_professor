#ifndef UNICODE
#define UNICODE
#endif
#pragma comment(lib, "netapi32.lib")


#include <stdio.h>
#include <Windows.h>
#include <LM.h>











//유니코드 사용지 wide_model 사용
int wmain(int argc, wchar_t* argv[])
{
	DWORD dwLevel = 0; // info_level 0 
	USER_MODALS_INFO_0* pBuf = NULL; //수정할 객체
	USER_MODALS_INFO_0* pBuf2 = NULL; //원본 객체
	NET_API_STATUS gStatus;	// get작동여부 판단
	NET_API_STATUS gStatus2; 
	NET_API_STATUS sStatus; //set작동여부 판단
	LPTSTR psServerName = NULL; //정책 정보 get, set 할 때 사용

	USER_MODALS_INFO_0 ui; //set method에 사용

	

	int choice = 0;
	int value = 0;

	if (argc > 2)
	{
		fwprintf(stderr, L"Usage: %s [\\\\ServerName\n", argv[0]);
		exit(1);
	}
	if (argc == 2)
	{
		psServerName = (LPTSTR)argv[1];
	}

	gStatus2 = NetUserModalsGet((LPCWSTR)psServerName, dwLevel, (LPBYTE*)&pBuf2); // 원본값


	while (true)
	{

		//레벨0으로 function 실행
		gStatus = NetUserModalsGet((LPCWSTR)psServerName, dwLevel, (LPBYTE*)&pBuf);

		//call 성공시 global 정보 획득
		if (gStatus == NERR_Success)
		{
			if (pBuf != NULL)
			{
				printf("사용자 암호정책 정보입니다\n");
				printf("Minimum password length: %d\n", pBuf->usrmod0_min_passwd_len);
				printf("Maximum password age (d): %d\n", pBuf->usrmod0_max_passwd_age / 86400);
				printf("Minimum password age (d): %d\n", pBuf->usrmod0_min_passwd_age / 86400);
				printf("Forced log off time (s): %d\n", pBuf->usrmod0_force_logoff);
				printf("Password history length: %d\n", pBuf->usrmod0_password_hist_len);
			}

		}
		else
			fprintf(stderr, "A system Error has occurred: %d\n", gStatus);

		if (pBuf != NULL)
			NetApiBufferFree(pBuf);

		printf("0. 종료\n1. 모두 취약하게 만들기\n2. 항목별 값 설정(직접입력)\n3. 초기 설정 값으로 되돌리기\n");
		scanf_s("%d", &choice);
		if (choice == 0)
		{
			if (pBuf2 != NULL)
				NetApiBufferFree(pBuf2);
			break;
		}
		if (choice == 1)
		{
			ui.usrmod0_min_passwd_len = 0;
			ui.usrmod0_min_passwd_age = 0;
			ui.usrmod0_max_passwd_age = (86400 * 1);
			ui.usrmod0_force_logoff = TIMEQ_FOREVER;
			ui.usrmod0_password_hist_len = 0;
		}
		if (choice == 2)
		{
			ui.usrmod0_force_logoff = TIMEQ_FOREVER;
			printf("최소 암호길이(0~20): ");
			scanf_s("%d", &value);
			ui.usrmod0_min_passwd_len = value;
			printf("최대 암호사용기간(최소 암호 사용 기간보다 커야합니다! (0~999): ");
			scanf_s("%d", &value);
			ui.usrmod0_max_passwd_age = (86400 * value);
			printf("최소 암호사용기간(0~998): ");
			scanf_s("%d", &value);
			ui.usrmod0_min_passwd_age = (86400*value);
			printf("기억하는 password 갯수: ");
			scanf_s("%d", &value);
			ui.usrmod0_password_hist_len = value;


		}
		if (choice == 3)
		{
			ui.usrmod0_force_logoff = pBuf2->usrmod0_force_logoff;
			ui.usrmod0_max_passwd_age = pBuf2->usrmod0_max_passwd_age;
			ui.usrmod0_min_passwd_age = pBuf2->usrmod0_min_passwd_age;
			ui.usrmod0_min_passwd_len = pBuf2->usrmod0_min_passwd_len;
			ui.usrmod0_password_hist_len = pBuf2->usrmod0_password_hist_len;
		}
	
		sStatus = NetUserModalsSet((LPCWSTR)psServerName, dwLevel, (LPBYTE)&ui, NULL);

		//set 성공시 정책 적용 성공.
		if (sStatus == NERR_Success)
			fwprintf(stderr, L"Set Procedure successfully on %s\n", argv[1]);

		else
			fprintf(stderr, "A system error has occured: %d\n", sStatus);

	
	}

	return 0;



}



