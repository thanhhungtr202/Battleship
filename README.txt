Name: Thanh Hung Tran
ID: 109688640

Structure of program:
---------------------
File organization: main.cpp
Functional organization: Class WaterVehicle contains length, starting row/column, orientation, sunk. Class Submarine inherit all of 
these variables while also having depth, surfaced, and its constructors, accessors and mutators functions. Overloaded operator =
is used to assign the values from the first submarine to the second submarine. main() propmt the user for all of the neccessary inputs
(starting row and column inputs are from 0-9, starting row and column is the cordinate of the end of the ship), then calling 
the respectives functions to determine whether or not the submarine was hit, miss, or sunk (2 hit = sunk). It will then output the shot grid locations, submarine location,  and whether or not the submarine was hit, miss, or 
sunk as well as all of the information of the second submarine

Status: It works completely

Hardware & Platform I used: Ryzen 7 5700U processor with 12GB RAM(Window 10 version 20H2 operating system)

Compile: extract the archive, and then from a shell run "make". This will create an executable "hw4". Then run ./hw4

