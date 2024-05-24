#include "Reader.h"

Reader::Reader(std::string username, std::string password)
{
    setUsername(username);
    setPassword(password);
    list.push_back(LibraryItem());
    gotDate.push_back(Date());
    returnDate.push_back(Date());
    returned.push_back(false);
    admin = false;
}

Reader::Reader()
{
    setUsername("");
    setPassword("");
    list.push_back(LibraryItem());
    gotDate.push_back(Date());
    returnDate.push_back(Date());
    returned.push_back(false);
    admin = false;
}

std::vector<LibraryItem> Reader::getBooks() const
{
    return list;
}

std::vector<Date> Reader::GetgotDate() const
{
    return gotDate;
}

std::vector<Date> Reader::GetreturnDate() const
{
    return returnDate;
}

bool Reader::isBookGotten(int id)
{
    for (auto book : list) {
        if (book.getUnique() == id) {
            return true;
        }
    }
    return false;
}

bool Reader::overDue(Date today)
{
    for (auto book : list) {
        int num= getNumberOfTheBook(book);
        if (returnDate.at(num).compare(today) < 0 && !returned.at(num))
            return true;
    }
    return false;
}

void Reader::addBook(LibraryItem& item, Date enroll, Date toReturn)
{
    list.push_back(item);
    gotDate.push_back(enroll);
    returnDate.push_back(toReturn);
}

void Reader::returnTheBook(LibraryItem& item, Date toReturn)
{
    int num = getNumberOfTheBook(item);
    returnDate.at(num) = toReturn;
    returned.at(num) = true;
}

bool Reader::isReturned(LibraryItem& item)
{
    int num = getNumberOfTheBook(item);
    return returned.at(num);
}

int Reader::getNumberOfTheBook(LibraryItem& item)
{
    for (size_t i = 0; i < list.size(); i++)
    {
        if (item.getUnique() == list.at(i).getUnique()) {
            return i;
        }
    }
    return -1;
}
