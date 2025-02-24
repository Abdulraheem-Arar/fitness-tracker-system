#include "header.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

string chooseExercise();

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
     double caloriesPerMinute = 0.0;

    if (activity == "Weightlifting") caloriesPerMinute = 108/30;
    else if (activity == "Running") caloriesPerMinute = 288/30;
    else if (activity == "Biking") caloriesPerMinute = 288/30;
    else if (activity == "Swimming") caloriesPerMinute = 216/30;
    else if (activity == "Walking") caloriesPerMinute = 133/30;
    else return 0.0; // If no activity matches, return 0

    return caloriesPerMinute * time;
    
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
        cout << "you are currently " << ((float)walkedSteps/(float)dailyStepGoal)*100 << "% through your daily step goal" << endl;
        cout << "you are currently " << ((float)eatenCalories/(float)dailyCalorieGoal)*100 << "% through your daily calorie intake goal" << endl;
}

bool selectProfile(vector<Profile> &profiles, Profile *&currentProfile){
    int choice = 0;
    if (profiles.empty()) {
        cout << "No profiles available to select.\n";
        return false;
    }
    if (currentProfile!=nullptr){
        cout << "enter 1 if you wish to select this profile -" << currentProfile->getName() << "- otherwise enter any other integer: " ;
        cin >> choice ;
    } else {
        showUsers(profiles);
        string name;
        cout << "\nwhat is the profile you want to select?\n";
        cin >> name;
        for(int i = 0;i< profiles.size();i++){
            if (profiles[i].getName() == name){
                currentProfile = &profiles[i];
                cout << "you have selected " << currentProfile->getName() << " as your current user" << endl;
                return true;
            }
        }
    }
    if (choice != 1 ){
        string name;
        cout << "\nwhat is the profile you want to select?\n";
        cin >> name;
        for(int i = 0;i< profiles.size();i++){
            if (profiles[i].getName() == name){
                currentProfile = &profiles[i];
                cout << "you have selected " << currentProfile->getName() << " as your current user" << endl;
                return true;
            }
        }
    }else if (choice ==1) {
        return true;
    } else if (choice ==0){
        cout << "could not find the profile you were looking for" << endl;
        return false;
    }
    cout << "could not find the profile you were looking for" << endl;
        return false;
}

void Profile::addActivity(){
    string name;
    int duration;
    name = chooseExercise();
    cout << "for how many minutes were you performing the activity?\n";
    cin >> duration;
    this->addActivity(name,duration);  
}

void displayMenu(){
    cout << endl << "please choose one of the following options: \n" ;
        cout << "1. create a new profile\n";
        cout << "2. add progress to goals\n";
        cout << "3. add a new activity\n";
        cout << "4. view profile information\n";
        cout << "5. remove profile\n";
        cout << "6. list all profiles\n";
        cout << "7. exit \n";
}

void createNewProfile(vector<Profile> &profiles, Profile *&currentProfile){
    string name;
    int age, stepGoal, calorieGoal;
    double weight, height;
    
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
    
    profiles.push_back(Profile(name, age, weight, height, stepGoal, calorieGoal,0,0));
    currentProfile = &profiles[profiles.size() - 1];
}



