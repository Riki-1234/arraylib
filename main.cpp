#include <iostream>
#include "vector.h"
#include <algorithm>

int main() {
	vector<int, 10> nums{0};
	nums[1] = 10;

	for (iterator<int> iterator = nums.begin(); iterator != nums.end(); iterator++) {
		std::cout << *iterator << " ";
	}
	std::cout << std::endl;

	nums.erase(nums.begin() + 1);

	for (auto iterator = nums.begin(); iterator != nums.end(); iterator++) {
		std::cout << *iterator << " ";
	}
	std::cout << std::endl;

	nums.pop_back();

	for (auto iterator = nums.begin(); iterator != nums.end(); iterator++) {
		std::cout << *iterator << " ";
	}
	std::cout << std::endl;

	std::cout << nums.front() << " " << nums.back();
}
