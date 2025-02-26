#include <iostream>
#include <vector>
#include "activityTypes.h"

using namespace std;

class Profile {
    private:
    static int counter;
    int id;
    string name;
    int age;
    double weight;
    double height;
    double BMI;
    int dailyStepGoal;
    int dailyCalorieGoal;
    int walkedSteps;
    int eatenCalories;
    vector<Activity*> activities;


    public:
    Profile() : id(counter++), name(""), age(0), weight(0), height(0), BMI(0), dailyStepGoal(0), dailyCalorieGoal(0) , walkedSteps(0) , eatenCalories(0) {}
    Profile(string name, int age, double weight, double height, int stepGoal, int calorieGoal,int walkedSteps, int eatenCalories);
    Profile(int id,string name,int age,double weight, double height, int stepGoal, int calorieGoal, int walkedSteps, int eatenCalories);


    ~Profile(){
        for (auto activity : activities) {
            delete activity;  // Free each dynamically allocated memory
        }
    }
    // Getters and Setters
    inline int getID() const {return id;};
    inline string getName() const {return name;};
    inline int getAge() const {return age;};
    inline double getWeight() const{return weight;};
    inline double getHeight() const{return height;};
    inline double getBMI() const {return BMI;};
    inline int getStepGoal() const{return dailyStepGoal;};
    inline int getCalorieGoal() const{return dailyCalorieGoal;};
    inline int getWalkedSteps() const{return walkedSteps;};
    inline int getEatenCalories() const{return eatenCalories;};
    inline const vector<Activity*>& getActivities() const { return activities; }



    void setName(string newName){name = newName;};
    void setAge(int newAge){age = newAge;};
    void setWeight(double newWeight){weight = newWeight;};
    void setHeight(double newHeight){height = newHeight;};
    void setStepGoal(int newStepGoal){dailyStepGoal = newStepGoal;};
    void setCalorieGoal(int newCalorieGoal){dailyCalorieGoal = newCalorieGoal;};


    // Utility Functions
    double calculateBMI() const;

    void addActivity(string type, double duration);

    void displayProfile() const;

    void addToGoals();

    
    void addActivity();

    void viewProfile();
    //equality operator

    bool operator==(const Profile &user) const{
        return this->id == user.getID();
    }

};