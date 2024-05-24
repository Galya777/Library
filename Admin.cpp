#include "Admin.h"

Admin::Admin(std::string username, std::string password)
{
	setUsername(username);
	setPassword(password);
	admin = true;
	setEmail("");
	setDepartment("");
}

Admin::Admin()
{
	setUsername("");
	setPassword("");
	admin = true;
	setEmail("");
	setDepartment("");
}

void Admin::setEmail(std::string email)
{
	this->email = email;
}

void Admin::setDepartment(std::string department)
{
	this->depatrment = department;
}

std::string Admin::getEmail() const
{
	return email;
}

std::string Admin::getDepartment() const
{
	return depatrment;
}
