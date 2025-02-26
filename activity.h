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

    Activity(int ID, string type, double duration) : userID(ID), activityType(type), duration(duration){};

    inline int getUserID() const{return userID;};
    inline string getActivityType() const{return activityType;};
    inline double getDuration() const{return duration;};
    inline double getCaloriesBurned() const{return caloriesBurned;};


    virtual void displayActivity() const{
        cout << "Activity: " << activityType 
                  << ", Duration: " << duration << " min"
                  << ", Calories Burned: " << caloriesBurned << " kcal\n";
    }

};


