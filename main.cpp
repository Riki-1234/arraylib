#include <iostream>
#include "array.h"
#include <algorithm>

int main() {
	array<int, 10> nums{0};
	nums[1] = 10;

	for (iterator<int> iterator = nums.begin(); iterator != nums.end(); iterator++) {
		std::cout << *iterator << " ";
	}
	std::cout << std::endl;

	nums.erase(nums.begin() + 1);

	for (iterator<int> iterator = nums.begin(); iterator != nums.end(); iterator++) {
		std::cout << *iterator << " ";
	}
	std::cout << std::endl;
}
