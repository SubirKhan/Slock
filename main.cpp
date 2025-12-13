#include <iostream>
#include <string>
#include <vector>
#include "people.h"

using namespace std;

int main() {

    
    vector<User> users; // vector that stores users created by admin

    // sample users 
    User user1;
    user1.passcode = "abc123";
    users.push_back(user1);

    User user2;
    user2.passcode = "hello";
    users.push_back(user2);

    // welcome message
    cout << "Welcome to SLock!" << endl;

    // user enters passcode
    string input_passcode;
    cout << "Enter passcode: ";
    cin >> input_passcode;

    // check if passcode exists
    bool found = false;

    for (int i = 0; i < users.size(); i++) {
        if (users[i].passcode == input_passcode) {
            found = true;
        }
    }

    
    if (found == true) {
        cout << "Hello, welcome to our lovely home!" << endl;
    }
    else {
        cout << "fuck off." << endl;
    }

    return 0;
}
