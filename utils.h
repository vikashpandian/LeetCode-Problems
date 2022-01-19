#pragma once
#include <vector>
#include <iostream>

template <class T>
void print2dMatrix(std::vector<std::vector<T>>& mx) {
	std::cout << "\n";
	for (auto& i : mx) {
		for (auto& j : i) std::cout << j << "\t";
		std::cout << "\n";
	}
	std::cout << "\n\n";
}
