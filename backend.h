#include "header.h"
#include <iostream>
#include <algorithm>

using namespace std;

namespace Utility {

    void showUsers(const vector<Profile> &profiles);

    bool selectProfile(vector<Profile> &profiles, Profile *&currentProfile);

    void displayMenu();

    void createNewProfile(vector<Profile> &profiles, Profile *&currentProfile);

    string chooseExercise();

    void removeProfile(vector<Profile> &profiles, Profile *&currentProfile);

};


