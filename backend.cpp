#include "backend.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>  // For system()
#include <thread>  // For std::this_thread::sleep_for

using namespace std;

    void Utility::showUsers(const vector<Profile> &profiles) {
    cout << "the following are all the users stored: "<< endl;
    for (int i = 0 ; i< profiles.size(); i++ ){
        cout << profiles[i].getName() ;
        if (i != profiles.size()-1){
            cout << ", ";
        }
        
    }
    cout << endl;
    }

    bool Utility::selectProfile(vector<Profile> &profiles, Profile *&currentProfile){
    int choice = 0;
    if (profiles.empty()) {
        cout << "No profiles available to select.\n";
        return false;
    }
    if (currentProfile!=nullptr){
        cout << "enter 1 if you wish to select this profile -" << currentProfile->getName() << "- otherwise enter any other integer: " ;
        cin >> choice ;
    } else {
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


void Utility::createNewProfile(vector<Profile> &profiles, Profile *&currentProfile){
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

    if (age > 0 && weight > 0 && height > 0 && stepGoal > 0 && calorieGoal > 0) {
        profiles.push_back(Profile(name, age, weight, height, stepGoal, calorieGoal,0,0));
        currentProfile = &profiles.back();
    } else {
        cout << "one of your inputs was invalid" << endl;
    }
    
}



string Utility::chooseExercise() {
    cout << "Choose an exercise:\n";
    cout << "1. Weightlifting\n";
    cout << "2. Running\n";
    cout << "3. Biking\n";
    cout << "4. Swimming\n";
    cout << "5. Walking\n";

    int choice =0;
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

void Utility::removeProfile(vector<Profile> &profiles, Profile *&currentProfile){
    if (profiles.empty()) {
        cout << "No profiles available to remove.\n";
        return;
    }

    int choice = 0;
    if (currentProfile !=nullptr){
        cout << "enter 1 if you wish to remove this profile -" << currentProfile->getName() << "- otherwise enter any other integer: " ;
        cin >> choice ;
    } else{
        Utility::showUsers(profiles);
        string name;
        cout << "\nwhat is the profile you want to remove?\n";
        cin >> name;
        bool found = false;
        for(int i = 0;i< profiles.size();i++){
            if (profiles[i].getName() == name){
                profiles.erase(profiles.begin() + i);
                currentProfile = nullptr;
                found = true;
            }
        }
        if (!found){
            cout << "no profile found which matches the name you provided" << endl;
        }
    }
    if (choice ==1 ){
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





