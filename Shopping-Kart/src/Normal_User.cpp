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
Normal_User::Normal_User() 
	: V_User(false) {}

// Constructor with User Name
Normal_User::Normal_User(const std::string& name)
	: V_User(name, false) {}

// Constructor with Name and Address 
Normal_User::Normal_User(const std::string& name, const std::string& address)
	: V_User(name, address, false) {}

// Constructor with all attributes needed 
Normal_User::Normal_User(const std::string& name, const std::string& address, const std::string& phone_number)
	: V_User(name, address, phone_number, false) {}

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

// Get Gold Status 
const bool Normal_User::get_Gold_Status() const { return this->Gold_Status == true; }

// Print User's History to the console // override
void Normal_User::print_user_history() const 
{ 
    Log
        "===================================================" New_line
        "              User Purchase History.               " New_line
        "===================================================" End;

    for (const auto& item : user_purchase_history)
        item.print_Item();

    Log "Press \"Q\" to continue." End;

    // Wait for User to Press Q to continue 
    while (true)
    {
        if (GetAsyncKeyState((unsigned short)'Q') && 0X8000)
        {
            Clear_Screen;
            return;
        }
    }
}

// Get Kart Information // override
void Normal_User::get_info() const
{
    // If Kart is Empty 
    if (this->user_kart.length() == 0)
    {
        Clear_Screen;
        Log
            "==================================================="   New_line
            "                    Kart is Empty                  "   New_line
            "==================================================="   End;

        Log "Press \"Q\" to continue." End;

        // Wait for User to Press Q to continue 
        while (true)
        {
            if (GetAsyncKeyState((unsigned short)'Q') && 0X8000)
            {
                Clear_Screen;
                return;
            }
        }
    }

    // Get the index and the information wanted from user then use Karts info method
    int index(0);
    while (true)
    {
        Log
            "==================================================="    New_line
            "Type the Index of what item in your Kart you want: "    New_line
            "==================================================="    And "\n";
            "Index: "; Get index; std::cin.ignore(1); Skip;

            // If Valid then print to screen // else reloop and try again 
            if (index <= this->user_kart.length())
            {
                Clear_Screen;
                this->user_kart.get_item(index).print_Item();
                Log "Press \"Q\" to continue." End;

                // Wait for User to Press Q to continue 
                while (true)
                {
                    if (GetAsyncKeyState((unsigned short)'Q') && 0X8000)
                    {
                        Clear_Screen;
                        return;
                    }
                }
            }
            else
            {
                Log "Invalid Index. Please Try Again." End;
                using namespace std::chrono_literals;
                std::this_thread::sleep_for(3s);
                Clear_Screen;
                continue;
            }
    }
    
    // Clear console
    Clear_Screen;
}

// Check Out Kart and Clear the Kart //override
void Normal_User::check_out()
{
	// Get Distance from User then run Kart Classes checkout method 
	float distance(0);
    Log "Enter Distance in Miles: "; Get distance; std::cin.ignore(1);
	Clear_Screen;
	this->user_kart.check_out(distance);

    Log "Press \" Q \" to continue." End;

    // Get input from user to exit 
    while (true)
    {
        // insert a press any key to continue here ********************
        if (GetAsyncKeyState((unsigned short)'Q') && 0X8000)
        {
            Clear_Screen;
            return;
        }
    }
}

//Print User's Kart 
void Normal_User::print_current_kart() const
{
	// Uses the Standard printing function that comes with the kart object
	this->user_kart.print_kart();
}
