#include <iostream>
#include <clocale>
#include <conio.h>

// Прототип функции
void firstInstruction(char& symbol, int& number1, int& number2);
void mathChocice(char& symbol, int number1, int number2);

int main() {
    setlocale(LC_ALL, "");

    char choice;
    char symbol;
    int number1;
    int number2;

    std::wcout << L"Добро пожаловать в калькулятор!" << std::endl;

    do {
        std::wcout << L"Если вы хотите начать или продолжить, введите 'y', в ином случае 'n': ";
        std::cin >> choice;

        if (choice == 'y') {
            std::wcout << L"Отлично, программа успешно запущена" << std::endl;
            firstInstruction(symbol, number1, number2);
            mathChocice(symbol, number1, number2);
        }
        else if (choice == 'n') {
            std::wcout << L"Программа завершает свою работу..." << std::endl;
            break;
        }
        else {
            std::wcout << L"Введен неправильный символ" << std::endl;
            continue;
        }

        if (_kbhit()) {
            int ch = _getch();
            if (ch == 27) break;
            std::wcout << L"Код: " << ch << std::endl;
        }

       

    } while (choice == 'y');

    return 0;
}

// Определение функции вне main()
void firstInstruction(char& symbol, int& number1, int& number2) {
    std::wcout << L"Какую операцию вы хотите выбрать?" << std::endl;
    std::wcout << L"+, -, /, *" << std::endl;
    std::cin >> symbol;
    std::wcout << L"Отлично, теперь давайте введем числа" << std::endl;
    std::wcout << L"Введите первое число: " << std::endl;
    std::cin >> number1;
    std::wcout << L"Введите второе число: " << std::endl;
    std::cin >> number2;
}

void mathChocice(char& symbol, int number1, int number2){
    if (symbol == '+') {
        std::cout << number1 << "+" << number2 << "=" << (number1 + number2) << std::endl;
    }
    else if (symbol == '-') {
        std::cout << number1 << "-" << number2 << "=" << (number1 - number2) << std::endl;
    }
    else if (symbol == '/') {
        if (number2 != 0)
            std::cout << number1 << "/" << number2 << "=" << (number1 / number2) << std::endl;
        else
            std::cout << "Ошибка: деление на ноль" << std::endl;
    }
    else if (symbol == '*') {
        std::cout << number1 << "*" << number2 << "=" << (number1 * number2) << std::endl;
    }
    else{
        std::wcout << L"Введен неправильный символ" << std::endl;
    }
}