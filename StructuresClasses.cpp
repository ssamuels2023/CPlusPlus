/*
Sophie Samuels
COP 3014 - Assignment 6
07.08.2024
*/


#include <iostream> //standard input/output stream library
#include <string> //string library
#include <iomanip> //input/output manipulation library
#include <iostream> //fixed/setprecision library
#include <fstream> //files library
using namespace std; //omit std:: prefix




//base class COP3014
class COP3014 {


private:
  string firstName;
  string lastName;
  string zNumber;


  int assignments[4]; // array for assignments
  int midtermExam;
  int finalExam;
  double totalGrade;
  string finalLetterGrade;


public:
  //constructor declarations
  COP3014();
  COP3014(string fName, string lName, string zNum, int assmts[4], int mGrade, int fGrade);


  void calculateTotal(); 
  void calculateLetterGrade();


  //setter function declarations
  void set_firstName(string new_firstName);
  void set_lastName(string new_lastName);
  void set_zNumber(string new_zNumber);
  void set_assignmentsGrade(int index, int new_grade);
  void set_midtermExamGrade(int new_midExam_grade);
  void set_finalExamGrade(int new_finalExam_grade);
  void set_totalGrade(double new_totalGrade);
  void set_finalLetterGrade(string new_finalLetterGrade);


  //getter function declarations
  string get_firstName() const;
  string get_lastName() const;
  string get_zNumber() const;
  int get_assignmentsGrade(int index) const;
  int get_midtermExamGrade() const;
  int get_finalExamGrade() const;
  double get_totalGrade() const;
  string get_finalLetterGrade() const;


  //input / output function declarations
  void input();
  void output();
};


//derived class Spring24 
class Spring24 : public COP3014 {
private:
  int labGrade; // addition of lab grade to Spring24 class


public:
  //constructor declarations
  Spring24();
  Spring24(string fName, string lName, string zNum, int assmts[4], int mGrade, int fGrade, int lGrade);


  //setter and getter function declarations for lab grade
  void set_labGrade(int new_labGrade);
  int get_labGrade() const;


  //overriding member function declaration for calculating total grade
  void calculateTotal();


  //input / output function declarations
  void input();
  void output() const;
};


//main function
int main() {  
    
  Spring24 student2;
  student2.set_firstName("Rachel");
  student2.set_lastName("Greene");
  int assignments1[4] = {85, 90, 88, 92};
  student2 = Spring24("Rachel", "Greene", "12345678", assignments1, 89, 93, 95);
  student2.output();


  Spring24 student4;
  student4.set_firstName("Ross");
  student4.set_lastName("Gellar");
  student4.input();
  student4.output();


  COP3014 student10;
  student10.set_firstName("Phoebe");
  student10.set_lastName("Bouffet");
  int assignments2[4] = {60, 82, 75, 0};
  student10 = Spring24("Phoebe", "Bouffet", "24506355", assignments2, -1, 90, 100);
  student10.output();


  COP3014 student11;
  student11.set_firstName("Chandler");
  student11.set_lastName("Bing");
  student11.input();
  student11.output();


  return 0;
}


//COP3014 class member function definitions
//default constructor
COP3014::COP3014() : firstName(""), lastName(""), zNumber(""), midtermExam(0), finalExam(0), totalGrade(100), finalLetterGrade("F") {
  for (int i = 0; i < 4; ++i) {
    assignments[i] = 0;
  }
}


//constructor including parameters
COP3014::COP3014(string fName, string lName, string zNum, int assmts[4], int mGrade, int fGrade) : firstName(fName), lastName(lName), zNumber(zNum), midtermExam(mGrade), finalExam(fGrade) {
  for (int i = 0; i < 4; ++i) {
    assignments[i] = assmts[i];
  }
  calculateTotal();
}


