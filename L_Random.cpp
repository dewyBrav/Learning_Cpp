#include <iostream>
#include "L_Random.h"
#include <cstdlib> // для функций rand() и srand()
#include <ctime> // для функции time()
#include <random> // для std::random_device и std::mt19937  (Вихря Мерсенна)

unsigned int L_Random::PRNG()
	{
        // Наше стартовое число - 4 541
        static unsigned int seed = 4541;

        // Берём стартовое число и, с его помощью, генерируем новое значение
        // Из-за использования очень больших чисел (и переполнения) угадать следующее число исходя из предыдущего - очень сложно
        seed = (8253729 * seed + 2396403);

        // Берём стартовое число и возвращаем значение в диапазоне от 0 до 32 767
        return seed % 32768;
	}
void L_Random::R_Print()
{
    srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа

    for (int count = 0; count < 10; ++count)
    {
        std::cout << rand() << "\t";

        // Если вывели 5 чисел, то вставляем символ новой строки
        if ((count + 1) % 5 == 0)
            std::cout << "\n";
    }
}
void L_Random::Mersen()
{
    std::random_device rd;
    std::mt19937 mersenne(rd()); // инициализируем Вихрь Мерсенна случайным стартовым числом 

// Примечание: Из-за одного бага в компиляторе Code::Blocks (если вы используете Code::Blocks в Windows) - удалите две строчки кода выше и раскомментируйте следующую строчку:
// std::mt19937 mersenne(static_cast<unsigned int>(time(0))); // инициализируем Вихрь Мерсенна случайным стартовым числом

    // Выводим несколько случайных чисел
    for (int count = 0; count < 10; ++count)
    {
        std::cout << mersenne() << "\t";

        // Если вывели 5 чисел, то вставляем символ новой строки
        if ((count + 1) % 5 == 0)
            std::cout << "\n";
    }
}