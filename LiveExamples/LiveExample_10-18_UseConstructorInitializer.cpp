#include <iostream>
#include <string>
using namespace std;

class Time
{
public:
  Time(int newHour, int newMinute, int newSecond)
  {
     hour = newHour;
     minute = newMinute;
     second = newSecond;
  }
  
  int getHour()
  {
    return hour;
  }

private:
  int hour;
  int minute;
  int second;
};

class Action
{
public:
  Action(const string& newActionName, int hour, int minute, int second)
    :time(hour, minute, second)
  {
    actionName = newActionName;
  }

  Time getTime() 
  {
    return time;
  }

private:
  string actionName;
  Time time;
};

int main()
{
  Action action("Go to class", 11, 30, 0);
  cout << action.getTime().getHour() << endl;

  return 0;
}