/*
  Sophie Samuels
  COP 3014
  Assignment 7
  07.16.2024
*/


#include <iostream> //standard input/output stream library
using namespace std; //omit std:: prefix




//rational number class
class RationalNumber
{
private:
  int numerator;
  int denominator;


  //function to calc greatest common divisor (gcd)
  int gcd(int x, int y) const;


  //function to reduce rational number
  void reduce();


public:
  //constructor declarations
  //default construtor to initialize rational num to 0/1
  RationalNumber();


  //constructor including 2 int parameters, initializes num/num
  RationalNumber(int num, int den);


  //constructor including 1 int parameter, initializes num/1
  RationalNumber(int num);


  //declare friend functions for input and output
  //friend: need to acces private/protected data members of the class
  //overload functions for reading / writing rational numbers
  friend istream& operator >> (istream& ins, RationalNumber& rat);
  friend ostream& operator << (ostream& outs, const RationalNumber& rat);


  //declare operation overloads for boolean/comparison operators
  //including const indicates the operations do not modify the object(s) they are called on
  bool operator==(const RationalNumber& other) const;
  bool operator<(const RationalNumber& other) const;
  bool operator<=(const RationalNumber& other) const;
  bool operator>(const RationalNumber& other) const;
  bool operator>=(const RationalNumber& other) const;
  bool operator!=(const RationalNumber& other) const;


  //declare operation overloads for arithmetic operators
  //including const indicates the operations do not modify the object(s) they are called on
  RationalNumber operator+(const RationalNumber& other) const;
  RationalNumber operator-(const RationalNumber& other) const;
  RationalNumber operator*(const RationalNumber& other) const;
  RationalNumber operator/(const RationalNumber& other) const;


  //declare operation overload for unary operator -
  //including const indicates the operations do not modify the object(s) they are called on
  RationalNumber operator-() const;


  //declare static member function to allow testing of all overloaded operators
  //https://www.geeksforgeeks.org/static-member-function-in-cpp/
  static void DemonstrateOperations();


  //declare static member function to allow testing of constructors
  static void TestConstructors();
};




//main function
int main() {


  //call static member function to demonstrate performance of all overloaded operators
  //outputs results to screen
  RationalNumber::DemonstrateOperations();


  //test constructor
  //outputs results to screen
  RationalNumber::TestConstructors();


  //special test cases
  cout << "Testing special cases:" << endl;
  cout << endl;
  //zero tests
  RationalNumber zero(0, 1);
  RationalNumber R3(5/6);
  cout << "Add zero: " << R3 + zero << " (Expected: 5/6)" << endl;
  cout << endl;
  //division by zero test
  RationalNumber divByZero = R3 / zero;
  cout << "Divide by zero: " << divByZero << endl;
  cout << endl;
  //zero divided by zero test
  RationalNumber zeroByZero = zero / zero;
  cout << "Divide zero by zero: " << zeroByZero << " (Expected: 0/1)" << endl;
  cout << endl;
  //negative number test
  RationalNumber negative(-2, 3);
  cout << "Negative number: " << negative << " (Expected: -2/3)" << endl;
  cout << endl;
  //inversion of number test
  RationalNumber inversion(1, -5);
  cout << "Inverted number: " << inversion << " (Expected: -1/5)" << endl;
  cout << endl;
  //large numbers test
  RationalNumber big(600000000, 300000000);
  cout << "Large number: " << big << " (Expected: 2/1)" << endl;
  cout << endl;




  return 0;
}


//function definitions
//function to calc greatest common divisor (gcd)
int RationalNumber::gcd(int x, int y) const {
  while (y != 0) {
    int temp = y;
    y = x % y; //modulo operator for correct calc
    x = temp;
  }
  return x;
}


//function to reduce rational number
void RationalNumber::reduce() {
  int div = gcd(numerator, denominator);
  numerator /= div;
  denominator/= div;


  if (denominator < 0) { //make sure denominator is positive
    numerator = -numerator;
    denominator = -denominator;
  }
}


