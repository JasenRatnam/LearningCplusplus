/*
 * Author: Jasen Ratnam 40094237
 * Date: 10/22/2018
 * Due: 10/26/2018
 * Assignment 3: User-Defined Functions/ Arrays
 * This program will control the movements of n object in a 10x10 grid.
 * the object will initial start at position (0,0). and will take the following
 * commands:
 * 1) up(n): move upwards of n cells.
 * 2) down(n): move downwards of n cells.
 * 3) turn right (n): turn right and move n cells.
 * 4) turn left (n): turn left and move n cells.
 * 5) reboot: return the object back to cell (0,0)
 */


#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cctype>
#include <sstream> 
#include <cstring> 

using namespace std;

int main()
{
    // 2D-array for the grid.
    string grid [10][10];
    // string array to save the last command.
    string lastCommand[10];
    
    // initialize grid.
    for (int i=0; i<10; i++) 
    {
        for (int j=0; j<10; j++)
        {
            grid[i][j] = '.';       
        }
    }
    
    // get menu choice from the user
    int choice;
    // give choices
    cout << "\nChoose one of the following options: \n"
            "1. Down\n"
            "2. Up\n"
            "3. Turn Right\n"
            "4. Turn Left\n"
            "5. Reboot\n"
            "6. Show Grid\n"
            "7. Cancel\n"
            "8. Replay\n"
            "9. Position\n"
            "10. Exit\n\n";

    // save choices
    cin >> choice;
    cout << "\n";

    // initialize position.
    int x = 0;
    int y = 0;
    int j = 0;
    bool playing = true;
    
    // until the user choose to quit.
    while(playing)
    {
        // Switch for the different choices.
        switch(choice)
        {
            case 1: // going down
            {
               // if the y position is 10 or bigger
               // the command cant be done
               // error message.
                if(y >= 10)
                {
                    cout << "Incorrect input, out of bounds.";
                    break;
                }
                
                else
                {
                    // make the y-position increment by 1.
                    int z = y + 1;
                    // make vertical line until new position
                    for(int i = y; i <= z-1; i++)
                    {
                        grid [i][x] = "|";
                    }
                    // save new position
                    y = z;
                    // save command
                    lastCommand[j] = "down";
                    j++; 
                    break;
                }
            }
            case 2: // going up
            {
                // if the y position is 0 or smaller
               // the command cant be done
               // error message.
                if(y <= 0)
                {
                    cout << "Incorrect input, out of bounds.";
                    break;
                }
                
                else
                {
                     // make the y-position decrement by 1.
                    int z = y - 1;
                    // make vertical line until new position
                    for(int i = y; i <= z-1; i--)
                    {
                        grid [i][x] = "|";
                    }
                    // save new position
                    y = z;
                    // save command
                    lastCommand[j] = "up";
                    j++;
                    break;
                }
            }
            case 3: // going right
            {
                // if the x position is 10 or bigger
               // the command cant be done
               // error message.
                if(x >= 10)
                {
                    cout << "Incorrect input, out of bounds.";
                    break;
                }
                
                else
                {
                    // make the x-position increment by 1.
                    int z = x + 1;
                     // make horizontal line until new position
                    for(int i = x; i <= z-1; i++)
                    {
                        grid [y][i] = "-";
                    }
                    // save new position
                    x = z;
                    // save command
                    lastCommand[j] = "right";
                    j++;
                    break;
                }
            }
            case 4: // going left
            {
                // if the x position is 0 or smaller
               // the command cant be done
               // error message.
                if(x <= 0)
                {
                    cout << "Incorrect input, out of bounds.";
                    break;
                }
                
                else
                {
                    // make the x-position decrement by 1.
                    int z = x - 1;
                    // make horizontal line until new position
                    for(int i = x; i <= z-1; i--)
                    {
                        grid [y][i] = "-";
                    }
                      // save new position
                    x = z;
                     // save command
                    lastCommand[j] = "left";
                    j++;
                    break;
                }
            }
            case 5: // reboot object back to cell (0,0)
            {
                // make position of ball (0,0)
                    x = 0; 
                    y = 0;
                    
                    // remove all lines and replace it with default
                    for (int i=0; i<10; i++) 
                    {
                        for (int j=0; j<10; j++)
                        {
                            grid[i][j] = '.';       
                        }
                    }
                    break;
            }
            case 6: // Print graph
            {
                // place ball in grid
                grid[y][x] = 'O';               
    
                // print the entire grid.
                for (int i=0; i<10; i++)        //Prints finished grid
                {
                    for (int j=0; j<10; j++)
                    {
                        cout << grid[i][j];
                    }
                    cout<<"\n";
                } 
                // reset ball to default
                grid[y][x] = '.';      
                    break;
            }
            case 7: // cancel last move
            {   // doesn't work proprelly dont know why?
                // find out what last command was do the inverse movement.
                if(lastCommand[0] == "down")
                {// do up movement
                    int z = y - 1;
                    for(int i = y; i <= z-1; i--)
                    {
                        grid [i][x] = "|";
                    }
                    y = z;
                    // remove last movement from array
                    for (int i = 0; i < 8; ++i)
                    {
                        lastCommand[i] = lastCommand[i + 1]; // copy next element left
                    }
                    break;
                }
                if(lastCommand[0] == "up")
                {// do down movement
                    int z = y + 1;
                    for(int i = y; i <= z-1; i++)
                    {
                        grid [i][x] = "|";
                    }
                    y = z;
                    // remove last movement from array
                    for (int i = 0; i < 8; ++i)
                    {
                        lastCommand[i] = lastCommand[i + 1]; // copy next element left
                    }
                    break;
                }
                if(lastCommand[0] == "right")
                {// do left movement
                    int z = x - 1;
                    for(int i = x; i <= z-1; i--)
                    {
                        grid [y][i] = "-";
                    }
                    x = z;
                    // remove last movement from array
                    for (int i = 0; i < 8; ++i)
                    {
                        lastCommand[i] = lastCommand[i + 1]; // copy next element left
                    }
                    break;
                }
                if(lastCommand[0] == "left")
                {// do right movement
                    int z = x + 1;
                    for(int i = x; i <= z-1; i++)
                    {
                        grid [y][i] = "-";
                    }
                    x = z;
                    // remove last movement from array
                    for (int i = 0; i < 8; ++i)
                    {
                        lastCommand[i] = lastCommand[i + 1]; // copy next element left
                    }
                    break;
                }
                    break;
            }
            case 8:
            {// Dont know what to do 
                    break;
            }
            case 9:
            {
                // print out the position of the ball. 
                cout << "x = " << x << "y = " << y;
                    break;
            }
            case 10:
            {
                // make boolean false and exit loop.
                    playing = false;
                    break;
            }
            default: 
                // ask for new input if wrong value.
                cout << "Invalid input.\n Please input a valid number.";
        }
        
        if(playing) // ask for new input.
        {
            cout << "\nPlease choose another option from the menu: ";

            cin >> choice;
            cout << "\n";
        }
    }
    return 0;
}

