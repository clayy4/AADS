#include "utils.hpp"

template <typename T>
T Dice<T>::roll() {
	return dis(rand_gen);
}