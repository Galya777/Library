#pragma once
#include "LibraryItem.h"
#include "Article.h"
/**
 * @brief 
 * This class represents a publishing series. It is a child of Library item and contains title, month and articles.
 * 
 * Класът представлява печатно издание. Наследник е на LibraryItem и съдържа в допълнение заглавие, месец на издаване и статии. 
*/
class Publishing: public LibraryItem
{
public:
	//!= Constructors (конструктури)
	Publishing(std::string ganre, std::string description, int year, int rating,  std::string title,int month, Article& article, int isbn=0);
	Publishing();

	//!= Setters
	void setTitle(std::string title);
	void setMonth(int month);
	void addContent(Article article);

	//!= Getters
	std::string getTitle();
	const int getMonth();
	std::vector<Article> getContent() const;

	
	void readFromFile(std::ifstream& file) const;
	void writeToFile(std::fstream& file) const;
	 
	void printBook();
private:
	std::string title;
	int month;
	std::vector<Article> content;
};

