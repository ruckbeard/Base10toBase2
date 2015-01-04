/* remainder example */
#include <stdio.h>      /* printf */
#include <math.h>       /* remainder */
#include <iostream>
#include <vector>
#include <string>

bool isOdd(int rem);

int main()
{
	int num;
	char tmp;
	std::string binary;
	std::vector<int> value;

	std::cout << "Enter a whole number: ";
	std::cin >> num;
	std::cout << "The number is in base 10 is " << num << "\n";

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
	
	value.push_back(49);

	for (int i = 0; i < value.size(); i++) {

		tmp = value[i];

		binary += tmp;
	}

	std::cout << "The number in base 2 is ";

	for (std::string::reverse_iterator rit = binary.rbegin(); rit != binary.rend(); ++rit)
		std::cout << *rit;

	std::cout << "\n";
	
	std::cin;
	return 0;
}

bool isOdd(int rem) {
	if (rem % 2 == 0) {
		return false;
	}
	else {
		return true;
	}
}