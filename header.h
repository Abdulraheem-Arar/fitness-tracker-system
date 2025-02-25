#pragma once

#include <iostream>
#include <vector>
#include "profile.h"

using namespace std;

void createNewProfile(vector<Profile> &profiles, Profile *&currentProfile);

void displayMenu();

void removeProfile(vector<Profile> &profiles,Profile *&currentProfile);

void showUsers(const vector<Profile> &profiles) ;

bool selectProfile(vector<Profile> &profiles, Profile *&currentProfile);

void initializeProfiles( vector<Profile> &profiles);

void saveProfiles(vector<Profile> &profiles);

void initializeActivities(vector<Profile> &profiles);

void saveActivities(vector<Profile> &profiles);

extern vector<Profile> profiles;