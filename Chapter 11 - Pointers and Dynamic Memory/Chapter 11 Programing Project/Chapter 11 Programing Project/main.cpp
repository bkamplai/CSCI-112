//
//  main.cpp
//  Chapter 11 Programing Project
//
//  Created by Brandon Kamplain on 5/7/22.
//

/* Instructions:
 (Geometry: find the bounding rectangle)
 A bounding rectangle is the minimum rectangle that endoses a set of points in a two-dimensional plane, as shown in Figure 11.9d. Write a function that returns a bounding rectangle for a set of points in a two-dimensional plane as follows:
 
        const int SIZE = 2;
        Rectangle2D getRectangle(const double points[][SIZE]);
 
    Write another function that returns a pointer to the bounding rectangle as follows:
 
        Rectangle2D* getRectanglePointer(const double points[][SIZE]);
 
    The Rectanlge2D class is deined in Programming Exercise 11.9. Write a test program that prompts the user to enter five points and displayas the bounding rectangle's center, width, and height.
 
    Sample Run:
    
    Enter five points: 1.0 2.5 3 4 5 6 7 8 9 10
    The bounding rectangle's center (5.0, 6.25), width 8.0, height 7.5
 
    Use the code from https://liangcpp.pearsoncmg.com/test/Exercise11_11.txt to complete your program. For a hint on the program, please see https://liangcpp.pearsoncmg.com/cpprevel2e.html. If you get a logic or runtime error, please refer to https://liangcpp.pearsoncmg.com/faq.html.*/

#include <iostream>
using namespace std;

const int SIZE = 2;

class Rectangle2D
{
private:
    double width;
    double height;
    double centerX;
    double centerY;
public:
    Rectangle2D(double wIn, double hIn, double cX, double cY)
    {
        width = wIn;
        height = hIn;
        centerX = cX;
        centerY = cY;
    }
    
    void print()
    {
        cout << "The bounding rectangle's center (" << centerX << ", " << centerY << "), width " << width << ", height " << height;
    }
};

Rectangle2D getRectangle(const double points[][SIZE])
{
    double minX = 999, maxX = -999;
    double minY = 999, maxY = -999;
    
    for(int i = 0; i < 5; i++)
    {
        if(minX > points[i][0])
            minX = points[i][0];
        
        if(maxX<points[i][0])
            maxX=points[i][0];
        
        if(minY>points[i][1])
            minY=points[i][1];

        if(maxY<points[i][1])
            maxY=points[i][1];
    }
    
    double width = maxX - minX;
    double height = maxY - minY;
    double centerX = minX + width/2;
    double centerY = minY + height/2;

    Rectangle2D rec(width,height,centerX,centerY);

    return rec;
}

int main(int argc, const char * argv[]) {
    
    int r=5,c=2;
    double points[r][SIZE];

    cout<<"Enter five points : ";

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
            cin >> points[i][j];
    }

    Rectangle2D rec = getRectangle(points);

    rec.print();
    
    return 0;
}
