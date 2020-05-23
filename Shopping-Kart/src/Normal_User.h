#pragma once
#include "V_User.h"

class Normal_User : public V_User
{
private:
	const bool Premium_Status = false; 
public:
	// Constructors 
	Normal_User();
	Normal_User(const std::string&);
	Normal_User(const std::string&, const std::string&);
	Normal_User(const std::string&, const std::string&, const std::string&);

	// Destructor -- Override
	~Normal_User() override;

	// Setters -- All Overridden
	

	// Getters -- All Overridden 

	// Specialty 
	void get_user_history() const override;
};

