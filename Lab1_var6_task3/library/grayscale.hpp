#ifndef GRASCALE_HPP
#define GRAYSCALE_HPP


#include <limits>
#include <iostream>
#include "utils.hpp"


template <typename T>
class GrScImage {
private:
    int _rows, _cols;
    T* _matrix;
public:
    GrScImage(const int rows, const int cols, const bool is_fill) : _rows(rows), _cols(cols) {
        _matrix = new T[_rows * _cols];
        Dice<T> dice(std::numeric_limits<T>::min()%1000, std::numeric_limits<T>::max()%1000);
        for (int r = 0; r < _rows; r++) {
            for (int c = 0; c < _cols; c++) {
                _matrix[r * _cols + c] = is_fill ? dice.roll() : 0;
            }
        }
    }

    ~GrScImage() {
        delete[] _matrix; 
    }

    T& operator()(int row, int col);

    GrScImage<T>& operator!();

    friend std::ostream& operator<<(std::ostream& os, const GrScImage<T>& img) {
        for (int r = 0; r < img._rows; r++) {
            for (int c = 0; c < img._cols; c++) {
                os << img._matrix[r * img._cols + c] << " ";
            }
            os << "\n";
        }
        return os;
    }

};


template <typename T>
T& GrScImage<T>::operator()(int row, int col) {
    return _matrix[row * _cols + col];
}


template <typename T>
GrScImage<T>& GrScImage<T>::operator!() {
    for (int i = 0; i < _rows * _cols; i++) {
        _matrix[i] = -_matrix[i];
    }
    return *this;
}

#endif // !GRASCALE_HPP