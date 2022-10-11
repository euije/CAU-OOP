#ifndef RECIPE_H
#define RECIPE_H

using namespace std;

#include <vector>
#include <string>

/*
    Tasks
    - Maintains the list of ingredients and transformation algorithm
    - Must know how to edit these data values
    - Must know how to interactively display itself on the output device
    - Must know how to print itself
    etc

    There are likely many instances of recipe, but they will all behave in the same way
    We say the behavior is common to the class Recipe
*/

class Recipe {
private:
    string name; // Name of the recipe
    int time_cost; // Amount of time
    vector< pair<string, int> > ingredient_list; // List of ingredients
    vector<string> steps; // List of steps -> discription

public:
    Recipe(string _name);
    Recipe(string _name, int _time_cost);
    Recipe(string _name, int _time_cost, vector< pair<string, int> > & _ingredients);
    Recipe(string _name, int _time_cost, vector< pair<string, int> > & _ingredients, vector< string > & _steps);

    void setName(string _name);
    void setTimeCost(int _time_cost);
    void addIngredient(string ingredient, int count); // Add a new ingredient to the ingredient list
    void setSteps(vector<string> _steps);

    void deleteIngredient(string _name); // Delete the given ingredient in list
    
    // Must know how to print itself
    void printRecipeSteps(); // Print recipe steps
    void printRecipeIngredients(); // Print recipe ingredients
};

#endif