//calculate total weighted grade average
void COP3014::calculateTotal() {
  double assignmentsAverage = (assignments[0] + assignments[1] + assignments[2] + assignments[3]) / 4.0;
  totalGrade = (assignmentsAverage * 0.25) + (midtermExam * 0.30) + (finalExam * 0.45);
  calculateLetterGrade(); // update letter grade after calculating total grade
}


  // convert total weighted grade average to letter grade
  void COP3014::calculateLetterGrade() { 
    if (finalExam == -1) { // score of -1 indicates that student was absent from final exam
      finalLetterGrade = "F"; // if student absent from final exam, they fail the class
    } else if (midtermExam == -1) { // score of -1 indicates that student was absent from midterm exam
      totalGrade = min(totalGrade, 70.0); // if student absent from midterm exam, totalGrade is maxed at 70.0 or 'C'
      if (totalGrade >= 70.0) {
        finalLetterGrade = "C";
      } else if (totalGrade >= 67.0) {
        finalLetterGrade = "C-";
      } else if (totalGrade >= 63.0) {
        finalLetterGrade = "D+";
      } else if (totalGrade >= 60.0) {
        finalLetterGrade = "D";
      } else if (totalGrade >= 51.0) {
        finalLetterGrade = "D-";
      } else {
        finalLetterGrade = "F";
      }
    } else {
      if (totalGrade >= 90.0) {
        finalLetterGrade = "A";
      } else if (totalGrade >= 87.0) {
        finalLetterGrade = "A-";
      } else if (totalGrade >= 83.0) {
        finalLetterGrade = "B+";
      } else if (totalGrade >= 80.0) {
        finalLetterGrade = "B";
      } else if (totalGrade >= 77.0) {
        finalLetterGrade = "B-";
      } else if (totalGrade >= 73.0) {
        finalLetterGrade = "C+";
      } else if (totalGrade >= 70.0) {
        finalLetterGrade = "C";
      } else if (totalGrade >= 67.0) {
        finalLetterGrade = "C-";
      } else if (totalGrade >= 63.0) {
        finalLetterGrade = "D+";
      } else if (totalGrade >= 60.0) {
        finalLetterGrade = "D";
      } else if (totalGrade >= 51.0) {
        finalLetterGrade = "D-";
      } else {
        finalLetterGrade = "F";
      }
    }
  }


  //setter functions
  void COP3014::set_firstName(string new_firstName) {
    firstName = new_firstName;
  }


  void COP3014::set_lastName(string new_lastName) {
    lastName = new_lastName;
  }


  void COP3014::set_zNumber(string new_zNumber) {
    if (new_zNumber.size() != 8) { // check if z-number is 8 characters long
      cout << "Z Number should be 8 digits, do not include Z" << endl;
      cout << "Enter again: ";
      string replacement_zNumber; // allows user to enter a new z-number
      cin >> replacement_zNumber;
      set_zNumber(replacement_zNumber); // recursive call to set_zNumber to continue to check that it is 8 char long
    } else {
        zNumber = new_zNumber; 
    }
  }


  void COP3014::set_assignmentsGrade(int index, int new_grade) {
    if (index >= 0 && index < 4) { // check if index within range of assignments array
        } else {
         cout << "Invalid index for assignment. Please enter value between 0 and 3" << endl;
        } if (new_grade >= 0 && new_grade <= 100) { // check if new_grade within range of 0 to 100
            assignments[index] = new_grade; 
            calculateTotal(); // update total grade after changing assignment grade
        } else {
          cout << "Invalid grade. Please enter value between 0 and 100" << endl;
        }
    }


  void COP3014::set_midtermExamGrade(int new_midExam_grade) {
    if (new_midExam_grade >= -1 && new_midExam_grade <= 100) { // check if midterm exam grade within range -1 to 100
      midtermExam = new_midExam_grade;
    } else {
      cout << "Invalid grade for midterm exam. Please enter value between 0 and 100" << endl;
      cout << "If student was absent from midterm exam, enter score as -1" << endl;
      int replacement_midtermExamGrade; // allows user to enter a new midterm exam grade
      cin >> replacement_midtermExamGrade; 
      return set_midtermExamGrade(replacement_midtermExamGrade); // recursive call to set_midtermExamGrade to continue to check that it is within range
    }
    calculateTotal(); // update total grade after changing midterm exam grade
  }


  void COP3014::set_finalExamGrade(int new_finalExam_grade) {
    if (new_finalExam_grade >= -1 && new_finalExam_grade <= 100) { // check if final exam grade within range -1 to 100
      finalExam = new_finalExam_grade;
    } else {
      cout << "Invalid grade for final exam. Please enter value between 0 and 100" << endl;
      cout << "If student was absent from final exam, enter score as -1" << endl;
      int replacement_finalExamGrade; // allows user to enter a new final exam grade
      cin >> replacement_finalExamGrade;
      return set_finalExamGrade(replacement_finalExamGrade); // recursive call to set_finalExamGrade to continue to check that it is within range
    }
    calculateTotal(); // update total grade after changing final exam grade
  }


  void COP3014::set_totalGrade(double new_totalGrade) { 
    if (new_totalGrade >= 0.0 && new_totalGrade <= 100.0) { // check if total grade within range 0.0 to 100.0
      totalGrade = new_totalGrade;
    } else {
      cout << "Invalid grade for total grade. Please enter grade between 0 and 100" << endl;
      int replacement_totalGrade; // allows user to enter a new total grade
      cin >> replacement_totalGrade;
      return set_totalGrade(replacement_totalGrade); // recursive call to set_totalGrade to continue to check that it is within range
    }
  }


  void COP3014::set_finalLetterGrade(string new_finalLetterGrade) {
    if (new_finalLetterGrade == "A" || new_finalLetterGrade == "A-" || new_finalLetterGrade == "B+" || new_finalLetterGrade == "B" || new_finalLetterGrade == "B-" || new_finalLetterGrade == "C+" || new_finalLetterGrade == "C" || new_finalLetterGrade == "C-" || new_finalLetterGrade == "D+" || new_finalLetterGrade == "D" || new_finalLetterGrade == "D-" || new_finalLetterGrade == "F") { // check if final letter grade is valid
      finalLetterGrade = new_finalLetterGrade;
    } else {
      cout << "Invalid grade for final letter grade. Please enter grade between A and F" << endl;
      string replacement_finalLetterGrade; // allows user to enter a new final letter grade
      cin >> replacement_finalLetterGrade;
      return set_finalLetterGrade(replacement_finalLetterGrade); // recursive call to set_finalLetterGrade to continue to check that it is valid
    }
  }


  //getter functions
  string COP3014::get_firstName() const {
    return firstName;
  }


  string COP3014::get_lastName() const {
    return lastName;
  }


  string COP3014::get_zNumber() const {
    return "Z" + zNumber; //adds Z to digit portion of Z-number
  }


  int COP3014::get_assignmentsGrade(int index) const { 
    if (index >= 0 && index < 4) { // check if index within range of assignments array
      return assignments[index];
    } else {
        cout << "Invalid index for assignment. Please enter value between 0 and 3" << endl;
        int newIndex; // allows user to enter a new index
        cin >> newIndex;
        return get_assignmentsGrade(newIndex); // recursive call to get_assignmentsGrade to continue to check that it is within range
      }
  }
    
  int COP3014::get_midtermExamGrade() const {
    return midtermExam;
  }


  int COP3014::get_finalExamGrade() const {
    return finalExam;
  }


  double COP3014::get_totalGrade() const {
    return totalGrade;
  }


  string COP3014::get_finalLetterGrade() const {
    return finalLetterGrade;
  }


  //input function asks user for student's name, Z-number and grades
  void COP3014::input() {
      
    if (firstName.empty()) { // user only prompted to enter first name if empty
        cout << "Enter student's first name: ";
        string firstName;
        cin >> firstName;
        set_firstName(firstName); 
    } else {
        cout << firstName; // displays first name so user can see which student info is being entered to file
    }


    if (lastName.empty()) { // user only prompted to enter last name if empty
        cout << "Enter student's last name: ";
        string lastName;
        cin >> lastName;
        set_lastName(lastName); 
    } else {
        cout << " " << lastName; // displays last name so user can see which student info is being entered to file
    }
        cout << endl;
      
      
    cout << "Enter student's Z-Number (include only numbers): "; 
    string zNumber;
    cin >> zNumber; 
    set_zNumber(zNumber);
      
    cout << "Enter four grades, one for each assignment: " << endl; 
    for (int i = 0; i < 4; ++i) { // loops through assignments array to get grades for each assignment
        int entered_grade;
        cin >> entered_grade;
        set_assignmentsGrade(i, entered_grade);
    }
      
    cout << "Enter grade for midterm exam: ";
    int midtermExam;  
    cin >> midtermExam;
    set_midtermExamGrade(midtermExam);
      
    cout << "Enter grade for final exam: ";
    int finalExam;
    cin >> finalExam;
    set_finalExamGrade(finalExam);
      
    calculateTotal(); // calculate total grade after setting grades
  }


