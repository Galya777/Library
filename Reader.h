#pragma once
#include "LibraryItem.h"
#include "User.h"
/**
 * @brief 
 * This class represents a reader, chield of a user.
 * 
 * Този клас представлява четящ, наследник на user. 
*/
class Reader: public User
{
public:
	//!= Constructors (конструктури)
	Reader(std::string username, std::string password);
	Reader();



	//!= Getters
	std::vector<LibraryItem> getBooks() const;
	std::vector<Date> GetgotDate() const;
	std::vector<Date> GetreturnDate() const;

	//checks if a book is in your list 
	bool isBookGotten(int id);
	///checks if the user has at least one overDue book (проверява дали потребителя има поне една просрочена книга)
	bool overDue(Date today);
	
	///adds a book in the list of taken books
	void addBook(LibraryItem& item, Date enroll, Date toReturn);
	///changes the date of returned book
	void returnTheBook(LibraryItem& item, Date toReturn);
	///checks if the book is returned
	bool isReturned(LibraryItem& item);

private:
	///returns the number of the book stored in the list
	int getNumberOfTheBook(LibraryItem& item);

	std::vector<LibraryItem> list;
	std::vector<Date> gotDate;
	std::vector<Date> returnDate;
	std::vector<bool> returned;
};
