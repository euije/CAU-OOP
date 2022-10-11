#ifndef DATE_H
#define DATE_H

using namespace std;

#include <string>
#include "meal.h"
#include "recipe.h"

/*
    User can edit specific meals
    User can annotate information about dates
    ''Bob's Birthday'', ``Christmas Dinner'', …
    Can print out grocery list for entire set of meals
*/

class Date {
private:
    int year; // YYYY
    int month; // MM
    int day; // DD
	string title; // ''Bob's Birthday'', ``Christmas Dinner'', …
	vector<Meal> special_meal_list;

public:
	Date(int _year, int _month, int _day, string _title);

	int getYear();
	int getMonth();
	int getDay();
	string getTitle();
	vector<Meal>& getSpecialMealList();

    void setYear();
	void setMonth();
	void setDay();
	void setTitle();

	void addSpecialMeal(Meal meal);
    void deleteSpecialMeal(string meal_title); // edit specific meals

    void printGroceryList(); // Can print out grocery list for entire set of meals // Meal -> ingredient list
};

#endif