//default construtor to initialize rational num to 0/1
RationalNumber::RationalNumber() : numerator(0), denominator(1) {}


//constructor including 2 int parameters, initializes num/num
RationalNumber::RationalNumber(int num, int den) : numerator(num), denominator(den) {
  if (den == 0) {
    cout << "Denominator cannot be zero" << endl;
    numerator = 0;
    denominator = 1;
  } else {
    reduce();
  }
}


//constructor including 1 int parameter, initializes num/1
RationalNumber::RationalNumber(int num) : numerator(num), denominator(1) {}


//define friend function for input
//overload the input operator to read rational numbers
istream& operator >> (istream& ins, RationalNumber& rat) { 
  char obelus;
  ins >> rat.numerator >> obelus >> rat.denominator; 
  if (rat.denominator == 0) { //makes sure denominator is not zero
    cout << "Denominator cannot be zero" << endl;
    rat.numerator = 0;
    rat.denominator = 1; //if denominator zero, sets num to 0/1 and prints error message (above)
  } else {
    rat.reduce(); //if denominator is not zero, function called to reduce fraction
  }
  return ins;
}


//define friend function for output
//overload the output operator to write rational numbers
ostream& operator << (ostream& outs, const RationalNumber& rat) { 
  outs << rat.numerator << '/' << rat.denominator; //outputs rational number in numerator/denominator
  return outs;
}


//define overload for equality operator
// (a/b) == (c/d) means (a * d) == (c * b) 
bool RationalNumber::operator==(const RationalNumber& other) const {
  return (numerator * other.denominator) == (other.numerator * denominator);
}


//define overload for less than operator
// (a/b) < (c/d) means (a * d) < (c * b)
bool RationalNumber::operator<(const RationalNumber& other) const {
  return (numerator * other.denominator) < (other.numerator * denominator);
}


//define overload for less than or equal to operator
// (a/b) <= (c/d) means (a * d) <= (c * b)
bool RationalNumber::operator<=(const RationalNumber& other) const {
  return (numerator * other.denominator) <= (other.numerator * denominator);
}


//define overload for greater than operator
// (a/b) > (c/d) means (a * d) > (c * b)
bool RationalNumber::operator>(const RationalNumber& other) const {
  return (numerator * other.denominator) > (other.numerator * denominator);
}


//define overload for greater than or equal to operator
// (a/b) >= (c/d) means (a * d) >= (c * b)
bool RationalNumber::operator>=(const RationalNumber& other) const {
  return (numerator * other.denominator) >= (other.numerator * denominator);
}


//define overload for inequality operator
// (a/b) != (c/d) means (a * d) != (c * b)
bool RationalNumber::operator!=(const RationalNumber& other) const {
  return (numerator * other.denominator) != (other.numerator * denominator);
}


//define overload for addition operator
// a/b + c/d = (a * d + b * c) / (b * d)
RationalNumber RationalNumber::operator+(const RationalNumber& other) const {
  int num = (numerator * other.denominator) + (denominator * other.numerator);
  int den = denominator * other.denominator;
  return RationalNumber(num, den);
}


//define overload for subtraction operator
// a/b - c/d = (a * d - b * c) / (b * d)
RationalNumber RationalNumber::operator-(const RationalNumber& other) const {
  int num = (numerator * other.denominator) - (denominator * other.numerator);
  int den = denominator * other.denominator;
  return RationalNumber(num, den);
}


//define overload for multiplication operator
// (a/b) * (c/d) = (a * c) / (b * d)
RationalNumber RationalNumber::operator*(const RationalNumber& other) const {
  int num = numerator * other.numerator;
  int den = denominator * other.denominator;
  return RationalNumber(num, den);
}


//define overload for division operator
// (a/b) / (c/d) = (a * d) / (c * b)
RationalNumber RationalNumber::operator/(const RationalNumber& other) const {
  if (other.numerator == 0) {
    cout << "Division by zero" << endl;
    return RationalNumber(0, 1);
  }
  int num = numerator * other.denominator;
  int den = other.numerator * denominator;
  return RationalNumber(num, den);
}


