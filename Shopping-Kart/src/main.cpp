#include "Normal_User.h"
#include "Gold_User.h"
#include "V_User.h"

// Personal Logging Macros
#define Log std::cout << 
#define And << 
#define End << std::endl 
#define Skip std::cout << std::endl 
#define New_line << "\n" << 
#define Clear_Screen std::system("cls")
#define Get std::cin >> 
#define AAnd >>

int main()
{
    try {
        Normal_User normal_User("Matty", "12 Lorine rd.");
        Gold_User gold_User("Dexter");
        gold_User.add_items_to_kart();
    }
    //try
    //{
    //    //  Vars Needed to create Profile // Stack Allocated 
    //    std::unique_ptr<V_User> p_Current_User; // pointer to current user 
    //    char input1[25], input2[25], input3[25], input4;
    //    std::string name, address, phone_number; 
    //    bool active_kart = true;

    //    // Clear Screen for Application
    //    Clear_Screen;

    //    // Opening Screen 
    //    Log
    //        "--------------------------------------"  New_line
    //        "-Welcome to Matty J's Online Shoping!-"  New_line
    //        "-      Lets set up your profile.     -"  New_line
    //        "-    First Type in your name below.  -"  New_line
    //        "--------------------------------------"  End;
    //        Log "Name         :";     std::cin.get(input1, 25, '.'); std::cin.ignore(1);
    //        Log "Address      :";     std::cin.get(input2, 25, '.'); std::cin.ignore(1);
    //        Log "Phone Number :";     std::cin.get(input3, 25, '.'); std::cin.ignore(1);
    //        Log "Would You Like to be a Gold Member? (y/n): "; Get input4; 

    //    // Assign input to temp vars // Stack Allocated 
    //    name = input1;
    //    address = input2; 
    //    phone_number = input3;


    //    //               S O S !!!!!!!!!!!!!!!!!!!!!!
    //    //*********************************************************
    //    // Create User Account // Heap Allocated 
    //   // auto user = create_User(input4);
    //   // user;
    //    //**********************************************************
    //    Normal_User user(name, address, phone_number);


    //    // Clear Screen 
    //    Clear_Screen;

    //    // Confirmation Screen 
    //    if (input4 == 'y')
    //    {
    //        Log
    //            "######################################################"  New_line
    //            "      Gold Account Created For " And name                New_line
    //            "Type the Number of the Operation You Would Like to Do "  New_line
    //            "######################################################"  End;
    //    }
    //    else
    //    {
    //        Log
    //            "------------------------------------------------------"  New_line
    //            "        Account Created For " And name                   New_line
    //            "Type the Number of the Operation You Would Like to Do:"  New_line
    //            "------------------------------------------------------"  End;
    //    }

    //    // Wait 3 seconds then clear the screen 
    //    using namespace std::chrono_literals;
    //    std::this_thread::sleep_for(3s);
    //    Clear_Screen; 

    //    // While Kart is Active: This will loop until User Checks Out 
    //    while (active_kart)
    //    {
    //        int operation(0);
    //        // Main Menu
    //        Log
    //            "1.) Add item to Kart."           New_line
    //            "2.) Retrive Item Information."   New_line
    //            "3.) Print out Kart status."      New_line
    //            "4.) Checkout Kart."              New_line
    //            "Action: "; Get operation;        Skip;

    //        switch (operation)
    //        {
    //        case 1:
    //            Clear_Screen;
    //            user.add_items_to_kart();
    //            break;

    //        case 2:
    //            Clear_Screen;
    //            user.get_info();
    //            break;

    //        case 3:
    //            Clear_Screen;
    //            user.print_current_kart();
    //            break;

    //        case 4:
    //            Clear_Screen;
    //            user.check_out();
    //            active_kart = false;
    //            break;

    //        default:
    //            Clear_Screen;
    //            Log "Invalid Number. Must be 1 - 4." End;
    //            break;
    //        }
    //    }
    //}

    // Error Handeling -------------------------------------------------------------------
    catch (std::invalid_argument error) { Log "Invalid Argument: " And error.what() End; }
    catch (std::range_error      error) { Log "Range Error: "      And error.what() End; }
    catch (std::length_error     error) { Log "Length Error: "     And error.what() End; }
    catch (...)                         { Log "Other Unidentified Error."           End; }
    //------------------------------------------------------------------------------------

    return 0;
}

// create user 
//const std::shared_ptr<V_User> create_User(const char& type)
//{
//    if (type == 'y')
//    {
//        std::shared_ptr<Gold_User> user = std::make_shared<Gold_User>();
//        return user;
//    }
//    else
//    {
//        std::shared_ptr<Normal_User> user = std::make_shared<Normal_User>();
//        return user; 
//    }
//}