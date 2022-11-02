//
//  clockType.h
//  Clock
//
//  Created by Brandon Kamplain on 1/26/22.
//

#ifndef clockType_h
#define clockType_h

class clockType
{
public:
    void setTime(int hours, int minutes, int seconds);
    void setHours(int hours);
    void setMinutes(int minutes);
    void setSeconds(int seconds);
    
    void getTime(int &hours, int &minutes, int &seconds);
    int getHours()const;
    int getMinutes()const;
    int getSeconds()const;
    
    void printTime()const;
    void operator++();
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const clockType &otherClock)const;
    int timeElapsed()const;
    int timeRemaining()const;
    void equalDifference(const clockType &otherClock)const;
    clockType();
    clockType (int hours, int minutes, int seconds);
    
private:
    int hr;
    int min;
    int sec;
    
};


#endif /* clockType_h */
