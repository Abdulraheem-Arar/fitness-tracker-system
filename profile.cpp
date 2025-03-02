#include "backend.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

int readFirstIntegerInLastLine();

//initializes the counter for the profiles class to 1+ the first integer in the last line
int Profile::counter = readFirstIntegerInLastLine() ;

int readFirstIntegerInLastLine() {
    // reads profile.csv
    ifstream file("profiles.csv", ios::in);
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return -1; // Return an error code
    }

    string line;
    int firstInteger = 0; // Default value in case no integer is found
    
    // Read through the file line by line
    while (getline(file, line)) {
        stringstream ss(line);
        ss >> firstInteger; // Extract the first integer from the current line
    }

    file.close();
    return firstInteger + 1;
}

//non default constructor
Profile::Profile(int id,string name,int age,double weight, double height, int stepGoal, int calorieGoal, int walkedSteps, int eatenCalories){
    this->id = id; 
    this->name = name; 
    this->age = age;
    this->weight = weight;
    this->height = height;
    this->dailyStepGoal = stepGoal;
    this->dailyCalorieGoal = calorieGoal;
    this->BMI = calculateBMI(); // calls caluclateBMI function and stores value
    this->walkedSteps = walkedSteps;
    this->eatenCalories = eatenCalories;
};

//calculates the BMI 
double Profile::calculateBMI() const{
    return weight / pow(height,2);
};

//function to add activity to the profile
void Profile::addActivity(string type, double duration){
    // pushes back a new activity object of the correct inherited class depending on the type chosen
    if (type == "Weightlifting") {
        activities.push_back(new Weightlifting(this->id, duration));
    }
    else if (type == "Running") {
        activities.push_back(new Running(this->id, duration));
    }
    else if (type == "Biking") {
        activities.push_back(new Biking(this->id, duration));
    } 
    else if (type == "Swimming") {
        activities.push_back(new Swimming(this->id, duration));
    } 
    else if (type == "Walking") {
        activities.push_back(new Walking(this->id, duration));
    } 
 
} 

//displays the profile information
void Profile::displayProfile() const{
        cout << "User: " << name << ", Age: " << age << ", Weight: " << weight << " kg" << ", BMI: " << BMI << endl;
        cout << "Activity History:\n";
        //iterates through all of the activities and displays each ones information 
        for (int i = 0; i < activities.size(); i++) {
            activities[i]->displayActivity();
        }
        cout << endl;
}

// function to add to the profile's goals
void Profile::addToGoals(){
    int addedSteps, addedcalories;
    cout << "how many more steps have you walked today: " ;
    cin >> addedSteps;
    cout << "how many more calories have you consumed today: ";
    cin >> addedcalories;
    // adds the inputted values to the stored progress trackers
    walkedSteps += addedSteps;
    eatenCalories += addedcalories;
    // displays progress to the step and calorie goals for the profile
    cout << "you are currently " << ((float)walkedSteps/(float)dailyStepGoal)*100 << "% through your daily step goal" << endl;
    cout << "you are currently " << ((float)eatenCalories/(float)dailyCalorieGoal)*100 << "% through your daily calorie intake goal" << endl;
}

string Utility::chooseExercise();

// adds activity but this function is used to first ask for user input, 2 functions were needed as the other one is used in situations where we dont want user input
void Profile::addActivity(){
    string name;
    int duration;
    // chooses exercise then user is asked for duration and a new activity is added by calling the addActivity function
    name = Utility::chooseExercise();
    cout << "for how many minutes were you performing the activity?\n";
    cin >> duration;
    this->addActivity(name,duration);  
    cout << "the activity has been added" << endl;
}
