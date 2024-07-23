/*
Sophie Samuels
COP3014 - Assignment 1
05.26.2024
*/


#include <iostream>
#include <cmath>
#include <cstdio>
#include <iomanip>
using namespace std;


int main() {

    //declare constant variables
    const double Y = 62.4; // Specific weight of water in lb/ft^3
    const double PI = 3.141592653589793; // Constant value of PI

    
    //Menu with options for Q1, Q2, Exit
    int choice; //declare variable 'choice'
    
    do {
        cout << endl;
            cout << "Menu:" << endl;
            cout << "1. Predict buoyancy of sphere in water (Q1)" << endl;
            cout << "2. Solve quadratic equation (Q2)" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice and press return: ";
        //get choice from user
        cin >> choice;

        //switch statement to determine which function to call
        switch (choice) {
            case 1: {
                //Variables
                double weight; //pounds
                double radius; //feet
                double volume; //Volume of sphere
                double buoyantForce; //Buoyant force

                //Inputs
                cout << "Enter the weight of the sphere (in pounds): ";
                cin >> weight;
                cout << "Enter the radius of the sphere (in feet): ";
                cin >> radius;

                //Calculate volume of sphere
                volume = (4.0 / 3.0) * PI * (radius * radius * radius);

                //Calculate buoyant force
                buoyantForce = volume * Y;

                //set precision of output
                cout << fixed << setprecision(2);

                //display volume
                cout << "The volume of the sphere is: " << volume << " cubic feet" << endl;

                //Determine if sphere will sink or float
                if (buoyantForce >= weight) {
                    cout << "The sphere will float" << endl;
                } else {
                    cout << "The sphere will sink" << endl;
                }
                break;
            }
            case 2: {
                //Variables
                double a, b, c;
                //ask and get coefficients a, b, c
                cout << "Enter coefficient a: ";
                cin >> a;
                cout << "Enter coefficient b: ";
                cin >> b;
                cout << "Enter coefficient c: ";
                cin >> c;

                //set equation for discriminant to determine nature of roots
                double discriminant = b * b - 4 * a * c;
                //declare double variables for root1 and root2
                double root1, root2;

                //set precision of outputs
                cout << fixed << setprecision(3);

                //Determine nature of roots through value of discriminant
                if (discriminant == 0) { 
                    root1 = -b / (2 * a);
                    cout << "The equation has one root: " << root1 << endl;
                } else if (discriminant > 0) {
                    root1 = (-b + sqrt(discriminant)) / (2 * a);
                    root2 = (-b - sqrt(discriminant)) / (2 * a);
                    cout << "The equation has two roots: " << root1 << " and " << root2 << endl;
                } else {
                    double realRoot = -b / (2 * a);
                    double imaginaryRoot = sqrt(-discriminant) / (2 * a);
                    cout << "The equation has two complex roots: " 
                        << realRoot << " + " << imaginaryRoot << "i and " //use of i to represent imaginary number
                        << realRoot << " - " << imaginaryRoot << "i" << endl; //use of i to represent imaginary number
                }
                break;
            }
            case 3: {
                cout << "Exiting program." << endl;
                exit(1);
            }
            default: 
                cout << "Not a valid choice." << endl;
                cout << "Choose from menu options." << endl;
            }
        } while (choice != 3);
    
    return 0;
}
