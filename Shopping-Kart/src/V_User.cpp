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
	: user_name(name) {}

// Constructor with name and adress 
V_User::V_User(const std::string& name, const std::string& address)
	: user_name(name), user_address(address) {}

// Constructor with all data
V_User::V_User(const std::string& name, const std::string& address, const std::string& phone_number)
	: user_name(name),user_address(address), user_phone_number(phone_number) {}

// Destructors-----------------------------
//-----------------------------------------
//-----------------------------------------
//-----------------------------------------

// Default Destructor 
V_User::~V_User() {}