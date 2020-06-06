#include "Kart.h"


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
Kart::Kart() { shoping_list.reserve(10); }

// Constructor with Name Only 
Kart::Kart(std::string name)
    :kart_name(name) 
{
    // If name is over 25 characters then Throw Error 
    if (name.size() >= 25)
        throw std::invalid_argument("Name cannot be longer than 25 characters");
    shoping_list.reserve(10);
}

// Normal Constructor 
Kart::Kart(std::string name, Item item)
    : kart_name(name), list_length(1)
{
    // If name is over 25 characters then Throw Error 
    if (name.size() >= 25)
        throw std::invalid_argument("Name cannot be longer than 25 characters");
    shoping_list.reserve(10);
    shoping_list.emplace_back(item);
}

// Constructor with Item 
Kart::Kart(Item item)
    : list_length(1)
{
    shoping_list.reserve(10);
    shoping_list.emplace_back(item);
}

// Copy Constructor 
Kart::Kart(const Kart& kart)
{
    this->list_length = kart.list_length;
    this->kart_name = kart.kart_name;
    shoping_list.reserve(10);
    for (const auto item : kart.shoping_list) 
        shoping_list.emplace_back(item);
}

// Destructors-----------------------------
//-----------------------------------------
//-----------------------------------------
//-----------------------------------------

// Default Destructor 
Kart::~Kart() {}

// Getters---------------------------------
//-----------------------------------------
//-----------------------------------------
//-----------------------------------------

// Get Item by Index // starting index: 1
const Item& Kart::get_item(int index) const
{
    // if Kart is empty then throw error
    if (shoping_list.empty()) 
        throw std::length_error("Kart is Empty.");
    // if index is out of range then throw error
    if (index > list_length || index <= 0) 
        throw std::range_error("Item Index is Out of Range.");

    return shoping_list.at(--index);
}

// Get Price of Item by Index // starting index: 1 
const float Kart::get_item_price(int index) const
{
    // if Kart is empty then throw Error 
    if (shoping_list.empty()) 
        throw std::length_error("Kart is Empty.");
    // if index is over the length then return the last element 
    if (index > list_length || index <= 0) 
        throw std::range_error("Item Index is Out of Range.");

    // If index is greater than 1 and less than length--> return item at the proper index 
    return shoping_list.at(--index).get_price();
}

// Get Name of Item by Index // starting index: 1
const std::string Kart::get_item_name(int index) const
{
    // if Kart is empty then return Error
    if (shoping_list.empty()) 
        throw std::length_error("Kart is Empty.");
    // if index is out of Range then Throw Error
    if (index > list_length || index <= 0) 
        throw std::range_error("Item Index is Out of Range.");

    // If index is in Range then return item at the proper index 
    return shoping_list.at(--index).get_name();
}

const unsigned int Kart::length() const { return this->list_length; }

// Setters--------------------------------- 
// ----------------------------------------
// ----------------------------------------
// ----------------------------------------

// Assign Name of Kart
void Kart::set_name(const std::string& name)
{
    //  If name is over 25 chars throw Error 
    if (name.length() > 25) 
        throw std::invalid_argument("Name of Kart Cannot be Greater Than 25 Characters.\n");
    this->kart_name = name;
}

// Add an Item to the Kart List // name and price 
void Kart::add_item(const std::string& name, const float& price)
{
    // Create new item and place into shopping list 
    std::shared_ptr<Item> new_item = std::make_shared<Item>(name, price);
    this->shoping_list.emplace_back(*new_item);
    this->list_length++;
}

// Add an Item to the Kart List // Item 
void Kart::add_item(const Item& item)
{
    // Create new item and place into shopping list 
    std::shared_ptr<Item> new_item = std::make_shared<Item>(item);
    this->shoping_list.emplace_back(*new_item);
    this->list_length++;
}

// Remove Item from the Kart 
void Kart::remove_item(int index)
{
    this->shoping_list.erase(shoping_list.begin() + (--index));
    this->list_length--;
}

// Calculate Total Price   
void Kart::check_out(const float& distance) const
{
    // If the distance is negative throw invalad arg error
    if (distance < 0.00f) 
        throw std::invalid_argument("Distance of Order Cannot Be Negative");

    // If Kart is empty --> Log Message and return 
    if (shoping_list.empty())
    {
        Log "***KART IS EMPTY. Please make a purchase to see your recipt.***" End;
        // Setting the std::cout to round to the 2nd decimal place 
        Log std::fixed And std::setprecision(2);

        // Logging the information 
        Log
            "------------------------"        New_line
            "CHECKING OUT: " And kart_name    New_line
            "------------------------"        New_line
            "Item Total:  " And "$" And 0.00  New_line
            "Tax:         " And "$" And 0.00  New_line
            "Shipping:    " And "$" And 0.00  New_line
            "------------------------"        New_line
            "Total Price: " And "$" And 0.00  New_line
            "------------------------"        End;
        return;
    }

    // sum = total price of all items // _TAX = sales tax // _DISTANCE_FEE = shipping fee per mile
    float sum(0);
    const float _TAX = 0.08f, _DISTANCE_FEE = 0.10f;

    for (auto& item : shoping_list) 
        sum += item.get_price();

    // Setting the std::cout to round to the 2nd decimal place 
    Log std::fixed And std::setprecision(2);

    // Logging the information 
    Log
        "-----------------------------"                            New_line
        "CHECKING OUT: " And kart_name                             New_line
        "-----------------------------"                            New_line
        "Item Total:  " And "$" And sum                            New_line
        "Tax:         " And "$" And(sum * _TAX)                    New_line
        "Shipping:    " And "$" And(distance * _DISTANCE_FEE)      New_line
        "-----------------------------"                            End;

    sum += (sum * _TAX) + (distance * _DISTANCE_FEE);

    Log
        "Total Price: " And "$" And sum     New_line
        "-----------------------------"     End;
}

// Print Kart 
void Kart::print_kart() const
{
    // Counter Var
    int counter(1);

    Log "======================================================"  End;

    // If Kart is Empty --> print message and return
    if (shoping_list.empty())
    {
        Log
            "                    Kart is Empty."                      New_line
            "======================================================"  End;
        return;
    }

    // Call each Items print function from first to last
    for (const auto& item : this->shoping_list)
    {
        Log " Index: " And counter End;
        item.print_Item();
        counter++;
    }

    Log "======================================================"  End;
}