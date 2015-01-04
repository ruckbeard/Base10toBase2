#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool isOdd(int rem);
std::vector<int> strToInt(std::string str);

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
	//convert a base 2 number into base 10
	std::cout << "Enter a binary number: ";
	std::cin >> binary;
	std::cout << "The number in base 2 is " << binary << std::endl;
	
	value = strToInt(binary);

	std::reverse(value.begin(), value.end());

	num = 0;
	for (int i = 0; i < value.size(); i++) {
		if (value.at(i) == 1) {
			num += pow(2, i);
		}
	}

	std::cout << "The number in base 10 is " << num << std::endl;
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
//convert string into vector
std::vector<int> strToInt(std::string str) {
	char tmp;
	std::vector<int> val;
	for (int i = 0; i < str.size(); i++) {
		tmp = str[i];
		if (tmp == 49)
			val.push_back(1);
		else
			val.push_back(0);
	}
	return val;
}