#include <iostream>
#include "Str.h"
#include <tuple>

int main()
{
	Str str1 = "Hello World";
	Str str2 = str1;
	Str str_char = 'a';
	str2 += str1;
	str2 += "Hello";
	str2 += 'q';
	std::tuple<size_t, size_t> substr = str2.find(str1);
	std::cout << str1 << " " << str1[1] << std::endl;
	std::cout << str2 << " " << str2.len() << std::endl;
	std::cout << str2.substr(0, 5) << std::endl;
	std::cout << str_char << std::endl;

	std::cin.get();
}