/* Mehrdad Ghannad - MIDTERM PROJECT - Hotel Management System
Teacher: Dr. Noukhovitch
Course: ICS4U1-03
Date: 22/01/2020
*/

#include <string>
#include <iostream>
#include <vector>
#include <algorithm> //count()
#include <time.h> 

using namespace std;

// The parent class
class Hotel {
    public:
        // Variables for each object
        string name;
        int duration;
        string date;
        int room_type;
        int room_num;

        // Create function that passes the values into the variables
        void create(string theName, int days, string theDate, int type, int number) {
            Hotel::name = theName;
            Hotel::duration = days;
            Hotel::date = theDate;
            Hotel::room_type = type;
            Hotel::room_num = number;
        }

        // Functions for returning the values for name, duration, date, room type, and room number
        string getName(void) {
            return Hotel::name;
        }
        int getDuration(void) {
            return Hotel::duration;
        }
        string getDate(void) {
            return Hotel::date;
        }
        string getRoomType(void) {
            if (Hotel::room_type == 1)
                return "Single";
            if (Hotel::room_type == 2)
                return "Double";
            if (Hotel::room_type == 3)
                return "King";
            if (Hotel::room_type == 4)
                return "Queen";
            if (Hotel::room_type == 5)
                return "Twin";
            if (Hotel::room_type == 6)
                return "VIP Suite";
        }
        int getRoomNum(void) {
            return Hotel::room_num;
        }
};

// Child class VIP
class Vip : public Hotel {
    public:
        bool freeWifi = true;
        bool swimmingPool = true;

        void statement() {
            if (Vip::freeWifi and Vip::swimmingPool) {
                cout << "VIP GUESTS SPECIAL:" << endl;
                cout << "You will have free access to wifi in the lobby and in your room." << endl;
                cout << "The Swimming pool will be open every day from 7am to 11pm." << endl;
                cout << endl;
            }
        }
};

// Function to calculate date after adding a number of days to it
string addDays(string date, int num) {
    int section = 1;
    string one;
    string two;
    string month;
    string year;
    int month_num;
    for(int i = 0; i < date.length(); i++){
        if (date[i] == '/') {
            section += 1;
        }
        if (date[i] != '/'){
            if (section == 1) {
                one += date[i];
            }
            if (section == 2) {
                two += date[i];
            }
            if (section == 3) {
                year += date[i];
            }
        }
    }

    int day = stoi(one) + num;
    month_num = stoi(two);

    int leftover;
    if (month_num == 2) {
        leftover = 28;
    }
    else if (month_num == 4 or month_num == 6 or month_num == 9 or month_num == 11) {
        leftover = 30;
    }
    else if (month_num == 1 or month_num == 3 or month_num == 5 or month_num == 7 or month_num == 8 or month_num == 10 or month_num == 12) {
        leftover = 31;
    }

    if (day > leftover) {
        month_num = month_num + 1;
        day = day - leftover;
    }

    two = to_string(month_num);
    string daystr = to_string(day);


    if (two == "01" or two == "1")
        month = "January";
    if (two == "02" or two == "2")
        month = "February";
    if (two == "03" or two == "3")
        month = "March";
    if (two == "04" or two == "4")
        month = "April";
    if (two == "05" or two == "5")
        month = "May";
    if (two == "06" or two == "6")
        month = "June";
    if (two == "07" or two == "7")
        month = "July";
    if (two == "08" or two == "8")
        month = "August";
    if (two == "09" or two == "9")
        month = "September";
    if (two == "10")
        month = "October";
    if (two == "11")
        month = "November";
    if (two == "12")
        month = "December";

    string phrase = month + " " + daystr + ", " + year;
    return phrase;
};

