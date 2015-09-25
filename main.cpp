#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

string keygen(int len)
{
    string key;

    key.resize(len);
    srand(time(NULL));
    // определяем ключ случайным образом
    for(int i = 0; i < len; i++) {
       key[i] = (char)rand()%(123 - 32) + 32;
    }
    return key;
}

string Vernam_encry(int len, string plTxt, string key)
{
    string cipTxt; //массив-приемник для зашифрованного текста

    cipTxt.resize(len);
    //собственно само шифрование
    for(int i = 0; i < len; i++)
       cipTxt[i] = plTxt[i]^key[i]; //побитовое XOR
    cout << "Encryption:\nPlaintext text: " << plTxt << endl;
    cout << "\nKey: " << key << endl;
    cout << "\nCiphertext text: " << cipTxt << endl;

    return cipTxt;
}

string Vernam_decry(int len, string cipTxt, string key)
{
    string plTxt; //объявляем массив для открытого текста

    key.resize(len);
    cipTxt.resize(len);
    plTxt.resize(len);
    //собственно само шифрование
    for(int i = 0; i < len; i++)
       plTxt[i] = cipTxt[i]^key[i]; //побитовое XOR
    //для наглядности выведем на экран результат работы
    cout << "Decryption:";
    cout << "\nCiphertext text: " << cipTxt << endl;
    cout << "\nKey: " << key << endl;
    cout << "\nPlaintext text: " << plTxt << endl;

    return plTxt;
}

int main()
{
    int len = 0;
    string cipherTxt, plTxt, key, new_plTxt;

    cout << "Enter you plaintext: ";
    getline(std::cin, plTxt);
    len = plTxt.length();// определяем длину строки открытого текста
    key = keygen(len);
    cipherTxt = Vernam_encry(len, plTxt, key);

    new_plTxt = Vernam_decry(len, cipherTxt, key);
    return 0;
}

