#include "Commands.h"
#include <iostream>

Commands::Commands(std::string com)
{
	command = com;
	books.push_back(Book());
	serries.push_back(Publishing());
	items.push_back(LibraryItem());
	users.push_back(User("admin", "i<3c++"));
	admins.push_back(Admin("admin", "i<3c++"));
	readers.push_back(Reader());
	today = Date(10, 8, 2022);
}

Commands::Commands()
{
	command=" ";
	books.push_back(Book());
	serries.push_back(Publishing());
	items.push_back(LibraryItem());
    users.push_back(User("admin","i<3c++"));
	admins.push_back(Admin("admin", "i<3c++"));
	readers.push_back(Reader());
	today = Date(10, 8, 2022);
}

void Commands::open()
{
	std::cin >> file;
	newFile.open(file, std::ios::binary | std::ios::in | std::ios::out);
	if (newFile) {
		char arr[MAX_CONTENT];
		while (!newFile.eof()) {
			newFile.getline(arr, MAX_CONTENT);
			std::cout << arr << std::endl;
		}
		
	}
	else {
		oldFile.open(file, std::ios::app);
		oldFile << "New File";
	}
	std::cout << "File successfully opened!" << std::endl;
	}

void Commands::close()
{
	if (oldFile.is_open() || newFile.is_open()) {
		oldFile.close();
		newFile.close();
		std::cout << "File successfully closed!" << std::endl;
	}
	else {
		std::cout << "No file is opened!";
	}
}

void Commands::save()
{
	char* buffer;
	long size;

	std::ifstream infile(file, std::ifstream::binary);
	std::ofstream outfile(file, std::ofstream::binary);
	infile.seekg(0, std::ifstream::end);
	size = infile.tellg();
	infile.seekg(0);
	buffer = new char[size];
	infile.read(buffer, size);
	outfile.write(buffer, size);
	delete[] buffer;

	outfile.close();
	infile.close();
	std::cout << "File successfully saved!" << std::endl;
}

void Commands::saveAs()
{
	char* buffer;
	long size;
	char path[MAX_FILE];
	std::cout << "Enter the path: ";
	std::cin >> path;
	std::ifstream infile(file, std::ifstream::binary);
	std::ofstream outfile(path, std::ofstream::binary);
	infile.seekg(0, std::ifstream::end);
	size = infile.tellg();
	infile.seekg(0);
	buffer = new char[size];
	infile.read(buffer, size);
	outfile.write(buffer, size);
	delete[] buffer;
	outfile.close();
	infile.close();
	std::cout << "File successfully saved!" << std::endl;
}

void Commands::help()
{
	std::cout << "The following commands are supported:" << std::endl;
	std::cout << "- open <file> --- opens <file>" << std::endl;
	std::cout << "- close --- closes currently opened file" << std::endl;
	std::cout << "- save --- saves the currently open file" << std::endl;
	std::cout << "- saveas <file> --- saves the currently open file in <file>" << std::endl;
	std::cout << "- help --- prints this information" << std::endl;
	std::cout << "- exit	--- exists the program" << std::endl;
	std::cout << "- login <username> <password>" << std::endl;
	std::cout << "- logout --- logout only if you are already logged in" << std::endl;
	std::cout << "- books all --- prints: title,genre,author,type, id for every book " << std::endl;
	std::cout << "- serries all --- prints: title,genre,author,type, id for every publishing serries " << std::endl;
	std::cout << "- list all --- prints: title,genre,type,id for every  item in the library" << std::endl;
	std::cout << "- books find <option> <option_string> --- finds book by given option" << std::endl;
	std::cout << "- serries find <option> <option_string> --- finds serries by given option" << std::endl;
	std::cout << "- list find <option> <option_string> --- finds item by given option" << std::endl;
	std::cout << "- list info <id> --- full info for book with this id" << std::endl;
	std::cout << "- books add --- adds book or publishings to the database (admin only)\n";
	std::cout << "- books remove <id> --- removes book by given ID (admin only)" << std::endl;
	std::cout << "- users add <username> <password> --- adds user in the database (admin only)\n";
	std::cout << "- users remove --- deletes user from database (admin only)\n";
}
bool Commands::Login()
{
	std::string username, password;
	std::cout << "Enter your username: ";
	std::cin >> username;
	std::cout << "Enter your password: ";
	std::cin >> password;
	if (username == user.getUsername() && password == user.getPassword()) {
		std::cout << "You are already logged in!" << std::endl;
		return true;
	}	
	for (size_t i = 0; i < users.size(); i++)
	{
		if (password == users.at(i).getPassword() && username==users.at(i).getUsername())
		{
			std::cout << "Welcome, " << username << "!\n";
			return true;
			user = users.at(i);
		}
	}
		std::cout << "Wrong password or username.\n";
		return false;
	
}

