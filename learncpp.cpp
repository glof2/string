#include <iostream>
#include "string.h"

int main()
{
	String string{"Hi!\n"};
	std::cout << "String length: " << string.length() << '\n';
	std::cout << "String capacity: " << string.capacity_length() << '\n';
	String str{"No"};
	string = str;
	std::cout << "String length: " << string.length() << '\n';
	std::cout << "String capacity: " << string.capacity_length() << '\n';
}