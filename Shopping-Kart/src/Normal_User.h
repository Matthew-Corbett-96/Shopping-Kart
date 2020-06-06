#pragma once
#include "V_User.h"

class Normal_User : public V_User
{
public:
	// Constructors 
	Normal_User();
	Normal_User(const std::string&);
	Normal_User(const std::string&, const std::string&);
	Normal_User(const std::string&, const std::string&, const std::string&);

	// Destructor -- Override
	virtual ~Normal_User() override;

	// Setters -- All Overridden
	

	// Getters -- All Overridden 
	const bool get_Gold_Status() const override; 

	// Specialty Functions 
	void print_user_history() const override;
	void get_info          () const override;
	void check_out         ()       override;
	void print_current_kart() const override;
};

