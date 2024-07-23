/*
Sophie Samuels
COP 3014 - Assignment 4
06.16.2024
*/
 
#include <iostream> // standard input/output stream
#include <fstream>  // input/output stream to operate files
#include <sstream>  // string stream
#include <iomanip>  // parameter manipulators
#include <vector>   // vector container
#include <ctime>    // obtain time
using namespace std;
 
// FUNCTION PROTOTYPES
// generates a random int between 1 and 10
int randomGenCount();
// generates a random int between 1 and 20
int randomGenScore();
// input function generates quiz scores (1-20) for 10 students
void generateData(const string& input_file, const vector<string>& firstNames, const vector<string>& lastNames);
// calculates average score out of 10
double averageScore(const vector<int>& scores, int numQuizzes);
// process input file read student names and scores from input file
void inputData(ifstream& infile, vector<string>& lastNames, vector<string>& firstNames, vector<int>& scores, vector<int>& numQuizzes);
// process output file write student names, scores, and average score to output file
void outputData(ofstream& outfile, const vector<string>& lastNames, const vector<string>& firstNames, const vector<int>& scores, const vector<int>& numQuizzes);
 
int main() {
 
  srand(time(0)); // seed random number generator
 
  // initialize vectors for first and last names
  vector<string> firstNames = {"Neil", "Buzz", "John", "Alan", "Mae", "Peggy", "Alan", "Sally", "Jim", "Sunita"}; 
  vector<string> lastNames = {"Armstrong", "Aldrin", "Glenn", "Shepard", "Jemison", "Whitson", "Bean", "Ride", "Lovell", "Williams"};
 
  string input_file = "gradeBook.txt"; // set input file name
  string output_file = "newGradeBook.txt"; // set output file name
 
  generateData(input_file, firstNames, lastNames); 
 
  vector<string> inputLastNames; // declare vector to store last names from input file
  vector<string> inputFirstNames; // declare vector to store first names from input file
  vector<int> scores;  // declare vector to store scores from input file; 
  vector<int> numQuizzes; //declare vector to store the number of quizzes taken by each student
 
  ifstream infile; // declare input file stream
  infile.open("gradeBook.txt"); // open input file
  if (infile.fail()) { // check if file opened successfully
    cout << "Failed to open the input file." << endl;
    exit(1); // exit program if file cannot be opened
  }
 
  inputData(infile, inputLastNames, inputFirstNames, scores, numQuizzes);
  infile.close(); // close input file
 
  ofstream outfile; 
  outfile.open("newGradeBook.txt");
  if (outfile.fail()) { 
    cout << "Failed to open the output file." << endl;
    exit(1); // exit program if file cannot be opened
  }
  
  outputData(outfile, inputLastNames, inputFirstNames, scores, numQuizzes);
  outfile.close(); // close output file
  
  cout << "Student data: names, quiz scores, and averages have been recorded in " << output_file << endl; // indicate to user that program has completed
 
  return 0;
}
 
// FUNCTION DEFINITIONS
// generates a random int between 1 and 10
int randomGenCount() {
  
  return (rand() % 10) + 1; // generates rand num between 1-10
}
 
// generates a random int between 1 and 20
int randomGenScore() {
  
  return (rand() % 20) + 1; // generates rand num between 1-20
}
 
// input function generates quiz scores (1-20) for 10 students
void generateData(const string& input_file, const vector<string>& lastNames, const vector<string>& firstNames) {
  
  ofstream outfile(input_file); // declares output file
  
  if (outfile.fail()) { // checks if file exists
    cout << "Failed to open the input file." << endl;
    exit(1); // quits program if file cannot be opened
  }
 
  for (int i = 0; i < 10; ++i) { // iterate for 10 students
    int quizCount = randomGenCount(); // generates random number of quizzes
    outfile << lastNames[i] << ", " << firstNames[i]; // get student names from vectors using for loop
 
    for (int j = 0; j < quizCount; ++j) { // repeat for number of quizzes each student took
      outfile << " " << randomGenScore(); // generates random scores for each quiz in quizCount
    }
    outfile << endl; // new line for next student
  }
  outfile.close(); // closes file
}
 
// calculates average score out of 10
double averageScore(const vector<int>& scores, int numQuizzes) { 
  
  double sum = 0; // initialize sum to zero
  for (int i = 0; i < numQuizzes; ++i) { // iterate for each quiz taken
    sum += scores[i]; // add each quiz score to sum
  }
  return sum / 10.0; // return average out of 10 total quizzes (each student can take 10 or less quizzes)
}
 
// process input file read student names and scores from input file
void inputData(ifstream& infile, vector<string>& lastNames, vector<string>& firstNames, vector<int>& scores, vector<int>& numQuizzes) {
  
  string line; // declare string variable 'line' to store each line of data obtained from input file
  while (getline(infile, line)) { // reads each line of input file until end of file using while loop
    stringstream nn(line); // creates a string stream object 'nn', passes string 'line' to constructor
    string lastName, firstName; // declare string variables 'lastName' and 'firstName' to store student names
 
    getline(nn, lastName, ','); // reads the last name from the string stream object 'nn'
    nn.ignore(); // ignores the space after the comma
    getline(nn, firstName, ' '); // reads the first name from the string stream object 'nn'
 
    lastNames.push_back(lastName); // adds last name to vector 'lastNames'
    firstNames.push_back(firstName); // adds first name to vector 'firstNames'
    
    int score; // declare int variable 'score' to store each quiz score
    int quizzes = 0; // initialize quizzes to zero
    while (nn >> score) { // reads each quiz score from string stream 'nn' until end of line
      scores.push_back(score); // adds each quiz score to vector 'scores'
      ++quizzes; // increments quizzes by 1
    }
 
    numQuizzes.push_back(quizzes); // add quiz count to numQuizzes
  }
}
 
// process output file write student names, scores, and average score to output file
void outputData(ofstream& outfile, const vector<string>& lastNames, const vector<string>& firstNames, const vector<int>& scores, const vector<int>& numQuizzes) {
 
  // header for output file
  outfile << "This file contains the updated gradebook." << endl; 
  outfile << "It displays the students' quiz scores along with the average score for each student." << endl;
  outfile << endl;
 
  int scoreIndex = 0; // initialize scoreIndex to zero
  for (int i = 0; i < lastNames.size(); ++i) { // iterate for each student
      vector<int> studentScores(scores.begin() + scoreIndex, scores.begin() + scoreIndex + numQuizzes[i]); // creates a vector of scores for each student; scores.begin() points to first element of 'scores' vector; + scoreIndex uses the scoreIndex variable to indicate the index of the first quiz score for each student; score.begin() + scoreIndex + numQuizzes[i] brings the program to the position directly after the final quiz score of each student
    //citation: https://stackoverflow.com/questions/6935389/how-to-get-iterator-to-a-particular-position-of-a-vector
    //citation: https://www.geeksforgeeks.org/vectorbegin-vectorend-c-stl/
      double average = averageScore(studentScores, numQuizzes[i]); // calculates average score for each student
 
      outfile << lastNames[i] << ", " << firstNames[i]; // write student names to output file
      for (int j = 0; j < numQuizzes[i]; ++j) { // iterate for each quiz taken by each student
        outfile << " " << scores[scoreIndex + j]; // write quiz scores to output file
      }
      scoreIndex += numQuizzes[i]; // increment scoreIndex by number of quizzes taken by each student
      outfile << ": " << fixed << setprecision(1) << average << endl; // writes average score to output file with 1 decimal place precision
    }
 
    outfile.close(); // closes output file
  }
