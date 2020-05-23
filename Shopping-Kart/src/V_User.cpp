#include "V_User.h"

// Personal Logging Macros-----------------
//-----------------------------------------
//-----------------------------------------
//-----------------------------------------
#define Log std::cout << 
#define And << 
#define End << std::endl 
#define Skip std::cout << std::endl 
#define New_line << "\n" << 
#define Clear_Screen std::system("cls")
#define Get std::cin >> 
#define AAnd >>
//-----------------------------------------
//-----------------------------------------
//-----------------------------------------
// ----------------------------------------



// Constructors----------------------------
//-----------------------------------------
//-----------------------------------------
//-----------------------------------------

// Default Constructor 
V_User::V_User() {}

// Constructor with name only 
V_User::V_User(const std::string& name)
	: user_name(name) 
{
	this->user_kart.set_name(user_name);
}


// Constructor with name and adress 
V_User::V_User(const std::string& name, const std::string& address)
	: user_name(name), user_address(address) 
{
	this->user_kart.set_name(user_name);
}

// Constructor with all data
V_User::V_User(const std::string& name, const std::string& address, const std::string& phone_number)
	: user_name(name), user_address(address), user_phone_number(phone_number) 
{
	this->user_kart.set_name(user_name);
}

// Destructors-----------------------------
//-----------------------------------------
//-----------------------------------------
//-----------------------------------------

// Default Destructor 
V_User::~V_User() {}

// Setters---------------------------------
//-----------------------------------------
//-----------------------------------------
//-----------------------------------------

// Set User Name to User and Kart 
void V_User::set_user_name(const std::string& name)
{
	this->user_name = name;
	this->user_kart.set_name(user_name);
}

// Set User Address
void V_User::set_user_address(const std::string& address) { this->user_address = address; }

// Set User Phone Number 
void V_User::set_user_phone(const std::string& phone_number) { this->user_phone_number = phone_number; }

// Getters---------------------------------
//-----------------------------------------
//-----------------------------------------
//-----------------------------------------

// Get User's Name 
const std::string& V_User::get_user_name() const { return this->user_name; }

// Get User's Adress
const std::string& V_User::get_user_address() const { return this->user_address; }

// Get User's Phone Number 
const std::string& V_User::get_user_phone() const { return this->user_phone_number; }

// Adding Item to the Kart 
void V_User::add_items_to_kart()
{
    char input[50];
    std::string name;
    float price;
    unsigned int quantity;

    // Get Item information from User
    Log
        "---------------------------------------------------" New_line
        "To add item. Type name of item, then price of item." New_line
        "---------------------------------------------------" New_line
        "Enter Item name: ";  Get name;                       Skip;
    Log "Enter Item price: "; Get price;                      Skip;
    Log "Quantity of item: "; Get quantity;                   Skip;

    // Create number of item specififed
    for (int i = 0; i < quantity; i++) this->user_kart.add_item(name, price);

    // Clear Screen
    Clear_Screen;

    // Print to console
    Log
        "---------------------------------------------------" New_line
        "                  " And name And " Added to Kart."   New_line
        "---------------------------------------------------" End;
}