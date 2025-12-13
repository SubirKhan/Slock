#ifndef PEOPLE_H
#define PEOPLE_H

#include <string>
using namespace std;

 // parent class
class User {
public:
    int user_ID;        // ID for the user 
    string passcode;    // passcode
};

// Landlord (Admin) class , inheritance from user parent class
class Landlord : public User {
   
};

// Guest class, inherits from user parent class
class Guest : public User {
    
};

#endif
