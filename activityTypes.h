#include "activity.h"

class Running : public Activity {
public:
    Running(int id, double duration) : Activity(id,"Running", duration) { caloriesBurned = calculateCaloriesBurned();
    }

    double calculateCaloriesBurned() {
        return duration * 288/30; 
    }

    void displayActivity() const override {
        cout << "Running for " << duration << " minutes and burned " << caloriesBurned << " calories." << endl;
    }
};

class Weightlifting : public Activity {
public:
    Weightlifting(int id, double duration) : Activity(id,"Weightlifting", duration) { caloriesBurned = calculateCaloriesBurned();
    }

    double calculateCaloriesBurned() {
        return duration * 108/30; 
    }

    void displayActivity() const override {
        cout << "Weightlifting for " << duration << " minutes and burned " << caloriesBurned << " calories." << endl;
    }
};

class Biking : public Activity {
public:
    Biking(int id, double duration) : Activity(id,"Biking", duration) { caloriesBurned = calculateCaloriesBurned();
    }

    double calculateCaloriesBurned() {
        return duration * 288/30; 
    }

    void displayActivity() const override {
        cout << "Biking for " << duration << " minutes and burned " << caloriesBurned << " calories." << endl;
    }
};

class Swimming : public Activity {
public:
    Swimming(int id, double duration) : Activity(id,"Swimming", duration) { caloriesBurned = calculateCaloriesBurned();
    }

    double calculateCaloriesBurned() {
        return duration * 216/30; 
    }

    void displayActivity() const override {
        cout << "Swimming for " << duration << " minutes and burned " << caloriesBurned << " calories." << endl;
    }
};

class Walking : public Activity {
public:
    Walking(int id, double duration) : Activity(id,"Walking", duration) { caloriesBurned = calculateCaloriesBurned();
    }

    double calculateCaloriesBurned() {
        return duration * 133/30; 
    }

    void displayActivity() const override {
        cout << "Walking for " << duration << " minutes and burned " << caloriesBurned << " calories." << endl;
    }
};