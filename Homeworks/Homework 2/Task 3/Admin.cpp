#include "Admin.h"

Admin::Admin(const char * IPaddress, const char * Username, const char * Password, const char * Title) :
	User(IPaddress, Username, Password, Title), PowerUser(IPaddress, Username, Password, Title)
{
}

void Admin::changeUsername(const char * NewUsername)
{
	std::cout << "Your username has been changed successfully!" << std::endl;
	setUsername(NewUsername);
}

void Admin::changeAnoherUsername(User & u, const char* NewUsername)
{
	std::cout << "You have changed the username of: \"" << u.getUsername() << "\" to: ";
	u.setUsername(NewUsername);
	std::cout << "\"" << u.getUsername() << "\"" << std::endl;
}