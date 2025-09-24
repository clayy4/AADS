#include <iostream>
#include "library/grayscale.hpp"
#include "library/utils.hpp"

int main() {

	GrScImage<int> halfgray(10, 5,1);
	std::cout << halfgray << "\n\n";
	!halfgray;
	std::cout << halfgray;
	return 0;
}
