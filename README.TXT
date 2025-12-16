I am making a Smart Lock, called "SLock". 

The code will have a user class and 2 child classes that will be derived from it.
These classes are 'Admin' and 'Guests'

This will be used to get access into homes or office buildings, or anything will a door.

Data Types:

- one use case for int will be for the number of uses or attempts
- one use for double/float wil be how many hours are allowed if the passcode is active for less than 1 day.
- one use case for char will be included in a random PW generator to make PW stronger. instead of all numbers...
- one use case for a string will be "max limit reached of uses" after 5 total users.

Special Variables:
- one use case for constant variable will be having 5 max users.
- one use case for static variable will be guest IDs?
- one use case for reference variable is will be to reference a constant variable, they can reference 5 users and return T/F?
- one use case for array or vector will be Guests
- one use case for struct or enum will be to take Phone#, Email, and Bank Account for Guests?

Log-in:
- string will be used for passcodes.Any length, any string.

Current Updates:
- login system with username and passcode
- admin menu for landlords to manage the system
- guest users get welcome message when they enter correctly
- list all users function for admin
- door unlock simulation

Special Features:
- after 5 failed attempts, users get charged $0.50 per attempt
- after 10 failed attempts, penalty uses modular arithmetic based on username length
- random passcode generator creates mix of letters and numbers with max character count of 6.