//define overload for unary minus operator
// -(a/b) = (-a/b)
RationalNumber RationalNumber::operator-() const {
  return RationalNumber(numerator, denominator);
}


//define static member function to allow testing of all overloaded operators
void RationalNumber::DemonstrateOperations() {
  
  //declare objects of class RationalNumber
  RationalNumber Num1, Num2;
  //prompt user to enter two rational numbers
  cout << "Enter the first rational number as a/b format: ";
  cin >> Num1;
  cout << "Enter the second rational number as a/b format: ";
  cin >> Num2;
  cout << endl;
  
  cout << "You entered: " << endl;
  cout << "Rational Number 1: " << Num1 << endl;
  cout << "Rational Number 2: " << Num2 << endl;
  cout << endl;
  
  //demonstrate boolean/comparison operations on the entered rational numbers
  //output results of each
  cout << "Boolean Opeations: " << endl;
  cout << endl;
  
  if (Num1 == Num2) { //equality operator
    cout << Num1 << " == " << Num2 << " is true." << endl;
  } else {
    cout << Num1 << " == " << Num2 << " is false." << endl;
  }


  if (Num1 < Num2) { //less than operator
  cout << Num1 << " < " << Num2 << " is true." << endl;
  } else {
    cout << Num1 << " < " << Num2 << " is false." << endl;
  }


  if (Num1 <= Num2) { //less than or equal to operator
    cout << Num1 << " <= " << Num2 << " is true." << endl;
    } else {
      cout << Num1 << " <= " << Num2 << " is false." << endl;
    }


  if (Num1 > Num2) { //greater than operator
    cout << Num1 << " > " << Num2 << " is true." << endl;
    } else {
      cout << Num1 << " > " << Num2 << " is false." << endl;
    }


  if (Num1 >= Num2) { //greater than or equal to operator
    cout << Num1 << " >= " << Num2 << " is true." << endl;
    } else {
      cout << Num1 << " >= " << Num2 << " is false." << endl;
    }


  if (Num1 != Num2) { //inequality operator
    cout << Num1 << " != " << Num2 << " is true." << endl;
    } else {
      cout << Num1 << " != " << Num2 << " is false." << endl;
    }


  cout << endl;
  
  //demonstrate arithmetic operations on the entered rational numbers
  //output results of each
  cout << "Arithmetic Operations: " << endl;
  RationalNumber sum = Num1 + Num2;
  cout << Num1 << " + " << Num2 << " = " << sum << endl;
  
  RationalNumber difference = Num1 - Num2;
  cout << Num1 << " - " << Num2 << " = " << difference << endl;
  
  RationalNumber product = Num1 * Num2;
  cout << Num1 << " * " << Num2 << " = " << product << endl;
  
  RationalNumber quotient = Num1 / Num2;
  cout << Num1 << " / " << Num2 << " = " << quotient << endl;


  cout << endl;
  
  //demonstrate unary operation -
  //output result
  cout << "Negation Operation: " << endl;
  RationalNumber negatedNum1 = -Num1;
  cout << "Negation of " << Num1 << " = " << -negatedNum1 << endl;
  RationalNumber negatedNum2 = -Num2;
  cout << "Negation of " << Num2 << " = " << negatedNum2 << endl;


  cout << endl;
  cout << "Demonstration Complete." << endl;
  cout << endl;
}


//define static member function to allow testing of constructors
void RationalNumber::TestConstructors() {
  cout << "Testing constructors:" << endl;
  cout << endl;
  
  RationalNumber thisNum;
  cout << "Default: " << thisNum << " (Expected: 0/1)" << endl;
  cout << endl;


  RationalNumber singleParameter(8);
  cout << "Single parameter: " << singleParameter << " (Expected: 8/1)" << endl;
  cout << endl;


  RationalNumber doubleParameter(3, 9);
  cout << "Double parameter: " << doubleParameter << " (Expected: 1/3 after reduced)" << endl;
  cout << endl;
}
