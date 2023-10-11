#pragma once
#include "Planner.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#define ESC 27 //ASCII коды для клавиш
#define UP 72
#define DOWN 80
#define ENTER 13
using namespace std;



void MenuCoutPlans(plansArray& a);
void MenuAddPlan(plansArray& a);
void MenuEditPlan(plansArray& a);
void MenuRemovePlan(plansArray& a);
void MenuSearchDyName(const plansArray& a);
void MenuSearchByDate(const plansArray& a);
void MenuSearchByDscrb(const plansArray& a);
void MenuSearchByPriority(const plansArray& a);
void MenuCoutWeek(plansArray& a);
void MenuCoutMonth(plansArray& a);