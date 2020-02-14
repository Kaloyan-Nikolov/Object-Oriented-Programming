#include "User.h"

int User::calculateKey()
{	
	this->key = 1 + (rand() % 20);	
	return this->key;
}

void User::copy(const User & u)
{
	setUsername(u.getUsername());
	setPasswordEncrypted(u.getEncryptedPassword());
	setTitle(u.getTitle());
	copyKey(u.getKey());
}

void User::setPasswordEncrypted(const char * Password)
{
	if (Password == nullptr)
	{
		return;
	}
	delete[] this->Password;
	this->Password = new char[strlen(Password) + 1];
	strcpy_s(this->Password, strlen(Password) + 1, Password);
}

void User::copyKey(int key)
{
	this->key = key;
}

void User::setUsername(const char * Username)
{
	if (Username == nullptr)
	{
		return;
	}
	delete[] this->Username;
	this->Username = new char[strlen(Username) + 1];
	strcpy_s(this->Username, strlen(Username) + 1, Username);
}

void User::setPassword(const char * Password)
{
	if (Password == nullptr)
	{
		return;
	}
	delete[] this->Password;
	int size = strlen(Password);
	this->Password = new char[size + 1];

	this->key = calculateKey();
	for (int i = 0; i < size; i++)
	{
		this->Password[i] = Password[i] + this->key;		
	}
	this->Password[size] = 0;	
}

void User::setTitle(const char * Title)
{
	if (Title == nullptr)
	{
		return;
	}
	delete[] this->Title;
	this->Title = new char[strlen(Title) + 1];
	strcpy_s(this->Title, strlen(Title) + 1, Title);
}

const char * User::getUsername() const
{
	return this->Username;
}

const char * User::getEncryptedPassword() const
{
	return this->Password;
}

const char * User::getRealPassword() const
{
	int size = strlen(this->Password);
	char* decrypedPassword = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		decrypedPassword[i] = this->Password[i] - this->key;
	}
	decrypedPassword[size] = 0;	

	return decrypedPassword; // to be deleted
}

const char * User::getTitle() const
{
	return this->Title;
}

const int User::getKey() const
{
	return this->key;
}

User::User()
{
	setUsername("Def username");
	setPassword("123456");
	setTitle("Def title");
}

User::User(const char * IPaddress, const char * Username, const char * Password, const char * Title) :
	Guest(IPaddress)
{
	setUsername(Username);
	setPassword(Password);
	setTitle(Title);	
}

User::User(const User & u) : Guest(u.getIPaddress())
{
	copy(u);
}

User & User::operator=(const User & u)
{
	if (this != &u)
	{
		Guest::operator=(u);
		copy(u);
	}

	return *this;
}

User::~User()
{
	delete[] this->Username;
	delete[] this->Password;
	delete[] this->Title;
}

void User::changePassword(const char * oldPassword, const char * newPassword)
{
	const char* RealPassword = this->getRealPassword();
	if (strcmp(RealPassword, oldPassword) == 0)
	{
		setPassword(newPassword);
		std::cout << "The password is successfully changed!" << std::endl;
	}
	else
	{
		std::cout << "Old password is incorrect!" << std::endl;
	}
	delete[] RealPassword;
}

void User::printDetails() const
{
	Guest::printDetails();
	std::cout << "Username: " << getUsername() << std::endl;
	std::cout << "Password: " << getEncryptedPassword() << std::endl;
	const char* RealPassword = this->getRealPassword();
	std::cout << "Real Password: " << RealPassword << std::endl;
	std::cout << "Title: " << getTitle() << std::endl;
	std::cout << "Key: " << getKey() << std::endl;
	delete[] RealPassword;
}
