#ifndef GRAYSCALE_HPP
#define GRAYSCALE_HPP

#include <random>
#include <limits>



template <typename T>
class GrScImage { //GrayScaleImage
private:
	int _rows;
	int _cols;
	int* _matrix;
public:
	GrScImage(const int rows, const int cols, const bool is_fill) : _rows(rows), _cols(cols) {
		_matrix = new int* [_rows * _cols];

		if (is_fill) {
			for (int r, c = 0; i < _rows, j < _cols; i++, j++) {
				_matrix(r, c) = rand;
			}
		}
		else {
			for (int r, c = 0; i < _rows, j < _cols; i++, j++) {
				_matrix(r, c) = 0;
			}
		}
	}
	T& operator()(int row, int col);

	//operator+
	//operator*
	//operator-
};

#endif