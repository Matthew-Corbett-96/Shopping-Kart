#include "Normal_User.h"
#include "Gold_User.h"
#include "User_Data_Base.h"

// Name Spaces -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
using namespace std::chrono_literals;
using namespace std::chrono;

// Personal Logging Macros -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
#define Log std::cout <<
#define And <<
#define End << "\n"
#define Skip std::cout << "\n"
#define New_line << "\n" <<
#define Clear_Screen std::system("cls")
#define Get std::cin >>
#define AAnd >>

// Globals -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  // keep track if user is still shopping
static bool still_shopping(true), active_session(true);
// pointer to current user
static V_User* p_Current_User(nullptr);
// DataBase of All the Users
User_Data_Base* User_Data_Base::instance = 0;
User_Data_Base* Storage = User_Data_Base::Access_Data_Base();

// Deffinitions -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
void start_Screen();
void change_User();
void create_User(const char& type,const std::string, const std::string, const std::string);
void remove_User();
void user_Profile();
void choose_Operation();
void print_options();
void remove_items();
//void edit_item(V_User& user);
void goodbye_Screen();
void display_kart();

// Main Application -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
int main()
{
    try
    {
        // Run Start Screen
        start_Screen();
        while (active_session)
        {
            // Select User or create user then direct back to select User
            change_User();
            if (active_session == false) break;
            // Run Operations Window Loop
            choose_Operation();
        }
        // Run Goodbye Screen
        goodbye_Screen();
    }
    //Error Handeling------------------------------------------------------------------------
    catch (std::invalid_argument error) { Log "Invalid Argument: " And error.what()    End; }
    catch (std::range_error      error) { Log "Range Error: "      And error.what()    End; }
    catch (std::length_error     error) { Log "Length Error: "     And error.what()    End; }
    catch (std::domain_error     error) { Log "Domain Error. "                         End; }
    catch (std::error_code       error) { Log "Other Error: "      And error.message() End; }
    catch (std::out_of_range     error) { Log "Out of Range: "     And error.what()    End; }
    //---------------------------------------------------------------------------------------
    return 0;
}


// Main UX && UI Functions -----------------------------------------

// Welcome User and Create Profile
void start_Screen()
{
    // Variables to recieve input and create the account
    char input1[25], input2[25], input3[25], input4;
    std::string name, address, phone_number;

    // Clear Screen for Application
    Clear_Screen;

    // Opening Screen
    Log
        "--------------------------------------"  New_line
        "-Welcome to Matty J's Online Shoping!-"  New_line
        "-      Lets set up your profile.     -"  New_line
        "--------------------------------------"  End;
    Log "Name         :";                         std::cin.get(input1, 25, '\n'); std::cin.ignore(1);
    Log "Address      :";                         std::cin.get(input2, 25, '\n'); std::cin.ignore(1);
    Log "Phone Number :";                         std::cin.get(input3, 25, '\n'); std::cin.ignore(1);
    Log "Like to be a Gold Member? (y/n): ";      Get input4; std::cin.ignore(1);

    // Assign input to temp vars // Stack Allocated
    name = input1;
    address = input2;
    phone_number = input3;

    // Create the User and push to container
    create_User(input4, name, address, phone_number);

    // Clear Screen
    Clear_Screen;

    // Confirmation Screen
    if (input4 == 'y')
    {
        Log
            "######################################################"  New_line
            "           Gold Account Created For " And name           New_line
            "######################################################"  End;
    }
    else
    {
        Log
            "------------------------------------------------------"  New_line
            "            Account Created For " And name               New_line
            "------------------------------------------------------"  End;
    }

    // Wait 3 seconds then clear the screen
    std::this_thread::sleep_for(5s);
    Clear_Screen;
}

// Main Menu Operations
void choose_Operation()
{
    // For when it is the 2nd User to enter the Application
    still_shopping = true;
    // Choose Print Screen Based on if User is Gold Status
    print_options();

    // Waiting for User Input
    while (still_shopping)
    {
        // Read input from key board, clear the screen,
        // And then go to apropriet screen

        // User Exits Shopping && Goes to User menu
        if (GetAsyncKeyState((unsigned short)'0') & 0X8000)
        {
            Clear_Screen;
            still_shopping = false;
        }

        // launch adding items
        if (GetAsyncKeyState((unsigned short)'1') & 0X8000)
        {
            Clear_Screen;
            p_Current_User->add_items_to_kart();
            print_options();
        }

        // launch remove item
        if (GetAsyncKeyState((unsigned short)'2') & 0X8000)
        {
            Clear_Screen;
            remove_items(); // TODO: Needs to be moved to Users Class 
            print_options();
        }

        // launch item info
        if (GetAsyncKeyState((unsigned short)'3') & 0X8000)
        {
            Clear_Screen;
            p_Current_User->get_info();
            print_options();
        }

        // print kart
        if (GetAsyncKeyState((unsigned short)'4') & 0X8000)
        {
            Clear_Screen;
            display_kart(); // TODO: needs to be moved to the Users Class 
            print_options();
        }

        // Check Out
        if (GetAsyncKeyState((unsigned short)'5') & 0X8000)
        {
            Clear_Screen;
            p_Current_User->check_out();
            print_options();
        }

        // See Shopping History
        if (GetAsyncKeyState((unsigned short)'6') & 0X8000)
        {
            Clear_Screen;
            p_Current_User->print_user_history();
            print_options();
        }

        // Launch Profile Page
        if (GetAsyncKeyState((unsigned short)'7') & 0X8000)
        {
            Clear_Screen;
            user_Profile();
            print_options();
        }

    } // End of While Loop

}

