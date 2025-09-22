#include "grayscale.hpp"

T& GrScImage::operator()(int row, int col) {
	return _matrix[row * _cols + col];
}