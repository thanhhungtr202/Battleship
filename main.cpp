#include <iostream>
#include <stdlib.h>     /* for rand generator */
#include <time.h>
#include <vector>

using namespace std;

#define PORTION 3       //assignment defines portion of grid to be 1/3
#define SIZE 100        //we will assume there is no grid larger than a 100x100.

#define TEST 0           //change to 1 to see verbose, change to 0 for basic

//############################## CLASS DEFINITION BEGINS####################################
class Grid{
    private:
        int array[SIZE][SIZE]; //2D array, default size
        int col;//column size
        int row;//row size
        /* used in AND to create bitwise & functionality */
        
    public:
        Grid();
        /*Create 2D array to size 10 (col) by 10 (row), initiate appropriate values to 0 */
        int getCol();
        /* returns col size */
        int getRow();
        /* returns row size */
        int getVal(int incol, int inrow);
        /* returns value of a specific index */
        void print();
        /* interate over row and col to print grid in understandable order */
        void random();
        /* fill grid with 1/portion of 1 values in random locations */
        void setLocation(int length, int x, int y, string orientation);
        /* setting ship location on grid  */
        int compare(Grid& a, Grid& b);
        /* compare torpedo locations with ship location */
};

class WaterVehicle
{
    protected:
        int length;
        int x, y;
        string orientation;
        bool sunk;
};

class Submarine : public WaterVehicle
{
    private:
        int depth;
        bool surfaced;
    public:
        Submarine(){};
        Submarine(int lengthV, int xV, int yV, string orientationV, int deptV);
        int getLength();
        int getRow();
        int getColumn();
        int getDepth();
        string getOrientation();
        bool getSunk();
        void setSunk();
        bool getSurfaced();
        void setSurfaced();
        void operator=(Submarine sub);
};

Grid::Grid(){
    /*Create 2D array to size 10 (col) by 10 (row), initiate appropriate values to 0 */
    col = 10;
    row = 10;
    for (int i = 0; i<row ; i++) {      //iterate over row
        for (int j = 0; j<col; j++) {   //iterate over column
            array[i][j] = 0;
        }
    }
}

//setting ship location on grid
void Grid::setLocation(int length, int x, int y, string orientation)
{
    if(orientation == "vertical")
    {
        int endOfShip = length + x;
        for(int i = x; i < endOfShip; i++)
        {
            array[i][y] = 1;
        }
    }
    else if(orientation == "horizontal")
    {
        int endOfShip = length + y;
        for(int i = y; i < endOfShip; i++)
        {
            array[x][i] = 1;
        }
    }
}

int Grid::getCol(){
    /* returns col size */
    return col;
}

int Grid::getRow(){
    /* returns row size */
    return row;
}

int Grid::getVal(int incol, int inrow){
    /* returns value of a specific index */
    return array[inrow][incol];
}

void Grid::print(){
    /* interate over row and col to print grid in understandable order */
    for (int y = 0; y<row ; y++) {
        for (int x = 0; x<col; x++) {
            cout << array[y][x] << " ";//access every value, print space
        }
        cout << endl; //print new line for new row
    }
    
}

void Grid::random(){
    /* fill grid with 1/portion of 1 values in random locations */
    int fill = 15; 
    if (TEST){
        cout << "third of " << (col*row) << " is " << fill << endl;
    }
    int index = 0;
    while (index<fill) {
        int rcol = rand() % col;            //random number for col index
        int rrow = rand() % row;
        if (1!=array[rrow][rcol]) {
            array[rrow][rcol] = 1;          //change value to 1
            index++;                        //one more filled, continue loop
        }                                   //if location already changed, do not iterate, try again.
    }
}
int Grid::compare(Grid& a, Grid& b){
    int hitCounter = 0;
    for (int y = 0; y<10 ; y++) 
    {
        for (int x = 0; x<10; x++) 
        {
            if((a.array[x][y] == 1) && (b.array[x][y] == 1))
            {
                hitCounter++;
            }
        }
    } 
    return hitCounter;
}

Submarine::Submarine(int lengthV, int xV, int yV, string orientationV, int deptV)
{
    length = lengthV;
    x = xV;
    y = yV;
    orientation = orientationV;
    depth = deptV;
    sunk = false;
    surfaced = false;
}

void Submarine::operator=(Submarine sub)
{
    length = sub.length;
    x = sub.x;
    y = sub.y;
    orientation = sub.orientation;
    sunk = sub.sunk;
    depth = sub.depth;
    surfaced = sub.surfaced;
}

int Submarine::getLength()
{
    return length;
}

int Submarine::getRow()
{
    return x;
}

int Submarine::getColumn()
{
    return y;
}

int Submarine::getDepth()
{
    return depth;
}

string Submarine::getOrientation()
{
    return orientation;
}

bool Submarine::getSunk()
{
    return sunk;
}

void Submarine::setSunk()
{
    sunk = true;
}

bool Submarine::getSurfaced()
{
    return surfaced;
}

void Submarine::setSurfaced()
{
    surfaced = true;
}
// ###################################CLASS DEFINITION ENDS################################

int main() {
    srand(time(NULL));      //seed rand for different values each time

    int x=0,y=0;
    int length, dept, startx, starty;
    string orientation;
    cout << "Enter length: " << endl;
    cin >> length;
    cout << "Enter depth: " << endl;
    cin >> dept;
    //starting x and y is the cordinate of the end of the ship(Start from 0)
    cout << "Enter starting grid location(Starting row(0-9)): " << endl;
    cin >> startx;
    cout << "Enter starting grid location(Starting column(0-9)): " << endl;
    cin >> starty;
    cout << "Enter orientation(horizontal or vertical): " << endl;
    cin >> orientation;
    Submarine sub(length, startx, starty, orientation, dept);
    //Torpedo Grid
    Grid a;
    //Submarine location Grid
    Grid b;
    a.random();
    cout << endl;
    cout << "Shot Locations: " << endl;
    a.print();
    b.setLocation(length, startx, starty, orientation);  
    cout << "Submarine Location: " << endl;
    b.print();
    int hitCounter = a.compare(a, b);
    //if hit == 2 then sunk
    if(hitCounter >= 2)
    {
        cout << "Result: " << "sunk" << endl;
        sub.setSunk();
    }
    else if(hitCounter == 1)
    {
        cout << "Result: " << "hit" << endl;
        sub.setSurfaced();
    }
    else
    {
        cout << "Result: " << "missed" << endl;
        sub.setSurfaced();
    }
    cout << endl;
    Submarine sub2;
    //sub2
    sub2 = sub;
    cout << "Submarine 2 information: " << endl;
    cout << "Length: " << sub2.getLength() << endl;
    cout << "Starting row: " << sub2.getRow() << endl;
    cout << "Starting column: " << sub2.getColumn() << endl;
    cout << "Orientation: " << sub2.getOrientation() << endl;
    cout << "Depth: " << sub2.getDepth() << endl;
    if(sub2.getSunk() == true)
    {
        cout << "Sunk: True"<< endl;
    }
    else
    {
        cout << "Sunk: False"<< endl; 
    }
    if(sub2.getSurfaced() == true)
    {
        cout << "Surfaced: True"<< endl;
    }
    else
    {
        cout << "Surfaced: False"<< endl; 
    }
    return 0;
}
