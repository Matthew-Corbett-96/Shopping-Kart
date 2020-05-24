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
        throw std::length_error("Name Can Only Be 25 Characters.\n");
        user_name = "N/A"; 
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
        throw std::length_error("Name Can Only Be 25 Characters.\n");
        user_name = "N/A";
    }
	this->user_kart.set_name(user_name);
}

// Constructor with all data
V_User::V_User(const std::string& name, const std::string& address, const std::string& phone_number)
	: user_name(name), user_address(address), user_phone_number(phone_number) 
{
    if (name.size() > 25)
    {
        throw std::length_error("Name Can Only Be 25 Characters.\n");
        user_name = "N/A";
    }
    if (user_phone_number.size() > 13)
    {
        throw std::length_error("Phone Number Must be Valid Length.\n");
        user_phone_number = "N/A";
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
        throw std::length_error("Name Can Only Be 25 Characters.\n");
        user_name = "N/A";
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
        throw std::length_error("Phone Number Must be Valid Length.\n");
        user_phone_number = "N/A";
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

// Adding Item to the Kart 
void V_User::add_items_to_kart()
{
    //chars for the input 
    char input1[50], input2[50],input3[5];

    // Get Item information from User
    Log
        "---------------------------------------------------" New_line
        "     Type the item's name, followed by a '/'       " New_line
        "---------------------------------------------------" New_line
        "Enter Item name: ";  std::cin.get(input1, 50, '/'); std::cin.ignore(1);
    Log "Enter Item price: "; std::cin.get(input2, 50, '/'); std::cin.ignore(1);
    Log "Quantity of item: "; std::cin.get(input3, 5, '/'); std::cin.ignore(1);

    // Variables 
    std::string name = input1;
    float price = atof(input2);
    unsigned int quantity(0);
    quantity = atoi(input3);

    // Create number of item specififed
    for (int i = 0; i < quantity; i++) this->user_kart.add_item(name, price);

    // Add the Items to the Users History Stack 
    for (int i = 0; i < quantity; i++) 
    {
        std::unique_ptr<Item> tempitem = std::make_unique<Item>(name, price);
        this->user_purchase_history.emplace_back(*tempitem);
    }

    // Clear Screen
    Clear_Screen;

    // Print to console
    Log
        "---------------------------------------------------" New_line
        "                  " And name And " Added to Kart."   New_line
        "---------------------------------------------------" End;
 
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(3s);
    Clear_Screen;
}
