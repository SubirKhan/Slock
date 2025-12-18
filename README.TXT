I am making a Smart Lock, called "SLock". 

The code will have a user class and 2 child classes that will be derived from it.
These classes are 'Landlord' and 'Guest'

This will be used to get access into homes or office buildings, or anything with a door.

Data Types:
- one use case for int will be for menu choices, failed attempt counters, and user indexing
- one use for double/float will be for penalty calculations ($0.50 per failed attempt)
- one use case for char will be included in a random PW generator array with letters and numbers
- one use case for a string will be for usernames, passcodes, and file names

Special Variables:
- one use case for constant variable will be max user = 5 to limit total users
- one use case for static variable will be totalAttempts to track all login attempts
- one use case for reference variable will be in calculatePenalty() function parameters
- one use case for array or vector will be vector<User> to store all users
- one use case for struct will be LoginInfo to hold username and passcode together

Log-in:
- string will be used for passcodes. Any length, any string.
- username and passcode required for authentication

Current Updates:
- login system with username and passcode verification
- admin menu for landlords to manage the system with 6 options
- guest users get welcome message when they enter correctly
- list all users function for admin showing failed attempts
- door unlock simulation displays "DOOR UNLOCKED!"
- add new user with random or manaul passcode option
- delete user function (cannot delete admin)
- change passcode for any user in system
- file I/O saves to users.txt and loads on startup

Special Features:
- after 5 failed attempts, users get charged $0.50 per attempt
- after 10 failed attempts, penalty uses modular arithmetic (attempts % 5) * 2
- random passcode generator creates mix of letters and numbers with 6 characters
- failed attempts tracked per user and reset on successful login
- input validation prevents crashes from invalid menu choices