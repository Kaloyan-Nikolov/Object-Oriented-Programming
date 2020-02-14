#pragma once
#include "Guest.h"

class Admin;

class User : public Guest
{
private:
	char* Username = nullptr;
	char* Password = nullptr;
	char* Title = nullptr;
	int key = 0;

	int calculateKey(); // assigns a random value to this->key
	void copy(const User &u);
	void setPasswordEncrypted(const char* Password); // receives already encrypted password	
	void copyKey(int key);
protected:
	void setUsername(const char* Username);
	void setPassword(const char* Password); // encrypts the password
	void setTitle(const char* Title);

public:
	const char* getUsername() const;
	const char* getEncryptedPassword() const; // returns the encrypted password
	const char* getRealPassword() const; // returns the decrypted password
	const char* getTitle() const;

	const int getKey() const;

	User();
	User(const char * IPaddress, const char* Username, const char* Password, const char* Title);
	User(const User &u);
	User& operator=(const User &u);
	virtual ~User();

	void changePassword(const char* oldPassword, const char* newPassword);

	virtual void printDetails() const override;

	friend class Admin;
};