void COP3014::output() {
  ofstream out_stream; // output stream declaration
  out_stream.open("gradebook.txt", ios::app); // connect to file by opening file, append to file to allow both classes to write to the same file
  out_stream << firstName << " " << lastName << " - " << get_zNumber() << endl; //use of get_zNumber function to ensure z-number is 8 characters long
  out_stream << "\t\t\tAssignment 1: " << assignments[0] << endl;
  out_stream << "\t\t\tAssignment 2: " << assignments[1] << endl;
  out_stream << "\t\t\tAssignment 3: " << assignments[2] << endl;
  out_stream << "\t\t\tAssignment 4: " << assignments[3] << endl;
  out_stream << "\t\t\tMidterm Exam: " << midtermExam << endl;
  out_stream << "\t\t\tFinal Exam: " << finalExam << endl;
  out_stream << fixed << setprecision(2) << "\t\t\tFinal Numeric Grade: " << totalGrade << endl; // set final grade to display 2 decimal places
  out_stream << "\t\t\tFinal Letter Grade: " << finalLetterGrade << endl << endl;
  out_stream.close(); // close file
  cout << "This information has been entered into the grade book." << endl; //lets user know info has been written to file
  cout << endl;
}


//Spring24 member function definitions
//default constructor
Spring24::Spring24() :COP3014(), labGrade(0) {}


