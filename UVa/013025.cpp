#include <iostream>

using namespace std;

int main() {
    tm timeStruct = {};
    timeStruct.tm_year = 2013 - 1900;
    timeStruct.tm_mon = 5 - 1;
    timeStruct.tm_mday = 29;
    timeStruct.tm_hour = 12; // To avoid any doubts about summer time, etc.
    mktime(&timeStruct);

    string weekdays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    printf("May 29, 2013 %s\n", weekdays[timeStruct.tm_wday].c_str()); //  0...6 for Sunday...Saturday

    return 0;
}