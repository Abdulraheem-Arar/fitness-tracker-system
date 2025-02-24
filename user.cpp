#include "header.h"


Profile *currentProfile = nullptr;
vector<Profile> profiles;

int main(){
//     Profile p1("John", 25, 70.0, 175.0, 10000, 2000, 5000, 1500);
//     p1.addActivity();
    
//     cout << p1.getActivities().size()<< endl;
// for (int i=0 ;i<p1.getActivities().size();i++){
//     cout << "activity info"<< endl;
//     cout << p1.getActivities()[i].getUserID()<< endl;
//     cout << p1.getActivities()[i].getActivityType()<< endl;
//     cout << p1.getActivities()[i].getDuration()<< endl;
//     cout << p1.getActivities()[i].getCaloriesBurned()<< endl;
// }

    initializeProfiles(profiles);
    initializeActivities(profiles);
    cout << "===================================" << endl;
    cout << "   Welcome to the Fitness Tracker  " << endl;
    cout << "===================================" << endl;
    

    int choice = 0;

    while (choice!=7){
        displayMenu();
        cin >> choice;
        switch(choice){
            case 1:
                createNewProfile(profiles, currentProfile);
                break;
            case 2:
                bool isfound1;
                isfound1 = selectProfile(profiles,currentProfile);
                if (isfound1) {currentProfile->addToGoals();};
                break;
            case 3:
                bool isfound2;
                isfound2 = selectProfile(profiles,currentProfile);
                if (isfound2) {currentProfile->addActivity();};
                break;
            case 4: 
                bool isfound3;
                isfound3 = selectProfile(profiles,currentProfile);
                if (isfound3) {currentProfile->displayProfile();};
                break;
            case 5:
                removeProfile(profiles,currentProfile);
                break;
            case 6:
                showUsers(profiles);
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
