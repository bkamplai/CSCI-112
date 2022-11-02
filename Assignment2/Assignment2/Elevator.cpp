//
//  Elevator.cpp
//  Created by Sherine Antoun on 4/21/20.
//  Copyright © 2020 Sherine Antoun. All rights reserved.

#include "Elevator.h"
// constructor for number of floors - no default constructor
Elevator::Elevator(int floors)
{
    maxfloor = floors;    // highest numbered floor in the building
    currentfloor = 0;
    currentdirection = 0;
    dooropen = 0;
    floorup = new int[maxfloor+1];    // array for up buttons on floor
    floordown = new int[maxfloor+1];    // array for down buttons
    button = new int[maxfloor+1];
}

//Destructor
Elevator::~Elevator()
{
    delete [] floorup;
    delete [] floordown;
    delete [] button;
}

// report current status: floor, direction, door status
// move the elevator 1 only floor at a time in the required direction
void Elevator::Move()
{
    //currentfloor = 0;
    
    //bools to determine where the request are coming from
    bool requestAbove = false;
    bool requestBelow = false;
    //no move with open doors
    if(dooropen)
        dooropen = false;
    //workout which floor is requesting elevator
    for (int i = currentfloor; i<=maxfloor; i++)
    {
        //looking for direction button pushed above our floor
        if(((floorup[i])||floordown[i]||button[i])&&(maxfloor!=currentfloor)&&(i!=currentfloor))
        {
            requestAbove = true;
        }
    }
    
    for (int i = currentfloor; i>=0; i--)
    {
        //looking for direction button pushed above our floor
        if((floorup[i]||floordown[i]||button[i])&&(0!=currentfloor)&&(i!=currentfloor))
        {
            requestBelow = true;
        }
    }
    
    //keep direction up
    if((currentdirection == 1)&&requestAbove)
    {
        currentdirection = 1;
        currentfloor++;
    }
    
    //current direction is up but all requests are below
    else if(currentdirection == 1 && !requestAbove && requestBelow)
    {
        currentdirection = -1;
        currentfloor--;
    }
    //keep going down
    else if(currentdirection == -1 && requestBelow)
    {
        currentdirection = -1;
        currentfloor--;
    }
    
    //current direction is down but all requests are above
    else if(currentdirection == -1 && !requestBelow && requestAbove)
    {
        currentdirection = 1;
        currentfloor++;
    }
    
    //deal with no requests so go into idell mode
    else if(!requestAbove && !requestBelow)
    {
        currentdirection = 0;
    }
    
    //stopped now move on request above
    else if(currentdirection == 0 && requestAbove)
    {
        currentdirection = 1;
        currentfloor++;
    }
    
    //stopped now move on request below
    else if(currentdirection == 0 && requestBelow)
    {
        currentdirection = -1;
        currentfloor--;
    }
    
    //clear flags
    requestBelow = false;
    requestAbove = false;
    
    //move completed - again determine where requests are coming from
    for (int i = currentfloor; i<=maxfloor; i++)
    {
        //look for direction button pushed from above
        if((i!=currentfloor)&&(floorup[i]||floordown[i]||button[i])&&(maxfloor!=currentfloor))
        {
            requestAbove = true;
        }
    }
    
    for (int i = currentfloor; i>=0; i--)
    {
        //look for direction button pushed from below
        if((i!=currentfloor)&&(floorup[i]||floordown[i]||button[i])&&(currentfloor!=0))
        {
            requestBelow = true;
        }
    }
    
    //check current floor for rquests
    if(floorup[currentfloor])
        requestAbove = true;
    
    // Bad memory allocation?
    if(floordown[currentfloor])
        requestBelow = true;//*/
    
    //keep direction up
    if((currentdirection == 1) && requestAbove)
    {
        currentdirection = 1;
    }
    
    //current direction is up but all requests are below
    else if(currentdirection == 1 && !requestAbove && requestBelow)
    {
        currentdirection = -1;
    }
    
    else if(currentdirection == -1 && requestBelow)
    {
        currentdirection = -1;
    }
    
    //current direction is down but all requests are above
    else if(currentdirection == -1 && !requestBelow && requestAbove)
    {
        currentdirection = 1;
    }
    
    else if(!requestAbove && !requestBelow)
    {
        currentdirection = 0;
    }
    
    //stopped and we have request
    else if(currentdirection == 0 && requestAbove)
    {
        currentdirection = 1;
    }
    
    //stopped and we have request
    else if(currentdirection == 0 &&requestBelow)
    {
        currentdirection = -1;
    }
    
    //check button to do with current floor to open door as needed
    // Bad memory allocation?
    /*if(button[currentfloor])
    {
        dooropen = true;
        button[currentfloor] = false;
    }*/
    
    //floorup reset
    if(currentdirection == 1 && floorup[currentfloor])
    {
        if(!dooropen)
            dooropen=true;
        floorup[currentfloor]=false;
    }
    
    else if(currentdirection == 1 && floordown[currentfloor])
    {
        if(!dooropen)
            dooropen=true;
        floordown[currentfloor]=false;
    }
    
    else
    {
        if(!dooropen)
            dooropen = true;
        //Bad memory allocation
        //button[currentfloor] = false;
    }
    
    //floordown reset
    if(currentdirection == -1 && floorup[currentfloor])
    {
        if(!dooropen)
            dooropen = true;
        floorup[currentfloor] = false;
    }
    
    else if(currentdirection == -1 && floordown[currentfloor])
    {
        if(!dooropen)
            dooropen = true;
        floordown[currentfloor] = false;
    }
    
    else
    {
        if(!dooropen)
            dooropen = true;
        //Bad memory allocation
        //button[currentfloor] = false;
    }
    
}

//talk to the driver program
void Elevator::Status(int& currentFloor, int& currDir,int& doorIsOpen)
{
    currentFloor = currentfloor;
    currDir = currentdirection;
    doorIsOpen = dooropen;
}

// handle rider request outside elevator
void Elevator::DirectionSelect(int floorNum, int direction)
{
    direction = currentdirection;
    if((direction == UP || direction == 1) && floorNum > currentfloor)
        currentfloor++;
    if((direction == DOWN || direction == -1) && floorNum < currentfloor)
        currentfloor--;
}
// handle rider request inside elevator
void Elevator::ChooseFloor(int floorchosen)
{
    if(currentdirection == 1)
        floorchosen = floorup[currentfloor];
    //else
        //floorchosen = floordown[currentfloor]; //Bad allocation
}
