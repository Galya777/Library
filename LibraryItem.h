#pragma once
#include <fstream>
#include <vector>
#include <string>

/**
 * @brief 
 * Base class that represents an item in the library
 * It can be book or publishing series like newspapers or magazines
 * 
 * ����� ����, ����� ������������ ������� �� ������������
 * ���� �� ���� ����� ��� ������� ������� - �������� ��� �������
*/
static int THIS_ID=0;
class LibraryItem
{


public:
	//!= Constructors (������������)
	LibraryItem(std::string ganre, std::string description,int year,int rating,int isbn=0);
	LibraryItem();


	//!= Setters
	void setGanre(std::string ganre);
	void setDescription(std::string description);
	void setYear(int year);
	void setRating(int rating);
    void setISBN(int isbn);

	//!= Getters
	std::string getGanre();
	std::string getDescription();
	const int getYear();
	const int getRating();
	const int getUnique();
	int getISBN() const;

	///writes to file (������� ��� ����)
	void writeToFile(std::fstream& file) const;
	///prints a book or series (�������� ����� ��� ������� �������)
    void printBook();

protected:
	std::string ganre;
	std::string description;
	int year;
	int rating;
	int uniqueNumber;
	int isbn;
};

