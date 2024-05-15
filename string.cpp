#include "string.h"
#include <cstring>
#include <cctype>
#include <memory>
#include <cstddef>


// Конструктор от const char*
String::String(const char* s) {
    // Вычисляем длину строки
    maxStringSize = std::strlen(s);
    // Если длина строки меньше или равна размеру smallString,
    // то храним строку в smallString и устанавливаем isStringShort в true
    if (maxStringSize <= sizeof(smallString) - 1) {
        isStringShort = true;
        std::strcpy(smallString, s);
    } else {
        // Иначе создаем динамически выделенный массив с достаточным
        // пространством для строки плюс один для терминатора
        // и храним строку в этом массиве
        isStringShort = false;
        lstr.stringHolder = new char[maxStringSize + 1];
        std::strcpy(lstr.stringHolder, s);
        lstr.maxStringCapacity = maxStringSize;
    }
}

// Конструктор по умолчанию для пустой строки
String::String() {
    // Инициализируем maxStringSize в 0
    maxStringSize = 0;
    // Устанавливаем isStringShort в true
    isStringShort = true;
    // Устанавливаем первый символ smallString в терминатор
    smallString[0] = '\0';
}

// Копирующий конструктор
String::String(const String& other) {
    // Копируем максимальную строковую длину
    maxStringSize = other.maxStringSize;
    // Если other - короткая строка, копируем строку данных в smallString
    if (other.isStringShort) {
        isStringShort = true;
        std::strcpy(smallString, other.smallString);
    } else {
        // Иначе создаем динамически выделенный массив с достаточным
        // пространством для строки плюс один для терминатора и копируем строку данных в него
        isStringShort = false;
        lstr.stringHolder = new char[maxStringSize + 1];
        std::strcpy(lstr.stringHolder, other.lstr.stringHolder);
        lstr.maxStringCapacity = other.lstr.maxStringCapacity;
    }
}

// Деструктор
String::~String() {
    // Если строка не является короткой строкой, удаляем динамически выделенный массив
    if (!isStringShort) {
        delete[] lstr.stringHolder;
    }
}

// Перегрузка оператора присваивания
String& String::operator=(const String& other) {
    // Если текущий объект не равен объекту, к которому совершается присваивание
    if (this != &other) {
        // Если текущая строка не является короткой строкой, удаляем динамически выделенный массив
        if (!isStringShort) {
            delete[] lstr.stringHolder;
        }
        // Копируем максимальную строковую длину
        maxStringSize = other.maxStringSize;
        // Если объект, к которому совершается присваивание, является короткой строкой, копируем строку данных в smallString
        if (other.isStringShort) {
            isStringShort = true;
            std::strcpy(smallString, other.smallString);
        } else {
            // Иначе создаем динамически выделенный массив с достаточным
            // пространством для строки плюс один для терминатора и копируем строку данных в него
            isStringShort = false;
            lstr.stringHolder = new char[maxStringSize + 1];
            std::strcpy(lstr.stringHolder, other.lstr.stringHolder);
            lstr.maxStringCapacity = other.lstr.maxStringCapacity;
        }
    }
    return *this;
}

// Перегрузка оператора присваивания от const char*
String& String::operator=(const char* s) {
    // Если строка не является короткой строкой, удаляем динамически выделенный массив
    if (!isStringShort) {
        delete[] lstr.stringHolder;
    }
    // Вычисляем длину строки
    maxStringSize = std::strlen(s);
    // Если длина строки меньше или равна размеру smallString,
    // то храним строку в smallString и устанавливаем isStringShort в true
    if (maxStringSize <= sizeof(smallString) - 1) {
        isStringShort = true;
        std::strcpy(smallString, s);
    } else {
        // Иначе создаем динамически выделенный массив с достаточным
        // пространством для строки плюс один для терминатора и храним строку в этом массиве
        isStringShort = false;
        lstr.stringHolder = new char[maxStringSize + 1];
        std::strcpy(lstr.stringHolder, s);
        lstr.maxStringCapacity = maxStringSize;
    }
    return *this;
}

