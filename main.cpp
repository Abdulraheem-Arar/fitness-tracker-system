#include "backend.h"

// initialized currenProfile pointer to null and declares the profiles vector
Profile *currentProfile = nullptr;
vector<Profile> profiles;

int main(){

    // initializes the profiles vector and the activities inside the each profile to the values stored inside the csv files
    fileSystem::initializeProfiles(profiles);
    fileSystem::initializeActivities(profiles);
    cout << "===================================" << endl;
    cout << "   Welcome to the Fitness Tracker  " << endl;
    cout << "===================================" << endl;
    

    int choice = 0;
    // main loop for the program runs while user doesnt choose to exit
    while (choice!=7){
        //displays menu 
        Utility::displayMenu();
        cin >> choice;
        // swicth statement depending on choice
        switch(choice){
            case 1:
                //creates a new profile
                Utility::createNewProfile(profiles, currentProfile);
                break;
            case 2:
                //looks for profile and then if a profile is found it adds progress to its goals
                bool isfound1;
                isfound1 = Utility::selectProfile(profiles,currentProfile);
                if (isfound1) {currentProfile->addToGoals();};
                break;
            case 3:
                // looks for a profile then if a profile is found it adds an activity to it
                bool isfound2;
                isfound2 = Utility::selectProfile(profiles,currentProfile);
                if (isfound2) {currentProfile->addActivity();};
                break;
            case 4: 
                //looks for a profile and if one is found it displays it
                bool isfound3;
                isfound3 = Utility::selectProfile(profiles,currentProfile);
                if (isfound3) {currentProfile->displayProfile();};
                break;
            case 5:
                // removes a profile form the profiles vector
                Utility::removeProfile(profiles,currentProfile);
                break;
            case 6:
                // displays a list of all of the users
                Utility::showUsers(profiles);
                break;
            case 7:
                //exits the program
                cout << "exiting the program" << endl;
                break;
            default:
                //validates the input
                cout << "please enter a corrrect choice" << endl ;
                break;
        }
    }
    //saves the information of profiles and activities to the two csv files
    fileSystem::saveProfiles(profiles);
    fileSystem::saveActivities(profiles);
}
