#ifndef RECIPE_DATABASE_H
#define RECIPE_DATABASE_H

using namespace std;

#include <fstream>
#include <vector>
#include <string>
#include "meal.h"
#include "recipe.h"

/*
    Actions
    - Must Maintain the Database of recipes
    - Must Allow the user to browse the database
    - Must permit the user to edit or annotate an existing recipe
    - Must permit the user to add a new recipe
*/

class RecipeDatabase {
private:
    // Maintain the Database of recipes
    ifstream ifs;
    ofstream ofs;

    vector<string> parsed_line_list;
    vector<Recipe> parsed_recipe_list;

public:
    void openFileStreams(string _path);

    // Allow the user to browse the database
    void readLineFromDB();
    void parseRecipeFromLine();

    void writeRecipeToDB(Recipe recipe); // add a new recipe
    void editRecipeOfDB(string _from_title, Recipe to_recipe); // edit or annotate an existing recipe 
    vector<Recipe>& getParsedRecipeList();
};

#endif