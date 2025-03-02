#include "saving.h"
#include <fstream>
#include <sstream>



void fileSystem::initializeProfiles(vector<Profile> &profiles){
    // reads from profile.csv 
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
        age = stoi(field); // Convert to integer
        
        getline(ss, field, ',');  
        weight = stod(field); // converts to double
        
        getline(ss, field, ',');  
        height = stod(field); // converts to double
        
        getline(ss, field, ',');  
        stepGoal = stoi(field); // Convert to integer
        
        getline(ss, field, ',');  
        calorieGoal = stoi(field); // Convert to integer
        
        getline(ss, field, ',');  
        walkedSteps = stoi(field); // Convert to integer
        
        getline(ss, field, ',');  
        eatenCalories = stoi(field); // Convert to integer

        // Create a new Profile object and append it to the profiles vector
        profiles.push_back(Profile(id, name, age, weight, height, stepGoal, calorieGoal, walkedSteps, eatenCalories));
    }
    // clode the file and leave the function 
    file.close();
    return;
}

void fileSystem::saveProfiles(vector<Profile> &profiles) {
    ofstream file("profiles.csv", ios::out);  // Open file in overwrite mode

    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return; // return an error code
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
    // close the file
    file.close();
}

void fileSystem::initializeActivities(vector<Profile> &profiles){
    // read form the activites.csv file
    ifstream file("activities.csv", ios::in);
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return ; // Return an error code
    }

    string line;
   
    // Skip the first line (header)
    getline(file, line);

    while (getline(file, line)) { // while you are not at the end of the file
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
        duration = stod(field); // Convert to double
        
        getline(ss, field, ',');  
        caloriesBurned = stod(field); // Convert to double

        // iterates through the profiles and adds the activity to the correct profile if the id matches
        for (auto &profile : profiles){
            if (profile.getID() == id){
                profile.addActivity(activityType,duration);
            }
        }
    }
    // closes the file
    file.close();
    return;
}


void fileSystem::saveActivities(vector<Profile> &profiles) {
     ofstream file("activities.csv", ios::out);  // Open file in overwrite mode

    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return; // returns an error code 
    }

    // Write the first line (header)
    file << "userID,activityType,duration,caloriesBurned\n";
    
    // Iterate through the profiles vector 
    for (const auto &profile : profiles) {
        // iterate through the activities vector for each profile and print the activity to the file
       for (const auto &activity : profile.getActivities()){
            file << activity->getUserID() << ","
                 << activity->getActivityType()<< ","
                 << activity->getDuration() << ","
                 << activity->getCaloriesBurned() << '\n';
       }
    }
    // close the file
    file.close();
}

