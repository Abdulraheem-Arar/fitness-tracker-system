#include "activity.h"

// this file contains the inherited classes for Activity for each individual activity type 
class Running : public Activity {
public:
    //constructor 
    Running(int id, double duration) : Activity(id,"Running", duration) { caloriesBurned = calculateCaloriesBurned(); //calculates the calories burned upon initialization 
    }

    //function to calculate burned calories specifically for running 
    double calculateCaloriesBurned() {
        return duration * 288/30; 
    }

    // overrided function that displays the activity specifically for running 
    void displayActivity() const override {
        cout << "Running for " << duration << " minutes and burned " << caloriesBurned << " calories." << endl;
    }
};

// Class representing Weightlifting activity
class Weightlifting : public Activity {
public:
    // constructor
    Weightlifting(int id, double duration) : Activity(id, "Weightlifting", duration) { 
        caloriesBurned = calculateCaloriesBurned(); // calculates the calories burned upon initialization
    }

    // function to calculate burned calories specifically for weightlifting
    double calculateCaloriesBurned() {
        return duration * 108 / 30; 
    }

    // overrided function that displays the activity specifically for weightlifting
    void displayActivity() const override {
        cout << "Weightlifting for " << duration << " minutes and burned " << caloriesBurned << " calories." << endl;
    }
};

// Class representing Biking activity
class Biking : public Activity {
public:
    // constructor
    Biking(int id, double duration) : Activity(id, "Biking", duration) { 
        caloriesBurned = calculateCaloriesBurned(); // calculates the calories burned upon initialization
    }

    // function to calculate burned calories specifically for biking
    double calculateCaloriesBurned() {
        return duration * 288 / 30; 
    }

    // overrided function that displays the activity specifically for biking
    void displayActivity() const override {
        cout << "Biking for " << duration << " minutes and burned " << caloriesBurned << " calories." << endl;
    }
};

// Class representing Swimming activity
class Swimming : public Activity {
public:
    // constructor
    Swimming(int id, double duration) : Activity(id, "Swimming", duration) { 
        caloriesBurned = calculateCaloriesBurned(); // calculates the calories burned upon initialization
    }

    // function to calculate burned calories specifically for swimming
    double calculateCaloriesBurned() {
        return duration * 216 / 30; 
    }

    // overrided function that displays the activity specifically for swimming
    void displayActivity() const override {
        cout << "Swimming for " << duration << " minutes and burned " << caloriesBurned << " calories." << endl;
    }
};

// Class representing Walking activity
class Walking : public Activity {
public:
    // constructor
    Walking(int id, double duration) : Activity(id, "Walking", duration) { 
        caloriesBurned = calculateCaloriesBurned(); // calculates the calories burned upon initialization
    }

    // function to calculate burned calories specifically for walking
    double calculateCaloriesBurned() {
        return duration * 133 / 30; 
    }

    // overrided function that displays the activity specifically for walking
    void displayActivity() const override {
        cout << "Walking for " << duration << " minutes and burned " << caloriesBurned << " calories." << endl;
    }
};
