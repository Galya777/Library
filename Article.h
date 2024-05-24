#pragma once
#include <string>
#include <vector>
/**
 * @brief 
 * This class represents article. 
 * Every article has title, author and keyWords.
 * 
 * Този клас представлява статия. 
 * всяка статия съдържа заглавие, автор и ключови думи.
*/
class Article
{
public:
	//!= Constructors (конструктури)
	Article(std::string title, std::string author, std::vector<std::string> keyWords);
	Article();

	//!= Setters
	void setTitle(std::string title);
	void setAuthor(std::string author);
	void setKeyWords(std::vector<std::string> const& keywords) { this->keyWords = keywords; }
	
	//!= Getters
	std::string getTitle();
	std::string getAuthor();
	std::vector<std::string> geKeyWords() const;
	


protected:
	std::string title;
	std::string author;
	std::vector<std::string> keyWords;
};

