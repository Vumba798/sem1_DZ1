#include <iostream>

#include <iostream>

#include <cmath>
#include <string>

using std::cout;
using std::cin;
using std::endl;



int main()
{
    bool mode;
    std::string plainText, cipherText;
    unsigned long initKey;
    unsigned short cipher, textInt, shift;
    int tmpInt = 0;
    cout << "Greetings, username!" << endl;
    cout << "Do you want to encrypt or decrypt? 1/0: ";
    cin >> mode;

    //последняя цифра - кол-во бит для сдвига
    //если предпоследняя цифра - чётная, то сдвиг вправо, если нечётная, то влево
    if (mode) { // режим шифрования
        cout << "==========================================" << endl;
        cout << "ENCRYPTION MODE" << endl <<
            "==========================================" << endl;
        cout << "Please, input the initKey(cipher): ";
        cin.ignore();
        cin >> initKey;
        srand(initKey);//генерация от ключа инициализации
        cout << "Please, input the text you want to encrypt: ";
        cin.ignore();
        std::getline(cin, plainText);

        shift = initKey % 10;
        initKey /= 10;

        if ((plainText.length() % 2) == 1) {  //если у нас длина текста не кратна блокам данных, то дозаполняем его символом
            plainText += '~';
        }
        for (unsigned int i = 0; i < plainText.length();i += 2) {
            textInt = static_cast<unsigned char> (plainText[i]);  //преобразуем символ в число
            textInt <<= 8; //сдвигаем на 8 бит
            textInt += static_cast<unsigned char> (plainText[i + 1]);;
            cipher = std::rand() % 32767; //генерация шифр-ключа 
            cout << "cipher = " << cipher << endl;
            textInt = cipher ^ textInt; //поразрядный XOR
            if (initKey % 2 == 0) {  //если символ отвечающий за направление сдвига чётный, то сдвиг вправо
                textInt = (textInt >> shift) | ((textInt) << (16 - shift));
            }else{  //если нечётный, то влево
                textInt = (textInt << shift) | ((textInt) >> (16 - shift));
            }
            cipherText += (textInt >> 8);//Добавляем в зашифрованный текст первый символ
            tmpInt = textInt << 8;
            cipherText += (tmpInt >> 8);//добавляем второй символ
        }
        cout << "cipherText is >> " << cipherText << " <<" << endl;
    }else{
        cout << "==========================================" << endl;
        cout << "DECRYPTION MODE" << endl <<
            "==========================================" << endl;
        cout << "Please, input the key-cipher: ";
        cin >> initKey;
        srand(initKey);//генерация от суммы двух символов ключа
        cout << "Please, input the text you want to decrypt: ";
        cin.ignore();
        getline(cin, cipherText);
        shift = initKey % 10;
        initKey /= 10;
        for (unsigned int i = 0; i < cipherText.length();i += 2) {
            // делаем тоже самое, что и в режиме шифрования, а именно переводим буквы в int
            textInt = static_cast<unsigned char>(cipherText[i]);
            textInt <<= 8;
            tmpInt = static_cast<unsigned char>(cipherText[i + 1]);
            textInt += tmpInt;
            cipher = std::rand() % 32767; //генерация шифр-ключа 
            cout << "cipher = " << cipher << endl;
            if (initKey % 2 == 0) {  //если цифра, отвечающая за направление сдвига чётная, то сдвиг наоборот, влево
                textInt = (textInt << shift) | (textInt) >> (16 - shift);
            }else{  //если нечётная, то наоборот, вправо
                textInt = (textInt >> shift) | (textInt) << (16 - shift);
            }
            textInt = cipher ^ textInt; //поразрядный XOR
            plainText += (textInt >> 8);//Добавляем в зашифрованный текст первый символ
            tmpInt = textInt << 8;
            plainText += (tmpInt >> 8);//добавляем второй символ
        }
        if (plainText[plainText.length() - 1] == '~'){  // Удаляем лишний символ
            plainText.erase(plainText.length() - 1, 1);
        }
        cout << "PlainText is: " << plainText << endl;
    }
    return 0;
}

