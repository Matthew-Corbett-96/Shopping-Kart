#include "Normal_User.h"
#include "Gold_User.h"
#include <Windows.h>
#include "User_Data_Base.h"

// Name Spaces 
using namespace std::chrono_literals;

// Personal Logging Macros
#define Log std::cout << 
#define And << 
#define End << std::endl 
#define Skip std::cout << std::endl 
#define New_line << "\n" << 
#define Clear_Screen std::system("cls")
#define Get std::cin >> 
#define AAnd >>


// Globals--------------------------------------------------------
// keeping track of the current operation taking place
static unsigned short operation(0);
// pointer to current user 
static V_User* p_Current_User = nullptr;
// DataBase of All the Users 
User_Data_Base* User_Data_Base::instance = 0;
User_Data_Base* Storage = User_Data_Base::Access_Data_Base();


// Deffinitions -------------------------------------------------
void start_Screen();
void main_application();
void change_User(bool&);
void create_User(const char& type,const std::string, const std::string, const std::string);
void choose_Operation();
//void add_items(V_User& user); //init user's add func
//void remove_items(V_User& user);
//void get_info(V_User& user);
//void edit_item(V_User& user);
//void print_kart(V_User& user);
//void print_history(V_User& user);
//void check_out(V_User& user);
//void goodbye(); // end application and say goodbye to users 



int main()
{
    try
    {
        // Run Start Screen 
        //start_Screen(); 
        Normal_User user("Matthew", "12 Lorine rd.", "506-546-5263");
        Gold_User otherUser("Bobby Bank", "33 Hopin Hill Ave.", "458-856-4785");
        V_User* pointer = &user;
        V_User* pointer1 = &otherUser;

        // Adding Users
        Storage->add(pointer);
        Storage->add(pointer1);

        // Remove a User 
        Storage->remove("Bobby Bank");

        // Get User to Pointer 
        Storage->get_User("Matthew",p_Current_User);
        Log
            p_Current_User->get_user_name   ()    New_line
            p_Current_User->get_user_address()    New_line
            p_Current_User->get_user_phone  ()    New_line
            p_Current_User->get_Gold_Status ()    End;
        //
        // Run Main Application 
        //main_application(); 
        
        //    switch (operation)
        //    {
        //    case 1:
        //        Clear_Screen;
        //        user.add_items_to_kart();
        //        break;

        //    case 2:
        //        Clear_Screen;
        //        user.get_info();
        //        break;

        //    case 3:
        //        Clear_Screen;
        //        user.print_current_kart();
        //        break;

        //    case 4:
        //        Clear_Screen;
        //        user.check_out();
        //        active_kart = false;
        //        break;

        //    default:
        //        Clear_Screen;
        //        Log "Invalid Number. Must be 1 - 4." End;
        //        break;
        //    }
        //}
    }

    //Error Handeling---------------------------------------------------------------------
    catch (std::invalid_argument error) { Log "Invalid Argument: " And error.what()    End; }
    catch (std::range_error      error) { Log "Range Error: "      And error.what()    End; }
    catch (std::length_error     error) { Log "Length Error: "     And error.what()    End; }
    catch (std::domain_error     error) { Log "Domain Error. "                         End; }
    catch (std::error_code       error) { Log "Other Error: "      And error.message() End; }
    catch (std::out_of_range     error) { Log "Out of Range: "     And error.what()    End; }
    //------------------------------------------------------------------------------------

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
        "-   Type Information followed by '/' -"  New_line
        "--------------------------------------"  End;
    Log "Name         :";                         std::cin.get(input1, 25, '/'); std::cin.ignore(2);
    Log "Address      :";                         std::cin.get(input2, 25, '/'); std::cin.ignore(2);
    Log "Phone Number :";                         std::cin.get(input3, 25, '/'); std::cin.ignore(1);
    Log "Like to be a Gold Member? (y/n): ";      Get input4;

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

// Main Application Loop
void main_application()
{
    // bool keeping track if user is still shopping
    bool still_shopping(true);
    bool active_session(true);

    while (active_session)
    {
        change_User(active_session); 
        while (still_shopping)
        {
            choose_Operation();
            return;
        }
    }
    return;
}

// Choosing a User 
void change_User(bool& active)
{
   
    
    while (true)
    {
        // Print Message to Console 
        Log
            "======================================="     New_line
            "=      Choose a User to Sign into     ="     New_line
            "=       Type the Name of the User     ="     New_line
            "=         Or Press 0 to Exit          ="     New_line
            "======================================="     New_line
            "Users:"                                      End;

        // Show the User the List of Users to Choose from
        int counter(1);
        for (const auto& user : Storage->users)
        {
            Log counter And ".)" And user.first End;
            counter++;
        }

        // get the input and point the correct User to the pointer 
        char user_name[25];
        Log "Name of User: "; std::cin.ignore(1); std::cin.get(user_name, 25, '\n'); std::cin.ignore(1);

        // if user chooses to exit program return 
        if (user_name == "0")
        {
            active = false;
            return;
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

void choose_Operation() 
{
    // Main Menu
    if (p_Current_User->get_Gold_Status())
    {
        Log
            "######################################################"                New_line
            "                 Gold Account: " And p_Current_User->get_user_name()   New_line
            " Type the Number of the Action You Would Like to Take "                New_line
            "######################################################"                End;
    }
    else
    {
        Log
            "======================================================"                New_line
            "                 Account: " And p_Current_User->get_user_name()        New_line
            " Type the Number of the Action You Would Like to Take "                New_line
            "======================================================"                End;
    }
    Log
        "Kart:"                           New_line 
        "1.) Add item to Kart."           New_line
        "2.) Remove Item From Kart"       New_line
        "3.) Get Item Information"        New_line
        "4.) Update Item Information"     New_line
        "5.) Show Kart Status "           New_line
        "6.) Checkout Kart"               New_line
        "User: "                          New_line
        "7.) See User History "           New_line
        "8.) See Profile "                New_line
        "9.) Edit Profile "               New_line
        "Action: "; std::cin.get(); 

    //read input from key board 
    if (GetAsyncKeyState((unsigned short)'0') & 0X8000)
        Log '0' End; 
}



// Commponent Functions --------------------------------------------
// create a user 
void create_User(
    const char& type, const std::string name, const std::string address, const std::string phone_num)
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








