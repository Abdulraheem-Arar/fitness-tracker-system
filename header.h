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

class Profile{
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
    vector<Activity> activities;

    public:
    Profile() : id(counter++), name(""), age(0), weight(0), height(0), BMI(0), dailyStepGoal(0), dailyCalorieGoal(0) , walkedSteps(0) , eatenCalories(0) {}
    Profile(string name, int age, double weight, double height, int stepGoal, int calorieGoal,int walkedSteps, int eatenCalories);
    Profile(int id,string name,int age,double weight, double height, int stepGoal, int calorieGoal, int walkedSteps, int eatenCalories);

    // Getters and Setters
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
    const vector<Activity>& getActivities() const{return activities;}; 


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



void createNewProfile(vector<Profile> &profiles, Profile *&currentProfile);

void displayMenu();

void removeProfile(vector<Profile> &profiles,Profile *&currentProfile);

void showUsers(const vector<Profile> &profiles) ;

bool selectProfile(vector<Profile> &profiles, Profile *&currentProfile);

void initializeProfiles( vector<Profile> &profiles);

void saveProfiles(vector<Profile> &profiles);

void initializeActivities(vector<Profile> &profiles);

void saveActivities(vector<Profile> &profiles);

extern vector<Profile> profiles;