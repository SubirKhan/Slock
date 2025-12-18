#ifndef PEOPLE_H
#define PEOPLE_H

#include <string>
using namespace std;

// struct for login
struct LoginInfo {
    string username;
    string passcode;
    
};


class User { // parent class
public:
    string username;     
    string passcode;    
    int failedAttempts;  // to track failed attempts
    static int totalAttempts;  // static requirement
    
    User() {
        failedAttempts = 0;
    }
};


int User::totalAttempts = 0; // static variable


class Landlord : public User { // landlord, which is the ADMIN, class
public:
    bool isAdmin = true;
};


class Guest : public User { // guest class
public:
    bool isAdmin = false;
};

#endif