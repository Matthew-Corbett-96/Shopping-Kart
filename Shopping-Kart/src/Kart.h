#pragma once

#include <vector>
#include <memory>
#include "Item.h"

class Kart
{
private:
    // Name of Kart // Optional
    std::string kart_name = "Kart";
    // List of Items
    std::vector<Item> shoping_list;

protected:
    // Number of Items in List
    unsigned int list_length = 0;

public:
    // Constructors
    Kart();
    Kart(std::string);
    Kart(std::string, Item);
    Kart(Item);
    Kart(const Kart&);

    // Destructors
    ~Kart();

    // Getters
    const Item&        get_item      (int) const;
    const float        get_item_price(int) const;
    const std::string  get_item_name (int) const;
    const unsigned int length        (   ) const;

    // Setters
    void set_name(const std::string&);
    void add_item(const std::string&, const float&);
    void add_item(const Item&);

    // Remover
    void remove_item(const int);

    // Calculate Total Price
    void check_out(const float&) const;

    // Print Kart
    void print_kart() const;

    // Friend Class is Item
    friend class Item;
};
