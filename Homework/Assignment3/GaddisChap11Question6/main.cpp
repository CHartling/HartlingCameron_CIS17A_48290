/* 
 * File: main.cpp
 * Author: Cameron Hartling
 * Created on Octorber 5th 2022 9:05pm
 * Purpose:  Store data on Movies
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
struct Movie{
    string title,director;
    int year;
    int runTime; //minutes
};
void output(Movie movieList[],int size){
    unsigned int i;
    for (i = 0; i < size; i++){
        cout << endl;
        cout << "Title:     " << movieList[i].title << endl;
        cout << "Director:  " << movieList[i].director << endl;
        cout << "Year:      " <<  movieList[i].year << endl;
        cout << "Length:    " << movieList[i].runTime << endl;
    }
}

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare
    int NUM_MOVIES;
    unsigned int i;
    string temp1;
    string temp2;
    
    //Initialize
    cout << "This program reviews structures" << endl;
    cout << "Input how many movies, the Title of the Movie, Director, Year Released, and the Running Time in (minutes)." << endl;
    cin >> NUM_MOVIES;
    Movie movieList[NUM_MOVIES];
    
    for (i = 0; i < NUM_MOVIES; i++){
        cin >> movieList[i].title >> temp1 >> temp2;
        movieList[i].title = movieList[i].title + " " + temp1 + " " + temp2;
        cin >> movieList[i].director >> temp1;
        movieList[i].director = movieList[i].director + " " + temp1;
        cin >> movieList[i].year >> movieList[i].runTime;
    }
    
    //Output
    output(movieList,NUM_MOVIES);
    
}//End main