void Commands::AddBook(std::string title, std::string author, std::string ganre, std::string description, int year, std::vector<std::string> keyWords, int rating)
{
	Book book=Book(title, author, ganre, description, year, keyWords, rating);
	this->items.push_back(book);
	this->books.push_back(book);
	std::cout << book.getTitle() << " by: " << book.getAuthor() << " was added to the database.\n";
}

void Commands::AddPublishing(std::string ganre, std::string description, int year, int rating,  std::string title, int month, Article& article, int isbn)
{
	Publishing seria = Publishing(ganre, description, year, rating, title, month, article);
	this->items.push_back(seria);
	this->serries.push_back(seria);
	std::cout << seria.getTitle() << " was added to the database.\n";
}

void Commands::Remove(int id)
{
	bool removed = false;
	int size = items.size();
	for (int i = 0; i < size; i++)
	{
		if (id == items.at(i).getUnique())
		{
			this->items.erase(items.begin() + i);
			std::cout << "Book with Id: " << id << " was deleted!\n";
			removed = true;
		}
	}
	if (!removed)
	{
		std::cout << "There is no book with Id: " << id << "!\n";
	}
}

void Commands::Info(int isbn_value)
{
	bool found = false;
	for (int i=0; i<items.size();++i)
	{
		if (items.at(i).getISBN() == isbn_value) {
			items.at(i).printBook();
			cout << endl;
			found = true;
		}
	}

	if (!found)
	{
		cout << "No book with ISBN: " << isbn_value << " was found" << endl;
	}
}

bool Commands::FindBook(std::string option, std::string options_string)
{
	bool found = false;
	for (auto book : books)
	{
		string title = book.getTitle();
		string author = book.getAuthor();


		if (option == "title" && options_string == title)
		{
			book.printBook();
			found = true;
		}
		else if (option == "author" && options_string == author)
		{
			book.printBook();
			found = true;
		}
		else if (option == "tag")
		{
			vector<string> keywords = book.geKeyWords();
			if (count(keywords.begin(), keywords.end(), options_string))
			{
				book.printBook();
				found = true;
			}
		}
	}
	return found;
}

bool Commands::FindPublishing(std::string option, std::string options_string)
{
	bool found = false;
	for (auto seria : serries)
	{
		string title = seria.getTitle();
		string author = seria.getContent().at(0).getAuthor();


		if (option == "title" && options_string == title)
		{
			seria.printBook();
			found = true;
		}
		else if (option == "author" && options_string == author)
		{
			seria.printBook();
			found = true;
		}
		else if (option == "tag")
		{
			vector<string> keywords = seria.getContent().at(0).geKeyWords();
			if (count(keywords.begin(), keywords.end(), options_string))
			{
				seria.printBook();
				found = true;
			}
		}
	}
	
	return found;
}