//constructor including parameter, adds labGrade parameter
Spring24::Spring24(string fName, string lName, string zNum, int assmts[4], int mGrade, int fGrade, int lGrade) : COP3014(fName, lName, zNum, assmts, mGrade, fGrade), labGrade(lGrade) {
    calculateTotal();
  }


  //setter function for lab grade
  void Spring24::set_labGrade(int new_labGrade) {
    if (new_labGrade >= 0 && new_labGrade <= 100) { // check if lab grade within range 0 to 100
      labGrade = new_labGrade;
    } else {
      cout << "Invalid grade for lab. Please enter value between 0 and 100" << endl;
      int replacement_labGrade; // allows user to enter a new lab grade
      cin >> replacement_labGrade;
      return set_labGrade(replacement_labGrade); // recursive call to set_labGrade to continue to check that it is within range
    }
    calculateTotal(); // update total grade after changing lab grade
  }


  //getter function for lab grade
  int Spring24::get_labGrade() const {
    return labGrade;
  }


  //calculate total weighted grade average to include lab grade
  void Spring24::calculateTotal() {
  double assignmentsAverage = (get_assignmentsGrade(0) + get_assignmentsGrade(1) + get_assignmentsGrade(2) + get_assignmentsGrade(3)) / 4.0;
set_totalGrade((assignmentsAverage * 0.25) + (get_midtermExamGrade() * 0.25) + (get_finalExamGrade() * 0.40) + (labGrade * 0.10));
  calculateLetterGrade(); // update letter grade after changing total grade
}  


  //input function, adds labGrade parameters
  //access private member function through ??? 
  void Spring24::input() {
    COP3014::input(); //call base class member function 'input'
    cout << "Enter grade for lab: ";
    int labGrade;
    cin >> labGrade;
    set_labGrade(labGrade); // call set_labGrade function to set lab grade
      
    calculateTotal(); // calculate total grade after setting lab grade
  }
  
  //output function, adds lab component
  //uses getter functions derived from base class to display information 
  void Spring24::output() const {
    ofstream out_stream; // output stream declaration
    out_stream.open("gradebook.txt", ios::app); // connect to file by opening file, activate append mode to allow both classes to write to the same file
    out_stream << get_firstName() << " " << get_lastName() << " - " << get_zNumber() << endl;
    out_stream << "\t\t\tAssignment 1: " << get_assignmentsGrade(0) << endl;
    out_stream << "\t\t\tAssignment 2: " << get_assignmentsGrade(1) << endl;
    out_stream << "\t\t\tAssignment 3: " << get_assignmentsGrade(2) << endl;
    out_stream << "\t\t\tAssignment 4: " << get_assignmentsGrade(3) << endl;
    out_stream << "\t\t\tLab:" << labGrade << endl;
    out_stream << "\t\t\tMidterm Exam: " << get_midtermExamGrade() << endl;
    out_stream << "\t\t\tFinal Exam: " << get_finalExamGrade() << endl;
    out_stream << fixed << setprecision(2) << "\t\t\tFinal Numeric Grade: " << get_totalGrade() << endl;
    out_stream << "\t\t\tFinal Letter Grade: " << get_finalLetterGrade() << endl << endl;
    out_stream.close();
    cout << "This information has been entered into the grade book." << endl;
    cout << endl;
}
