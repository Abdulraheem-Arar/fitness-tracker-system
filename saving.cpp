#include "header.h"
#include <fstream>
#include <sstream>



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
            file << activity->getUserID() << ","
                 << activity->getActivityType()<< ","
                 << activity->getDuration() << ","
                 << activity->getCaloriesBurned() << '\n';
       }
    }

    file.close();
}

