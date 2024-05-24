#include "LibraryItem.h"
#include <iostream>

int LibraryItem::getISBN() const
{
    return isbn;
}

void LibraryItem::writeToFile(std::fstream& file) const
{
	file << uniqueNumber << " ";
}

void LibraryItem::printBook()
{
	std::cout << uniqueNumber << " ";
}

void LibraryItem::setISBN(int isbn)
{
    this->isbn = isbn;
}

LibraryItem::LibraryItem(std::string ganre, std::string description, int year, int rating, int isbn)
{
	setGanre(ganre);
	setDescription(description);
	setYear(year);
	setRating(rating);
	setISBN(isbn);
	this->uniqueNumber = THIS_ID;
	THIS_ID++;
}

LibraryItem::LibraryItem()
{
	setGanre("");
	setDescription("");
	setYear(0);
	setRating(0);
	setISBN(0);
}



void LibraryItem::setGanre(std::string ganre)
{
	this->ganre = ganre;
}

void LibraryItem::setDescription(std::string description)
{
	this->description = description;
}

void LibraryItem::setYear(int year)
{
	this->year = year;
}

void LibraryItem::setRating(int rating)
{
	this->rating = rating;
}

std::string LibraryItem::getGanre()
{
	return ganre;
}

std::string LibraryItem::getDescription()
{
	return description;
}

const int LibraryItem::getYear()
{
	return year;
}

const int LibraryItem::getRating()
{
	return rating;
}

const int LibraryItem::getUnique()
{
	return uniqueNumber;
}
