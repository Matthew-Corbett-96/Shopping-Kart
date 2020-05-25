#pragma once 

#include <iostream> 
#include <string> 
#include <iomanip>
#include <exception>
#include <stdexcept>

class Item
{
private:
    // Name of item 
    std::string item_name = "N/A";
    // Price of Item 
    float item_price = 0.00f;

public:
    // Constructors
    Item();
    Item(std::string, float);
    Item(const Item&);
    Item(const std::unique_ptr<Item>&);

    // Destructor
    ~Item();

    // Print Item
    void print_Item() const;

    // Setters 
    void set_name (const std::string&);
    void set_price(const float&);

    // Getters 
    const std::string get_name () const;
    const float       get_price() const;

    // Operator overloading 
    Item& operator= (const Item& item);
    bool  operator> (const Item& item);
    bool  operator< (const Item& item);
    bool  operator==(const Item& item);

    // Friends with Kart Class 
    friend class Kart;
};

