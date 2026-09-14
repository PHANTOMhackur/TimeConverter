#include <iostream>
using namespace std;

class TimeConverter
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    TimeConverter()
    {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
    void secondsToTime(int totalSeconds)
    {
        hours = totalSeconds / 3600;

        minutes = (totalSeconds % 3600) / 60;

        seconds = totalSeconds % 60;

        cout << "\nHH:MM:SS => "
             << hours << ":"
             << minutes << ":"
             << seconds << endl;
    }
    int timeToSeconds(int h, int m, int s)
    {
        int totalSeconds;

        totalSeconds = (h * 3600) + (m * 60) + s;

        return totalSeconds;
    }
};


int main()
{
    TimeConverter converter;
    int choice;
    int totalSeconds;
    int hours, minutes, seconds;

    cout << "\n1. Convert Seconds to HH:MM:SS";
    cout << "\n2. Convert HH:MM:SS to Seconds";
    cout << "\n3. Exit";
    cout << "\n\nEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            cout << "\nEnter total seconds: ";
            cin >> totalSeconds;

            if (totalSeconds < 0)
            {
                cout << "Invalid input! Seconds cannot be negative."
                     << endl;
            }
            else
            {
                converter.secondsToTime(totalSeconds);
            }

            break;


        case 2:
            cout << "\nEnter hours: ";
            cin >> hours;
            cout << "Enter minutes: ";
            cin >> minutes;
            cout << "Enter seconds: ";
            cin >> seconds;

            if (hours < 0 || minutes < 0 || minutes >= 60 ||
                seconds < 0 || seconds >= 60)
            {
                cout << "Invalid time entered!" << endl;
            }
            else
            {
                totalSeconds = converter.timeToSeconds(
                    hours, minutes, seconds
                );
                cout << "\nTotal seconds: "
                     << totalSeconds << endl;
            }
            break;


        case 3:
            cout << "\nThank you for using Time Converter!"
                 << endl;

            break;
        default:
            cout << "\nInvalid choice!" << endl;
    }
    return 0;
}