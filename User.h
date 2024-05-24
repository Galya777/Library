#pragma once
#include <iostream>
#include <fstream>
#include "Date.h"
/**
 * @brief 
 * This class represents the user. It has username, password, date of registration and date of last enterance.
 * 
 * “ози клас представл€ва потребител€. »ма потребителско име, парола, дата на регистраци€ и дата на последно влизане.
*/
class User
{
public:
	//!= Constructors (конструктури)
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
	
	///user is logging out (потребител€ излиза от системата)
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
	///помощна функци€ за инициализиране на данните 
	void init(std::string username, std::string password);
	
	std::string username;
	std::string password;
	bool admin;
	
	Date enrollingDate;
	Date lastSeenDate;
};