bool Commands::FindUser(std::string option, std::string options_string)
{
	bool found = false;
	for (auto user : users)
	{
		string username = user.getUsername();
	
		if (option == "username" && options_string == username)
		{
			user.printUser();
			found = true;
		}
		else if (option == "id")
		{
			if (!user.getAdmin()) {
				for (auto reader : readers) {
					if (user.getUsername()==reader.getUsername() && reader.isBookGotten(atoi(options_string.c_str()))) {
						reader.printUser();
						found = true;
					}
				}
			}
		}
		else if (option == "state")
		{
			if (options_string == "overdue") {
				if (!user.getAdmin()) {
					for (auto reader : readers) {
						if (user.getUsername() == reader.getUsername() && reader.overDue(today)) {
							reader.printUser();
							found = true;
						}
					}
				}
			} else if (options_string == "reader") {
				if (!user.getAdmin()) {
					for (auto reader : readers) {
						if (user.getUsername() == reader.getUsername() && reader.getBooks().size()>=5) {
							reader.printUser();
							found = true;
						}
					}
				}

			} else if (options_string == "inactivate") {
				if (!user.getAdmin()) {
					for (auto reader : readers) {
						for (size_t i = 0; i < reader.GetgotDate().size(); i++)
						{
	                    if (user.getUsername() == reader.getUsername() && reader.GetgotDate().at(i).compare(today)>3) {
							reader.printUser();
							found = true;
						}
						}
					
					}
				}
			}
		}
	}

	return found;
}

void Commands::changePassword(std::string username)
{
	cout << "Hello, "<<username<<"!\n";
	cout << "Enter your new password: ";
	std::string password;
	cin >> password;
	for (auto user : users) {
		if (user.getUsername() == username) {
			user.setPassword(password);
			if (user.getAdmin()) {
				for (auto admin : admins) {
					if (admin.getUsername() == username) {
						admin.setPassword(password);
					}
				}
			}
			else {
				for (auto reader : readers) {
					if (reader.getUsername() == username) {
						reader.setPassword(password);
					}

				}
			}
		}
	}
}

void Commands::takeBook(int id)
{
	if (!isBookTaken(id)) {
		for (auto book : books) {
			if (book.getUnique() == id) {
				for (auto reader : readers) {
					if (reader.getUsername() == user.getUsername()) {
						Date toReturn = Date(today.get_day(), today.get_month() + 1, today.get_year()); //book must be returned in a month
						reader.addBook(book, today, toReturn);
						cout << "Successfully added a book!";
					}
				}
			}
		}
	}
	else {
		cout << "Sorry, this book is already taken!";
	}
}

void Commands::returnBook(int id)
{
	if (isTheBookTakenByYou(id)) {
		for (auto book : books) {
			if (book.getUnique() == id) {
				for (auto reader : readers) {
					if (reader.getUsername() == user.getUsername()) {
						reader.returnTheBook(book, today);
						cout << "Successfully added a book!";
					}
				}
			}
		}
	}
	else {
		cout << "Sorry, the book is not taken by you!\n";
	}
}

void Commands::removeUser(std::string username)
{
	bool removed = false;
	int size = users.size();
	for (int i = 0; i < size; i++)
	{
		if (username == users.at(i).getUsername())
		{
			this->users.erase(users.begin() + i);
			std::cout << "User with : " << username << " was deleted!\n";
			removed = true;
		}
	}
	if (!removed)
	{
		std::cout << "There is no user: " << username << "!\n";
	}
}


