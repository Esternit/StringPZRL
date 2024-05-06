#include <cstring> // Для использования функций std::strlen и std::strcpy.
#include "string.h"
#include <cctype> // Для использования функций std::tolower и std::toupper.

using std::cin;
using std::cout;

// Количество созданных объектов класса String.
int String::num_strings = 0;

// Возвращает количество созданных объектов класса String.
int String::HowMany()
{
    return num_strings;
}

// Конструктор на основе C-строки.
String::String(const char *s)
{
    len = std::strlen(s);    // Вычисляем длину строки.
    str = new char[len + 1]; // Выделяем память под новую строку.
    std::strcpy(str, s);     // Копируем исходную строку в новую.
    num_strings++;           // Увеличиваем счетчик созданных объектов.
}

/**
 * Конструктор по умолчанию.
 *
 * Создает новый объект класса String с пустой C-строкой.
 */
String::String() : String("")
{
}

// Конструктор копирования.
String::String(const String &st)
{
    num_strings++;            // Увеличиваем счетчик созданных объектов.
    len = st.len;             // Устанавливаем длину нового объекта равной длине исходного.
    str = new char[len + 1];  // Выделяем память под новую строку.
    std::strcpy(str, st.str); // Копируем исходную строку в новую.
}

// Деструктор.
String::~String()
{
    --num_strings; // Уменьшаем счетчик созданных объектов.
    delete[] str;  // Освобоняем память, выделенную для строки.
}

// Оператор присваивания.
String &String::operator=(const String &st)
{
    if (this == &st)
        return *this;         // Если присваиваем самому себе, возвращаем себя.
    delete[] str;             // Освобоняем память, выделенную для текущей строки.
    len = st.len;             // Устанавливаем длину нового объекта равной длине исходного.
    str = new char[len + 1];  // Выделяем память под новую строку.
    std::strcpy(str, st.str); // Копируем исходную строку в новую.
    return *this;             // Возвращаем себя.
}

// Оператор присваивания на основе C-строки.
String &String::operator=(const char *s)
{
    delete[] str;            // Освобоняем память, выделенную для текущей строки.
    len = std::strlen(s);    // Вычисляем длину новой строки.
    str = new char[len + 1]; // Выделяем память под новую строку.
    std::strcpy(str, s);     // Копируем новую строку в память, выделенную для нее.
    return *this;            // Возвращаем себя.
}

// Преобразует все символы в нижний регистр.
void String::stringlow()
{
    for (int j = 0; j < len; ++j)            // Проходимся по строке символ за символом.
        str[j] = (char)std::tolower(str[j]); // Преобразуем каждый символ в нижний регистр.
}

// Преобразует все символы в верхний регистр.
void String::stringup()
{
    for (int j = 0; j < len; ++j)
        str[j] = (char)std::toupper(str[j]);
}

// Подсчитывает количество вхождений символа в строку.
int String::has(char ch) const
{
    int counter = 0;              // Счетчик вхождений символа.
    for (int j = 0; j < len; ++j) // Проходимся по строке символ за символом.
        if (str[j] == ch)         // Если символ равен заданному, увеличиваем счетчик.
            ++counter;

    return counter; // Возвращаем счетчик вхождений.
}

// Оператор доступа по индексу для изменения.
char &String::operator[](int i)
{
    return str[i];
}

// Оператор доступа по индексу для константности.
const char &String::operator[](int i) const
{
    return str[i];
}

// Оператор сравнения на меньше.
bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

// Оператор сравнения на больше.
bool operator>(const String &st1, const String &st2)
{
    return st2 < st1;
}

// Оператор сравнения на равенство.
bool operator==(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

// Оператор вставки в поток.
ostream &operator<<(ostream &os, const String &st)
{
    os << st.str; // Вставляем строку в поток.
    return os;    // Возвращаем поток.
}

// Оператор конкатенации.
String operator+(const String &st1, const String &st2)
{
    String _temp;                        // Временный объект.
    delete[] _temp.str;                  // Освобоняем память, выделенную по умолчанию.
    _temp.len = st1.len + st2.len;       // Вычисляем длину будущей строки.
    _temp.str = new char[_temp.len + 1]; // Выделяем память под новую строку.

    std::strcpy(_temp.str, st1.str);
    std::strcpy(_temp.str + st1.len, st2.str); // Сцепляем строки и сохраняем в временный объект.

    return _temp; // Возвращаем временный объект.
}

// Оператор ввода из потока.
istream &operator>>(istream &is, String &st)
{
    char temp[String::CINLIM];    // Буфер для ввода.
    is.get(temp, String::CINLIM); // Считываем строку.
    if (is)
        st = temp; // Присваиваем буффер объекту.
    while (is && is.get() != '\n')
        continue; // Считываем остаток строки.
    return is;    // Возвращаем поток.
}
