#pragma once
#include <iostream>
#include <fstream>
#include "Date.h"
/**
 * @brief 
 * This class represents the user. It has username, password, date of registration and date of last enterance.
 * 
 * ���� ���� ������������ �����������. ��� ������������� ���, ������, ���� �� ����������� � ���� �� �������� �������.
*/
class User
{
public:
	//!= Constructors (������������)
	User(std::string username, std::string password);
	User();
	
	//!= Setters
	void setUsername(std::string username);
	void setPassword(std::string password);
	void setAdmin(bool a);
	void setDate(std::string enrollingDate);
	void setLastDate(std::string lastSeenDate);

	//!= Getters
	std::string getUsername() const;
	std::string getPassword() const;
	bool getAdmin() const;
	std::string getEnrollingDate() const;
	std::string getLastSeenDate() const;
	
	///user is logging out (����������� ������ �� ���������)
	void Loggout();
	

	///redefining operator <<
	friend std::ostream& operator<<(std::ostream& out, const User& other);
	///reading form file
     void readFromFile(std::ifstream& file) const;
    ///writing to file
	 void writeToFile(std::fstream& file) const;

	 void printUser();
	
protected:
	///helper function for easy initialization 
	///������� ������� �� �������������� �� ������� 
	void init(std::string username, std::string password);
	
	std::string username;
	std::string password;
	bool admin;
	
	Date enrollingDate;
	Date lastSeenDate;
};

