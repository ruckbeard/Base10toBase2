ConvertBaseNumber
=============

This program converts a number to any base from 2 to 16 bit. Input the base you want to convert from, then input the base you want to convert to, then enter the number. The program works by converting everything to base 10, then using the remainder method of conversion for both upward and downward conversions. If the initial base is not base 10, it takes the number input by the user as a string, converts the string into a vector, then reverses the vector. It then converts it into a base 10 number format. It then obtains the remainder, dividing the number by the base until it reaches 1 or 0, adding the remainder to the vector in character code. The vector is then reversed and converted back into a string for proper display back to the user.
