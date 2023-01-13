#define _CRT_SECURE_NO_WARNINGS
#include "Validate.h"
#include <ctime>
#include <iomanip>
#include <iostream>

bool Validate::IsBlankField(std::string from)
{
	if (from.size() == 0)
	{
		std::time_t crtTime = std::time(nullptr);
		std::cerr << "\t\tError ";
		std::cerr << '[' << std::put_time(std::localtime(&crtTime), "%Y-%m-%d %H:%M:%S") << ']';
		std::cerr << " This field can't be blank!";
		std::cout << "\n\n";
		return true;
	}
	return false;
}
