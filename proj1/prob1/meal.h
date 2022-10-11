#ifndef MEAL_H
#define MEAL_H

using namespace std;

#include <vector>
#include <string>
#include "recipe.h"

/*
    holds information about a single meal
    - Allows user to interact with the recipe database to select individual recipes for meals
    - User sets number of people to be present at meal, recipes are automatically scaled
    - Can produce grocery list for entire meal, by combining grocery lists from individual scaled recipes
*/

class Meal {
private:
    vector<Recipe> menu_list; // menu list corresponding to current meal that could be used
    string title; // meal name
    int number_of_people; // number that current meal can serve to people

public:
    Meal(string _title, int _number_of_people);

    void addMenu(Recipe recipe);

    vector<Recipe>& getMenuList();
    string getTitle();
    int getNumberOfPeople();

    void setTitle(string _title);
    void setNumberOfPeople(int _number_of_people);
};

#endif