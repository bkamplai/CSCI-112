//
//    enlarge.cpp
//    test
//
//    Created by Antoun, Sherine on 9/14/21.
//    Copyright © 2021 Antoun, Sherine. All rights reserved.
//
//
//    A PPM image is comprised of pixels - each pixel is made
//    up of R (red), G (green) and B (blue) value. A PPM picture
//    is represented by a header, which describes the size of
//    the image followed by the pixels.
//    If a picture has a resolution of 640 * 480 that means there
//    are 640 pixels on the horizontal (x) axis and there are 480
//    pixels on the vertical axis.
//    The program below reads in a picture into a buffer which is
//    fixed lenght.
//    The buffer has 1500 * 1500 pixel structures. The buffer is
//    an array. A picture in a file can be represented as an array.
//    The image is not allowed to exceed these dimensions.
//    The code reads the pixels from the file (along with header info).


#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 128;                // constant for size of strings
const char cookie[MAX] = "P6";        // PPM header cookie
const int XMAX = 1500;                // constants for MAX image size
const int YMAX = 1500;

struct pixel                        // composition of a pixel.
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

// prototype, function takes filename to read, integers for x and y dimensions
// of image and then the array of pixels. The function should open the file
// read the pixels into the array then terminate.

bool openfile(char[], int&, int&, pixel[XMAX][YMAX]);
bool writefile(char[], int, int, int, pixel[XMAX][YMAX]);

int main()
{
    int xdim, ydim;
    int scale = 1;
    pixel picmap[XMAX * YMAX];        // Buffer to store pixels
    char filename[MAX];
    
    cout << "Enter a name of a PPM file: " << endl;
    cin >> filename;

    if (openfile(filename, xdim, ydim, picmap) == false)
    {
        cout << "Error reading file... " << endl;
        return 0;
    }

    cout << "How many times would you like to make the image bigger (MAX is 10:" << endl;
    cin >> scale;
    
    if (scale < 0 || scale > 10)
    {
        cout << "Scaling value is invalid: " << endl;
        return 0;
    }

    cout << "Enter new filename: ";
    cin >> filename;

    if (writefile(filename, xdim, ydim, scale, picmap) == false)
    {
        cout << "Error writing file... " << endl;
        return 0;
    }
    
    return 0;
}


// the function below opens and image and reads it into the pixel buffer, filename is image to open, xdim and ydim
// are dimensions of the image, picmap is the array to read into.

bool openfile(char filename[], int& xdim, int& ydim, pixel picmap[XMAX][YMAX])
{
    ifstream ins;
    char buffer[MAX];                // global temp vars to store stuff
    int garbage;
    char c;
    

    ins.open(filename, ios::in);

    if (ins.fail())                    // check if file opened
        return false;


    ins >> buffer;                    // read image header and get dimensions
    ins >> buffer >> xdim >> ydim >> garbage;

    **picmap = pixel *picmap[xdim][ydim];
    
    if (xdim > XMAX || ydim > YMAX)
    {
        return false;
    }

    ins.get(c);                    // get unwanted newline

    // now read the pixels into the buffer one by one
    
    for (int i = 0; i < (xdim * ydim); i++)
    {
        ins.read((char*)&picmap[i], sizeof(pixel));
    }

    ins.close();
    return true;
}

// this function write the image in a scaled manner - same args as above except now we have a integer
// for scaling.

bool writefile(char filename[], int xdim, int ydim, int scale, pixel picmap[XMAX][YMAX])
{
    ofstream ofs;
    ofs.open(filename, ios::out | ios::binary);
    
    int offset = 0;
    

    if (ofs.fail())
        return false;

    // write header information.
    
    ofs << "P6" << endl << "#." << endl << (xdim * scale) << " " << (ydim * scale) << endl << "255" << endl;

    // scale and write image.

    for (int z = 0; z < ydim; z++)
    {
        for (int i = 0; i < scale; i++)
        {
            for (int y = 0; y < xdim; y++)
            {
                for (int a = 0; a < scale; a++)
                {
                    ofs.write((char*)&picmap[offset + 1], sizeof(pixel));
                    //1 or i?
                }
            }
        }
    }

    ofs.close();
    return true;
}
