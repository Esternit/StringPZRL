#ifndef STRING1_H_
#define STRING1_H_
#include <iostream>
#include <cstddef>
#include <memory>
#include <array>
using std::ostream;
using std::istream;

class String
{
    private:
    /**
     * @brief длина строки в байтах
     */
    size_t maxStringSize;
    /**
     * @brief максимальная длина строки в байтах
     *         если длина строки больше чем это значение
     *         строка хранится в куче
     */
    // static const int MAX = 80;
    /**
     * @brief объединение двух вариантов
     *         маленькая строка хранится в стеке
     *         большая строка хранится в куче
     */
    union {
        /**
         * @brief если строка маленькая, то хранит ее в стеке
         *         иначе хранит в куче
         */
        struct {
            /**
             * @brief указатель на строку
             */
            char *stringHolder;
            /**
             * @brief максимальная вместимость строки в байтах
             */
            size_t maxStringCapacity;
        } lstr;
        /**
         * @brief маленькая строка хранится в стеке
         *         длина строки меньше или равна MAX
         */
        char smallString[sizeof(lstr)];
    };
    
    public:
        
        bool isStringShort;

        String(const char * s);
        String();
        String(const String &);
        ~String();
        size_t length() const { return maxStringSize; }

        String & operator=(const String &);
        String & operator=(const char *);
        char & operator[](int i);
        const char & operator[](int i) const;
        void stringtolow();
        void stringtoup();

        friend bool operator<(const String &st, const String &st2);
        friend bool operator>(const String &st1, const String &st2);
        friend bool operator==(const String &st, const String &st2);
        friend ostream & operator<<(ostream & os, const String &st2);
        friend istream & operator>>(istream & is, String & st);
        friend String operator+(const String& st1, const String& st2);

};
#endif