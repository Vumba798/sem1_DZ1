#include <iostream>
#include <bitset>
#include <cmath>
#include <string>

using std::cout;
using std::cin;
using std::endl;



int main() {
    bool mode = 0;
    bool direction = 0;
    std::string plainText = ""; // Расшифрованный
    std::string cipherText = ""; // зашифрованный 
    std::bitset<8> byte; 
    unsigned long initKey = 0; // вводим с клавиатуры
    unsigned long cipher = 0; // гамма (шифр)
    unsigned long textInt = 0; // блок
    unsigned long shift = 0; // количество бит сдвига
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
        srand(initKey);  //генерация от ключа инициализации
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
                "abcdef~~"
                "abcd"
                01100001 01100010 01100011 01100100  // text before
                00000000 00000000 00000000 00000000  // textInt before
                01100001 // letter 'a'
                00000000 00000000 00000000 01100001 // textInt after adding 'a' letter
                00000000 00000000 01100001 00000000 
                textInt <<= 8; //сдвигаем на 8 бит
                textInt += static_cast<unsigned char>(plainText[i + j]);  //преобразуем символ в число
                int a = 3;
                unsigned int b = 4;
            }
             
            cipher = std::rand() % 4294967295; //генерация шифр-ключа 
            textInt = cipher ^ textInt; //поразрядный XOR



            01100001 01100010 01100011 01100100  // text before

                00001100 00101100 01001100 01101100 100
                10000000 00000000 00000000 00000000
                10001100 00101100 01001100 01101100 // textInt unchangeble 
                00000000 00000000 10001100 00101100  // скобка вторая итерация
                00101100
                "00101100"
                42;
            byte.to_int()
            cout << textInt //десятичная
            "10001100"
            if (direction) { // сдвиг в зависимости от направления
                textInt = (textInt >> shift) | ((textInt) << (32 - shift));
            }else{
                textInt = (textInt << shift) | ((textInt) >> (32 - shift));
            }
            for (size_t j = 0; j < 4; ++j) {
                byte = static_cast<unsigned char> (textInt >> 8 * (3 - j));
                cipherText += byte.to_string();//Добавляем в зашифрованный текст байт
            }
        }
        cout << "cipherText is >> " << cipherText << " <<" << endl;
    }else{ // РАСШИФРОВКА
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
        for (size_t i = 0; i < cipherText.length(); i += 32) {
            // делаем тоже самое, что и в режиме шифрования, а биты в строковом представлении
            // в битсет, а затем в число.
           "100010100101010010111110000"

            x1 x2 | f(x1,x2) - XOR
            0  0  | 0
            0  1  | 1
            1  0  | 1
            1  1  | 0


            01110111 // исходный символ
            10010001 // гамма функция
            --------
            11100110 // зашифрованное сообщение
            10010001
            01110111 // расшифрованное сообщение
            
            for (size_t j = 0; j < 32; j += 8) {
                textInt <<= 8;
                std::bitset<8> tempByte(cipherText.c_str() + i + j);
                textInt += tempByte.to_ulong(); // from bitset to unsigned long
            }
            cipher = std::rand() % 4294967295; //генерация шифр-ключа 
            if (direction) { // сдвиг в обратную сторону 
                textInt = (textInt >> shift) | ((textInt) << (32 - shift));
            }else{
                textInt = (textInt << shift) | ((textInt) >> (32 - shift));
            }
            textInt = cipher ^ textInt; //поразрядный XOR
				a = 97; 01100001 
                b = 98 01100010 
                c = 99 01100011
                d = 100; 01100100
            01100001 01100010 01100011 01100100  // text before

            00000000 00000000 00000000 01100001 -> 01100001 // достаём a
            00000000 00000000 01100001 01100010 -> 01100010 // достаём b
            00000000 01100001 01100010 01100011 -> 01100011 // достаём c 
            01100001 01100010 01100011 01100100 -> 01100100 // достаём d
            for (size_t j = 0; j < 4; ++j) {
                tmpChar = static_cast<unsigned char> (textInt >> 8 * (3 - j));
                plainText += tmpChar;//Добавляем в расшифрованный текст символы
            }
        }
        while (plainText[plainText.length() - 1] == '~'){  // Удаляем лишний символ
            plainText.erase(plainText.length() - 1, 1);
        }
        cout << "PlainText is: " << plainText << endl;
    }
    return 0;
}

