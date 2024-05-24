#include "Publishing.h"
#include <iostream>

Publishing::Publishing(std::string ganre, std::string description, int year, int rating, std::string title, int month, Article& article, int isbn)
{
	setGanre(ganre);
	setDescription(description);
	setYear(year);
	setRating(rating);
	setISBN(isbn);
	setTitle(title);
	setMonth(month);
	addContent(article);
}

Publishing::Publishing()
{
	setTitle("");
	setMonth(0);
	addContent(Article());
}

void Publishing::setTitle(std::string title)
{
	this->title = title;
}

void Publishing::setMonth(int month)
{
	this->month = month;
}

void Publishing::addContent(Article article)
{
	content.push_back(article);
}

std::string Publishing::getTitle()
{
	return title;
}

const int Publishing::getMonth()
{
	return month;
}

std::vector<Article> Publishing::getContent() const
{
	return content;
}

void Publishing::readFromFile(std::ifstream& file) const
{
	file.read((char*)uniqueNumber, sizeof(uniqueNumber));
	file.read((char*)title.c_str(), sizeof(title));
	file.read((char*)description.c_str(), sizeof(description));
	file.read((char*)ganre.c_str(), sizeof(ganre));

}

void Publishing::writeToFile(std::fstream& file) const
{
	file << title << " " << "publishing seria" << " " << ganre << " " << uniqueNumber;
}

void Publishing::printBook()
{
	std::cout << title << " " << "publishing seria" << " " << ganre << " " << uniqueNumber;
}