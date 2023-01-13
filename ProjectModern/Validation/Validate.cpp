#define _CRT_SECURE_NO_WARNINGS
#include "Validate.h"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <regex>

bool Validate::IsBlankField(const std::string& from)
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


bool Validate::ContainsOnlyWhiteSpaces(const std::string& from)
{
	for (std::string::const_iterator it = from.begin(); it != from.end(); ++it)
	{
		if (*it != ' ') 
			return false;
	}

	std::time_t crtTime = std::time(nullptr);
	std::cerr << "\t\tError ";
	std::cerr << '[' << std::put_time(std::localtime(&crtTime), "%Y-%m-%d %H:%M:%S") << ']';
	std::cerr << " This field can't be blank!";
	std::cout << "\n\n";

	return true;
}

bool Validate::ContainsNumbers(const std::string& from)
{
	const std::regex pattern("^[^0-9]+$");
	if (std::regex_match(from, pattern))
		return true;

	std::time_t crtTime = std::time(nullptr);
	std::cerr << "\t\tError ";
	std::cerr << '[' << std::put_time(std::localtime(&crtTime), "%Y-%m-%d %H:%M:%S") << ']';
	std::cerr << " Your name can't contain any numbers!";
	std::cout << "\n\n";
	return false;
}
