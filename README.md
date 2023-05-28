# cloting_showroom_oop
The given program is a clothing store management system written in C++. It allows the user to perform various operations such as adding products, modifying product details, and generating receipts for purchases. The program uses object-oriented programming concepts and inheritance to organize the different sections of clothing (female, male, and children).

The program consists of the following classes:

purevirtual: This is an abstract base class that declares a pure virtual function display(). It serves as the interface for other classes to implement.

dress: This class inherits from purevirtual and implements its display() function. It also contains functions for managing products, such as adding, editing, and removing items. The menu() function displays the main menu of the program and allows the user to choose between the administrator and buyer options.

female, male, and children: These classes inherit from the dress class and represent the different sections of clothing in the store. They override the display() function to gather specific information about the remaining stock after each purchase.

The main() function initializes an instance of the dress class and calls its menu() function to start the program. After performing the desired operations, the program prompts the user to edit the stock details. Depending on the user's choice, it allows editing the stock details of the different clothing sections by creating objects of the respective classes (female, male, children) and calling their display() functions.

The program uses file handling to store product details in a text file called "Product.txt". It reads and writes product information to this file when adding or editing products.

Overall, this program provides basic functionality for managing a clothing store, including adding products, modifying details, and generating receipts.
