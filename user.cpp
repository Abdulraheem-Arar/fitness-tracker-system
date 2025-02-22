#include "header.h"


Profile currentProfile;
vector<Profile> profiles;

int main(){

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
                bool isfound;
                isfound = selectProfile(profiles,currentProfile);
                if (isfound) {currentProfile.addToGoals();};
                break;
            case 3:
                addActivity(profiles, currentProfile);
                break;
            case 4: 
                viewProfile(profiles, currentProfile);
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
}


