#include <iostream>

#include <iostream>

#include <cmath>
#include <string>

using std::cout;
using std::cin;
using std::endl;



int main() {
    bool mode = 0;
    bool direction = 0;
    std::string plainText = "";
    std::string cipherText = "";
    unsigned long initKey = 0;
    unsigned long cipher = 0;
    unsigned long textInt = 0;
    unsigned long shift = 0;
    unsigned char tmpChar = '0';

    cout << "Greetings, username!" << endl;
    cout << "Do you want to encrypt or decrypt? 1/0: ";
    cin >> mode;

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
        cout << "Please, input the direction of shift (1/0): ";
        // если 1, то сдвиг влево, если 0, то вправо.
        cin >> direction;
        cout << "Please, input amount of bits in the shift: ";
        // кол-во бит сдвига
        cin >> shift;

        while ((plainText.length() % 4) != 0) {  //если у нас длина текста не кратна блокам данных, то дозаполняем его символом
            plainText += '~';
        }
        for (unsigned int i = 0; i < plainText.length();i += 4) {
            for (size_t j = 0; j < 4; ++j) {
                textInt <<= 8; //сдвигаем на 8 бит
                textInt += static_cast<unsigned char>(plainText[i + j]);  //преобразуем символ в число
            }
            cipher = std::rand() % 4294967295; //генерация шифр-ключа 
            textInt = cipher ^ textInt; //поразрядный XOR
            if (!direction) { // сдвиг в зависимости от направления
                textInt = (textInt >> shift) | ((textInt) << (32 - shift));
            }else{
                textInt = (textInt << shift) | ((textInt) >> (32 - shift));
            }
            for (size_t j = 0; j < 4; ++j) {
                tmpChar = static_cast<unsigned char> (textInt >> 8 * (3 - j));
                cipherText += tmpChar;//Добавляем в зашифрованный текст символы
            }
        }
        cout << "cipherText is >> " << cipherText << " <<" << endl;
    }else{
        cout << "==========================================" << endl;
        cout << "DECRYPTION MODE" << endl <<
            "==========================================" << endl;
        cout << "Please, input the key-cipher: ";
        cin >> initKey;
        srand(initKey);
        cout << "Please, input the text you want to decrypt: ";
        cin.ignore();
        getline(cin, cipherText);
        cout << "Please, input the direction of shift (1/0): ";
        // если 1, то сдвиг влево, если 0, то вправо.
        cin >> direction;
        cout << "Please, input amount of bits in the shift: ";
        // кол-во бит сдвига
        cin >> shift;
        for (size_t i = 0; i < cipherText.length(); i += 4) {
            // делаем тоже самое, что и в режиме шифрования, а именно переводим буквы в int
            for (size_t j = 0; j < 4; ++j) {
                textInt <<= 8;
                textInt += static_cast<unsigned char>(cipherText[i + j]);
            }
            cipher = std::rand() % 4294967295; //генерация шифр-ключа 
            if (direction) { // сдвиг в обратную сторону 
                textInt = (textInt >> shift) | ((textInt) << (32 - shift));
            }else{
                textInt = (textInt << shift) | ((textInt) >> (32 - shift));
            }
            textInt = cipher ^ textInt; //поразрядный XOR
            for (size_t j = 0; j < 4; ++j) {
                tmpChar = static_cast<unsigned char> (textInt >> 8 * (3 - j));
                plainText += tmpChar;//Добавляем в зашифрованный текст символы
            }
        }
        while (plainText[plainText.length() - 1] == '~'){  // Удаляем лишний символ
            plainText.erase(plainText.length() - 1, 1);
        }
        cout << "PlainText is: " << plainText << endl;
    }
    return 0;
}

