#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

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
	//if the number does not equal 1, check if it is an odd number, if it is, add a 1 to vector and subtract 1 from the number
	//if it is even, add a 0, then divide by 2 until the number equals 1.
	while (num != 1) {
		if (isOdd(num) == true) {
			value.push_back(49);
			num--;
		}
		else {
			value.push_back(48);
		}
		num = num / 2;
	}
	//add last digit to the number
	value.push_back(49);
	//change vector<int> into string
	for (int i = 0; i < value.size(); i++) {
		tmp = value[i];
		binary += tmp;
	}
	//output the string in reverse to display it correctly
	std::cout << "The number in base 2 is ";
	for (std::string::reverse_iterator rit = binary.rbegin(); rit != binary.rend(); ++rit)
		std::cout << *rit;
	std::cout << "\n";
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