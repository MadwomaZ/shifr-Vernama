#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

string Vernam_encry()
{
   int len = 0;

   string plTxt; //объявляем массив для открытого текста
   string key;   //точно такой же массив объявляем для ключа
   string cipTxt; //массив-приемник для зашифрованного текста

   cout << "Enter you plaintext: ";
   getline(std::cin, plTxt);
   len = plTxt.length();// определяем длину строки открытого текста
   key.resize(len);
   cipTxt.resize(len);
   srand(time(NULL));
// определяем ключ случайным образом
   for(int i = 0; i < len; i++) {
      key[i] = (char)rand()%(123 - 32) + 32;
   }
//собственно само шифрование
   for(int i = 0; i < len; i++)
      cipTxt[i]=plTxt[i]^key[i]; //побитовое XOR
//для наглядности выведем на экран результат работы
   cout << "\nPlaintext text: " << plTxt << endl;
   cout << "\nKey: " << key << endl;
   cout << "\nCiphertext text: " << cipTxt << endl;

   return cipTxt;
}

int main()
{
    Vernam_encry();
    return 0;
}

