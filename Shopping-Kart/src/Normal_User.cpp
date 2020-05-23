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

// Specialty Functions---------------------
//-----------------------------------------
//-----------------------------------------
//-----------------------------------------

// Print User's History to the console // override
void Normal_User::print_user_history() const { for(const auto& item : user_purchase_history) item.print_Item(); }

// Get Kart Information // override
void Normal_User::get_info() const
{
    // Get the index and the information wanted from user then use Karts info method
    int todo(0), index(0);

    Log
        "---------------------------------------------------"              New_line
        "Type the Index of what item in your Kart you want: "; Get index;  Skip;

    // Clear console
    Clear_Screen;
    this->user_kart.get_item(index).print_Item();
}

// Check Out Kart and Clear the Kart //override
void Normal_User::check_out()
{
	// Get Distance from User then run Kart Classes checkout method 
	float distance;
	Log "Enter Distance in Miles: "; Get distance;
	Clear_Screen;
	this->user_kart.check_out(distance);
}

//Print User's Kart 
void Normal_User::print_current_kart() const
{
	// Uses the Standard printing function that comes with the kart object
	this->user_kart.print_kart();
}
