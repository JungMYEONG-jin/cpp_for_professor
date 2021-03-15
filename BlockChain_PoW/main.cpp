#include <iostream>

#include "KISA_SHA256.h"


using namespace std;

typedef struct BlockHeader {
	BYTE prevHash[257]; // 이전 해시값
};

typedef struct Block {
	int blockSize; // 거래내역 크기
	BlockHeader header;
	int transactionNum = 0; // 몇번째 거래인지
	BYTE transaction[100]; // 거래내역
};

int main()
{



	Block blocks[10]; // 블록 생성

	int select = 0;
	int tot = 0;

	cout << "첫 거래 내용" << endl;
	cin >> blocks[0].transaction;
	blocks[0].transactionNum++;
	
	blocks[0].blockSize = strlen((char*)blocks[0].transaction);

	tot++;
	
	while (tot < 10)
	{
		cout << tot + 1 << "번째 거래내용 입력 : ";
		cin >> blocks[tot].transaction;
		blocks[tot].transactionNum = blocks[tot - 1].transactionNum + 1;



		blocks[tot].blockSize = strlen((char*)blocks[tot].transaction);
		SHA256_Encrpyt(blocks[tot - 1].transaction, blocks[tot - 1].blockSize, blocks[tot].header.prevHash);
		// 블록의 거래내역과 이전 해시값을 암호화시킨다

		tot++;




	}
	int error = 0;
	while (true)
	{
		cout << "1. 거래내역 확인\t2.  거래내역 변조\t0.  종료\n";

		cin >> select;

		if (select == 0)
			return 0;
		else if (select == 1)
		{
			error = 0;
			int i;
			cout << "번호 선택(1~9) : ";
			cin >> select;

			BYTE Encrypt[257];
			SHA256_Encrpyt(blocks[select - 1].transaction, blocks[select - 1].blockSize, Encrypt);

			for (i = 0; i < 256; i++)
			{
				if (blocks[select].header.prevHash[i] != Encrypt[i])
					break;
				//cout << i << endl;
			}
			if (i != 256)
				cout << "거래기록이 변조되었습니다\n";
			else
				cout << "거래기록 : " << blocks[select - 1].transaction << '\n';


		}
		else if (select == 2)
		{
			error = 0;
			cout << "번호 선택(1~9) : ";
			cin >> select;

			blocks[select - 1].transaction[0] = (BYTE)"\0";
			cout << "\n거래내용 입력 : ";
			cin >> blocks[select - 1].transaction;
			cout << "변조 완료\n";
		}
		else
		{
			error++;
			if (error == 3)
			{
				cout << "제한된 횟수 이상으로 잘못된 번호를 입력하여 종료됩니다\n";
				return 0;
			}
			cout << "잘못된 값을 입력하였습니다. 3회 이상 오류시 종료됩니다.\n";
			
		}
	}



	return 0;


}
