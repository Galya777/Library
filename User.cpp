#include "User.h"

void User::readFromFile(std::ifstream& file) const
{
	file.read((char*)username.c_str(), sizeof(username));
	file.read((char*)password.c_str(), sizeof(password));
	
}

void User::writeToFile(std::fstream& file) const
{
	file << username << " " << password;
}

void User::printUser()
{
	std::cout << username << " " << password;
}

void User::init(std::string username, std::string password)
{
	setUsername(username);
	setPassword(password);
}



User::User(std::string username, std::string password)
{
	init(username, password);
}

User::User()
{
	init("", "");
}



void User::setUsername(std::string username)
{
	this->username =  username;
}

void User::setPassword(std::string password)
{
	this->password = password;
}

void User::setAdmin(bool a)
{
	admin = a;
}

void User::setDate(std::string enrollingDate)
{
	this->enrollingDate = Date(enrollingDate);
}

void User::setLastDate(std::string lastSeenDate)
{
	this->lastSeenDate = Date(lastSeenDate);
}

std::string User::getUsername() const
{
	return username;
}

std::string User::getPassword() const
{
	return password;
}

bool User::getAdmin() const
{
	return admin;
}

std::string User::getEnrollingDate() const
{
	return enrollingDate.createString();
}

std::string User::getLastSeenDate() const
{
	return lastSeenDate.createString();
}

void User::Loggout()
{
	std::cout << "Successfully logged out of " << username << ".\n";
	init("", "");
	admin = false;
}



std::ostream& operator<<(std::ostream& out, const User& other)
{
	out << other.username << " " << other.password;
	return out;
	
}
