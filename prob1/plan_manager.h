#ifndef PLAN_MANAGER_H
#define PLAN_MANAGER_H

using namespace std;

#include <vector>
#include "date.h"

/*
    Permits the user to select a sequence of dates for planning
    Permits the user to edit an existing plan
    Associates with Date object
*/

class PlanManager {
private:
    vector<Date> plan_list;
public:
	PlanManager() {};

    vector<Date>& getPlanList() { return plan_list; };
    vector<Date> getSpecificPlanList(vector<string> _date_title_list); //Permits the user to select a sequence of dates for planning

    void editSpecificPlan(string _date_title); // the user to edit an existing plan
	void addPlan(Date date);
};

#endif