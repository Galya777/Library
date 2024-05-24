#pragma once
#include "LibraryItem.h"
#include "Article.h"
/**
 * @brief 
 * This class represents a book witch is a child of LibraryItem and Article
 * 
 * ���� ���� ������������ �����. ��������� � �� LibraryItem � Article
*/
class Book: public LibraryItem, public Article
{
public:
	//!= Constructors (������������)
	Book(std::string title, std::string author, std::string ganre, std::string description, int year, std::vector<std::string> keyWords, int rating, int isbn=0);
	Book();

	/*!
* Overloading operator ">>". It is used for reading from file
* ������������� �� �������� ">>". �������� �� �� ������ �� ����� �� ����
*/
	friend std::istream& operator>>(std::istream& in, Book& book);
	/*!
* Overloading operator "<<". It is used for writinf from file
* ������������� �� �������� "<<". �������� �� �� ��������� �� ����� ��� ����
*/
	friend std::ostream& operator<<(std::ostream& out, const Book& other);

	 void readFromFile(std::ifstream& file) const;
	 void writeToFile(std::fstream& file) const;
	
	///prints a book om the console
	void printBook();
private:
	void init(std::string title, std::string author, std::string ganre, std::string description, int year, std::vector<std::string> keyWords, int rating);
	
};

