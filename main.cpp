#include <iostream>
#include <string>
#include <vector>
#include "people.h"

using namespace std;

const int MAX_USERS = 5;  // max users allowed

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
    
    
    cout << "Welcome to SLock!" << endl; // welcome message
    
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
            
            string input_username, input_passcode; // user enters username and passcode
            cout << "Enter username: ";
            cin >> input_username;
            cout << "Enter passcode: ";
            cin >> input_passcode;
            
            
            bool found = false; // check if user exists
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
                        cout << "5. Change user passcode" << endl;
                        cout << "6. Logout" << endl;
                        cout << "Choice: ";
                        
                        int adminChoice;
                        cin >> adminChoice;
                        
                        if (adminChoice == 1) {
                            cout << "DOOR UNLOCKED!" << endl;
                        }
                        else if (adminChoice == 2) {
                            // add new user
                            if (users.size() >= MAX_USERS) {
                                cout << "Maximum users reached (" << MAX_USERS << ")" << endl;
                            }
                            else {
                                User newUser;
                                cout << "Enter new username: ";
                                cin >> newUser.username;
                                
                                // check if username already exists
                                bool exists = false;
                                for (int i = 0; i < users.size(); i++) {
                                    if (users[i].username == newUser.username) {
                                        exists = true;
                                        break;
                                    }
                                }
                                
                                if (exists) {
                                    cout << "Username already exists!" << endl;
                                }
                                else {
                                    cout << "Enter passcode for new user: ";
                                    cin >> newUser.passcode;
                                    users.push_back(newUser);
                                    cout << "User added successfully!" << endl;
                                }
                            }
                        }
                        else if (adminChoice == 3) {
                            // delete user
                            cout << "\nSelect user to delete:" << endl;
                            for (int i = 0; i < users.size(); i++) {
                                cout << i+1 << ". " << users[i].username << endl;
                            }
                            cout << "Enter number: ";
                            int deleteChoice;
                            cin >> deleteChoice;
                            
                            if (deleteChoice == 1) {
                                cout << "Cannot delete admin!" << endl;
                            }
                            else if (deleteChoice > 0 && deleteChoice <= users.size()) {
                                users.erase(users.begin() + deleteChoice - 1);
                                cout << "User deleted!" << endl;
                            }
                            else {
                                cout << "Invalid choice!" << endl;
                            }
                        }
                        else if (adminChoice == 4) {
                            // list users
                            cout << "\nAll users:" << endl;
                            for (int i = 0; i < users.size(); i++) {
                                cout << i+1 << ". " << users[i].username << endl;
                            }
                        }
                        else if (adminChoice == 5) {
                            // change user passcode
                            cout << "\nSelect user to change passcode:" << endl;
                            for (int i = 0; i < users.size(); i++) {
                                cout << i+1 << ". " << users[i].username << endl;
                            }
                            cout << "Enter number: ";
                            int changeChoice;
                            cin >> changeChoice;
                            
                            if (changeChoice > 0 && changeChoice <= users.size()) {
                                cout << "Enter new passcode: ";
                                string newPass;
                                cin >> newPass;
                                users[changeChoice - 1].passcode = newPass;
                                cout << "Passcode changed!" << endl;
                            }
                            else {
                                cout << "Invalid choice!" << endl;
                            }
                        }
                        else if (adminChoice == 6) {
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
                cout << "GTFO" << endl;
                User::totalAttempts++;  // increment static counter
            }
        }
    }
    
    return 0;
}