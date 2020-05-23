#include "Kart.h"
#include "Normal_User.h"
#include <stdlib.h>

// Personal Logging Macros
#define Log std::cout << 
#define And << 
#define End << std::endl 
#define Skip std::cout << std::endl 
#define New_line << "\n" << 
#define Clear_Screen std::system("cls")
#define Get std::cin >> 
#define AAnd >>

// Function declorations----------------
void add_items_to_kart(Kart&);
void get_item_info    (Kart&);
void check_out_kart   (Kart&);
//--------------------------------------

int main()
{
    try
    {
        //  Vars Needed to create Profile 
        char input[25];
        std::string name, adress, phone_number; 
        bool active_kart = true;

        // Clear Screen for Application
        Clear_Screen;

        // Opening Screen 
        Log
            "--------------------------------------"  New_line
            "-Welcome to Matty J's Online Shoping!-"  New_line
            "-      Lets set up your profile.     -"  New_line
            "-    First Type in your name below.  -"  New_line
            "--------------------------------------"  New_line
            "Name: "; std::cin.get(input, 25);        Skip;
        name = input;
        Normal_User user(name);
        Clear_Screen;

        // Operation Screen 
        Log
            "------------------------------------------------------"  New_line
            "        Account Created for " And name                   New_line
            "Type the number of the operation you would like to do:"  New_line
            "------------------------------------------------------"  End;

        // While Kart is Active: This will loop until User Checks Out 
        while (active_kart)
        {
            int operation(0);
            // Main Menu
            Log
                "1.) Add item to Kart."           New_line
                "2.) Retrive Item Information."   New_line
                "3.) Print out Kart status."      New_line
                "4.) Checkout Kart."              New_line
                "Action: "; Get operation;        Skip;

            switch (operation)
            {
            case 1:
                Clear_Screen;
                user.add_items_to_kart();
                break;

            case 2:
                Clear_Screen;
                get_item_info(user.user_kart));
                break;

            case 3:
                Clear_Screen;
                user.user_kart.print_kart();
                break;

            case 4:
                Clear_Screen;
                check_out_kart(user.user_kart);
                active_kart = false;
                break;

            default:
                Clear_Screen;
                Log "Invalid Number. Must be 1 - 4." End;
                break;
            }
        }
    }

    // Error Handeling -------------------------------------------------------------------
    catch (std::invalid_argument error) { Log "Invalid Argument: " And error.what() End; }
    catch (std::range_error      error) { Log "Range Error: "      And error.what() End; }
    catch (std::length_error     error) { Log "Length Error: "     And error.what() End; }
    catch (...) { Log "Other Error: "      End; }
    //------------------------------------------------------------------------------------

    return 0;
}



// Get information on items in Kart
void get_item_info(Kart& kart)
{
    // Get the index and the information wanted from user then use Karts info method
    int todo(0), index(0);

    Log
        "---------------------------------------------------"              New_line
        "Type the Index of what item in your Kart you want: "; Get index;  Skip;

    Log
        "---------------------------------------------------"              New_line
        "Name(0), Price(1), or Both(2): "; Get todo;

    // Clear console
    Clear_Screen;

    switch (todo)
    {
        // The information based on users preference 
    case 0:
        Log
            "------------------------"                    New_line
            "Item Name: " And kart.get_item_name(index)   New_line
            "------------------------"                    End;
        break;
    case 1:
        Log
            "------------------------"                    New_line
            "Item Price: " And kart.get_item_price(index) New_line
            "------------------------"                    End;
        break;
    case 2:
        kart.get_item(index).print_Item();
        break;
    }
}

// Kart Checkout Function
void check_out_kart(Kart& kart)
{
    // Get Distance from User then run Kart Classes checkout method 
    float distance;
    Log "Enter Distance in Miles: "; Get distance;
    Clear_Screen;
    kart.check_out(distance);
}