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
	static bool IsBlankField(std::string from);
private:
};