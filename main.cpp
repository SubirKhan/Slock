#include <iostream>
#include <string>
#include <vector>
#include "people.h"

using namespace std;

int main() {
    
    vector<User> users; // vector that stores users
    
    
    User admin; // default admin
    admin.username = "admin"; // making username for admin
    admin.passcode = "test15"; // making passcode for admin
    users.push_back(admin);
    
    
    User user1; // sample user 1
    user1.username = "john"; // making username for guest 1
    user1.passcode = "abc123"; // making passcode for guest 1
    users.push_back(user1);
    
    User user2; // sample user 2
    user2.username = "jane"; // making username for guest 2
    user2.passcode = "hello"; // making passcode for guest 2
    users.push_back(user2);
    
    
    cout << "Welcome to SLock!" << endl; // welcome message!
    
    bool running = true;
    
    while (running) {
        cout << "\n1. Login" << endl;
        cout << "2. Exit" << endl;
        cout << "Choice: ";
        
        int choice;
        cin >> choice;
        
        if (choice == 2) {
            running = false;
            cout << "Goodbye!" << endl;
        }
        else if (choice == 1) {
            // user enters username and passcode
            string input_username, input_passcode;
            cout << "Enter username: ";
            cin >> input_username;
            cout << "Enter passcode: ";
            cin >> input_passcode;
            
            // check if user exists
            bool found = false;
            bool isAdmin = false;
            
            for (int i = 0; i < users.size(); i++) {
                if (users[i].username == input_username && 
                    users[i].passcode == input_passcode) {
                    found = true;
                    
                    // check if its admin
                    if (input_username == "admin") {
                        isAdmin = true;
                    }
                    break;
                }
            }
            
            if (found == true) {
                if (isAdmin == true) {
                    cout << "Welcome Admin!" << endl;
                    
                    
                    bool adminMenu = true; // admin menu
                    while (adminMenu) {
                        cout << "\nAdmin Menu:" << endl;
                        cout << "1. Unlock door" << endl;
                        cout << "2. Add user" << endl;
                        cout << "3. Delete user" << endl;
                        cout << "4. List all users" << endl;
                        cout << "5. Logout" << endl;
                        cout << "Choice: ";
                        
                        int adminChoice;
                        cin >> adminChoice;
                        
                        if (adminChoice == 1) {
                            cout << "DOOR UNLOCKED!" << endl;
                        }
                        else if (adminChoice == 4) {
                            // list users
                            cout << "\nAll users:" << endl;
                            for (int i = 0; i < users.size(); i++) {
                                cout << i+1 << ". " << users[i].username << endl;
                            }
                        }
                        else if (adminChoice == 5) {
                            adminMenu = false;
                            cout << "Logged out." << endl;
                        }
                    }
                }
                else {
                    cout << "Hello, welcome to our lovely home!" << endl;
                }
            }
            else {
                cout << "ACCESS DENIED" << endl;
                User::totalAttempts++;  // increment static counter
            }
        }
    }
    
    return 0;
}