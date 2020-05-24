#pragma once 

#include <string>
#include <iostream>
#include "Kart.h"
#include <list>
#include <exception>
#include <memory>
#include <chrono>
#include <thread>

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
	std::list<Item> user_purchase_history;
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
	virtual void print_user_history() const = 0; 
	virtual void add_items_to_kart ();
	virtual void get_info          () const = 0; 
	virtual void check_out         ()       = 0;
	virtual void print_current_kart() const = 0; 
};