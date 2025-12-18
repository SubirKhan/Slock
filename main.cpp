#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>  // for rand
#include <ctime>    // for time
#include <fstream>  // for file operations
#include "people.h"

using namespace std;

const int MAX_USERS = 5;  // max users allowed


string generateRandomPasscode() { // function to generate random passcode
    
    char letters[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m', // array of characters to use
                      'n','o','p','q','r','s','t','u','v','w','x','y','z',
                      '0','1','2','3','4','5','6','7','8','9'};
    
    string passcode = "";
    
    // generate 6 random characters
    for (int i = 0; i < 6; i++) {
        int randomIndex = rand() % 36;  // 26 letters + 10 numbers = 36
        passcode = passcode + letters[randomIndex];
    }
    
    return passcode;
}

// function to calculate penalty using reference
void calculatePenalty(int &attempts, double &penalty) {
    if (attempts > 5 && attempts <= 10) {
        // charge 50 cents per attempt after 5th
        int extraAttempts = attempts - 5;
        penalty = extraAttempts * 0.50;
    }
    else if (attempts > 10) {
        // modular penalty
        penalty = 2.50;  // base penalty for attempts 6-10
        
        // add modular calculation
        int remainder = attempts % 5;
        penalty = penalty + (remainder * 2.0);
    }
}

// function to save users to file
void saveUsersToFile(vector<User> &users) {
    ofstream file;
    file.open("users.txt");
    
    if (file.is_open()) {
        for (int i = 0; i < users.size(); i++) {
            file << users[i].username << ",";
            file << users[i].passcode << ",";
            file << users[i].failedAttempts << endl;
        }
        file.close();
        cout << "Users saved to file!" << endl;
    }
    else {
        cout << "Error saving file!" << endl;
    }
}


void loadUsersFromFile(vector<User> &users) { // function to load users from file
    ifstream file;
    file.open("users.txt");
    
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            // parse the line
            User user;
            int comma1 = line.find(',');
            int comma2 = line.find(',', comma1 + 1);
            
            user.username = line.substr(0, comma1);
            user.passcode = line.substr(comma1 + 1, comma2 - comma1 - 1);
            user.failedAttempts = stoi(line.substr(comma2 + 1));
            
            users.push_back(user);
        }
        file.close();
        cout << "Loaded " << users.size() << " users from file!" << endl;
    }
    else {
        cout << "No save file found, starting fresh." << endl;
    }
}

int main() {
    
    srand(time(0));  // random number generator
    
    vector<User> users; // vector that stores users
    
    
    loadUsersFromFile(users); // load users from file if it exists
    
        if (users.size() == 0) { // if no users loaded we will create defaults

        User admin; // default admin
        admin.username = "admin"; // making username for admin
        admin.passcode = "test19"; // making passcode for admin
        users.push_back(admin);
        
        
        User user1; // sample user 1
        user1.username = "john"; // making username for guest 1
        user1.passcode = "abc123"; // making passcode for guest 1
        users.push_back(user1);
        
        User user2; // sample user 2
        user2.username = "jane"; // making username for guest 2
        user2.passcode = "hello"; // making passcode for guest 2
        users.push_back(user2);
    }
    
    
    cout << "Welcome to SLock!" << endl; // welcome message
    
    bool running = true;
    
    while (running) {
        cout << "\n1. Login" << endl;
        cout << "2. Exit" << endl;
        cout << "Choice: ";
        
        int choice;
        cin >> choice;

        if (cin.fail()) {
    cin.clear();  // clears the error of invalid entry at log in menu
    cin.ignore(1000, '\n');  // ignore bad input
    cout << "Invalid input! Please enter 1 or 2." << endl;
    continue;  // go back to start of loop
}
        
        if (choice == 2) {
            running = false;
            saveUsersToFile(users);  // save before exiting
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
            int userIndex = -1;  // track which user for failed attempts
            
            for (int i = 0; i < users.size(); i++) {
                if (users[i].username == input_username) {
                    userIndex = i;  // found the user
                    if (users[i].passcode == input_passcode) {
                        found = true;
                        users[i].failedAttempts = 0;  // reset on successful login
                        
                        // check if its the admin
                        if (input_username == "admin") {
                            isAdmin = true;
                        }
                        break;
                    }
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
                                    // ask if they want random passcode
                                    cout << "Generate random passcode? (y/n): ";
                                    char randomChoice;
                                    cin >> randomChoice;
                                    cin.ignore(); // prevents terminal from endlessly crashing
                                    
                                    if (randomChoice == 'y' || randomChoice == 'Y') {
                                        newUser.passcode = generateRandomPasscode();
                                        cout << "Generated passcode: " << newUser.passcode << endl;
                                    }
                                    else {
                                        cout << "Enter passcode for new user: ";
                                        cin >> newUser.passcode;
                                    }
                                    
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
                                cout << i+1 << ". " << users[i].username;
                                if (users[i].failedAttempts > 0) {
                                    cout << " (Failed attempts: " << users[i].failedAttempts << ")";
                                }
                                cout << endl;
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
                cout << "ACCESS DENIED" << endl;
                User::totalAttempts++;  // increment static counter
                
                // if we find the username but wrong password
                if (userIndex != -1) {
                    users[userIndex].failedAttempts++;
                    
                    // check if penalty applies
                    if (users[userIndex].failedAttempts > 5) {
                        double penalty = 0.0;
                        calculatePenalty(users[userIndex].failedAttempts, penalty);
                        cout << "Warning: You have " << users[userIndex].failedAttempts << " failed attempts!" << endl;
                        cout << "Penalty owed: $" << penalty << endl;
                    }
                }
            }
        }
    }
    
    return 0;
}