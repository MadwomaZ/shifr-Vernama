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
    string cipTxt; //строка для зашифрованного текста

    cipTxt.resize(len);

    //шифрование
    for(int i = 0; i < len; i++)
       cipTxt[i] = plTxt[i]^key[i]; //побитовое XOR

    //результат работы
    cout << "Encryption:\nPlaintext text: " << plTxt << endl;
    cout << "\nKey: " << key << endl;
    cout << "\nCiphertext text: " << cipTxt << endl;

    return cipTxt;
}

string Vernam_decry(int len, string cipTxt, string key)
{
    string plTxt; //строка для открытого текста

    key.resize(len);
    cipTxt.resize(len);
    plTxt.resize(len);

    //дешифрование
    for(int i = 0; i < len; i++)
       plTxt[i] = cipTxt[i]^key[i]; //побитовое XOR

    //результат работы
    cout << "Decryption:\nCiphertext text: " << cipTxt << endl;
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

    cipherTxt = Vernam_encry(len, plTxt, key); //зашифрованный текст

    new_plTxt = Vernam_decry(len, cipherTxt, key); //расшифрованный открытый текст
    return 0;
}

