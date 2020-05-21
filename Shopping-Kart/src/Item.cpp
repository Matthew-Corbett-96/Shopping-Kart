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
Item::Item() {}

// Normal Constructor 
Item::Item(std::string m_name, float m_price)
    :item_name(m_name), item_price(m_price)
{
    if (m_name.length() > 25) throw std::invalid_argument("Name of Items Cannot be Greater Than 25 Characters.\n");
    if (m_price < 0.00f) throw std::invalid_argument("Price of Items Cannot be Negative.\n");
}

// Copy Constructor 
Item::Item(const Item& other_item)
{
    this->item_name = other_item.item_name;
    this->item_price = other_item.item_price;
}

// Copy Constructor w/ Unique Pointers 
Item::Item(const std::unique_ptr<Item>& item)
{
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
    std::cout << std::setprecision(2) << std::fixed;
    std::cout << "----------\n";
    std::cout << "Item: " << get_name() << "\nPrice: $" << get_price() << "\n";
    std::cout << "----------\n";
}

// Setters---------------------------------
//-----------------------------------------
//-----------------------------------------
//-----------------------------------------

// Set Item Name 
void Item::set_name(const std::string& m_name)
{
    if (m_name.length() > 25) throw std::invalid_argument("Length of Name Cannot be More Than 25 characters\n");
    item_name = m_name;
}

// Set Item Price 
void Item::set_price(const float& price)
{
    if (price < 0.00f) throw std::invalid_argument("Price Cannot be Negative.\n");
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