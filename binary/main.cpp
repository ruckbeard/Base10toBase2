#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int getRemainder(int num, int toBase);
vector<int> strToInt(string str);
int returnValAsInt(int val);
char returnValAsChar(int val);
int checkNumber(int fromBase, int num, int pos, int size);

int main()
{
	//declare variables
	unsigned int num = 0;
	unsigned int fromBase;
	unsigned int toBase;
	int check;
	char tmp;
	string tempStr;
	string result;
	vector<int> value;
	bool fromBaseCorrect = false;
	bool toBaseCorrect = false;
	bool numberCorrect = false;
	//get the base to convert from, the base to convert to, and the number to convert
	while (fromBaseCorrect == false) {
		cout << "Enter the base you want to convert from: ";
		cin >> fromBase;
		if (fromBase >= 2 && fromBase <= 16) {
			fromBaseCorrect = true;
		}
		else {
			cout << "You must enter 2-16." << endl;
		}
	}
	while (toBaseCorrect == false) {
		cout << "Enter the base you want to convert to: ";
		cin >> toBase;
		if (toBase >= 2 && toBase <= 16) {
			toBaseCorrect = true;
		}
		else {
			cout << "You must enter 2-16." << endl;
		}
	}
	int x = 0;
	cout << "Enter the number you want to convert: ";
	cin >> tempStr;
	while (numberCorrect == false) {
		check = checkNumber(fromBase, tempStr[x], x, tempStr.size());
		if (check == 1) {
			x = 0;
			cout << "Check your number, it does not match the base you chose to convert from.";
			cout << "Enter the number you want to convert: ";
			cin >> tempStr;
		}
		else if (check == 2) {
			numberCorrect = true;
		}
		x++;
	}
	for (int i = 0; i < tempStr.size(); i++) {
		vector<int> tmp = strToInt(tempStr);
		reverse(tmp.begin(), tmp.end());
		num += tmp[i] * pow(fromBase, i);
	}
	//find the remainder
	while (num > 1) {
		value.push_back(returnValAsChar(getRemainder(num, toBase)));
		num = num / toBase;
	}
	//if you are left with 1, add it to the number
	if (num == 1) {
		value.push_back(49);
	}
	//reverse vector for proper format
	reverse(value.begin(), value.end());
	//change vector<int> into string
	for (int i = 0; i < value.size(); i++) {
		tmp = value[i];
		result += tmp;
	}
	//output the string
	cout << "The number in base " << toBase << " is " << result << endl;
	return 0;
}
//check if number is odd
int getRemainder(int num, int toBase) {
	int val = num % toBase;
	return val;
}
//convert string into vector
vector<int> strToInt(string str) {
	char tmp;
	vector<int> val;
	for (int i = 0; i < str.size(); i++) {
		tmp = str[i];
		val.push_back(returnValAsInt(tmp));
	}
	return val;
}
//return char val as int
int returnValAsInt(int tmp) {
	int val = 0;
	if (tmp == 48)
		val = 0;
	else if (tmp == 49)
		val = 1;
	else if (tmp == 50)
		val = 2;
	else if (tmp == 51)
		val = 3;
	else if (tmp == 52)
		val = 4;
	else if (tmp == 53)
		val = 5;
	else if (tmp == 54)
		val = 6;
	else if (tmp == 55)
		val = 7;
	else if (tmp == 56)
		val = 8;
	else if (tmp == 57)
		val = 9;
	else if (tmp == 65)
		val = 10;
	else if (tmp == 66)
		val = 11;
	else if (tmp == 67)
		val = 12;
	else if (tmp == 68)
		val = 13;
	else if (tmp == 69)
		val = 14;
	else if (tmp == 70)
		val = 15;
	return val;
}
//return int val as char
char returnValAsChar(int tmp) {
	char val = 0;
	if (tmp == 0)
		val = 48;
	else if (tmp == 1)
		val = 49;
	else if (tmp == 2)
		val = 50;
	else if (tmp == 3)
		val = 51;
	else if (tmp == 4)
		val = 52;
	else if (tmp == 5)
		val = 53;
	else if (tmp == 6)
		val = 54;
	else if (tmp == 7)
		val = 55;
	else if (tmp == 8)
		val = 56;
	else if (tmp == 9)
		val = 57;
	else if (tmp == 10)
		val = 65;
	else if (tmp == 11)
		val = 66;
	else if (tmp == 12)
		val = 67;
	else if (tmp == 13)
		val = 68;
	else if (tmp == 14)
		val = 69;
	else if (tmp == 15)
		val = 70;
	return val;
}

int checkNumber(int fromBase, int num, int pos, int size) {
	num = returnValAsInt(num);
	if (num >= 0 && num < fromBase && pos != size){
		return 0;
	}
	else if (num >= 0 && num < fromBase && pos == size) {
		return 2;
	}
	else {
		return 1;
	}
		
}