void Commands::run()
{
	do {
		std::cout << "Enter your command: ";
		std::cin >> command;
		if (command == "open") {
			open();

		}
		else if (command == "close") {
			close();
		}
		else if (command == "save") {
			for (unsigned i = 0; i < items.size(); ++i) {
				items.at(i).writeToFile(oldFile);
			}
			for (unsigned i = 0; i < users.size(); ++i) {
				users.at(i).writeToFile(oldFile);
			}
			save();
		}
		else if (command == "save as") {
			for (unsigned i = 0; i < items.size(); ++i) {
				items.at(i).writeToFile(oldFile);
			}
			for (unsigned i = 0; i < users.size(); ++i) {
				users.at(i).writeToFile(oldFile);
			}
			saveAs();
		}
		else if (command == "help") {
			help();
		}
		else if (command == "login") {
			if (loggedIn)
				std::cout << "You are already logged in." << std::endl;
			else {
				if (Login())
					loggedIn = true;

			}
		}
		else if (command == "logout") {
			if (loggedIn)
			{
				user.Loggout();
				loggedIn = false;
			}
			else
				std::cout << "No logged in user!" << std::endl;
		}
		else if (command == "bookall") {
			for (int i = 0; i < books.size(); ++i) {
				books.at(i).printBook();
				std::cout << std::endl;
			}
		}
		else if (command == "serriesall") {
			for (int i = 0; i < serries.size(); ++i) {
				serries.at(i).printBook();
				std::cout << std::endl;
			}
		}
		else if (command == "listall") {
			for (int i = 0; i < items.size(); ++i) {
				items.at(i).printBook();
				std::cout << std::endl;
			}
		}
		else if (command == "bookfind") {
			if (loggedIn)
			{
				string option_string, option;
				cout << "Enter option and option string: ";
				cin >> option >> option_string;

				bool found= FindBook(option, option_string);
				if (!found)
				{
					cout << "Book with " << option << ": " << option_string << " wasn't found" << endl;
				}
			}
			else
				cout << "You have to login first!\n";
		}
		else if (command == "userfind") {
			if (loggedIn)
			{
				string option_string, option;
				cout << "Enter option and option string: ";
				cin >> option >> option_string;

				bool found = FindUser(option, option_string);
				if (!found)
				{
					cout << "User with " << option << ": " << option_string << " wasn't found" << endl;
				}
			}
			else
				cout << "You have to login first!\n";
		}
		else if (command == "seriafind") {
			if(loggedIn){
			string option_string, option;
			cout << "Enter option and option string: ";
			cin >> option >> option_string;

			bool found= FindPublishing(option, option_string);
			if (!found)
			{
				cout << "Serries with " << option << ": " << option_string << " wasn't found" << endl;
			}
		}
		else
			cout << "You have to login first!\n";
	}
		else if (command == "listfind") {
			if (loggedIn) {
				string option_string, option;
				cout << "Enter option and option string: ";
				cin >> option >> option_string;

				bool found1=FindPublishing(option, option_string);
				bool found2 = FindBook(option, option_string);
				if (!found1 && !found2) {
					cout << "Book or serries with " << option << ": " << option_string << " wasn't found" << endl;
				}
				
			}
			else
				cout << "You have to login first!\n";
		}
	
		else if (command == "listinfo") {
			if (loggedIn)
			{
				int id;
				cout << "Enter the id: ";
				cin >> id;
				Info(id);				
			}
			else
				cout << "You have to login first!\n";
		}
		else if (command == "bookadd") {
			if (loggedIn && user.getAdmin())
			{
				string title, author, ganre, description, word;
				vector<string> keywords;
				int year, rating;
				string option;
				std::cout << "Please, enter if you are going to add a book or a publishing: ";
				std::cin >> option;
				if (option == "book") {
					cout << "Enter title: ";
					cin >> title;
					cout << "Enter author: ";
					cin >> author;
					cout << "Enter ganre: ";
					cin >> ganre;
					cout << "Enter description: ";
					cin >> description;
					cout << "Enter year: ";
					cin >> year;
					cout << "Enter keywords: ";
					cin >> word;
					keywords.push_back(word);
					cout << "Enter rating: ";
					cin >> rating;
					AddBook(title, author, ganre, description, year, keywords, rating);
				}
				else if (option == "publishing") {
					cout << "Enter title: ";
					cin >> title;
					cin >> author;
					cout << "Enter ganre: ";
					cin >> ganre;
					cout << "Enter description: ";
					cin >> description;
					cout << "Enter year: ";
					cin >> year;
					int month;
					cout << "Enter month: ";
					cin >> month;
					cout << "Enter rating: ";
					cin >> rating;
					std::string aTitle;
					cout << "Enter title: ";
					cin >> aTitle;
					cout << "Enter author: ";
					cin >> author;
					cout << "Enter keywords: ";
					cin >> word;
					keywords.push_back(word);
					Article art = Article(aTitle, author, keywords);
					AddPublishing(ganre, description, year, rating, title, month, art);
				}
				else {
					std::cout << "This option is not supported!";
				}
			}
			else {
			cout << "Only Admin can add new books!\n";
		}
		}
		else if (command == "bookremove") {
			if (loggedIn && user.getAdmin())
			{
				int id;
				cout << "Enter the id: ";
				cin >> id;
				Remove(id);
			}else {
			cout << "Only Admin can remove books!\n";
		}
	}
		else if (command == "useradd") {
			if (loggedIn && user.getAdmin())
			{
				string username, password; bool admin;
				cout << "Enter username: ";
				cin >> username;
				while (FindUser("username", username)) {
					cout << "This username is taken! Try new: ";
					cin >> username;
				}
				cout << "Enter password: ";
				cin >> password;
				cout << "Are you admin? Answear binary: ";
				cin >> admin;
				if (admin) {
					Admin a =Admin(username.c_str(), password.c_str());
					a.setAdmin(admin);
					admins.push_back(a); 
					users.push_back(a);
					if (oldFile.is_open()) {
						a.writeToFile(oldFile);
					}
				}
				else {
					Reader u = Reader(username.c_str(), password.c_str());
					readers.push_back(u);
					u.setAdmin(admin);
					users.push_back(u);

					if (oldFile.is_open()) {
						u.writeToFile(oldFile);
					}
				}
			}
			else if (!loggedIn)
			{
				cout << "You have to login first!\n";
			}
			else {
				cout << "Only Admin can add new users!\n";
			}


		}
		else if (command == "userremove") {
			if (loggedIn && user.getAdmin())
			{
				string username;
				cout << "Enter username: ";
				cin >> username;
				removeUser(username);

			}
			else if (!loggedIn)
			{
				cout << "You have to login first!\n";
			}
			else {
				cout << "Only Admin can remove users!\n";
			}
		}
		else if (command == "changepassword") {
		if (loggedIn && user.getAdmin())
		{
			string username;
			cout << "Enter username: ";
			cin >> username;
			changePassword(username);

		}
		else if (!user.getAdmin()) {
			changePassword(user.getUsername());
		}
		else if (!loggedIn)
		{
			cout << "You have to login first!\n";
		}
		else {
			cout << "Only Admin can remove users!\n";
		}
		}
		else if (command == "takebook") {
		if (loggedIn)
		{
			int id;
			cout << "Enter the id: ";
			cin >> id;
			takeBook(id);
		}
		else
			cout << "You have to login first!\n";
		}
		else if (command == "returnbook") {
		if (loggedIn)
		{
			int id;
			cout << "Enter the id: ";
			cin >> id;
			returnBook(id);
		}
		else
			cout << "You have to login first!\n";
		}
		else if (command != "exit") {
			std::cout << "Invalid command! Try again!" << std::endl;
		}
	} while (command != "exit");
	
}

bool Commands::isBookTaken(int id)
{
	for (auto reader : readers) {
		for (auto book : reader.getBooks()) {
			if (book.getUnique() == id && reader.isReturned(book)) {
				return true;
			}
		}
	}
	return false;
}

bool Commands::isTheBookTakenByYou(int id)
{
	if (!user.getAdmin()) {
		for (auto reader : readers) {
			if (reader.getUsername() == user.getUsername()) {
				for (auto book : reader.getBooks()) {
					if (book.getUnique() == id) {
						return true;
					}
				}
			}
		}
	}
	return false;
}
