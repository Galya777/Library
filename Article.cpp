#include "Article.h"

Article::Article(std::string title, std::string author, std::vector<std::string> keyWords)
{
	setTitle(title);
	setAuthor(author);
	setKeyWords(keyWords);
}

Article::Article()
{
	setTitle(title);
	setAuthor(author);
	setKeyWords(keyWords);
}

void Article::setTitle(std::string title)
{
	this->title = title;
}

void Article::setAuthor(std::string author)
{
	this->author = author;
}

std::string Article::getTitle()
{
	return title;
}

std::string Article::getAuthor()
{
	return author;
}

std::vector<std::string> Article::geKeyWords() const
{
	return keyWords;
}
