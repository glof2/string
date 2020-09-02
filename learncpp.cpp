#include <iostream>
#include "string.hpp"

int main()
{
	String string{"Hi!\n"};
	std::cout << string;
	string = "Very nice!\n";
	std::cout << string;
	std::cout << string.length() << '\n';
	std::cout << string.capacity_length() << '\n';
}