// Goodbye Message
void goodbye_Screen()
{
    // Clear the Screen
    Clear_Screen;
    // goodbye Message
    Log
        "======================================================="  New_line
        "=Thanks For Shopping With Matty J's Online Shoopping !="  New_line
        "=            Hope to see you Real Soon !              ="  New_line
        "======================================================="  End;
    // pause for 3 seconds
    std::this_thread::sleep_for(3s);
}

// Commponent Functions --------------------------------------------

// create a user
void create_User(const char& type, const std::string name, const std::string address, const std::string phone_num)
{
    // Currently Using Raw Pointers --> will need to be fixed lator
    if (type == 'y')
    {
        V_User* user = new Gold_User(name, address, phone_num);
        Storage->add(user);
    }
    else
    {
        V_User* user = new Normal_User(name, address, phone_num);
        Storage->add(user);
    }
}
// Prints the Options Menu in the in Choose operations Tab
void print_options()
{
    if (p_Current_User->get_Gold_Status())
    {
        Log
            "######################################################"                New_line
            "                 Gold Account: " And p_Current_User->get_user_name()   New_line
            " Type the Number of the Action You Would Like to Take "                New_line
            "              Or Press \"0\" to Sign Out              "                New_line
            "######################################################"                End;
    }
    else
    {
        Log
            "======================================================"                New_line
            "                 Account: " And p_Current_User->get_user_name()        New_line
            " Type the Number of the Action You Would Like to Take "                New_line
            "              Or Press \"0\" to Sign Out              "                New_line
            "======================================================"                End;
    }
    Log
        "Kart:"                           New_line
        "1.) Add item to Kart"            New_line
        "2.) Remove Item From Kart"       New_line
        "3.) Item Information"            New_line
        "4.) See My Kart"                 New_line
        "5.) Checkout"                    New_line
        "User: "                          New_line
        "6.) Your Shopping History "      New_line
        "7.) Your Profile "               New_line
        "Action: ";
}
// Remove items from Active Kart
void remove_items()
{
    // Create index var
    int index(0);

    // UI Here
    Log
        "======================================================"  New_line
        "=   Type the Index of the Item You Wish To Remove.   ="  New_line
        "======================================================"  End;
    p_Current_User->print_current_kart();
    Log "Index: "; Get index; std::cin.ignore(1);

    // Access Kart
    p_Current_User->accessKart().remove_item(index);

    // Clear the Screen
    Clear_Screen;

    // Confirmation Screen
    Log
        "======================================================"  New_line
        "=                Item Has Been Remove.               ="  New_line
        "======================================================"  End;

    // Pause 3 Seconds then clear screen again
    std::this_thread::sleep_for(3s);
    Clear_Screen;
}
// Choosing a User
void change_User()
{
    while (true)
    {
        // Print Message to Console
        Log
            "======================================="     New_line
            "=    To Choose a User to Sign into    ="     New_line
            "=       Type the Name of the User     ="     New_line
            "=   Type \"New\" to Create a New User   ="   New_line
            "=   Type \"Remove\" to Delete a User    ="   New_line
            "=         Type \"Exit\" to Exit         ="   New_line
            "======================================="     New_line
            "Users:"                                      End;

        // Show the User the List of Users to Choose from
        int counter(1);
        for (const auto& user : Storage->users)
        {
            Log " " And counter And ".)" And user.first End;
            counter++;
        }

        // get the input and point the correct User to the pointer
        char user_n[25];
        Log "Name of User: "; std::cin.get(user_n, 25, '\n'); std::cin.ignore(1);

        std::string user_name = user_n;
        // if user chooses to exit program return
        if (user_name == "Exit")
        {
            active_session = false;
            break;
        }

        // if user chooses to create new user
        if (user_name == "New")
        {
            start_Screen();
            continue;
        }

        // if user chooses to remove a user
        if (user_name == "Remove")
        {
            remove_User();
            continue;
        }

        // Check if a Valid User : if not then try again
        if (Storage->users.count(user_name))
        {
            Storage->get_User(user_name, p_Current_User);
            break;
        }
        else
        {
            Log "User Dose Not Exist." End;
            std::this_thread::sleep_for(3s);
            Clear_Screen;
            continue;
        }
    }
    //clear screen and return
    Clear_Screen;
}
// Displaying Kart to User Interface
void display_kart()
{
    p_Current_User->print_current_kart();
    Log "Press \"Q\" to Continue" End;
    while (true)
    {
        if (GetAsyncKeyState((unsigned short)'Q') && 0x8000)
        {
            Clear_Screen;
            return;
        }
    }
}
// User Profile Interface
void user_Profile()
{
    bool active = true;
    while (active)
    {
        p_Current_User->print_profile();
        // Wait for user to press the correct Key
        while (true)
        {
            // change Name
            if (GetAsyncKeyState((unsigned short)'1') && 0x8000)
            {
                char name[25];
                Clear_Screen;
                Log
                    "======================================================"    New_line
                    "                    Enter New Name                    "    New_line
                    "======================================================"    End;

                Log "Name: ";  std::cin.get(name, 25, '\n'); std::cin.ignore(1);
                std::string s_name = name;
                p_Current_User->set_user_name(s_name);

                Clear_Screen;
                Log
                    "======================================================"    New_line
                    "         New User Name is " And s_name                     New_line
                    "======================================================"    New_line
                    "Press \"Q\" to continue"                                   End;

                while (true)
                {
                    if (GetAsyncKeyState((unsigned short)'Q') && 0X8000)
                        break;
                }
                Clear_Screen;
                break;
            }
            // change Adress
            if (GetAsyncKeyState((unsigned short)'2') && 0x8000)
            {
                char address[25];
                Clear_Screen;

                Log
                    "======================================================"    New_line
                    "                    Enter New Address                 "    New_line
                    "======================================================"    End;

                Log "Address: ";  std::cin.get(address, 25, '\n'); std::cin.ignore(1);
                std::string s_address = address;
                p_Current_User->set_user_address(s_address);

                Clear_Screen;
                Log
                    "======================================================"    New_line
                    "         New User Address is " And s_address               New_line
                    "======================================================"    New_line
                    "Press \"Q\" to continue"                                   End;

                while (true)
                {
                    if (GetAsyncKeyState((unsigned short)'Q') && 0X8000)
                        break;
                }
                Clear_Screen;
                break;
            }
            // Change Phone Number
            if (GetAsyncKeyState((unsigned short)'3') && 0x8000)
            {
                char phone[25];
                Clear_Screen;

                Log
                    "======================================================"    New_line
                    "                    Enter New Number                  "    New_line
                    "======================================================"    End;

                Log "Name: ";  std::cin.get(phone, 25, '\n'); std::cin.ignore(1);
                std::string s_phone = phone;
                p_Current_User->set_user_phone(s_phone);

                Clear_Screen;
                Log
                    "======================================================"    New_line
                    "         New User Number is " And s_phone                  New_line
                    "======================================================"    New_line
                    "Press \"Q\" to continue"                                   End;

                while (true)
                {
                    if (GetAsyncKeyState((unsigned short)'Q') && 0X8000)
                        break;
                }

                Clear_Screen;
                break;
            }
            // Clear Purchase History
            if (GetAsyncKeyState((unsigned short)'4') && 0x8000)
            {
                Clear_Screen;
                p_Current_User->clear_history();
                Log "======================================================"  New_line
                    "             User Purchase Histroy Cleared            "  New_line
                    "======================================================"  End;
                std::this_thread::sleep_for(3s);
                Clear_Screen;
                break;
            }
            // Exit
            if (GetAsyncKeyState((unsigned short)'5') && 0x8000)
            {
                // Set bool to false to stop the loop
                Clear_Screen;
                active = false;
                break;
            }
        }
    }
    Clear_Screen;
}