// Перегрузка оператора [] для получения символа по индексу
char& String::operator[](int i) {
    // Если строка является короткой строкой, возвращаем символ на указанном индексе в smallString
    if (isStringShort) {
        return smallString[i];
    } else {
        // Иначе возвращаем символ на указанном индексе в lstr.stringHolder
        return lstr.stringHolder[i];
    }
}

// Перегрузка оператора [] для получения символа по индексу
const char& String::operator[](int i) const {
    // Если строка является короткой строкой, возвращаем символ на указанном индексе в smallString
    if (isStringShort) {
        return smallString[i];
    } else {
        // Иначе возвращаем символ на указанном индексе в lstr.stringHolder
        return lstr.stringHolder[i];
    }
}

// Перегрузка stringtolower
void String::stringtolow() {
    // Если строка является короткой строкой, проходимся по каждому символу в smallString
    // и кастаем его в нижний регистр с помощью std::tolower
    if (isStringShort) {
        for (size_t i = 0; i < maxStringSize; i++) {
            smallString[i] = std::tolower(smallString[i]);
        }
    } else {
        // Иначе проходимся по каждому символу в lstr.stringHolder
        // и кастаем его в нижний регистр с помощью std::tolower
        for (size_t i = 0; i < maxStringSize; i++) {
            lstr.stringHolder[i] = std::tolower(lstr.stringHolder[i]);
        }
    }
}

// Перегрузка функции stringtoupper
void String::stringtoup() {
    // Если строка является короткой строкой, проходимся по каждому символу в smallString
    // и кастаем его в верхний регистр с помощью std::toupper
    if (isStringShort) {
        for (size_t i = 0; i < maxStringSize; i++) {
            smallString[i] = std::toupper(smallString[i]);
        }
    } else {
        // Иначе проходимся по каждому символу в lstr.stringHolder
        // и кастаем его в верхний регистр с помощью std::toupper
        for (size_t i = 0; i < maxStringSize; i++) {
            lstr.stringHolder[i] = std::toupper(lstr.stringHolder[i]);
        }
    }
}

// Перегрузка оператора <
bool operator<(const String& st, const String& st2) {
    // Если обе строки являются короткими строками, сравниваем данные в smallString
    if (st.isStringShort && st2.isStringShort) {
        return std::strcmp(st.smallString, st2.smallString) < 0;
    } else if (!st.isStringShort && !st2.isStringShort) {
        // Если обе строки не являются короткими строками, сравниваем данные в lstr.stringHolder
        return std::strcmp(st.lstr.stringHolder, st2.lstr.stringHolder) < 0;
    } else if (st.isStringShort && !st2.isStringShort) {
        // Если st является короткой строкой и st2 не является, сравниваем данные в smallString
        // с данными в lstr.stringHolder st2
        return std::strcmp(st.smallString, st2.lstr.stringHolder) < 0;
    } else {
        // Если st не является короткой строкой и st2 является, сравниваем данные в lstr.stringHolder st
        // с данными в smallString st2
        return std::strcmp(st.lstr.stringHolder, st2.smallString) < 0;
    }
}

// Перегрузка оператора >
bool operator>(const String& st1, const String& st2) {
    // Если обе строки являются короткими строками, сравниваем данные в smallString
    if (st1.isStringShort && st2.isStringShort) {
        return std::strcmp(st1.smallString, st2.smallString) > 0;
    } else if (!st1.isStringShort && !st2.isStringShort) {
        // Если обе строки не являются короткими строками, сравниваем данные в lstr.stringHolder
        return std::strcmp(st1.lstr.stringHolder, st2.lstr.stringHolder) > 0;
    } else if (st1.isStringShort && !st2.isStringShort) {
        // Если st1 является короткой строкой и st2 не является, сравниваем данные в smallString
        // с данными в lstr.stringHolder st2
        return std::strcmp(st1.smallString, st2.lstr.stringHolder) > 0;
    } else {
        // Если st1 не является короткой строкой и st2 является, сравниваем данные в lstr.stringHolder st1
        // с данными в smallString st2
        return std::strcmp(st1.lstr.stringHolder, st2.smallString) > 0;
    }
}

