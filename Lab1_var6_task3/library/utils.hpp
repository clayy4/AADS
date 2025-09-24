#ifndef UTILS_H
#define UTILS_H

#include <random>

template <typename T>
class Dice {
private:
    std::mt19937 rand_gen;                     ///< Генератор случайных чисел
    std::uniform_int_distribution<T> dis;    ///< Распределение для генерации чисел

public:

    Dice() = default;

    Dice(const T min, const T max) : rand_gen(std::random_device{}()), dis(min, max) {}

    T roll() {
        return static_cast<T>(dis(rand_gen));
    }
};

#endif // UTILS_H