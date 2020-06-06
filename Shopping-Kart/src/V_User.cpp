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
    // If name is over 25 characters, throw Error. 
    if (name.size() > 25)
    {
        user_name = "N/A"; 
        throw std::length_error("Name Can Only Be 25 Characters.");
    }
    else
	    this->user_kart.set_name(user_name);
}


// Constructor with name and adress 
V_User::V_User(const std::string& name, const std::string& address)
	: user_name(name), user_address(address) 
{
    if (name.size() > 25)
    {
        user_name = "N/A";
        throw std::length_error("Name Can Only Be 25 Characters.");
    }
	this->user_kart.set_name(user_name);
}

// Constructor with all data
V_User::V_User(const std::string& name, const std::string& address, const std::string& phone_number)
	: user_name(name), user_address(address), user_phone_number(phone_number) 
{
    if (name.size() > 25)
    {
        user_name = "N/A";
        throw std::length_error("Name Can Only Be 25 Characters.");
    }
    if (user_phone_number.size() > 13)
    {
        user_phone_number = "N/A";
        throw std::length_error("Phone Number Must be Valid Length.");
    }
	this->user_kart.set_name(user_name);
}

// Default Constructor w/ status 
V_User::V_User(bool status) 
    : Gold_Status(status) {}

// Constructor with name and status 
V_User::V_User(const std::string& name, bool status)
    : user_name(name), Gold_Status(status)
{
    // If name is over 25 characters, throw Error. 
    if (name.size() > 25)
    {
        user_name = "N/A";
        throw std::length_error("Name Can Only Be 25 Characters.");
    }
    else
        this->user_kart.set_name(user_name);
}


// Constructor with name and adress 
V_User::V_User(const std::string& name, const std::string& address, bool status)
    : user_name(name), user_address(address), Gold_Status(status)
{
    if (name.size() > 25)
    {
        user_name = "N/A";
        throw std::length_error("Name Can Only Be 25 Characters.");
    }
    this->user_kart.set_name(user_name);
}

// Constructor with all data
V_User::V_User(const std::string& name, const std::string& address, const std::string& phone_number, bool status)
    : user_name(name), user_address(address), user_phone_number(phone_number), Gold_Status(status)
{
    if (name.size() > 25)
    {
        user_name = "N/A";
        throw std::length_error("Name Can Only Be 25 Characters.");
    }
    if (user_phone_number.size() > 13)
    {
        user_phone_number = "N/A";
        throw std::length_error("Phone Number Must be Valid Length.");
    }
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
    if (name.size() > 25)
    {
        user_name = "N/A";
        throw std::length_error("Name Can Only Be 25 Characters.");
        return;
    }
	this->user_name = name;
	this->user_kart.set_name(user_name);
}

// Set User Address
void V_User::set_user_address(const std::string& address) { this->user_address = address; }

// Set User Phone Number 
void V_User::set_user_phone(const std::string& phone_number) 
{ 
    if (user_phone_number.size() > 12)
    {
        user_phone_number = "N/A";
        throw std::length_error("Phone Number Must be Valid Length.");
    }
    this->user_phone_number = phone_number; 
}

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

// Access to the Users Kart for Item Manipulation and removing 
Kart& V_User::accessKart() { return this->user_kart; }

// Adding Item to the Kart 
void V_User::add_items_to_kart()
{
    //chars for the input 
    char input1[50], input2[50],input3[5];

    // Get Item information from User
    Log
        "---------------------------------------------------" New_line
        "        Type the item info, then press Enter       " New_line
        "---------------------------------------------------" End;
    Log "Enter Item name: ";            std::cin.ignore(1);   std::cin.get(input1, 50, '\n'); std::cin.ignore(1);
    Log "Enter Item price: ";                                 std::cin.get(input2, 50, '\n'); std::cin.ignore(1);
    Log "Quantity of item: ";                                 std::cin.get(input3, 5, '\n');  std::cin.ignore(1);

    // Variables 
    std::string name = input1;
    float price = atof(input2);
    unsigned int quantity(0);
    quantity = atoi(input3);

    // Create number of item specififed
    // Add the Items to the Users History Stack 
    for (int i = 0; i < quantity; i++) 
    {
        this->user_kart.add_item(name, price);
        std::unique_ptr<Item> tempitem = std::make_unique<Item>(name, price);
        this->user_purchase_history.emplace_back(*tempitem);
    }

    // Clear Screen
    Clear_Screen;

    // Print to console
    Log
        "---------------------------------------------------" New_line
        "               " And name And " Added to Kart."      New_line
        "---------------------------------------------------" End;
 
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(3s);
    Clear_Screen;
}
