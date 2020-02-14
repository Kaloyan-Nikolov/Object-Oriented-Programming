#include "VIP.h"

VIP::VIP(const char * IPaddress, const char * Username, const char * Password, const char * Title) :
	User(IPaddress, Username, Password, Title)
{
}

void VIP::changeTitle(const char * newTitle)
{
	setTitle(newTitle);
}