/*
Sophie Samuels
COP 3014 - Assignment 5
06.20.2024
*/
 
#include <iostream> //standard input/output stream
#include <string> //string library
#include <iomanip> //input/output manipulation
using namespace std;
 
 
class Movie
{
public:
  //constructor prototype
  Movie(const string& name, const string& mpaa_rating);
 
  void set_name(const string& new_name); //movie name setter
  string get_name() const; //returns movie name
  void set_mpaa_rating(const string& new_mpaa_rating); //movie rating setter
  string get_mpaa_rating() const; //returns the MPAA rating as G, PG, PG-13, R
 
  //function adds a rating to the movie
  //verifies parameter is between 1 and 5
  //if valid parameter, increments # of ratings and adds rating to total
  void add_rating(int rating);
 
  //calculates and returns average rating of all given movie ratings
  double average_rating() const;
  
 
private:
  string movieName;
  string mpaa_rating;
  int rating_count_1, rating_count_2, rating_count_3, rating_count_4, rating_count_5;
};
 
//MAIN
int main() {
  
  //TEST
  //create at least 2 Movie objects
  Movie movie1("Rain Man", "R");
  Movie movie2("Sixteen Candles", "PG");
  Movie movie3("Shrek", "PG-13");
 
  //add at least 5 ratings for each movie
  movie1.add_rating(5);
  movie1.add_rating(4);
  movie1.add_rating(6); //this is ignored because it is outside of the parameters
  movie1.add_rating(3);
  movie1.add_rating(5);
  movie1.add_rating(5);
 
  movie2.add_rating(4);
  movie2.add_rating(3);
  movie2.add_rating(3);
  movie2.add_rating(2);
  movie2.add_rating(5);
 
  movie3.add_rating(3);
  movie3.add_rating(4);
  movie3.add_rating(5);
  movie3.add_rating(5);
  movie3.add_rating(5);
 
  //output movie name, MPAA rating, and average rating for each Movie object
  cout << "Movie: " << movie1.get_name() << endl;
  cout << fixed << setprecision(1) << "MPAA Rating: " << movie1.get_mpaa_rating() << endl;
  cout << "Average Viewer Rating: " << movie1.average_rating() << endl;
  cout << endl;
 
  cout << "Movie: " << movie2.get_name() << endl;
  cout << fixed << setprecision(1) << "MPAA Rating: " << movie2.get_mpaa_rating() << endl;
  cout << "Average Viewer Rating: " << movie2.average_rating() << endl;
  cout << endl;
 
  cout << "Movie: " << movie3.get_name() << endl;
  cout << fixed << setprecision(1) << "MPAA Rating: " << movie3.get_mpaa_rating() << endl;
  cout << "Average Viewer Rating: " << movie3.average_rating() << endl;
  cout << endl;
 
 
  
 
  
  return 0;
}
 
//FUNCTION DEFINITIONS
//implement constructor
Movie::Movie(const string& name, const string& mpaa_rating) 
    : movieName(name), mpaa_rating(mpaa_rating), rating_count_1(0), rating_count_2(0), rating_count_3(0), rating_count_4(0), rating_count_5(0) {}
  
 
//setter function updates movie name
void Movie::set_name(const string& new_name) {
  movieName = new_name;
}
 
//getter function returns movie name
string Movie::get_name() const {
  return movieName;
}
 
//setter function updates movie rating
void Movie::set_mpaa_rating(const string& new_mpaa_rating) {
  mpaa_rating = new_mpaa_rating;
}
 
//getter function returns the MPAA rating as G, PG, PG-13, R
string Movie::get_mpaa_rating() const {
  return mpaa_rating;
}
 
//function adds a rating to the movie
//verifies parameter is between 1 and 5
//if valid parameter, increments # of ratings and adds rating to total
void Movie::add_rating(int rating) {
  
    if (rating >= 1 && rating <= 5) {
    //switch statement to determine which rating to increment
      switch (rating) {
        case 1: 
          rating_count_1++; 
          break;
        case 2: 
          rating_count_2++;
          break;
        case 3: 
          rating_count_3++;
          break;
        case 4: 
          rating_count_4++;
          break;
        case 5: 
          rating_count_5++;
          break;
      }
    } else { 
          cout << rating << " is not a valid entry." << endl;
          cout << endl;
    }
}
 
//calculates and returns average rating of all given movie ratings
double Movie::average_rating() const {
  
  double average = 0;
  int total_ratings_count = rating_count_1 + rating_count_2 + rating_count_3 + rating_count_4 + rating_count_5;
  int total_ratings_value = (rating_count_1 * 1) + (rating_count_2 * 2) + (rating_count_3 * 3) + (rating_count_4 * 4) + (rating_count_5 * 5);
  average = static_cast<double>(total_ratings_value) / total_ratings_count;
 
  return average;
}
