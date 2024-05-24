#pragma once
#include "LibraryItem.h"
#include "Article.h"
/**
 * @brief 
 * This class represents a book witch is a child of LibraryItem and Article
 * 
 * Този клас представлява книга. Наследник е на LibraryItem и Article
*/
class Book: public LibraryItem, public Article
{
public:
	//!= Constructors (конструктури)
	Book(std::string title, std::string author, std::string ganre, std::string description, int year, std::vector<std::string> keyWords, int rating, int isbn=0);
	Book();

	/*!
* Overloading operator ">>". It is used for reading from file
* Предефиниране на оператор ">>". Използва се за четене на книга от файл
*/
	friend std::istream& operator>>(std::istream& in, Book& book);
	/*!
* Overloading operator "<<". It is used for writinf from file
* Предефиниране на оператор "<<". Използва се за записване на книга във файл
*/
	friend std::ostream& operator<<(std::ostream& out, const Book& other);

	 void readFromFile(std::ifstream& file) const;
	 void writeToFile(std::fstream& file) const;
	
	///prints a book om the console
	void printBook();
private:
	void init(std::string title, std::string author, std::string ganre, std::string description, int year, std::vector<std::string> keyWords, int rating);
	
};

