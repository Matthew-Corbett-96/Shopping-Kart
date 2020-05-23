#pragma once 

#include <string>
#include <iostream>
#include "Item.h"
#include "Kart.h"
#include <map>
#include <exception>
#include <memory>

/************THIS CLASS IS AN INTERFACE*****************/ 
/**************CANNOT BE IMPLIMENTED********************/

class V_User {
protected:
	// User's Name
	std::string user_name = "N/A";
	// User's Shopping Kart object 
	Kart user_kart; 
	// Address of User to determin shipping 
	std::string user_address = "N/A";
	// User Phone Number 
	std::string user_phone_number = "N/A";
	// User's purchase History w/ time stamps 
	std::multimap<std::string, Item> user_purchase_history;
public:
	// Constructors 
	V_User();
	V_User(const std::string&);
	V_User(const std::string&, const std::string&);
	V_User(const std::string&, const std::string&, const std::string&);

	// Destructor -- Virtual 
	virtual ~V_User();

	// Setters -- All Virtual 
	virtual void set_user_name   (const std::string&);
	virtual void set_user_address(const std::string&);
	virtual void set_user_phone  (const std::string&);

	// Getters -- All Virtual
	virtual const std::string& get_user_name   () const;
	virtual const std::string& get_user_address() const;
	virtual const std::string& get_user_phone  () const;

	// Specialty Functions 
	virtual void get_user_history() const = 0;
	void add_items_to_kart();
};