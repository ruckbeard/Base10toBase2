#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isOdd(int rem);
vector<int> strToInt(string str);

int main()
{
	//declare variables
	int num;
	char tmp;
	string binary;
	vector<int> value;
	//get a whole number from user to conver into base 2
	cout << "Enter a whole number: ";
	cin >> num;
	cout << "The number is in base 10 is " << num << "\n";
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
	reverse(value.begin(), value.end());
	//change vector<int> into string
	for (int i = 0; i < value.size(); i++) {
		tmp = value[i];
		binary += tmp;
	}
	//output the string
	cout << "The number in base 2 is " << binary << endl;
	//convert a base 2 number into base 10
	cout << "Enter a binary number: ";
	cin >> binary;
	cout << "The number in base 2 is " << binary << endl;
	//change the binary string into a vector
	value = strToInt(binary);
	//reverse the binary number to properly calculate
	reverse(value.begin(), value.end());
	//loop through the vector and check for a value of 1, then add 2 to the power of the position it was found at
	num = 0;
	for (int i = 0; i < value.size(); i++) {
		if (value.at(i) == 1) {
			num += pow(2, i);
		}
	}
	//output the final number in base 10 format
	cout << "The number in base 10 is " << num << endl;
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
vector<int> strToInt(string str) {
	char tmp;
	vector<int> val;
	for (int i = 0; i < str.size(); i++) {
		tmp = str[i];
		if (tmp == 49)
			val.push_back(1);
		else
			val.push_back(0);
	}
	return val;
}