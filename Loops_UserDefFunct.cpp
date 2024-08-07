/*
Sophie Samuels
COP3014 - Assignment 2
06.01.2024
*/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <cstring>
using namespace std;

//function prototypes
void encryption (char original [], char secret [], int key);
void decryption (char original [], char secret [], int key);

int main() {

char originalMessage[1000]; //initiate array for original message 
char secretMessage[1000]; //initiate array for secret message

//decalre variables
int key; //declare int variable key

cout << "Enter message to be encrypted: "; 
cin.getline(originalMessage, 1000); //get user input for original message; 
  //learned from https://www.geeksforgeeks.org/getline-function-c/

cout << "Enter key for encryption (between 1 and 100): "; 
cin >> key; //get user input for key
  
encryption(originalMessage, secretMessage, key); //function call 1
cout << "Encrypted message: " << secretMessage << endl; //print encrypted message

strcpy(secretMessage, ":mmZ\\dxZmx]Zpgy");
cout << "Captured encrypted message: " << secretMessage << endl; //displays encrypted message
  
cout << "Iterating to decrypt the captured message: " << secretMessage << endl; //tells user message is being decrypted
for (int trialkey = 1; trialkey < 101; trialkey++) { //iterates through all possible keys
  decryption(originalMessage, secretMessage, trialkey); //function call 2
  cout << "Possible decryption with use of key  " << trialkey << ": " << originalMessage << endl; //prints each possible decryption
}

  return 0;
}

//function definition for encryption
void encryption(char original[], char secret[], int key) {
  int i = 0; //declare int i and set to 0 to run through each char of array
  while (original[i] != '\0') { //while loop runs through entire array
    if (original[i] + key > 126) { 
      secret[i] = 32 + ((original[i] + key) - 127); //encrypts char if greater than 126
    }
    else {
      secret[i] = (original[i] + key); //encrypts char if less than 126
    }
    i++; //iterates through each char of the array 
  }
  secret[i] = '\0'; //end the encrypted message with a null character
}

//function definition for decryption (reversing logic implemented by encryption function)
void decryption(char original[], char secret[], int key) {
  int i = 0; //declare int i and set to 0 to run through each char of array
  while (secret[i] != '\0') { //while loop runs through entire array
    if (secret[i] - key < 32) { 
      original[i] = 127 - (32 - (secret[i] - key)); //check if subtracting key from ASCII value is less than 32
    } else {
      original[i] = secret[i] - key; //if value is not less than 32, subtract key from ASCII value
    }
    i++; //iterates through each char of the array
    }
  original[i] = '\0'; //end the decrypted message with a null character
  } 
