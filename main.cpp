#include "header.h"
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

string chooseExercise();

int Profile::counter = 1;

Profile::Profile(std::string name, int age, double weight, double height, int stepGoal, int calorieGoal){
    this->id = counter++; 
    this->name = name; 
    this->age = age;
    this->weight = weight;
    this->height = height;
    this->dailyStepGoal = stepGoal;
    this->dailyCalorieGoal = calorieGoal;
    this->BMI = calculateBMI();
    this->walkedSteps = 0;
    this->eatenCalories = 0;
};

double Profile::calculateBMI() const{
    return weight / pow(height,2);
};

void Profile::addActivity(string type, double duration){
    activities.push_back(Activity(this->id,type, duration));

} 

 void Profile::displayProfile() const{
        cout << "User: " << name << ", Age: " << age << ", Weight: " << weight << " kg" << ", BMI: " << BMI << endl;
        cout << "Activity History:\n";
        for (int i = 0; i < activities.size(); i++) {
        activities[i].displayActivity();
        }
        cout << endl;
}

void Activity::displayActivity() const{
        cout << "Activity: " << activityType 
                  << ", Duration: " << duration << " min"
                  << ", Calories Burned: " << caloriesBurned << " kcal\n";
}

double Activity::calculateCaloriesBurned(string activity, double time){
     int activityIndex =0;

    if (activity == "Weightlifting") activityIndex = 1;
    else if (activity == "Running") activityIndex = 2;
    else if (activity == "Biking") activityIndex = 3;
    else if (activity == "Swimming") activityIndex = 4;
    else if (activity == "Walking") activityIndex = 5;
    else if (activity == "Exit") activityIndex = 6;

    // I make the assumption here that the person weighs 155 pounds
    double caloriesPerMinute;
    switch (activityIndex) {
        case 1: caloriesPerMinute = 108/30; break;  // Weightlifting
        case 2: caloriesPerMinute = 288/30; break; // Running
        case 3: caloriesPerMinute = 288/30; break;  // Biking
        case 4: caloriesPerMinute = 216/30; break; // Swimming
        case 5: caloriesPerMinute = 133/30; break;  // Walking
        default: return 0.0;
    }

        return caloriesPerMinute*time;
    
}

void Profile::addToGoals(){
    int choice;
    int addedSteps, addedcalories;
    
        cout << "how many more steps have you walked today: " ;
        cin >> addedSteps;
        cout << "how many more calories have you consumed today: ";
        cin >> addedcalories;
        walkedSteps += addedSteps;
        eatenCalories += addedcalories;
        cout << "you are currently " << (walkedSteps/dailyStepGoal)*100 << "% through your daily step goal" << endl;
         cout << "you are currently " << (eatenCalories/dailyCalorieGoal)*100 << "% through your daily calorie intake goal" << endl;
}

bool selectProfile(vector<Profile> &profiles, Profile &currentProfile){
    int choice;
    if (profiles.empty()) {
        cout << "No profiles available to select.\n";
        return false;
    }
    cout << "enter 1 if you wish to select this profile -" << currentProfile.getName() << "- otherwise enter any other integer: " ;
    cin >> choice ;
    if (choice != 1 ){
        string name;
        cout << "\nwhat is the profile you want to select?\n";
        cin >> name;
        for(int i = 0;i< profiles.size();i++){
            if (profiles[i].getName() == name){
                currentProfile = profiles[i];
                cout << "you have selected " << profiles[i].getName() << " as your current user" << endl;
                return true;
            }
        }
    }
    return true;
}

void viewProfile(const vector<Profile> &profiles,Profile &currentProfile){
    string name;
    int choice;
    if (profiles.size() == 0){
        cout << "you must have a profile to view a profile." << endl ;
        return;
    }
    cout << "enter 1 if you wish to view this profile -" << currentProfile.getName() << "- otherwise enter any other integer: " ;
    cin >> choice ;
    if (choice == 1 ){
        currentProfile.displayProfile();
    } else{
    cout << "\nwhat is the profile you want to view\n";
    cin >> name;
    
        for(int i = 0;i< profiles.size();i++){
            if (profiles[i].getName() == name){
             profiles[i].displayProfile();
             currentProfile = profiles[i];
            }
       
        }
         cout << "your current profile is now set to the profile you viewed" << endl;
    }
    
    
}