// Function that actually changes the value of the date
// Very similar to addDays() but this function passes by reference, allowing the value for date to actually change
void actuallyAddDays(string &date, int num) {
    int section = 1;
    string one;
    string two;
    string month;
    string year;
    int month_num;
    for(int i = 0; i < date.length(); i++){
        if (date[i] == '/') {
            section += 1;
        }
        if (date[i] != '/'){
            if (section == 1) {
                one += date[i];
            }
            if (section == 2) {
                two += date[i];
            }
            if (section == 3) {
                year += date[i];
            }
        }
    }

    int day = stoi(one) + num;
    month_num = stoi(two);

    int leftover;
    if (month_num == 2) {
        leftover = 28;
    }
    else if (month_num == 4 or month_num == 6 or month_num == 9 or month_num == 11) {
        leftover = 30;
    }
    else if (month_num == 1 or month_num == 3 or month_num == 5 or month_num == 7 or month_num == 8 or month_num == 10 or month_num == 12) {
        leftover = 31;
    }

    if (day > leftover) {
        month_num = month_num + 1;
        day = day - leftover;
    }

    two = to_string(month_num);
    string daystr = to_string(day);

    string newDate = daystr + "/" + two + "/" + year;
    date = newDate;
};

// Function to calculate number of days between two dates
int daysBetween(string current, string future) {
    int c_section = 1;
    string c_day;
    string c_month;
    string c_year;
    for(int i = 0; i < current.length(); i++){
        if (current[i] == '/') {
            c_section += 1;
        }
        if (current[i] != '/'){
            if (c_section == 1) {
                c_day += current[i];
            }
            if (c_section == 2) {
                c_month += current[i];
            }
            if (c_section == 3) {
                c_year += current[i];
            }
        }
    }

    int c_day_int = stoi(c_day);
    int c_month_int = stoi(c_month);
    int c_year_int = stoi(c_year);

    int f_section = 1;
    string f_day;
    string f_month;
    string f_year;
    for(int i = 0; i < future.length(); i++){
        if (future[i] == '/') {
            f_section += 1;
        }
        if (future[i] != '/'){
            if (f_section == 1) {
                f_day += future[i];
            }
            if (f_section == 2) {
                f_month += future[i];
            }
            if (f_section == 3) {
                f_year += future[i];
            }
        }
    }

    int f_day_int = stoi(f_day);
    int f_month_int = stoi(f_month);
    int f_year_int = stoi(f_year);

    if (f_year_int < c_year_int) {
        return -1;
    }
    else if(f_year_int = c_year_int) {
        if (f_month_int < c_month_int) {
            return -1;
        }
        else if (f_month_int > c_month_int) {
            if (c_month_int == 4 or c_month_int == 6 or c_month_int == 9 or c_month_int == 11) {
                return f_day_int + (30 - c_day_int);
            } else if (c_month_int == 1 or c_month_int == 3 or c_month_int == 5 or c_month_int == 7 or c_month_int == 8 or c_month_int == 10 or c_month_int == 12) {
                return f_day_int + (31 - c_day_int);
            }
        }
        else if (f_month_int = c_month_int) {
            if (f_day_int < c_day_int) {
                return -1;
            } else {
                return f_day_int - c_day_int;
            }
        }

    }
};

