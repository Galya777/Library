#include "Book.h"
#include <iostream>

Book::Book(std::string title, std::string author, std::string ganre, std::string description, int year, std::vector<std::string> keyWords, int rating, int isbn )
{
	init(title, author, ganre, description, year, keyWords, rating);
	this->isbn = isbn;
}

Book::Book()
{
	std::vector<std::string> k = { "", "" };
	init(" "," ", " ", " ", 0, k, 0); 
	this->isbn = 0;

	
}



void Book::readFromFile(std::ifstream& file) const
{
	file.read((char*)uniqueNumber, sizeof(uniqueNumber));
	file.read((char*)title.c_str(), sizeof(title));
	file.read((char*)author.c_str(), sizeof(author));
	file.read((char*)description.c_str(), sizeof(description));
	file.read((char*)ganre.c_str(), sizeof(ganre));
}

void Book::writeToFile(std::fstream& file) const
{
	file << title << " " << author << " " << ganre << " " << uniqueNumber;
}

void Book::printBook()
{
	std::cout << title << " " << author<< "book" << " " << ganre << " " << uniqueNumber;
}

void Book::init(std::string title, std::string author, std::string ganre, std::string description, int year, std::vector<std::string> keyWords, int rating)
{
	setTitle(title);
	setAuthor(author);
	setGanre(ganre);
	setDescription(description);
	setYear(year);
	setKeyWords(keyWords);
	setRating(rating);

}

std::istream& operator>>(std::istream& in, Book& other)
{
	in >> other.title >> other.author >> other.description >> other.ganre >> other.uniqueNumber;
	return in;
	// TODO: insert return statement here
}

std::ostream& operator<<(std::ostream& out, const Book& other)
{
	out << other.title << " " << other.author << " " << other.description << " " << other.ganre << " " << other.uniqueNumber;
	return out;
}
