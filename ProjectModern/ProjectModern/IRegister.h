#pragma once
class IRegister
{
public:

	virtual ~IRegister() = default;

	virtual void SetName(const std::string& name) = 0;

	virtual void SetUsername(const std::string& username) = 0;

	virtual void SetPassword(const std::string& password) = 0;

	virtual void SetDateOfBirth(const std::string& dateOfBirth) = 0;

	virtual void SetCountry(const std::string& country) = 0;

	virtual std::string GetName() const = 0;

	virtual std::string GetUsername() const = 0;

	virtual std::string GetPassword() const = 0;

	virtual std::string GetDateOfBirth() const = 0;

	virtual std::string GetCountry() const = 0;

	virtual void CreateUser() = 0;

};

