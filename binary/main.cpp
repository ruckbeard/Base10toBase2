#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool isOdd(int rem);

int main()
{
	//declare variables
	int num;
	char tmp;
	std::string binary;
	std::vector<int> value;
	//get a whole number from user to conver into base 2
	std::cout << "Enter a whole number: ";
	std::cin >> num;
	std::cout << "The number is in base 10 is " << num << "\n";
	//right shift num until it equals 1 and check if even or odd, add binary digit accordingly to vector
	while (num != 1) {
		if (isOdd(num) == true) {
			value.push_back(49);
		} else {
			value.push_back(48);
		}
		num = num >> 1;
	}
	//add last digit to the number, always is 1
	value.push_back(49);
	//reverse vector
	std::reverse(value.begin(), value.end());
	//change vector<int> into string
	for (int i = 0; i < value.size(); i++) {
		tmp = value[i];
		binary += tmp;
	}
	//output the string
	std::cout << "The number in base 2 is " << binary << std::endl;
	return 0;
}
//check if number is odd
bool isOdd(int rem) {
	if (rem % 2 == 0) {
		return false;
	}
	else {
		return true;
	}
}