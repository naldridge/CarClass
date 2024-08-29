# CarClass
C++ Car Class assignment for Programming Fundamentals 2

Creating and using a class in C++
For this assignment you will create a class, class header file and a test program.
Name your class Car and contain the following attributes:
• Miles Per Gallon
• Odometer
• Fuel in Tank
• Fuel Tank Size
Be sure Miles per gallon and fuel in tank are floating point numbers. The odometer should
be in integer miles.
Your Car class will implement the following methods.
• Add gas. It should take a floating point number and adjust the amount of fuel
in the tank. Be sure that you do not allow the tank to be overfilled.
• Drive. This method should take an integer for the number of miles driven. It
will calculate and update the new remaining fuel. Be sure it does not allow you
to drive more that the current fuel will allow (No driving on an empty tank). It
should update the odometer based on the miles driven. If there is not enough
fuel for the requested range. Only deduct the amount of miles driven until the
car ran out of gas.
You may add any additional methods and attributes that you think are necessary to
implement the requirements.
Create a car.cpp and a car.h file. Include the definition of the class in the car.h file.
Place the implementation in the car.cpp. You are allowed to place constructors and
destructors in the header file, but the add gas and drive methods should be in the
car.cpp file.
The test program should do the following:
• Create a car object.
• Place a test menu in a loop. The menu should have the following options
o Add gas.
o Drive.
o Exit.
• If the user adds gas or drives, prompt for the required value. Make sure the
value is a valid type (i. e. float or int)
• After calling either add gas or drive. Display the resulting odometer and
remaining fuel.
Test your code, including giving it garbage.
Be sure your code is well commented. Comments make up 25% of the grade