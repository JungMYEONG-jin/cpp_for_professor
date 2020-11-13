#include <algorithm>
#include <exception>

using namespace std;


string range = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 .";

 

std::string encrypt(std::string text)

{

        if (text.empty())

               return text;

 

        int nextChar = -1;

        for (int i = 0; i < text.length(); i++)

        {

               if (range.find(text.substr(i, 1)) == string::npos) //허용된 문자가 아니라면

                       throw exception();

               int idx = range.find(text.substr(i, 1));

 

               int bits[6];

               int divisor = 32; //첫 번째 비트는 2^5

               for (int j = 0; j < 6; j++)

               {

                       bits[j] = idx / divisor;

                       idx %= divisor;

                       divisor /= 2;

               }

 

               //1번 조건

               //해당 문자의 5번째 비트와 다음 문자의 첫비트를 바꾼다

               if (nextChar != -1)

                       bits[0] = nextChar;

               if (i < text.length() - 1)

               {

                       nextChar = bits[4];

                       bits[4] = range.find(text.substr(i + 1, 1)) / 32; //첫번째 비트는 2^5이므로

               }

               //2번 조건

               //2번째 비트와 4번째 비트를 뒤바꾼다

               bits[1] = 1 - bits[1];

               bits[3] = 1 - bits[3];

               //3번 조건

               //1, 2, 3번째 비트와 4, 5, 6번째 비트를 서로 바꾼다

               swap(bits[0], bits[3]);

               swap(bits[1], bits[4]);

               swap(bits[2], bits[5]);

               //4번 조건

               //모든 홀수번째 비트와 짝수번째 비트를 서로 바꾼다

               for (int j = 0; j < 6; j+=2)

                       swap(bits[j], bits[j + 1]);

               //5번 조건

               //비트를 거꾸로

               for (int j = 0; j < 3; j++)

                       swap(bits[j], bits[5 - j]);

               //6번 조건

               //첫번째 비트와 세번째 비트를 맞바꾼다

               swap(bits[0], bits[2]);

 

               int newChar = 0;

               divisor = 32;

               for (int j = 0; j < 6; j++)

               {

                       newChar += bits[j] * divisor;

                       divisor /= 2;

               }

               text.replace(i, 1, range.substr(newChar, 1)); //해당 문자를 찾는다

        }

        return text;

}

 

std::string decrypt(std::string encryptedText)

{

        if (encryptedText.empty())

               return encryptedText;

 

        //encrypt와 반대로

        for (int i = encryptedText.length() - 1; i >= 0; i--)

        {

               if (range.find(encryptedText.substr(i, 1)) == string::npos) //허용된 문자가 아니라면

                       throw exception();

               int idx = range.find(encryptedText.substr(i, 1));

 

               int bits[6];

               int divisor = 32;

               for (int j = 0; j < 6; j++)

               {

                       bits[j] = idx / divisor;

                       idx %= divisor;

                       divisor /= 2;

               }

 

               //6번 조건

               swap(bits[0], bits[2]);

               //5번 조건

               for (int j = 0; j < 3; j++)

                       swap(bits[j], bits[5 - j]);

               //4번 조건

               for (int j = 0; j < 6; j += 2)

                       swap(bits[j], bits[j + 1]);

               //3번 조건

               swap(bits[0], bits[3]);

               swap(bits[1], bits[4]);

               swap(bits[2], bits[5]);

               //2번 조건

               bits[1] = 1 - bits[1];

               bits[3] = 1 - bits[3];

 

               int newChar = 0;

               divisor = 32;

               for (int j = 0; j < 6; j++)

               {

                       newChar += bits[j] * divisor;

                       divisor /= 2;

               }

               encryptedText.replace(i, 1, range.substr(newChar, 1));

        }

 

        int beforeChar = -1;

        for (int i = encryptedText.length() - 1; i >= 0; i--)

        {

               if (range.find(encryptedText.substr(i, 1)) == string::npos) //허용된 문자가 아니라면

                       throw exception();

               int idx = range.find(encryptedText.substr(i, 1));

 

               int bits[6];

               int divisor = 32;

               for (int j = 0; j < 6; j++)

               {

                       bits[j] = idx / divisor;

                       idx %= divisor;

                       divisor /= 2;

               }

 

               //1번 조건

               if (beforeChar != -1)

                       bits[4] = beforeChar;

               if (i > 0)

               {

                       beforeChar = bits[0];

                       //5번째 비트(2^1)가 켜져있는지 꺼져있는지만 알고싶으므로

                       //MOD 4를 진행한 후 2로 나누어 판별

                       bits[0] = (range.find(encryptedText.substr(i - 1, 1)) % 4) / 2;

               }

 

               int newChar = 0;

               divisor = 32;

               for (int j = 0; j < 6; j++)

               {

                       newChar += bits[j] * divisor;

                       divisor /= 2;

               }

               encryptedText.replace(i, 1, range.substr(newChar, 1));

        }

        return encryptedText;

}
