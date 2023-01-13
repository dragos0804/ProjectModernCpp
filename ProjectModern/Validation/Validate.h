#pragma once
#include <ostream>
#include <string>
#ifdef VALIDATION_EXPORT
#define VALIDATION_API _declspec(dllexport)
#else 
#define VALIDATION_API _declspec(dllimport)
#endif

class VALIDATION_API Validate
{
public:
	static bool IsBlankField(const std::string& from);
	static bool ContainsOnlyWhiteSpaces(const std::string& from);
	static bool ContainsNumbers(const std::string& from);

private:
};