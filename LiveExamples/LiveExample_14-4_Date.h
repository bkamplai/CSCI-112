#ifndef DATE_H
#define DATE_H
class Date
{
public:
  Date(int year, int month, int day)
  {
    this->year = year;
    this->month = month;
    this->day = day;
  }

  friend class AccessDate; // AccessDate is a friend of Date

private:
  int year;
  int month;
  int day;
};

#endif