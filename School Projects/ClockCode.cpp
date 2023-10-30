/*
    Program Name: Chadda Clock
    Author: Dennis Ward II
    Date: 09/17/2023
    Description: This program allows users to manage time in 24-hour format and display in both 24 & 12-hour format.
*/

#include <iostream>
#include <string>
#include <iomanip>
/*intialize global time as int.I believe a better approach is to not use a global but instead confine any time calulations to its own class.
I think that would make this program more modular, but for the purpose of this assignment I believe having time as a global is suitable*/
int time_hour, time_minute, time_second;

void intializeTime() {
    std::cout << "Please enter intialialize time, should be in 24-hour format'hh mm ss'" << "\n";
    std::cin >> time_hour >> time_minute >> time_second;
}
/**
 * Converts an unsigned integer to a two-digit string.
 *
 * @param number The unsigned integer to convert.
 * @return A string representation of the number (always two digits).
 */

std::string twoDigitString(unsigned int n) {
    // Check if n is between 0 and 9 adds a leading 0 if so
    if (n >= 0 && n <= 9) {
        return "0" + std::to_string(n);
    }
    else {
        // if not converts to string
        return std::to_string(n);
    }
}

/**
 * Creates a string consisting of a given character repeated n times.
 *
 * @param n The number of times the character should be repeated.
 * @param c The character to repeat.
 * @return A string containing the repeated character.
 */

std::string nCharString(size_t n, char c) {// creates a string of c, n times
    
    std::string result(n, c);// creates a string of c, n times

    return result; //returns string
}

/**
 * Formats the time in 24-hour format as "hh:mm:ss".
 *
 * @param hours The hours (0-23).
 * @param minutes The minutes (0-59).
 * @param seconds The seconds (0-59).
 * @return The formatted time string.
 */

std::string formatTime24(unsigned int h, unsigned int m, unsigned int s) {

    std::string str = twoDigitString(h) +":" + twoDigitString(m) + ":" + twoDigitString(s);//formats "hh:mm:ss"
   
    return str;
}

/**
 * Formats the time in 12-hour format with AM or PM designation.
 *
 * @param hours24 The hours in 24-hour format (0-23).
 * @param minutes The minutes (0-59).
 * @param seconds The seconds (0-59).
 * @return The formatted time string.
 */

std::string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    std::string str;
    if (h > 11 ) {// if in PM hours
        if (h != 12) { h = h - 12; }//exception for 12 noon which is PM
       str = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " P M";
    }
    else {
        if (h == 0) { h = 12; }//exception for midnight
        str = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " A M";
    }


    return str;
}

/**
 * Creates a formatted line for easier str formatting.
 *
 * @param width The total width of the formatted line.
 * @param str The content to be centered in the line.
 * @return A formatted line for the menu.
 */

std::string formatLine(int width, std::string str) {
    int bufferSpaceLength = (width - str.length()) / 2 -1;//logic for spaces
    std::string buffer_space = nCharString(bufferSpaceLength, ' ');
    std::string line = "*" + buffer_space + str + buffer_space + "*";//format
    return line;
}

/**
 * Prints a menu with numbered options.
 *
 * @param strings An array of strings representing the menu options.
 * @param numStrings The number of menu options.
 * @param width The width of the menu.
 */

void printMenu(const char* strings[], unsigned int numStrings, unsigned char width) {
    std::cout << nCharString(width, '*') << "\n";
    for (size_t i = 0; i < numStrings; i++)
    {
        unsigned int str_length = strlen(strings[i])+2;
        std::string str = std::to_string(i + 1) + "-" + strings[i];
        std::cout << formatLine(width, str) << "\n";

    }
    std::cout << nCharString(width, '*') << "\n";

}

/**
 * Gets a valid menu choice from the user.
 *
 * @param maxChoice The maximum valid menu choice.
 * @return The user's chosen menu option.
 */

unsigned int getMenuChoice(unsigned int maxChoice) {
    unsigned int choice;
    
    do {//IL until broken must choose option within range
        std::cin >> choice;
        if (choice <= maxChoice && choice > 0) {
            break;
        }
        std::cout << "Please make another choice!\n";
    } while (true);
    return choice;
}

void processUserChoice(int choice) {

}

/**
 * Display both 12-hour and 24-hour formatted times in a visual representation.
 *
 * @param h The hours component of the time.
 * @param m The minutes component of the time.
 * @param s The seconds component of the time.
 */

void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
    std::string twelve_hour = formatTime12(h, m, s);
    std::string twenty_four = formatTime24(h, m, s);
    int width = 30;
    std::string border = nCharString(width, '*') + nCharString(4, ' ') + nCharString(width, '*') + "\n";
    std::string title = formatLine(width, "12-Hour Clock ") + nCharString(4, ' ') + formatLine(width, "24-Hour Clock ") + "\n";
    std::string body = formatLine(width, twelve_hour) + nCharString(4, ' ') + formatLine(width, twenty_four) + "\n";
    std::cout << border + title + body + border;
}


/**
 * Adds one hour to the global time.
 */
void addOneHour() {
    time_hour = (time_hour + 1);
}

/**
 * Adds one minute to the global time.
 */
void addOneMinute() {
    time_minute = (time_minute + 1);
}

/**
 * Adds one second to the global time.
 */
void addOneSecond() {
    time_second = (time_second + 1);
}

/**
 * Validates the entered time. If out of range, prompts the user for a valid input.
 * Handles roll-overs for hours, minutes, and seconds.
 */

void validateTime() {
    bool update = true;
    //check if entered time is to far out of range ot handle promps for new time.
    if (time_hour > 47 || time_minute > 119 || time_second > 119) {
        std::cout << "Error: The entered time is out of range." << "\n";
        intializeTime();
        return;
    }
    //handles roll over time
    while (update) {
        update = false;
        if (time_hour > 23) {
            time_hour = time_hour - 24;
            update = true;
        }
        if (time_minute > 59) {
            time_minute = time_minute - 60;
            time_hour = time_hour + 1;
            update = true;
        }
        if (time_second > 59) {
            time_second = time_second - 60;
            time_minute = time_minute + 1;
            update = true;
        }
    }
    
}

int main()
{
    intializeTime();//instializes time
    while (true) {
        validateTime(); // Validate and handle any roll-overs
        displayClocks(time_hour, time_minute, time_second);

        const char* menuItems[] = { "Add One Hour", "Add One Minute", "Add One Second", "New Intial Time", "Exit Pogram"};//sets menu options
        unsigned int numItems = sizeof(menuItems) / sizeof(menuItems[0]);
        printMenu(menuItems, numItems, 30);// Print menu options
        std::cout << "Please choose what to do! Enter 1, 2, 3, or 4\n";
        int choice = getMenuChoice(numItems);// Get user's choice

        //processes user choice.
        switch (choice) {
        case 1:
            std::cout << "Option 1 selected." << "\n";
            addOneHour();
            break;
        case 2:
            std::cout << "Option 2 selected." << "\n";
            addOneMinute();
            break;
        case 3:
            std::cout << "Option 3 selected." << "\n";
            addOneSecond();
            break;
        case 4:
            std::cout << "Option 3 selected." << "\n";
            intializeTime();
            break;
        case 5:
            std::cout << "Bye bye!" << "\n";
            return 0;
            break;
        default:
            std::cout << "Invalid option selected." << "\n";
            break;
        }
    }
    return 1;//returns error shouldnt reach here
}
/* There are alot of paramaters i wouldnt have used i would have used simple paramaters int and string mostly in order to do this assignment.
Sense used different ones so i stuck with them*/