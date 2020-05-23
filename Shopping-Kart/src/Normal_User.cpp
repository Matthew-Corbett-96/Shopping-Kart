#include "Normal_User.h"

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
// ----------------------------------------

// Default Constructor
Normal_User::Normal_User() {}

// Constructor with User Name
Normal_User::Normal_User(const std::string& name)
	: V_User(name) {}

// Constructor with Name and Address 
Normal_User::Normal_User(const std::string& name, const std::string& address)
	: V_User(name, address) {}

// Constructor with all attributes needed 
Normal_User::Normal_User(const std::string& name, const std::string& address, const std::string& phone_number)
	: V_User(name, address, phone_number) {}

// Destructors-----------------------------
//-----------------------------------------
//-----------------------------------------
//-----------------------------------------

// Default Destructor
Normal_User::~Normal_User() {}


// Print User's History to the console 
void Normal_User::get_user_history() const
{
	// TBT 
}

