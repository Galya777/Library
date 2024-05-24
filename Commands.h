#pragma once
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include "Book.h"
#include "User.h"
#include "LibraryItem.h"
#include "Article.h"
#include "Publishing.h"
#include "Reader.h"
#include "Admin.h"
using namespace std;
const int MAX_CONTENT = 100;
const int MAX_FILE = 100;
/*
This class represents the engine of the app and contains all commands

���� ���� ������������ "���������" �� ������������ � ������� ������ ���������� �������
*/
class Commands
{
public:
	//!= Constructors (������������)
	Commands(std::string com);
	Commands();

	///opens a file
	void open();
	///close a file 
	void close();
	///save to a file
	void save();
	///save to  new file
	void saveAs();
	///help
	void help();
	///let the user to log in (��������� �� ����������� �� ����� � ���������)
	bool Login();

	///adds a book (������ �����)
	void AddBook(std::string title, std::string author, std::string ganre, std::string description, int year, std::vector<std::string> keyWords, int rating);
	///adds a publishing (������ ������� �������)
	void AddPublishing(std::string ganre, std::string description, int year, int rating,  std::string title, int month, Article& article, int isbn=0);
	

	///removes a book by given ID 
	void Remove(int id);
	///prints info by given ISBN (�������� ���������� �� ������� �� ����� isbn �����)
	void Info(int isbn_value);
	///finds a book by an option (������ ����� �� ������ �����)
	bool FindBook(std::string option, std::string options_string);
	///finds a publishing by an option (������ ������� ������� �� ������ �����)
	bool FindPublishing(std::string option, std::string options_string);
	///finds a user by an option (������ ���������� �� ������ �����)
	bool FindUser(std::string option, std::string options_string);

	///changes password of a user (����� �������� �� ����������)
	void changePassword(std::string username);
	///let a user take a book (��������� �� ����������� �� ����� �����)
	void takeBook(int id);
	///let user return a book (��������� �� ����������� �� ����� �����)
	void returnBook(int id);

	///removes a user (�������� ����������)
	void removeUser(std::string username);

	///function for running the app (������� �� ���������� �� ������������)
	void run();
private:
	///checks if the book is already taken
	bool isBookTaken(int id);
	///checks if the book is taken by you
	bool isTheBookTakenByYou(int id);
	
	std::string command;
	std::fstream oldFile;
	std::ifstream newFile;
	char file[MAX_FILE];
	std::vector<LibraryItem>items;
	std::vector<Book>books;
	std::vector<Publishing>serries;
	std::vector<User>users;
	std::vector<Reader>readers;
	std::vector<Admin>admins;
	Date today;
	///checks if there is a logged user
	///��������� ���� ��� ������ ����������
	bool loggedIn;

	///represents the logged user in the moment
	///only one user can enter the system at the same time
	///������������ ������� ����������
	///���� ���� ���������� ���� �� � � ��������� �� ���� � ���� �����
	/// !=���� �� �� ������� (can be inproved in the fiture)
	User user;
};

