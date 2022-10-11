#ifndef GREETER_H
#define GREETER_H

#include "plan_manager.h"
#include "recipe_database.h"
#include "recipe.h"

using namespace std;

/*
    When the application is started, 
    the Greeter puts an informative and friendly welcome window (the greeting) on the screen

    Actions
    - Casually browse the database of recipes
    - Add a new recipe
    - Edit or annotate a recipe
    - Review a plan for several meals
    - Create a plan of meals
*/

class Greeter {
private:
    int selected_menu = 0;
	int selected_plan = 0;
    int selected_recipe = 0;

public:
	Greeter() {}

    int getSelectedMenu() { return selected_menu; };
    int getSelectedPlan() { return selected_plan; };
    int getSelectedRecipe() { return selected_recipe; };

	void getOptionFromInput(int* option); // Get menu option from user input
	void printWelcome(); // An informative and friendly welcome window (the greeting) on the screen

	Recipe addNewRecipe(); // Get a new recipe from user input
    void editRecipe(Recipe* recipe); // Edit a recipe from user input
    void annotateRecipe(Recipe* recipe); // Make comments to a recipe from user input
	void saveRecipe(Recipe newRecipe, RecipeDatabase recipeDB); // Add a new recipe to DB
    
    void printRecipe(Recipe recipe); // Print the recipe to the screen
	void showAllRecipes(RecipeDatabase recipeDB); // Show all recipes from database

    void printPlanFormatted(PlanManager manager, int _selected_plan); // Print tReview a plan for several meals
    void createPlan(PlanManager manager, int selected_recipe); // Create a plan of meals
};

#endif