void addActivity(vector<Profile> &profiles, Profile &currentProfile){
    string name, activity;
    int duration;
    int choice; 
    if (profiles.size() == 0){
        cout << "you must have a profile to add an activity." << endl ;
        return;
    }
    cout << "enter 1 if you wish to make changes to this profile -" << currentProfile.getName() << "- otherwise enter any other integer: " ;
    cin >> choice ;
    if (choice ==1){
        activity = chooseExercise();
        cout << "for how many minutes were you performing the activity?\n";
        cin >> duration;
        currentProfile.addActivity(activity,duration);
    } else {
        cout << "\nwhat is the profile you want to add an activity to?\n";
        cin >> name;
        activity = chooseExercise();
        cout << "for how long were you performing the activity?\n";
        cin >> duration;
        for(int i = 0;i< profiles.size();i++){
            if (profiles[i].getName() == name){
                profiles[i].addActivity(activity,duration);
            }
        }
    }
    
}

void displayMenu(){
    cout << endl << "please choose one of the following options: \n" ;
        cout << "1. create a new profile\n";
        cout << "2. select a profile\n";
        cout << "3. add a new activity\n";
        cout << "4. view profile information\n";
        cout << "5. remove profile\n";
        cout << "6. view all profiles\n";
        cout << "7. exit \n";
}

void createNewProfile(vector<Profile> &profiles, Profile &currentProfile){
                string name;
                int age, stepGoal, calorieGoal;
                double weight,height;
                cout << "\nwhat is your name:\n";
                cin >> name;
                cout << "what is your age:\n";
                cin >> age;
                cout << "what is your weight in kilograms(kg):\n";
                cin >> weight;
                cout << "what is your height in meters(m):\n";
                cin >> height;
                cout << "what is your daily step goal:\n";
                cin >> stepGoal;
                cout << "what is your daily calorie goal:\n";
                cin >> calorieGoal;
                profiles.push_back(Profile(name,age,weight,height,stepGoal,calorieGoal));
                currentProfile = profiles[profiles.size()-1];
}


string chooseExercise() {
    cout << "Choose an exercise:\n";
    cout << "1. Weightlifting\n";
    cout << "2. Running\n";
    cout << "3. Biking\n";
    cout << "4. Swimming\n";
    cout << "5. Walking\n";

    int choice;
    cout << "Enter your choice (1-6): ";
    cin >> choice;

    
    while (choice < 1 || choice > 6) {
        cout << "Invalid choice. Please enter a number between 1 and 6: ";
        cin >> choice;
    }

    
    switch (choice) {
        case 1: return "Weightlifting";
        case 2: return "Running";
        case 3: return "Biking";
        case 4: return "Swimming";
        case 5: return "Walking";
    }
    return "invalid";
}

void removeProfile(vector<Profile> &profiles, Profile &currentProfile){
    if (profiles.empty()) {
        cout << "No profiles available to remove.\n";
        return;
    }

    int choice;
    cout << "enter 1 if you wish to remove this profile -" << currentProfile.getName() << "- otherwise enter any other integer: " ;
    cin >> choice ;
    if (choice ==1){
        auto it = std::find(profiles.begin(), profiles.end(), currentProfile);
        if (it != profiles.end()) {
            profiles.erase(it);
        }
    } else {
        string name;
        cout << "\nwhat is the profile you want to remove?\n";
        cin >> name;
        for(int i = 0;i< profiles.size();i++){
            if (profiles[i].getName() == name){
                profiles.erase(profiles.begin() + i);
            }
        }
    }
}

void showUsers(const vector<Profile> &profiles) {
    cout << "the following are all the users stored: "<< endl;
    for (int i = 0 ; i< profiles.size(); i++ ){
        cout << profiles[i].getName() ;
        if (i != profiles.size()-1){
            cout << ", ";
        }
        
    }
    cout << endl;
}


