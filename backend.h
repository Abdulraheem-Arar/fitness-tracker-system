#include "saving.h"
#include <iostream>
#include <algorithm>

using namespace std;

// utility namespace to organize functions together
namespace Utility {
    
    void showUsers(const vector<Profile> &profiles);

    bool selectProfile(vector<Profile> &profiles, Profile *&currentProfile);

    // function to diplay the main menu for the program
    inline void displayMenu(){
    cout << endl << "please choose one of the following options: \n" ;
        cout << "1. Create a new profile\n";
        cout << "2. Add progress to goals\n";
        cout << "3. Add a new activity\n";
        cout << "4. View profile information\n";
        cout << "5. Remove profile\n";
        cout << "6. List all profiles\n";
        cout << "7. Save and exit \n";
    }

    void createNewProfile(vector<Profile> &profiles, Profile *&currentProfile);

    string chooseExercise();

    void removeProfile(vector<Profile> &profiles, Profile *&currentProfile);

    bool isValidName(string name);
};


