#pragma once
#include "PowerUser.h"
#include "VIP.h"

class Admin : public PowerUser, public VIP
{
public:
	Admin() = default;
	Admin(const char * IPaddress, const char * Username, const char * Password, const char * Title);

	void changeUsername(const char* NewUsername);
	void changeAnoherUsername(User &u, const char* NewUsername);
};
