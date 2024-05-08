#include <iostream>
using namespace std;
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "string.h"

struct Fixture : public ::testing::Test
{
    virtual void SetUp()
    {
        fails = 0;
    }

    virtual void TearDown()
    {
        if (fails > 0)
        {
            std::cerr << "Fixture::TearDown sees failures" << std::endl;
        }
    }

    unsigned fails;
};

TEST_F(Fixture, creation)
{
    String s2("Billy");
    EXPECT_EQ(s2, "Billy");
    fails += ::testing::Test::HasFailure();
    cout << "constructor test passed" << endl; // при этом будет выведено на экран данное сообщение
}

TEST_F(Fixture, assignment)
{
    String s2 = "Billy";
    EXPECT_EQ(s2, "Billy");
    fails += ::testing::Test::HasFailure();
    cout << "assignment operator test passed" << endl; // при этом будет выведено на экран данное сообщение
}

TEST_F(Fixture, cassignment)
{
    String s2 = 'B';
    EXPECT_EQ(s2, "B");
    fails += ::testing::Test::HasFailure();
    cout << "const assignment operator test passed" << endl; // при этом будет выведено на экран данное сообщение
}

TEST_F(Fixture, plus)
{
    String s1("hi");
    String s2("Billy");
    String s3;
    s3 = s1 + s2;
    EXPECT_EQ(s3, "hiBilly");
    fails += ::testing::Test::HasFailure();
    cout << "operator + test passed" << endl; // при этом будет выведено на экран данное сообщение
}

TEST_F(Fixture, upper)
{
    String s2("Billy");
    s2.stringup();
    EXPECT_EQ(s2, "BILLY");
    fails += ::testing::Test::HasFailure();
    cout << "function upper test passed" << endl; // при этом будет выведено на экран данное сообщение
}

/**
 * Функция main - точка входа в программу.
 *
 * @return - возвращает 0, чтобы указать системе, что программа завершилась успешно.
 */
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
    //     String s1(" и я - студент C++.");             // Создаем объект s1 и присваиваем ему строку " и я - студент C++."
    //     String s2 = "Пожалуйста, введите ваше имя: "; // Создаем объект s2 и присваиваем ему строку "Пожалуйста, введите ваше имя: "
    //     String s3;                                    // Создаем пустой объект s3
    //     cout << s2;                                   // Выводим содержимое объекта s2 на экран
    //     cin >> s3;                                    // Читаем содержимое с клавиатуры и присваиваем его объекту s3
    //     s2 = "Мое имя " + s3;                         // Объединяем объекты s2 и s3 и присваиваем их объекту s2
    //     cout << s2 << ".\n";                          // Выводим содержимое объекта s2 на экран
    //     s2 = s2 + s1;                                 // Объединяем объекты s2 и s1 и присваиваем их объекту s2
    //     s2.stringup();                                // Преобразуем все символы объекта s2 в верхний регистр
    //     cout << "Строка\n"
    //          << s2 << "\nсодержит " << s2.has('A')
    //          << " символы 'A' в ней.\n"; // Выводим содержимое объекта s2 на экран
    //     s1 = "красный";                  // Изменяем содержимое объекта s1 на "красный"

    //     String rgb[3] = {String(s1), String("зеленый"), String("синий")}; // Создаем массив объектов типа String и инициализируем его объектами
    //     cout << "Введите имя основного цвета для смешивания света: ";     // Выводим на экран сообщение для ввода
    //     String ans;                                                       // Создаем пустой объект ans
    //     bool success = false;                                             // Создаем переменную success и присваиваем ей значение false
    //     while (cin >> ans)                                                // Читаем содержимое с клавиатуры и присваиваем его объекту ans
    //     {
    //         ans.stringlow();            // Преобразуем все символы объекта ans в нижний регистр
    //         for (int i = 0; i < 3; ++i) // Проходимся по массиву rgb
    //         {
    //             if (ans == rgb[i]) // Если объект ans равен объекту из массива rgb
    //             {
    //                 cout << "Верно!\n"; // Выводим на экран сообщение о правильном ответе
    //                 success = true;     // Устанавливаем success в значение true
    //                 break;              // Прекращаем цикл
    //             }
    //         }
    //         if (success)                     // Если success равен true
    //             break;                       // Прекращаем цикл
    //         else                             // Если success равен false
    //             cout << "Попробуйте еще!\n"; // Выводим на экран сообщение для повторения ввода
    //     }
    //     cout << "До свидания\n"; // Выводим на экран сообщение о завершении программы
    //     return 0;                // Возвращаем значение 0, чтобы указать системе, что программа завершилась успешно
}
