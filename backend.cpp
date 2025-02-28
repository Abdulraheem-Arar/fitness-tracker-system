#include "backend.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>  // For system()
#include <thread>  // For std::this_thread::sleep_for

using namespace std;

    // function to display all users in the profiles vector
    void Utility::showUsers(const vector<Profile> &profiles) {
    cout << "the following are all the users stored: "<< endl;
    //loops through the profiles vector and prints each user
    for (int i = 0 ; i< profiles.size(); i++ ){
        cout << profiles[i].getName() ;
        if (i != profiles.size()-1){
            cout << ", ";
        }
        
    }
    cout << endl;
    }

    //function that selects a profile and assigns it to the current profile
    bool Utility::selectProfile(vector<Profile> &profiles, Profile *&currentProfile){
    int choice = 0;
    //if no profiles just return false
    if (profiles.empty()) {
        cout << "No profiles available to select.\n";
        return false;
    }
    // if the currentprofile points to something then ask the user if they want to make the changes to their current profile
    if (currentProfile!=nullptr){
        cout << "enter 1 if you wish to select this profile -" << currentProfile->getName() << "- otherwise enter any other integer: " ;
        cin >> choice ;
    } else { 
        //if the currentprofile points to null show them all the users and then ask for a name and search the profiles vector for the corresponding name
        Utility::showUsers(profiles);
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
    //if the user selects to view another profile show them all the users and then ask for a name and search the profiles vector for the corresponding name
    if (choice != 1 ){
        string name;
        cout << "\nwhat is the profile you want to select?\n";
        cin >> name;
        for(int i = 0;i< profiles.size();i++){
            if (profiles[i].getName() == name){
                currentProfile = &profiles[i];
                cout << "you have selected " << currentProfile->getName() << " as your current user" << endl;
                //returns true if the profile was found
                return true;
            }
        }
    }else if (choice ==1) {
        // if user stays on the same profile just retunr true
        return true;
    } else if (choice ==0){
        cout << "could not find the profile you were looking for" << endl;
        // returns false when the profile was not found
        return false;
    }
    cout << "could not find the profile you were looking for" << endl;
        // returns false when the profile was not found
        return false;
}


void Utility::createNewProfile(vector<Profile> &profiles, Profile *&currentProfile){
    // function that takes inputs for all profile fields and creates a new instance of a profile and adds it to the profiles vector
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

    // if inputs are valid then profile is pushed to profiles vector and currentprofile is set to the new profile
    if (age > 0 && weight > 0 && height > 0 && stepGoal > 0 && calorieGoal > 0) {
        profiles.push_back(Profile(name, age, weight, height, stepGoal, calorieGoal,0,0));
        currentProfile = &profiles.back();
    } else {
        cout << "one of your inputs was invalid" << endl;
    }
    
}



string Utility::chooseExercise() {
    //function which allows the user to pick which type of activity they have completed
    cout << "Choose an exercise:\n";
    cout << "1. Weightlifting\n";
    cout << "2. Running\n";
    cout << "3. Biking\n";
    cout << "4. Swimming\n";
    cout << "5. Walking\n";

    int choice =0;
    cout << "Enter your choice (1-5): ";
    cin >> choice;

    // validates input
    while (choice < 1 || choice > 5) {
        cout << "Invalid choice. Please enter a number between 1 and 6: ";
        cin >> choice;
    }
    // returns the string corresponding to the choice 
    switch (choice) {
        case 1: return "Weightlifting";
        case 2: return "Running";
        case 3: return "Biking";
        case 4: return "Swimming";
        case 5: return "Walking";
    }
    return "invalid";
}

void Utility::removeProfile(vector<Profile> &profiles, Profile *&currentProfile){
    //function which removes a profile for the profiles vector 
    if (profiles.empty()) {
        cout << "No profiles available to remove.\n";
        return;
    }

    int choice = 0;
    //if the current profile doesnt point to null ask for the users choice and display their current profile
    if (currentProfile !=nullptr){
        cout << "enter 1 if you wish to remove this profile -" << currentProfile->getName() << "- otherwise enter any other integer: " ;
        cin >> choice ;
    } else{
        // if the current profile does point to null show all of the users and ask which one they want to remove
        Utility::showUsers(profiles);
        string name;
        cout << "\nwhat is the profile you want to remove?\n";
        cin >> name;
        bool found = false;
        //iterate through the profiles vector and find the matching profile then remove that one from the profiles vector
        for(int i = 0;i< profiles.size();i++){
            if (profiles[i].getName() == name){
                profiles.erase(profiles.begin() + i);
                currentProfile = nullptr;
                found = true;
            }
        }
        // if no matching profile is found let the user know 
        if (!found){
            cout << "no profile found which matches the name you provided" << endl;
        }
    }
    // if the user chooses to delete their current profile
    if (choice ==1 ){
        // finds the current profile in the profiles vector
        auto it = std::find(profiles.begin(), profiles.end(), *currentProfile);
        // if the current profile was found then it is erased
        if (it != profiles.end()) {
            profiles.erase(it);
        }
    } else {
        // if the user chooses to delete a different profile then they will be asked for the name of the profile
        string name;
        cout << "\nwhat is the profile you want to remove?\n";
        cin >> name;
        bool found = false;
        // iterates through the profiles vector and erases the chosen profile
        for(int i = 0;i< profiles.size();i++){
            if (profiles[i].getName() == name){
                profiles.erase(profiles.begin() + i);
                found = true;
            }
        }
           // if no matching profile is found let the user know 
        if (!found){
            cout << "no profile found which matches the name you provided" << endl;
        }
    }
}