/**
 * @brief Перегрузка оператора ==
 * @param st первый string
 * @param st2 второй string
 * @return true если строки равны, false иначе
 */
bool operator==(const String& st, const String& st2) {
    /**
     * @brief Сравнивает два string, чтобы проверить равны ли они
     * @param st первый string
     * @param st2 второй string
     * @return true если строки равны, false иначе
     */
    bool st1IsShort = st.isStringShort;
    bool st2IsShort = st2.isStringShort;
    if (st1IsShort && st2IsShort) {
        // Если обе строки являются короткими строками, сравниваем данные в smallString
        return std::strcmp(st.smallString, st2.smallString) == 0;
    } else if (!st1IsShort && !st2IsShort) {
        // Если обе строки не являются короткими строками, сравниваем данные в lstr.stringHolder
        return std::strcmp(st.lstr.stringHolder, st2.lstr.stringHolder) == 0;
    } else if (st1IsShort) {
        // Если st является короткой строкой и st2 не является, сравниваем данные в smallString
        // с данными в lstr.stringHolder st2
        return std::strcmp(st.smallString, st2.lstr.stringHolder) == 0;
    } else {
        // Если st не является короткой строкой и st2 является, сравниваем данные в lstr.stringHolder
        // st с данными в smallString st2
        return std::strcmp(st.lstr.stringHolder, st2.smallString) == 0;
    }

}

/**
 * @brief Перегрузка оператора <<
 * @param os выводящий поток
 * @param st строка, которую нужно вывести
 * @return выводящий поток
 */
ostream& operator<<(ostream& os, const String& st) {
    /**
     * Выводит строку. Если строка короткая, выводит ее smallString, иначе выводит lstr.stringHolder
     */
    if (st.isStringShort) {
        os << st.smallString;
    } else {
        os << st.lstr.stringHolder;
    }
    return os;
}

/**
 * @brief Перегрузка оператора >
 * @param is вводящий поток
 * @param st строка, которую нужно прочитать
 * @return вводящий поток
 */
istream& operator>>(istream& is, String& st) {
    /**
     * Читает строку. Читает максимум String::MAX символов из вводящего потока.
     * Если вводящий поток валиден, копирует прочитанные символы в строку
     * После ввода skip'ит остаток строки
     */
    char temp[sizeof(String::lstr)];
    is.get(temp, sizeof(String::lstr));
    if (is) {
        st = temp;
    }
    while (is && is.get() != '\n') {
        continue;
    }
    return is;
}

/**
 * @brief Перегрузка оператора +
 * @param st1 первая строка
 * @param st2 вторая строка
 * @return новая строка, которая является конкатенацией st1 и st2
 */
String operator+(const String& st1, const String& st2) {
    /**
     * Конкатенирует две строки. Если сумма размеров строк меньше или равна String::MAX,
     * хранит результат в smallString. иначе выделяет память для результата и хранит в lstr.stringHolder
     */
    String temp;
    temp.maxStringSize = st1.maxStringSize + st2.maxStringSize;
    if (temp.maxStringSize <= sizeof(temp.smallString) - 1) {
        temp.isStringShort = true;
        std::strcpy(temp.smallString, st1.isStringShort ? st1.smallString : st1.lstr.stringHolder);
        std::strcat(temp.smallString, st2.isStringShort ? st2.smallString : st2.lstr.stringHolder);
    } else {
        temp.isStringShort = false;
        std::cout << "String holder changed" << std::endl;
        temp.lstr.stringHolder = new char[temp.maxStringSize + 1];
        std::strcpy(temp.lstr.stringHolder, st1.isStringShort ? st1.smallString : st1.lstr.stringHolder);
        std::strcat(temp.lstr.stringHolder, st2.isStringShort ? st2.smallString : st2.lstr.stringHolder);
        temp.lstr.maxStringCapacity = temp.maxStringSize;
    }
    return temp;
}


