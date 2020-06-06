#include "Item.h"

// Personal Logging Macros-----------------
//-----------------------------------------
//-----------------------------------------
//-----------------------------------------
#define Log std::cout << 
#define And << 
#define End << "\n" 
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
Item::Item() 
{
    // Time Stamp
    using namespace std::chrono;
    system_clock::time_point end = system_clock::now();
    time_t end_time = system_clock::to_time_t(end);
    ctime_s(time_created, sizeof time_created, &end_time);
    for (int i = 0; i < 26; i++)
    {
        if (time_created[i] == '\n')
            time_created[i] = '.';
    }
}

// Normal Constructor 
Item::Item(std::string m_name, float m_price)
    :item_name(m_name), item_price(m_price)
{
    // Time Stamp
    using namespace std::chrono; 

    system_clock::time_point end = system_clock::now();
    time_t end_time = system_clock::to_time_t(end);
    ctime_s(this->time_created, sizeof time_created, &end_time);
    for (int i = 0; i < 26; i++)
    {
        if (time_created[i] == '\n')
            time_created[i] = '.';
    }
    // ---------------------------------------------------
    if (m_name.length() > 25)
    {
        item_name = "N/A";
        throw std::invalid_argument("Name of Items Cannot be Greater Than 25 Characters.");
    }

    if (m_price < 0.00f)
    {
        item_price = 0.00f;
        throw std::invalid_argument("Price of Items Cannot be Negative.");
    }
}

// Copy Constructor 
Item::Item(const Item& other_item)
{
    // Time Stamp
    using namespace std::chrono;
    system_clock::time_point end = system_clock::now();
    time_t end_time = system_clock::to_time_t(end);
    ctime_s(time_created, sizeof time_created, &end_time);
    for (int i = 0; i < 26; i++)
    {
        if (time_created[i] == '\n')
            time_created[i] = '.';
    }
    // --------------------------------------
    this->item_name = other_item.item_name;
    this->item_price = other_item.item_price;
}

// Copy Constructor w/ Unique Pointers 
Item::Item(const std::unique_ptr<Item>& item)
{
    // Time Stamp
    using namespace std::chrono;
    system_clock::time_point end = system_clock::now();
    time_t end_time = system_clock::to_time_t(end);
    ctime_s(time_created, sizeof time_created, &end_time);
    for (int i = 0; i < 26; i++)
    {
        if (time_created[i] == '\n')
            time_created[i] = '.';
    }
    // -------------------------------------
    this->item_name = item->item_name;
    this->item_price = item->item_price;
}

// Destructor---------------------------------
//--------------------------------------------
//--------------------------------------------
//--------------------------------------------

// Default Destructor
Item::~Item() {}

// Print Item
void Item::print_Item() const
{
    // Set the Decimal Point in the Printing 
    Log std::setprecision(2) And std::fixed;

    Log
        "---------------------------------------"  New_line
        "    Item : " And get_name()               New_line
        "    Price: $" And get_price()             New_line
        "    Time : " And get_time()               New_line
        "---------------------------------------"  End;
}

// Setters---------------------------------
//-----------------------------------------
//-----------------------------------------
//-----------------------------------------

// Set Item Name 
void Item::set_name(const std::string& m_name)
{
    // If length is too large then Throw Error 
    if (m_name.length() > 25)
        throw std::invalid_argument("Length of Name Cannot be More Than 25 characters");
    item_name = m_name;
}

// Set Item Price 
void Item::set_price(const float& price)
{
    // If the Price is negative then throw Error 
    if (price < 0.00f) 
        throw std::invalid_argument("Price Cannot be Negative.");
    item_price = price;
}

// Getters---------------------------------
//-----------------------------------------
//-----------------------------------------
//-----------------------------------------

// Get Item Name 
const std::string Item::get_name() const { return this->item_name; }

// Get Item Price 
const float Item::get_price() const { return this->item_price; }

// Get Time Created 
const std::string Item::get_time() const { return this->time_created; }

// Overloaded Operations -------------------
//------------------------------------------
//------------------------------------------
//------------------------------------------

// Assignment Operator 
Item& Item::operator=(const Item& item)
{
    this->item_name = item.item_name;
    this->item_price = item.item_price;
    return *this;
}

// Greater Than Operator // compares the item.item_price 
bool Item::operator>(const Item& item)
{
    if (this->item_price > item.item_price) return true;
    return false;
}

// Less Than Operator // compares the item.item_price 
bool Item::operator<(const Item& item)
{
    if (this->item_price < item.item_price) return true;
    return false;
}

// Equal to Operator // compares the item.item_price 
bool Item::operator==(const Item& item)
{
    if (this->item_price == item.item_price) return true;
    return false;
}