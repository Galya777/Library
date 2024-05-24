#pragma once
#include "LibraryItem.h"
#include "User.h"
/**
 * @brief
 * This class represents an admin, chield of a user.
 *
 * ���� ���� ������������ �������������, ��������� �� user.
*/
class Admin: public User
{
public:
	//!= Constructors (������������)
	Admin(std::string username, std::string password);
	Admin();

	//!= Setters
	void setEmail(std::string email);
	void setDepartment(std::string department);

	//!= Getters
	std::string getEmail() const;
	std::string getDepartment() const;
private:
	std::string email;
	std::string depatrment;
};

