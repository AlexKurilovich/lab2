#include "task1.h"

union BinF {
    int i;
    float number;
};
BinF binf;

union BinD {
    uint64_t int_form;
    double number;
};
BinD bind;

bool problem() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("cls");
        return 0;
    }
    else return 1;
}


void PrintBinInt(int num) { // Задание 2,3
    cout << "Результат: ";
    uint32_t mask = 1 << sizeof(int) * 8 - 1;
    for (int i = 0; i < sizeof(int) * 8; i++) {
        if (num & mask) {
            cout << 1;
        }
        else {
            cout << 0;
        }
        if (i == 0 || i == 7) cout << " ";
        if (i > 7) {
            if ((i - 7) % 8 == 0) cout << " ";
        }

        mask >>= 1;
    }
    cout << "\n           ^ Sign";
    cout << endl << endl;
}

void PrintBinFloat(float num) { // Задание 2,3
    binf.number = num;
    cout << "Результат: ";
    uint32_t mask = 1 << sizeof(int) * 8 - 1;
    for (int i = 0; i < sizeof(int) * 8; i++) {
        if (binf.i & mask) {
            cout << 1;
        }
        else {
            cout << 0;
        }
        if (i == 0 || i == 8) cout << " ";
        if (i > 8) {
            if ((i - 8) % 8 == 0) cout << " ";
        }
        mask >>= 1;
    }
    cout << endl << setw(13) << "(S)" << "(---E--)" << " " << "(" << setfill('-') << setw(12) << "M" << setw(12) << ")" << setfill(' ') << endl;
    cout << endl << endl;
}

void PrintBinDouble(double num) { // задание 4
    bind.number = num;
    cout << endl << "Результат: ";
    uint64_t mask = 1ULL << 63;
    for (int i = 0; i < 64; i++) {
        cout << ((bind.int_form & mask) ? '1' : '0');
        if (i == 0 || i == 11) cout << " ";
        if (i > 11) {
            if ((i + 1) % 8 == 0) cout << " ";
        }
        mask >>= 1;
    }
    cout << endl << setw(13) << "(S)" << "(----E----) " << "(" << setfill('-') << setw(29) << "M" << setw(28) << ")" << setfill(' ') << endl;
    cout << endl << endl;
}

void ReplaceBitsDouble() {
    short pos;
    bool bitVal;
    cout << "Введите позицию бита (0-63): ";
    cin >> pos;
    cout << "Введите значение бита (0-1): ";
    cin >> bitVal;

    if (bitVal) bind.int_form |= (uint64_t(1) << pos);
    else bind.int_form &= ~(uint64_t(1) << pos);

    PrintBinDouble(bind.number);
    cout << "Новое число: " << bind.number << endl << endl;
}

void ReplaceBitsFloat() {
    short pos;
    bool bitVal;
    cout << "Введите позицию бита (0-31): ";
    cin >> pos;
    cout << "Введите значение бита (0-1): ";
    cin >> bitVal;

    if (bitVal) binf.i |= (uint32_t(1) << pos);
    else binf.i &= ~(uint32_t(1) << pos);

    PrintBinFloat(binf.number);
    cout << "Новое число: " << binf.number << endl << endl;
}

void ReplaceBitsInt(int num) {
    short pos;
    bool bitVal;
    cout << "Введите позицию бита (0-31): ";
    cin >> pos;
    cout << "Введите значение бита (0-1): ";
    cin >> bitVal;

    if (bitVal) num |= (uint32_t(1) << pos);
    else num &= ~(uint32_t(1) << pos);

    PrintBinInt(num);
    cout << "Новое число: " << num << endl << endl;
}

void ChangeSignInt(int num) {
    num = ~num + 1;
    PrintBinInt(num);
    cout << "Новое число: " << num << endl << endl;
}

void ChangeSignFloat(float num) {
    uint32_t mask = 1U << 31;
    binf.i ^= mask;
    PrintBinFloat(binf.number);
    cout << "Новое число: " << binf.number << endl << endl;
}

void ChangeSignDouble(double num) {
    uint64_t mask = 1ULL << 63;
    bind.int_form ^= mask;
    PrintBinDouble(bind.number);
    cout << "Новое число: " << bind.number << endl << endl;
}

int MenuForReplace() {
    short select = 0;
    while (true) {
        cout << "1. Изменить один бит\n"
            << "2. Изменить знак\n"
            << "3." << "\x1b[32m" << " Готово" << "\x1b[0m\n\n"
            << "Выберите действие: ";
        cin >> select;
        if (problem() == 0) continue;
        return select;
    }
}

void task1() {
    short select = 0;
    int num_int = 0;
    double num_double = 0;
    float num_float = 0;
    while (true) {
        cout << "1 - Типы данных\n"
            << "2 - Двоичное представление int\n"
            << "3 - Двоичное представление float\n"
            << "4 - Двоичое представление double\n"
            << "5 - Завершить работу\n"
            << "Выберите операцию: ";
        cin >> select;
        if (problem() == 0) continue;
        switch (select) {
        case 1:
            system("cls"); // задание 1
            cout << "int: " << sizeof(int) << " байт\n\n"
                << "short int: " << sizeof(short int) << " байт\n\n"
                << "long int: " << sizeof(long int) << " байт\n\n"
                << "float: " << sizeof(float) << " байт\n\n"
                << "double: " << sizeof(double) << " байт\n\n"
                << "long double: " << sizeof(long double) << " байт\n\n"
                << "char: " << sizeof(char) << " байт\n\n"
                << "bool: " << sizeof(bool) << " байт\n\n";
            break;
        case 2:
        {
            system("cls");
            cout << "Введите целое число: ";
            cin >> num_int;
            if (problem() == 0) continue;
            PrintBinInt(num_int);
            int menu = MenuForReplace();
            if (menu == 1) {
                ReplaceBitsInt(num_int);
            }
            else if (menu == 2) {
                ChangeSignInt(num_int);
            }

            break;
        }
        case 3:
        {
            system("cls");
            cout << "Введите число: ";
            cin >> num_float;
            if (problem() == 0) continue;
            PrintBinFloat(num_float);
            int menu = MenuForReplace();
            if (menu == 1) {
                ReplaceBitsFloat();
            }
            else if (menu == 2) {
                ChangeSignFloat(num_float);
            }

            break;
        }
        case 4: {
            system("cls");
            cout << "Введите число: ";
            cin >> num_double;
            if (problem() == 0) continue;
            PrintBinDouble(num_double);
            int menu = MenuForReplace();
            if (menu == 1) {
                ReplaceBitsDouble();
            }
            else if (menu == 2) {
                ChangeSignDouble(num_double);
            }

            break;
        }
        case 5:
            system("cls");
            return;
        default:
            system("cls");
            break;
        }
    }
}