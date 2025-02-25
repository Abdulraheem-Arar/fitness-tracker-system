#include <iostream>
#include <vector>

using namespace std;




class Activity{
    private:
    int userID;
    string activityType;
    double duration;
    double caloriesBurned;
    

    public:

    Activity(int ID, string type, double duration) : userID(ID), activityType(type), duration(duration), caloriesBurned(calculateCaloriesBurned(type,duration)){};

    int getUserID() const{return userID;};
    string getActivityType() const{return activityType;};
    double getDuration() const{return duration;};
    double getCaloriesBurned() const{return caloriesBurned;};


    void displayActivity() const;

    static double calculateCaloriesBurned(string activity,double time);

};