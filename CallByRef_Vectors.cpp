/*
Sophie Samuels
COP 3014 - Assignment 3
06.09.2024
*/
 
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <limits>
using namespace std;
 
//function prototypes
//calculates and returns monthly interest rate
double calcMonthlyInterestRate(double APR);
//calculates and returns amortization AKA monthly payment
double calcAmortization(double P, double r, int n);
//calculates monthly interest and principal balance
void calcMonthlyIP(double P, double r, int n, double M, double& totalInterest, double& totalPaid);
//keeps track of total payments and interests accumulated
void calcTotals(double P, double r, int n, double& totalPaid, double& totalInterest);
//prompts and allows user to enter input for P, APR, and n
void inputValues(double& P, double& APR, int& n);
//displays tabular information
void outputInformation(double P, double r, int n, double &totalPaid, double &totalInterest);
//displays summary of payments at the end
void displaySummary(double M, double& totalPaid, double& totalInterest);
 
 
int main() {
 
 //Initialize variable for menu
 char choice; //choice = user's choice to continue or quit program
 
 do { //do while loop to allow user to continue or quit program
     cout << endl;
         cout << "Menu:" << endl;
         cout << "Calculate Loan Amortization Schedule: Enter C" << endl;
         cout << "Exit: Enter E" << endl;
         cout << "Enter your choice and press return: ";
     //get choice from user
     cin >> choice;
     choice = toupper(choice); //convert choice to uppercase
 
     if (choice == 'C') {
       //initialize variables
       double APR, P, r, M; //APR = annual percentage rate, P = principal, r = monthly interest rate, M = monthly payment
       double totalInterest, totalPaid; //totalInterest = total interest paid, totalPaid = total amount paid
       int n; //n = number of months/payments
         
       //function calls
       //prompts and allows user to enter input for P, APR, and n
       inputValues(P, APR, n);
     
       //calculates and returns monthly interest rate
       r = calcMonthlyInterestRate(APR);
     
       //display tabular information
       outputInformation(P, r, n, totalPaid, totalInterest);
     
       //display summary of payments at the end
       M = calcAmortization(P, r, n); //calculate monthly payment to include and pass to displaySummary
       
       displaySummary(M, totalPaid, totalInterest); //displays information for final output
       
     } else if (choice != 'E') {
       cout << "Invalid choice. Please try again." << endl;
     }
 } while (choice != 'E'); //loop continues until user enters 'E' to exit program
     
 cout << "Thank you for using the loan calculator. Exiting program." << endl;
 
 return 0;
}
 
//function definitions
//calculates and returns monthly interest rate
double calcMonthlyInterestRate(double APR) {
 
 return pow((1 + (APR / 100)), (1.0 / 12)) - 1; //convert APR to monthly percentage rate
}
 
//calculates and returns amortization AKA monthly payment
double calcAmortization(double P, double r, int n) {
 
 double M = P * (r * pow((1 + r), n)) / (pow((1 + r), n) - 1); //amortization equation
 return M;
}
 
//calculates monthly interest and principal balance
void calcMonthlyIP(double P, double r, int n, double M, double& totalInterest, double& totalPaid) {
 
 double balance = P;
 totalInterest = 0;
 totalPaid = 0;
 
 cout << fixed << setprecision(2); //set precision of outputs to 2 decimal places
 
 //display headers using cout.width() to align columns
 cout << endl;
 cout.width(2);
 cout << "Month";
 cout.width(3);
 cout << "";
 cout.width(10);
 cout << "Beginning Balance";
 cout.width(14);
 cout << "Interest";
 cout.width(14);
 cout << "Principal";
 cout.width(5);
 cout << "";
 cout.width(14);
 cout << "Remaining Balance" << endl;
 
 for (int month = 1; month <= n; ++month) { //loop to calculate monthly totals
 
   double interest = balance * r; //calculate interest of each month's balance
   double principal = M - interest; //calculate principal amount of each month by subtracting interest from amortized amount
   double beginningBalance = balance; //set monthly beginning balance to current balance for value before monthly payment is made
   balance -= principal; //make balance current by subtracting principal amount due
   totalInterest += interest; //make lifetime interest current by adding current month's interest to total interest amount
   totalPaid += M; //make lifetime paid current by adding current month's balance to total remaining balance
 
   //display monthly values
   cout << endl;
   cout.width(2);
   cout << month;
   cout.width(18);
   cout << beginningBalance;
   cout.width(18);
   cout << interest;
   cout.width(14);
   cout << principal;
   cout.width(15);
   cout << fabs(balance) << endl << endl; //use of fabs to return absolute value, correcting final ending balance value //reference from ZyBooks*
 }
}
 
//keeps track of total payments and interests accumulated
void calcTotals(double P, double r, int n, double& totalPaid, double& totalInterest) {
 
 double M = calcAmortization(P, r, n); //calculate monthly payment
 calcMonthlyIP(P, r, n, M, totalInterest, totalPaid); //calculate monthly interest and principal balances
}
 
//prompts and fills input for P, APR, and n
void inputValues(double& P, double& APR, int& n) {
 
 //https://www.geeksforgeeks.org/ask-user-input-until-correct-input-is-received-in-cpp/ Reference*
 //https://cplusplus.com/forum/beginner/2957/ Reference*
 
 //validate the input for P
 while (true) {
   cout << "Enter the loan amount: ";
   cin >> P;
   if (cin.fail() || P <= 0) { //cin.fail() checks if input is not a number;  <= 0 checks if input is negative
     cin.clear(); //clears error
     cin.ignore(numeric_limits<streamsize>::max(), '\n'); //removes invalid input
     cout << "Invalid input. Please enter a positive integer: ";
   } else {
     cout << "Loan amount: $" << P << endl;
     break;
   }
 }
 
 //validate the input for APR
 while (true) {
   cout << "Enter the annual percentage rate of the loan: ";
   cin >> APR;
   if (cin.fail() || APR <= 0) { //cin.fail() checks if input is not a number;  <= 0 checks if input is negative
     cin.clear(); //clears error
     cin.ignore(numeric_limits<streamsize>::max(), '\n'); //removes invalid input
     cout << "Invalid input. Please enter a positive integer: ";
   } else {
     cout << "APR: " << APR << "%" << endl;
     break;
   }
 }
 
 //validate the input for n
 while (true) {
   cout << "Enter the number of months / payments of the loan: ";
   cin >> n;
   if (cin.fail() || n <= 0) { //cin.fail() checks if input is not a number;  <= 0 checks if input is negative
     cin.clear(); //clears error
     cin.ignore(numeric_limits<streamsize>::max(), '\n'); //removes invalid input
     cout << "Invalid input. Please enter a positive integer: ";
   } else {
     cout << "Time for repayment (in months): " << n << endl;
     break;
   }
 }
}
 
//displays tabular information
void outputInformation(double P, double r, int n, double& totalPaid, double& totalInterest) {
 
 double M = calcAmortization(P, r, n); //calculate monthly payment
 calcMonthlyIP(P, r, n, M, totalInterest, totalPaid); //calculate and display monthly interest and principal balances
}
 
//displays summary of payments at the end
void displaySummary(double M, double& totalPaid, double& totalInterest) {
 
 cout << "Payment Every Month: $" << M << endl << endl;
 cout << "Total Payments: $" << totalPaid << endl << endl;
 cout << "Total Interest: $" << totalInterest << endl;
}