// Remove a user from the data base and then call the destructor 
void remove_User() 
{
    Clear_Screen;
    while (true)
    {
        // Promt to type name
        char n_name[25];
        std::string name;
        Log
            "======================================================" New_line
            "    Type the name of the user you wish to remove      " New_line
            "======================================================" End;
        // Show the User the List of Users to Choose from
        int counter(1);
        for (const auto& user : Storage->users)
        {
            Log " " And counter And ".)" And user.first End;
            counter++;
        }

        // Get name of user 
        Log "Name: "; std::cin.get(n_name, 20, '\n'); std::cin.ignore(1);
        name = n_name;

        // Check if a Valid User : if not then try again
        if (Storage->users.count(name))
        {
            Storage->get_User(name, p_Current_User); 
            Clear_Screen;
            // Call on Database to remove user from Database 
            Storage->remove(name);
            p_Current_User = nullptr;

            Log
                "======================================================" New_line
                "    User \" " And n_name And "\" has been removed.    " New_line
                "======================================================" New_line
                "Press \"Q\" to Continue"                                End;
            while (true)
            {
                if (GetAsyncKeyState((unsigned short)'Q') && 0x8000)
                {
                    Clear_Screen;
                    return;
                }
            }
        }
        else
        {
            Log "Invalid Name. Try Again." End;
            std::this_thread::sleep_for(3s);
            Clear_Screen;
            continue;
        }
    }
  
    
}