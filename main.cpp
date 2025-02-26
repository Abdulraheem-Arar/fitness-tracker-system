#include "backend.h"


Profile *currentProfile = nullptr;
vector<Profile> profiles;

int main(){


    initializeProfiles(profiles);
    initializeActivities(profiles);
    cout << "===================================" << endl;
    cout << "   Welcome to the Fitness Tracker  " << endl;
    cout << "===================================" << endl;
    

    int choice = 0;

    while (choice!=7){
        Utility::displayMenu();
        cin >> choice;
        switch(choice){
            case 1:
                Utility::createNewProfile(profiles, currentProfile);
                break;
            case 2:
                bool isfound1;
                isfound1 = Utility::selectProfile(profiles,currentProfile);
                if (isfound1) {currentProfile->addToGoals();};
                break;
            case 3:
                bool isfound2;
                isfound2 = Utility::selectProfile(profiles,currentProfile);
                if (isfound2) {currentProfile->addActivity();};
                break;
            case 4: 
                bool isfound3;
                isfound3 = Utility::selectProfile(profiles,currentProfile);
                if (isfound3) {currentProfile->displayProfile();};
                break;
            case 5:
                Utility::removeProfile(profiles,currentProfile);
                break;
            case 6:
                Utility::showUsers(profiles);
                break;
            case 7:
                cout << "exiting the program" << endl;
                break;
            default:
                cout << "please enter a corrrect choice" << endl ;
                break;
        }
    }

    saveProfiles(profiles);
    saveActivities(profiles);
}
