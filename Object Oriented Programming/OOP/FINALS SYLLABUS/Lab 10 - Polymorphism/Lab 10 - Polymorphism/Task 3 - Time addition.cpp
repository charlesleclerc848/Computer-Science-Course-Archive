#include <iostream>
using namespace std;

class Time {
   private:
   	int hours, minutes, seconds;

   public:

    void input() {
        cout << "Enter hours : ";
        cin >> hours;
        cout << "Enter minutes : ";
        cin >> minutes;
        cout << "Enter seconds: ";
        cin >> seconds;
    }

    // Overload the + operator
    Time operator + (Time &t) {
        Time temp;
        temp.hours = hours + t.hours;
        temp.minutes = minutes + t.minutes;
        temp.seconds = seconds + t.seconds;
        if(temp.minutes>60)
        {
        	temp.minutes = temp.minutes-60;
        	temp.hours += 1;
		}
		if(temp.seconds>60)
		{
			temp.seconds = temp.seconds-60;
        	temp.minutes += 1;
		}
        return temp;
    }

    void output() 
	{
        cout << "\nTotal Time : " << hours << ":" << minutes << ":" << seconds;
    }
};

int main() {
    Time t1, t2, totalTime;

    cout << "***** Enter First Time *****\n";
    t1.input();

    cout << "\n***** Enter Second Time *****\n";
    t2.input();

    totalTime = t1 + t2;
    totalTime.output();

    return 0;
}
