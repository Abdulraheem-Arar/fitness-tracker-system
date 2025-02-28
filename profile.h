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
    //consturctors , one defualt and one used for profiles taken from files a and one for newly created profiles while program is running
    Profile() : id(counter++), name(""), age(0), weight(0), height(0), BMI(0), dailyStepGoal(0), dailyCalorieGoal(0) , walkedSteps(0) , eatenCalories(0) {}; 
    Profile(string name, int age, double weight, double height, int stepGoal, int calorieGoal,int walkedSteps, int eatenCalories): Profile(counter++, name, age, weight, height, stepGoal, calorieGoal, walkedSteps, eatenCalories) {};
    Profile(int id,string name,int age,double weight, double height, int stepGoal, int calorieGoal, int walkedSteps, int eatenCalories);


    ~Profile(){
        for (auto activity : activities) {
            delete activity;  // Free each dynamically allocated memory
        }
    }

    // Getters and Setters
    static int getCounter() {return counter;}
    int getID() const {return id;};
    string getName() const {return name;};
    int getAge() const {return age;};
    double getWeight() const{return weight;};
    double getHeight() const{return height;};
    double getBMI() const {return BMI;};
    int getStepGoal() const{return dailyStepGoal;};
    int getCalorieGoal() const{return dailyCalorieGoal;};
    int getWalkedSteps() const{return walkedSteps;};
    int getEatenCalories() const{return eatenCalories;};
    const vector<Activity*>& getActivities() const { return activities; }


    // setters were not used in the actual program but I included them anyways for better practice
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
    
    //equality operator
    bool operator==(const Profile &user) const{
        //checks if the id matches the compared profile id
        return this->id == user.getID();
    }

};