int main() {
    unsigned int choice;
    int i = 0;

    // A list that will store all objects
    vector <Hotel> hotel_list;

    // Get current date and time from the user's device
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int currentYear = 1900 + ltm->tm_year;
    int currentMonth = 1 + ltm->tm_mon;
    int currentDay = ltm->tm_mday;
    string currentDate = to_string(currentDay) + "/" + to_string(currentMonth) + "/" + to_string(currentYear);
    cout << "Welcome to our Hotel Management System! Select a command from below:" << endl;

    // Main while loop
    while(true) {
        // Welcome message and guide
        cout << endl;
        cout << "~~~~~~~~~~~~~~~~~~~COMMANDS~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "1 - Book a room" << endl;
        cout << "2 - Review your reservation" << endl;
        cout << "3 - Cancel a reservation" << endl;
        cout << "4 - Show all reservations" << endl;
        cout << "5 - Advance" << endl;
        cout << "0 - Quit" << endl;
        cout << endl;

        // Get input from user
        cout << endl;
        cout << "Enter command: ";
        cin >> choice;

        if (choice > 5 or choice < 0) {
            cout << "Invalid input! ";
        }

        // If input is 0, close the program
        if (choice == 0) {
            cout << "Thanks for using our Hotel Management System" << endl;
            if (hotel_list.size() != 0) {
                cout << "See you soon!";
            }
            return 0;
        }

        // If input is 1, create a new object and pass the values in it
        if (choice == 1) {
            string name;
            string date;
            int duration;
            int room_type;

            // Get input for class variables
            cin.ignore();
            cout << "Enter full name: "; getline(cin, name);

            while (true) {
                cout << "Enter date for reservation (dd/mm/yy): ";
                cin >> date;
                int section = 1;
                string one;
                string two;
                string month;
                string year;
                int month_num;
                for(int i = 0; i < date.length(); i++){
                    if (date[i] == '/') {
                        section += 1;
                    }
                    if (date[i] != '/'){
                        if (section == 1) {
                            one += date[i];
                        }
                        if (section == 2) {
                            two += date[i];
                        }
                        if (section == 3) {
                            year += date[i];
                        }
                    }
                }

                int day = stoi(one);
                month_num = stoi(two);

                size_t n = std::count(date.begin(), date.end(), '/');
                if (n != 2) {
                    cout << "Wrong format! ";
                } else if(day > 31 or day < 0 or month_num < 0 or month_num > 12) {
                    cout << "Impossible! ";
                } else if (daysBetween(currentDate, date) == -1) {
                    cout << "That day is in the past! ";
                } else if (daysBetween(currentDate, date) <= 2) {
                    cout << "Reservation date has to be at least 3 days away! ";
                } else  {
                    break;
                }
            }

            while (true) {
                cout << "How long would you like to stay (in days): ";
                cin >> duration;
                if (duration >= 30) {
                    cout << "You cannot stay for more than 30 days! ";
                } else if(duration <= 1) {
                    cout << "Minimum duration for stay is 2 days! ";
                } else {
                    break;
                }
            }

            cout << endl;
            cout << "Room choices are:" <<  endl;
            cout << "1 - Single" << endl;
            cout << "2 - Double" << endl;
            cout << "3 - Queen" << endl;
            cout << "4 - King" << endl;
            cout << "5 - Twin" << endl;
            cout << "6 - VIP suite" << endl;
            cout << endl;

            while (true) {
                cout << "Please select an option from 1 to 6: ";
                cin >> room_type;
                if (room_type > 6 or room_type <= 0) {
                    cout << "Invalid input! ";
                } else {
                    break;
                }
            }

            // Select a random number from 1 to 100
            srand(time(NULL));
            int room_num = (rand() % 100) + 1;
            while (true) {
                for (int i = 0; i < hotel_list.size(); i++) {
                    if (room_num == hotel_list[i].getRoomNum()) {
                        room_num = (rand() % 100) + 1;
                    } else {
                        break;
                    }
                }
                break;
            }
            cout << "Your room number is: " << room_num << ". Do not forget this number!" << endl;
            cout << endl;

            // Create the object (Hotel or Vip) and pass the values in the create function
            // Add the object to the list
            if (room_type != 6) {
                Hotel object;
                object.create(name, duration, date, room_type, room_num);
                hotel_list.push_back(object);
            } else if (room_type == 6) {
                Vip vObject;
                vObject.create(name, duration, date, 6, room_num);
                hotel_list.push_back(vObject);
                vObject.statement();
            }

        }

        if (choice == 2) {
            if (hotel_list.size() == 0) {
                cout << "Nothing to show you" << endl;
            } else {
                int num;
                cout << "Enter your room number: ";
                cin >> num;
                for (int i = 0; i < hotel_list.size(); i++) {
                    if (hotel_list[i].getRoomNum() == num) {
                        if (daysBetween(currentDate, hotel_list[i].getDate()) != -1) {
                            cout << endl;
                            cout << "Name: " << hotel_list[i].getName() << endl;
                            cout << "Room type: " << hotel_list[i].getRoomType() << endl;
                            cout << "From date: " << addDays(hotel_list[i].getDate(), 0) << endl;
                            cout << "To date: " << addDays(hotel_list[i].getDate(), hotel_list[i].getDuration()) << endl;
                            cout << "Days until reservation: " << daysBetween(currentDate, hotel_list[i].getDate()) << endl;
                            cout << endl;
                            break;
                        }
                    }
                }
            }
        }

        if (choice == 3) {
            if (hotel_list.size() == 0) {
                cout << "There are currently no active reservations. " << endl;
            }
            else {
                // Get input to confirm the users identity
                int input1;
                string input2;
                cout << "Enter room number: "; cin >> input1;
                cin.ignore();
                cout << "Enter full name for confirmation: "; getline(cin, input2);

                for (int i = 0; i < hotel_list.size(); i++) {
                    if (hotel_list[i].getRoomNum() == input1) {
                        if(hotel_list[i].getName() == input2) {
                            if (daysBetween(currentDate, hotel_list[i].getDate()) <= 3) {
                                cout << "Sorry, but you can only cancel your reservation if it is more than 3 days away!" << endl;
                            } else {
                                cout << hotel_list[i].getName() << "'s " << hotel_list[i].getRoomType() << " room reservation has been cancelled." << endl;
                                hotel_list.erase(hotel_list.begin() + i);
                                cout << endl;

                            }
                        } else {
                            cout << "Room number and name don't match!" << endl;
                            cout << endl;
                        }
                    }
                }
            }
        }

        if (choice == 4) {
            string password;
            bool access = false;
            cout << endl;
            cout << "Enter password: ";

            // Validate password
            while(true) {
                cin >> password;
                if (password == "1234") {
                    access = true;
                    break;
                } else if (password == "0") {
                    break;
                } else {
                    cout << "Wrong password! Try again or enter 0 to go back: ";
                }
            }
            if (access) {
                if (hotel_list.size() == 0) {
                    cout << endl;
                    cout << "Nothing to show you" << endl;
                } else {
                    // Show data for every guest by going through the list
                    for (int i = 0; i < hotel_list.size(); i++) {
                        if (daysBetween(currentDate, hotel_list[i].getDate()) != -1) {
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                            cout << "Name: " << hotel_list[i].getName() << endl;
                            cout << "Room type: " << hotel_list[i].getRoomType() << endl;
                            cout << "From date: " << addDays(hotel_list[i].getDate(), 0) << endl;
                            cout << "To date: " << addDays(hotel_list[i].getDate(), hotel_list[i].getDuration()) << endl;
                            cout << "Room number: " << hotel_list[i].getRoomNum() << endl;
                            cout << "Days until reservation: " << daysBetween(currentDate, hotel_list[i].getDate()) << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        }
                    }
                }
            }
        }

        if (choice == 5) {
            int num_day;

            while (true) {
                cout << endl;
                cout << "How many days would you like to advance? ";
                cin >> num_day;
                if (num_day < 0) {
                    cout << "Nice try but you can't travel back in time! ";
                } else if (num_day > 30) {
                    cout << "You can't time travel more than 30 days!";
                } else {
                    break;
                }
            }
            // Call the actuallyAddDays() function
            actuallyAddDays(currentDate, num_day);
            cout << endl;
            cout << "Today's date is: " << addDays(currentDate, 0) << endl;
            for (int i = 0; i < hotel_list.size(); i++) {
                if (hotel_list.size() != 0) {
                    if (daysBetween(currentDate, hotel_list[i].getDate()) != -1) {
                        // Show date until reservation for each guest
                        cout << "Days until reservation date for " << hotel_list[i].getName() << ": " << daysBetween(currentDate, hotel_list[i].getDate()) << endl;
                    }
                }
            }
        }
    }
}