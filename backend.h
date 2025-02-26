#include "header.h"
#include <iostream>
#include <algorithm>

using namespace std;

namespace Utility {

    void showUsers(const vector<Profile> &profiles);

    bool selectProfile(vector<Profile> &profiles, Profile *&currentProfile);

    inline void displayMenu(){
    cout << endl << "please choose one of the following options: \n" ;
        cout << "1. create a new profile\n";
        cout << "2. add progress to goals\n";
        cout << "3. add a new activity\n";
        cout << "4. view profile information\n";
        cout << "5. remove profile\n";
        cout << "6. list all profiles\n";
        cout << "7. exit \n";
    }

    void createNewProfile(vector<Profile> &profiles, Profile *&currentProfile);

    string chooseExercise();

    void removeProfile(vector<Profile> &profiles, Profile *&currentProfile);

};


