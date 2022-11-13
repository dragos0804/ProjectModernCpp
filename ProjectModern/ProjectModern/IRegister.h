#pragma once
class IRegister
{
public:

	virtual ~IRegister() = default;

	virtual void SetName(const std::string& name) = 0;

	virtual void SetUsername(const std::string& username) = 0;

	virtual void SetPassword(std::string password) = 0;

	virtual void SetDateOfBirth(std::string dateOfBirth) = 0;

	virtual void SetCountry(std::string country) = 0;

	virtual std::string GetName() = 0;

	virtual std::string GetUsername() = 0;

	virtual std::string GetPassword() = 0;

	virtual std::string GetDateOfBirth() = 0;

	virtual std::string GetCountry() = 0;

	virtual void CreateUser() = 0;

};

