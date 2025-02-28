#pragma once

#include <iostream>
#include <vector>
#include "profile.h"

//filesystem namespace to organize function together
namespace fileSystem {
    void initializeProfiles( vector<Profile> &profiles);

    void saveProfiles(vector<Profile> &profiles);

    void initializeActivities(vector<Profile> &profiles);

    void saveActivities(vector<Profile> &profiles);
}

// Declares profiles vector as external, allowing it to be shared across multiple files
extern vector<Profile> profiles;