#pragma once 

#include <iostream>  // output to console 
#include <string>    // use std::string type
#include <iomanip>   // manipulate the console output 
#include <exception> // exception handeling 
#include <stdexcept> // more modern lib
#include <chrono>    // modern c++ time 
#include <ctime>     // conversion functions for c or c++ 
#include <time.h>    // C time lib for back up 

class Item
{
private:
    // Name of item 
    std::string item_name = "N/A";
    // Price of Item 
    float item_price = 0.00f;
    // Time Created 
    char time_created[26];

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
    const std::string get_time () const; 

    // Operator overloading 
    Item& operator= (const Item& item);
    bool  operator> (const Item& item);
    bool  operator< (const Item& item);
    bool  operator==(const Item& item);

    // Friends with Kart Class 
    friend class Kart;
};

