#include <iostream>
#include <string>
using namespace std;


class User {
public:

private: 

    string name;
    int attempts_used;
    bool active_inactive;
    string phone_num;
    string email;

public:
    int user_ID;
    string passcode;
};

 
class Landlord : public User { // Landlord class is inherting from USer (parent) 

};


class Guest : public User {  // Guest class is inherting from USer (parent)


};

