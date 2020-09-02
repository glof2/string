#include <iostream>
#include "string.h"

int main()
{
	String string{"Hi!\n"};
	std::cout << "String capacity: " << string.capacity_length() << '\n';
	std::cout << string;
}