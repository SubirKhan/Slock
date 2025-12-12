#include <iostream>
#include <string>

class User {
public:

private: 

string name;
int user_ID;
string passnode;
int attempts_used;
bool active_inactive;
string phone_num;
string email;


};

 
class Landlord : public User { // Landlord class is inherting from USer (parent) 

};


class Guest : public User {  // Guest class is inherting from USer (parent)


};

