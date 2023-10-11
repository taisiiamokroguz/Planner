#pragma once
#include <iostream>
using namespace std;
#include <string.h>
#include <iomanip>
#include <ctime>
#include <string>
#include <sstream>
#include <limits>
#include <chrono>
#include <algorithm>
#include <conio.h>



struct planner
{
	tm dateof;
	time_t datesec;
	short priority = 0;
	char* name = NULL;
	char* descrb = NULL;
	
};




struct plansArray
{
	planner** list = nullptr;
	int count = 0;

};

void Destroy(plansArray& a);
void InputDeal(planner* deal);
void CoutPlans(const plansArray& a);
void AddPlan(plansArray& a,  planner* newPlan);
bool CompareByPriority(const planner* a, const planner* b);
int FindNameIndex(const plansArray& a, const planner* st);
int FindDescriptionIndex(const plansArray& a, const planner* st);
int FindPlanByDateTime(const plansArray& a, const planner* st);
int FindIndex(const plansArray& a, planner* st, bool (*comparator)(const planner*, const planner*));
void SearchBySmth(const plansArray& a, int index);
void PlansToday(const plansArray& a);
void PlansThisWeek(const plansArray& a);
void PlansForMonth(const plansArray& a);
void EditPlan(plansArray& a, int index);
bool CompareByPriority2(const planner* a, const planner* b);
void SortPriority(plansArray& a);
bool CompareByDate(const planner* a, const planner* b);
void SortDate(plansArray& a);
void RemovePlan(plansArray& a, int index);