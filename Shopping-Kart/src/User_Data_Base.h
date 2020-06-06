#pragma once

// Libs 
#include "Gold_User.h"
#include "Normal_User.h"
#include <unordered_map>

// Personal Logging Macros
#define Log std::cout << 
#define And << 
#define End << std::endl 
#define Skip std::cout << std::endl 
#define New_line << "\n" << 
#define Clear_Screen std::system("cls")
#define Get std::cin >> 
#define AAnd >>

// Singleton User Data Base 
class User_Data_Base
{
protected:

    // instance 
    static User_Data_Base* instance;

    // Private Vars 
    unsigned int length = 0;
    bool empty = true;

    //Constructor 
    User_Data_Base() { users.reserve(100); }

    // Destructor 
    ~User_Data_Base()
    {
        for (auto user : users)
            delete user.second;
    }

public:

    // Public Vars 
    std::unordered_map<std::string, V_User*> users;

    // Getters 
    static User_Data_Base* Access_Data_Base()
    {
        if (instance == 0)
            instance = new User_Data_Base;
        return instance;
    }

    void get_User(std::string name, V_User*& user_needed) const
    {
        if (users.count(name))
        {
            user_needed = users.at(name);
            return;
        }
        Log "User Not Found. Try Again." End;
    }

    unsigned int size() const { return length; }

    bool is_empty() const { return empty; }

    // Helpers 
    void add(V_User* new_user)
    {
        users.emplace(new_user->get_user_name(), new_user);
        //switch empty to false if true
        if (empty == true)
            empty = false;
        length++;
    }

    void remove(std::string old_user_name)
    {
        if (users.count(old_user_name))
        {
            users.erase(old_user_name);
            length--;
            if (length == 0)
                empty = true;
            return;
        }
        Log "User Does Not Exist." End;
    }
};