string chooseExercise() {
    cout << "Choose an exercise:\n";
    cout << "1. Weightlifting\n";
    cout << "2. Running\n";
    cout << "3. Biking\n";
    cout << "4. Swimming\n";
    cout << "5. Walking\n";

    int choice;
    cout << "Enter your choice (1-5): ";
    cin >> choice;

    
    while (choice < 1 || choice > 5) {
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

void removeProfile(vector<Profile> &profiles, Profile *&currentProfile){
    if (profiles.empty()) {
        cout << "No profiles available to remove.\n";
        return;
    }

    int choice;
    if (currentProfile !=nullptr){
        cout << "enter 1 if you wish to remove this profile -" << currentProfile->getName() << "- otherwise enter any other integer: " ;
        cin >> choice ;
    } else{
        showUsers(profiles);
        string name;
        cout << "\nwhat is the profile you want to remove?\n";
        cin >> name;
        bool found = false;
        for(int i = 0;i< profiles.size();i++){
            if (profiles[i].getName() == name){
                profiles.erase(profiles.begin() + i);
                found = true;
            }
        }
        if (!found){
            cout << "no profile found which matches the name you provided" << endl;
        }
    }
    if (choice ==1){
        auto it = std::find(profiles.begin(), profiles.end(), *currentProfile);
        if (it != profiles.end()) {
            profiles.erase(it);
        }
    } else {
        string name;
        cout << "\nwhat is the profile you want to remove?\n";
        cin >> name;
        bool found = false;
        for(int i = 0;i< profiles.size();i++){
            if (profiles[i].getName() == name){
                profiles.erase(profiles.begin() + i);
                found = true;
            }
        }
        if (!found){
            cout << "no profile found which matches the name you provided" << endl;
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

void initializeProfiles( vector<Profile> &profiles){
    ifstream file("profiles.csv", ios::in);
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return ; // Return an error code
    }

    string line;
   
    // Skip the first line (header)
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string field;

        string name;
        int id, age, stepGoal, calorieGoal, walkedSteps, eatenCalories;
        double weight, height;

        // Read each field separated by commas and store them in appropriate variables
        getline(ss, field, ',');  
        id = stoi(field); // Convert to integer
        
        getline(ss, name, ','); 
        
        getline(ss, field, ',');  
        age = stoi(field);
        
        getline(ss, field, ',');  
        weight = stod(field);
        
        getline(ss, field, ',');  
        height = stod(field);
        
        getline(ss, field, ',');  
        stepGoal = stoi(field);
        
        getline(ss, field, ',');  
        calorieGoal = stoi(field);
        
        getline(ss, field, ',');  
        walkedSteps = stoi(field);
        
        getline(ss, field, ',');  
        eatenCalories = stoi(field);

        // Create a new Profile object and append it to the profiles vector
        profiles.push_back(Profile(id, name, age, weight, height, stepGoal, calorieGoal, walkedSteps, eatenCalories));
    }

    file.close();
    return;
}

void saveProfiles(vector<Profile> &profiles) {
    ofstream file("profiles.csv", ios::out);  // Open file in overwrite mode

    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    // Write the first line (header)
    file << "id,name,age,weight,height,dailyStepGoal,dailyCalorieGoal,BMI,walkedSteps,eatenCalories\n";

    // Iterate through the profiles vector and write each profile to the file
    for (const auto &profile : profiles) {
        file << profile.getID() << ","
              << profile.getName() << ","
             << profile.getAge() << ","
             << profile.getWeight() << ","
             << profile.getHeight() << ","
             << profile.getStepGoal() << ","
             << profile.getCalorieGoal() << ","
             << profile.getBMI() << ","
             << profile.getWalkedSteps() << ","
             << profile.getEatenCalories() << "\n";
    }

    file.close();
}

void initializeActivities(vector<Profile> &profiles){
    ifstream file("activities.csv", ios::in);
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return ; // Return an error code
    }

    string line;
   
    // Skip the first line (header)
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string field;

        string activityType;
        int id;
        double duration, caloriesBurned;

        // Read each field separated by commas and store them in appropriate variables
        getline(ss, field, ',');  
        id = stoi(field); // Convert to integer
        
        getline(ss, activityType, ','); 
        
        getline(ss, field, ',');  
        duration = stod(field);
        
        getline(ss, field, ',');  
        caloriesBurned = stod(field);

        for (auto &profile : profiles){
            if (profile.getID() == id){
                profile.addActivity(activityType,duration);
            }
        }
    }

    file.close();
    return;
}


void saveActivities(vector<Profile> &profiles) {
     ofstream file("activities.csv", ios::out);  // Open file in overwrite mode

    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    // Write the first line (header)
    file << "userID,activityType,duration,caloriesBurned\n";
    
    // Iterate through the profiles vector and write each profile to the file
    for (const auto &profile : profiles) {
       for (const auto &activity : profile.getActivities()){
            file << activity.getUserID() << ","
             << activity.getActivityType()<< ","
             << activity.getDuration() << ","
             << activity.getCaloriesBurned() << '\n';
       }
    }

    file.close();
}

