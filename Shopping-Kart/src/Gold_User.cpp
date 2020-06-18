#include "Gold_User.h"

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
Gold_User::Gold_User()
    :V_User(true) {}

// Constructor with User Name
Gold_User::Gold_User(const std::string& name)
	: V_User(name, true) {}

// Constructor with Name and Address 
Gold_User::Gold_User(const std::string& name, const std::string& address)
	: V_User(name, address, true) {}

// Constructor with all attributes needed 
Gold_User::Gold_User(const std::string& name, const std::string& address, const std::string& phone_number)
	: V_User(name, address, phone_number, true) {}

// Destructors-----------------------------
//-----------------------------------------
//-----------------------------------------
//-----------------------------------------

// Default Destructor
Gold_User::~Gold_User() {}

// Get Gold Status 
const bool Gold_User::get_Gold_Status() const { return this->Gold_Status == true; }

// Specialty Functions---------------------
//-----------------------------------------
//-----------------------------------------
//-----------------------------------------

// Print User's History to the console // override
void Gold_User::print_user_history() const 
{ 
    Log
        "###################################################" New_line
        "              User Purchase History.               " New_line
        "###################################################" End;

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
void Gold_User::get_info() const
{
    // If Kart is Empty 
    if (this->user_kart.length() == 0)
    {
        Clear_Screen;
        Log
            "###################################################"   New_line
            "              Kart is Empty                        "   New_line
            "###################################################"   End;

        using namespace std::chrono_literals;
        std::this_thread::sleep_for(3s);
        Clear_Screen;
        return;
    }

	// Get the index and the information wanted from user then use Karts info method
    int index(0);
    while (true)
    {
        Log
            "###################################################"    New_line
            "Type the Index of what item in your Kart you want: "    New_line
            "###################################################"    And "\n";
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
}

// Check Out Kart and Clear the Kart //override
void Gold_User::check_out()
{
	// Using the Chrono Lib to get seconds // Using Thread for sleep_for 
	using namespace std::chrono_literals;

	Log
		"###################################################" New_line
		"|           Gold Members Get Free Shipping!       |" New_line
		"###################################################" End;
	std::this_thread::sleep_for(3s);
	Clear_Screen;
	this->user_kart.check_out(0);
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
void Gold_User::print_current_kart() const
{
	// Uses the Standard printing function that comes with the kart object
	this->user_kart.print_kart();
}

// Adding Item to the Kart 
void Gold_User::add_items_to_kart()
{
    char input1[50], input2[50], input3[5];
    

    // Get Item information from User
    Log
        "###################################################" New_line
        "|           Type the Item's Information.          |" New_line
        "###################################################" End;
    Log "Enter Item name: ";                                  std::cin.get(input1, 50, '\n'); std::cin.ignore(1);
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
        "###################################################" New_line
        "               " And name And " Added to Kart.     " New_line
        "###################################################" End;

    using namespace std::chrono_literals;
    std::this_thread::sleep_for(3s);
    Clear_Screen;
}