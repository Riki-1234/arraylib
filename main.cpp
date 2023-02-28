#include <iostream>
#include "array.h"

int main() {
	array<int, 10> nums{0};
	for (iterator<int> iterator = nums.begin(); iterator != nums.end(); iterator++) {
		std::cout << *iterator << " ";
	}
}
