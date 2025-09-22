

#ifndef DICE_H
#define DICE_H

#include <random>
#include <cmath>
#include <limits>

template <typename T>
class Dice {
private:
    std::mt19937 rand_gen;                     ///< Генератор случайных чисел
    std::uniform_real_distribution<T> dis;    ///< Распределение для генерации чисел

public:

    Dice() = default;

    Dice(const T min, const T max) : rand_gen(std::random_device{}()), dis(std::numeric_limits<T>::min(), std::numeric_limits<T>::max()) {}


    T roll();
};

#endif // DICE_H