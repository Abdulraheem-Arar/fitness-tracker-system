#include "header.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

int readFirstIntegerInLastLine();

int Profile::counter = readFirstIntegerInLastLine();

int readFirstIntegerInLastLine() {
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
    return firstInteger;
}


Profile::Profile(std::string name, int age, double weight, double height, int stepGoal, int calorieGoal,int walkedSteps, int eatenCalories){
    this->id = counter++; 
    this->name = name; 
    this->age = age;
    this->weight = weight;
    this->height = height;
    this->dailyStepGoal = stepGoal;
    this->dailyCalorieGoal = calorieGoal;
    this->BMI = calculateBMI();
    this->walkedSteps = walkedSteps;
    this->eatenCalories = eatenCalories;
};

Profile::Profile(int id,string name,int age,double weight, double height, int stepGoal, int calorieGoal, int walkedSteps, int eatenCalories){
    this->id = id; 
    this->name = name; 
    this->age = age;
    this->weight = weight;
    this->height = height;
    this->dailyStepGoal = stepGoal;
    this->dailyCalorieGoal = calorieGoal;
    this->BMI = calculateBMI();
    this->walkedSteps = walkedSteps;
    this->eatenCalories = eatenCalories;
};

double Profile::calculateBMI() const{
    return weight / pow(height,2);
};

void Profile::addActivity(string type, double duration){
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

void Profile::displayProfile() const{
        cout << "User: " << name << ", Age: " << age << ", Weight: " << weight << " kg" << ", BMI: " << BMI << endl;
        cout << "Activity History:\n";
        for (int i = 0; i < activities.size(); i++) {
            activities[i]->displayActivity();
        }
        cout << endl;
}

void Profile::addToGoals(){
    int addedSteps, addedcalories;
        cout << "how many more steps have you walked today: " ;
        cin >> addedSteps;
        cout << "how many more calories have you consumed today: ";
        cin >> addedcalories;
        walkedSteps += addedSteps;
        eatenCalories += addedcalories;
        cout << "you are currently " << ((float)walkedSteps/(float)dailyStepGoal)*100 << "% through your daily step goal" << endl;
        cout << "you are currently " << ((float)eatenCalories/(float)dailyCalorieGoal)*100 << "% through your daily calorie intake goal" << endl;
}

string chooseExercise();


void Profile::addActivity(){
    string name;
    int duration;
    name = chooseExercise();
    cout << "for how many minutes were you performing the activity?\n";
    cin >> duration;
    this->addActivity(name,duration);  
}