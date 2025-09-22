#ifndef GRAYSCALE_HPP
#define GRAYSCALE_HPP

#include <limits>
#include "utils.hpp"


template <typename T>
class GrScImage { //GrayScaleImage
private:
	int _rows;
	int _cols;
	T* _matrix;
public:
	GrScImage(const int rows, const int cols, const bool is_fill) : _rows(rows), _cols(cols) {
		_matrix = new T[_rows * _cols];

		Dice<T> dice(std::numeric_limits<T>::min(), std::numeric_limits<T>::max());

		if(is_fill){
			for (int r = 0; r < _rows; r++) {
				for (int c = 0; c < _cols; c++) {
					_matrix[r * c + c] = dice.roll();
				}
			}
		}
		else {
			for (int r = 0; r < _rows; r++) {
				for (int c = 0; c < _cols; c++) {
					_matrix[r * c + c] = 0;
				}
			}
		}
	}
	T& operator()(int row, int col);

	//operator+
	//operator*
	//operator-
};

#endif