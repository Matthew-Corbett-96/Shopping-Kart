#pragma once
#include "V_User.h"

class Gold_User : public V_User
{

public:
	// Constructors
	Gold_User();
	Gold_User(const std::string&);
	Gold_User(const std::string&, const std::string&);
	Gold_User(const std::string&, const std::string&, const std::string&);

	// Destructor -- Override
	virtual ~Gold_User() override;

	// Setters -- All From V_User

	// Getters  
	const bool get_Gold_Status() const override;


	// Specialty Functions
	void print_user_history() const override;
	void get_info          () const override;
	void check_out         ()       override;
	void print_current_kart() const override;
	void add_items_to_kart ()       override;
};

