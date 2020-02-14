#pragma once
#include "User.h"

class VIP : virtual public User
{
public:
	VIP() = default;
	VIP(const char * IPaddress, const char * Username, const char * Password, const char * Title);

	void changeTitle(const char* newTitle);
};
