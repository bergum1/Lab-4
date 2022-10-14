/*
 Austin Bergum
 C++ Fall 2022
 Due: 14 October 2022
 Lab 4 Temperature Output
 Description: Design and write a C++ program that inputs a series of hourly temperature
 from a file, and outputs a bar chart (using stars) of the temperatures. The temperature
 should be printed to the left of the corresponding bar, and there should be a heading
 that gives the scale of the chart. The range of temperatures should be from  -30 to 120.
 Because it is hard to display 150 characters on the screen, you should have each star
 represent a range of 3 degrees. That way, the bars will be at most 50 characters wide.
 Use meaningful variable names, proper indentation, and appropriate comments.
 Thoroughly test the program using your own data sets. Make sure to vet the values from
 the input file.
 */

#include <iostream> //library <iostream> to output
#include <fstream> //library <fstream> to read in data from file

void input(int &data, int &t, int &spaces); //void function call with pass by reference variables
void graph_output(); //void function call with pass by reference variables
void positive_stars(int &data, int &t, int &spaces); //void function call with pass by reference variables
void negative_spaces(int &data, int &t, int &spaces); //void function call with pass by reference variables

using namespace std;

int main() // pre-condition: main function outputs everything to the screen, <iostream> is needed for this. post-condition: everything is outputted to the screen.
{
    graph_output(); //
    int data; //data is the values from the infile being outputted on the screen seen on the left hand side
    int t; //t is the number of stars being outputted to the screen
    int spaces; //spaces is the ammount of space needed to alighn the stars from the data on the negative side
    input(data, t, spaces); // void input function being declared

    return 0;
}

void input( int &data, int &t, int &spaces ) //pre-condition: fstream needed to read in the file. post-condition: data is being read in from the file which then is later outputted to the screen and used to declare the number of stars needed to be outputted
{
    ifstream inFile;
    inFile.open("/Users/austinbergum/Desktop/Xcode Projects/Lab 4/Lab4.dat");
    
    if (!inFile) //outputs "cant find file" to the screen if the code cannot locate the file location
    {
        cout << "Can't find file..." << endl << endl;
    }
    
    inFile >> data;
    
    while (inFile) //loop created to assing data point to t variable which lets the code know how many stars needed to be outputted for that number
    {
        t = data/3;
        spaces = 10 + t;
        if (data == 0) //outputs data = 0 to show that it's a temperature
        {
            cout << setw(3) << data << "             |" << endl;
        }
        if (data == -1) //outputs data = -1
        {
            cout << setw(3) << data << "             |" << endl;
        }
        positive_stars(data, t, spaces); //declare positive_stars function here to run in the while loop to tell the program what stars need to be outputted for each number.
        inFile >> data; //reads in the data
    }
}

void positive_stars( int &data, int &t, int &spaces ) //void function declares how many stars need to exist for each data point number. pre-condition: <iomanip> is needed in order to use setw(). Did not include it about because the code ran fine without it, which means that <iomanip> must already exist in one of the libraries. post-condition: if statements created to set values for stars, to be outputted between a certain range of numbers, and to output lines after the stars are finished being made. this whole function outputs all the data and stars on the screen, then is later declared in the while loop of the input void function so that is runs for every number inputted in the infile.
{
    if (data > -31 && data < -1)
    {
        cout << setw(3) << data << setw(3);
        negative_spaces(data, t, spaces);
    }
        if (data > -31 && data < -1)
    {
        for (int i = 0; t < i; i--)
        {
            cout << "*";
        }
        
        if (data % -3 < -1)
        {
            cout << "*" << "|" << endl;
        }
        else
        {
            cout << "|" << endl;
        }
    }
    if (data > 0 && data < 121)
    {
        cout << setw(3) << data << "             |";
        for (int i = 0; i < t; i++)
        {
            cout << "*";
        }
        if (data % 3 > 1)
        {
            cout << "*" << endl;
        }
        else
        {
            cout << endl;
        }
    }
}

void graph_output() //pre-condition: <iostream> neede to output on the screen. post-condition: outputs to the screen and lets viewers know the values that the stars represent.
{
    cout << "Temperatures for 24 hours:" << endl << "    -30         0         30        60        90       120" << endl;
}

void negative_spaces( int &data, int &t, int &spaces) //created a for loop to make space between the data thats outputted and the stars do that the stars allign from the right and print out to the left if that makes sense
{
    for (int i = 0; i <= spaces; i++)
    {
        cout << " ";
    }
}
