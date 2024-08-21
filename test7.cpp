//This program uses the Car class.
//The Car class declaration is in file Car.h
//The Car member functions are in Car.cpp
//These files should all be combined into a project.
#include <conio.h>
#include <iostream>
#include <iomanip>
#include <limits>
#include <random>
#include <array>
#include "Car.h"
using namespace std;

string modelName;                               //global variable to store user selected model name

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  +                                      carRandomizer                                       +
  + Function that creates and returns an array of random numbers for user car selection.     +
  + Utilizes Mersenne Twister pseudo-random generator                                        +
  + (https://learn.microsoft.com/en-us/shows/goingnative-2013/rand-considered-harmful)       +
  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
array<int, 4> carRandomizer() {
    array<int, 4> arr;                                   //Local array variable
    int rNum;                                           //Local random int variable to fill array
    random_device rd;                                   //Seed
    mt19937 mt(rd());                                   //Init MT pseudo-rand num generator

    uniform_int_distribution<int> dist(0, 3);           //Uniformly distributed in range (0 , 3)

    for (int i = 0; i < 4; ++i) {
        rNum = dist(mt);
        arr[i] = rNum;
    }

    return arr;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  +                                      errorInput                                          +
  + Function that checks for user input errors. Takes flag to define partial success or total+
  + failure before clearing input buffer.                                                    +
  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void errorInput(bool resolve) {

    if (!resolve) {
        cout << "I didn't understand that. Let's try again." << endl;
        cout << "Remember just type the number." << endl;
        cout << "Press any key to continue." << endl;
        getch();
        system("cls");
    }
    
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    
    return;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  +                                     buildCar()                                           +
  + Creates and returns a locally defined Car Object.                                        +
  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

Car buildCar(int userInput) {
    Car tempItem;                                   //local Car object
    //string modelName;                             //local variable for model name
    int tankSize;                                   //local variable for tank size
    int fuelEconomy;                                //local variable for fuel economy
    int carRand = rand() % 5;

    if (userInput == 1) {
        tankSize = 12;
        fuelEconomy = (rand() % 11) + 14;
    } else if (userInput == 2) {
        tankSize = 18;
        fuelEconomy = (rand() % 9) + 8;
    } else if (userInput == 3) {
        tankSize = 12;
        fuelEconomy = (rand() % 23) + 28;
    }



    //Stores the data in the Car object and return it
    tempItem.buildInfo(tankSize, fuelEconomy);
    return tempItem;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  +                                   welcomeScreen()                                        +
  + Program intro. Outputs strings as a welcome message.                                     +
  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void welcomeScreen() {
    cout << "Welcome to the Grayson College Car Lot!" << endl;
    cout << "Let's get you into a car today." << endl;
    cout << "Press any key when you're ready to get started." << endl;
    getch();                                                         //awaits user input to continue program
    return;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  +                                    carSelect()                                           +
  + Function that takes user input to build and return Car Object.                          +
  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

Car carSelect() {
    bool continueValue = false;
    Car userSelection;
    int modelInput;
    array arrRNum = carRandomizer();                               //random number array
    string arrCars[4][4] = {                                       //multidimensional array for car model names
        {"Ford Mustang", "Chevy Camaro", "Mazda RX-8", "Dodge Charger"},
        {"Ram 1500", "Chevy Colorado", "Ford F-150", "Toyota Tundra"},
        {"Chevy Bolt", "Toyota Prius", "Kia Soul", "BMW X5"},
        {"Lamborghini Murcielago", "Ferrari SF90", "Ford Shelby GT", "Aston Martin Vantage"}
    };

    while (!continueValue) {
        cout << "Alright. Let's see what we have in stock." << endl;
        cout << "Looks like we have 4 models ready to go right now." << endl;
        cout << "Model #1: " << arrCars[0][arrRNum[0]] << "." << endl;
        cout << "Model #2: " << arrCars[1][arrRNum[1]] << "." << endl;
        cout << "Model #3: " << arrCars[2][arrRNum[2]] << "." << endl;
        cout << "Model #4: " << arrCars[3][arrRNum[3]] << "." << endl;
        cout << "Please input the Model # you are interested in." << endl;
        cin >> modelInput;
        
        if ((modelInput > 0) && (modelInput < 4)) {
            modelName = arrCars[(modelInput - 1)][arrRNum[modelInput - 1]];
            cout << "Great selection! Let's show you those stats." << endl;
            userSelection = buildCar(modelInput);
            getch();
            continueValue = true;
            system("cls");
        } else if (modelInput == 4) {
            cout << "Oh come on. Did you really think we stock those here." << endl;
            cout << "Let's try that again." << endl;
            cout << "Press any key when you're ready to continue." << endl;
            getch();
            system("cls");
            errorInput(true);
            continue;
        } else {
            if (cin.fail()) {
                errorInput(false); 
            }
            continue;
        }
    }

    return userSelection;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  +                                     showCar()                                            +
  + Function that displays Car Object stats for user. Takes in Car Object as constant and    +
  + outputs Fuel Tank Size, Fuel Economy, Fuel Remaining, Odometer Reading. Due to constant  +
  + parameter, this function is unable to mutate object data.                                +
  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void showCar(const Car &item) {
    cout << fixed << showpoint << setprecision(2) << endl;
    cout << "Your Car: " << modelName << endl;
    cout << "Fuel Tank Size: " << item.getFuelTankSize() << " gallons." << endl;
    cout << "Fuel Economy: " << item.getMilesPerGallon() << " mpg." << endl;
    cout << "Fuel Remaining: " << item.getFuelInTank() << " gallons remaining." << endl;
    cout << "Odometer Reading: " << item.getOdometer() << " miles." << endl;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  +                                    playMenu()                                            +
  + Function that outputs a game menu for user input.                                        +
  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

int playMenu() {
    int returnValue;

    system("cls");

    cout << "Now you're ready to get moving." << endl;
    cout << "Here are your options:" << endl;
    cout << "1. Show Vehicle Stats." << endl;
    cout << "2. Drive." << endl;
    cout << "3. Fill Gas Tank." << endl;
    cout << "4. Restart Program." << endl;
    cout << "5. Exit Program." << endl;
    cout << "Enter the number for your selection." << endl;
    cin >> returnValue;

    return returnValue;
 }

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  +                                     driveCar()                                           +
  + Function that alters the Car Object based on user input. User inputs miles to drive,     +
  + the function calls Object setter which checks fuel level and sets a new fuel level and   +
  + odometer reading based on miles driven before fuel runs out. A success means the user was+
  + able to drive the entire distance without running out of gas. Partial success is when the+
  + user ran out of gas before completing their journey. Failure results when the user didn't+
  + input a valid float value for the journey.                                               +
  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

bool driveCar(Car &item) {
    bool returnValue = true;
    float milesToDrive;
    int objResponse;

    cout << "Let's hit the road." << endl;
    cout << "How far would you like to drive?" << endl;
    cout << "(Remember we use miles as our unit of measurement.)" << endl;
    cin >> milesToDrive;
    
    objResponse = item.driveCar(milesToDrive);

    if (objResponse == 1) {
        //success
        cout << "Whew. That was a great drive." << endl;
        cout << "Another " << milesToDrive << " miles under your belt." << endl;
        cout << "Press any key to continue." << endl;
        getch();
    } else if (objResponse == 2) {
        //partial success
        cout << "Well it looks like you weren't able to complete your journey." << endl;
        cout << "You'll need to add some gas if you want to continue." << endl;
        cout << "Press any key to continue." << endl;
        getch();
    } else {
        //failure
        returnValue = false;
        cout << "Well your car won't even start." << endl;
        cout << "Did you remember to add gas?" << endl;
        cout << "I hope you didn't put diesel in there. That's going to be a bad day." << endl;
        cout << "While I call AAA, why don't you see what went wrong." << endl;
        cout << "Press any key to continue." << endl;
        errorInput(true);
        getch();
    }

    return returnValue;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  +                                     addGas()                                             +
  + Function that calls the addFuel setter to Car Object. User inputs amount of gas as float,+
  + if the user input an amount less than or equal to what would completely fill the tank    +
  + the setter returns success. If the user iput an amount that would exceed the fuel        +
  + capacity, the setter returns a partial success and only sets the fuelLevel to max. If the+
  + user didn't enter a float value at all, the setter returns a fail.                       +
  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

bool addGas(Car &item) {
    bool returnValue = true;
    float fuelToAdd;
    int objResponse;

    cout << "Let's get you back on the road." << endl;
    cout << "How much gas would you like to add?" << endl;
    cout << "(Remember we use gallons as our units of measurement.)" << endl;
    cin >> fuelToAdd;

    objResponse = item.addFuel(fuelToAdd);

    if (objResponse == 1) {
        //success
        cout << "That's what I'm talking about!" << endl;
        cout << "You're good to go. Get outta here and put some miles on that odometer." << endl;
        cout << "Press any key to continue." << endl;
        getch();
    } else if (objResponse == 2) {
        //partial success
        cout << "Ok. Well that made a mess." << endl;
        cout << "Don't worry I'll clean up the fuel spill." << endl;
        cout << "Why don't you get out of here before my manager sees." << endl;
        cout << "Press any key to continue." << endl;
        getch();
    } else {
        //failure
        returnValue = false;
        errorInput(true);
        cout << "Hmm. Are you sure you're qualified to drive?" << endl;
        cout << "Why don't you double check what you need to do before you go any further." << endl;
        cout << "Press any key to continue." << endl;
        getch();

    }

    return returnValue;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  +                                     gameProcess()                                        +
  + Function that takes in the user created Car Object and moves it to Object getter and     +
  + setter functions based on user selections. Also provides a program exit option. Contains +
  + input validator function call.                                                           +
  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

bool gameProcess(Car &item) {
    bool returnValue = true;

    while (returnValue) {
        int continuePlay = playMenu();
        bool continueValue;
        if (continuePlay == 1) {
            //show stats
            showCar(item);
            cout << "Press any key to continue." << endl;
            getch();
            system("cls");
        } else if (continuePlay == 2) {
            //Drive
            continueValue = driveCar(item);
        } else if (continuePlay == 3) {
            //Fill Tank
            continueValue = addGas(item);
        } else if (continuePlay == 4) {
            //Restart
            cout << "Press any key to restart." << endl;
            getch();
            break;
        } else if (continuePlay == 5) {
            //Exit
            returnValue = false;

        } else {
            if (cin.fail()) {
            errorInput(continueValue); 
            }
        }
    };

    return returnValue;
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  +                                     gameExit()                                           +
  + Outputs strings as a goodbye message.                                                    +
  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void gameExit() {
    cout << "I hate to see you go." << endl;
    cout << "I hope you had some fun at least." << endl;
    cout << "Remember to spay and neuter your pets." << endl;
    cout << "Press any key to confirm exit." << endl;
    getch();

    return;
}

/* *************************************************MAIN******************************************* */
int main() {
    bool gameStart = true;                              //when changed from true to false, runs exit function

    while (gameStart) {
        system("cls");                                  //clears screen
        welcomeScreen();
        system("cls");
        Car player1 = carSelect();

        gameStart = gameProcess(player1);
    }
    
    gameExit();

    return 0;
}