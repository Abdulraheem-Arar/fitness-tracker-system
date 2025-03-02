#include <iostream>
#include <vector>

using namespace std;


class Activity {
    protected:
    int userID;
    string activityType;
    double duration;
    double caloriesBurned;
    
    public:
    // constructor
    Activity(int ID, string type, double duration) : userID(ID), activityType(type), duration(duration){}; 


    //getter functions
    int getUserID() const{return userID;};
    string getActivityType() const{return activityType;};
    double getDuration() const{return duration;};
    double getCaloriesBurned() const{return caloriesBurned;};


    // function to display the activity information (virtual as it is overriden in the inherited classes)
    virtual void displayActivity() const{ 
        cout << "Activity: " << activityType 
                  << ", Duration: " << duration << " min"
                  << ", Calories Burned: " << caloriesBurned << " kcal\n";
    }

};


