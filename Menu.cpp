
#include "Planner.h"
#include "Menu.h"

void MenuCoutPlans(plansArray& a)
{
    int ch, ch2;
    cout << "������������� ������� ����� �������? (1-��, 2-���)" << endl;

    while (!(cin >> ch) || (ch != 1 && ch != 2))
    {
        cout << "���������� ��������. ������ 1 ��� 2." << endl;
        cin.clear();  
        cin.ignore();  
    }

    if (ch == 1)
    {
        cout << "������������� �� ���� (1) ��� �� ���������� (2)?" << endl;
        while (!(cin >> ch2) || (ch2 != 1 && ch2 != 2))
        {
            cout << "���������� ��������. ������ 1 ��� 2." << endl;
            cin.clear();  
            cin.ignore();  
        }

        if (ch2 == 1)
        {
            SortDate(a);
            CoutPlans(a);
        }
        else if (ch2 == 2)
        {
            SortPriority(a);
            CoutPlans(a);
        }
    }
    else if (ch == 2)
    {
        CoutPlans(a);
    }
}

void MenuAddPlan(plansArray& a)
{
    planner* st = new planner;
    cout << "������� ������ ��� ������ �����" << endl;
    InputDeal(st);

    AddPlan(a, st);
    cout << "� ������ �������� ����� ����!" << endl;
    _getch();
}

void MenuRemovePlan(plansArray& a)
{
    
    planner* st = new planner;
    st->name = new char[100];
    cout << "������� �������� �����: ";
    cin.getline(st->name, 100);

    int index = FindNameIndex(a, st);
    if (index >= 0)
        RemovePlan(a, index);
    else
        cout << "������ ����� � �������� ���!" << endl;
    delete[] st->name;
    st = nullptr;

    _getch();
}

void MenuEditPlan(plansArray& a)
{
    
    planner* st = new planner;
    st->name = new char[100];
    cout << "������� �������� �����: ";
    cin.getline(st->name, 100);

    int index = FindNameIndex(a, st);
    if (index >= 0)
        EditPlan(a, index);
    else
        cout << "������ ����� � �������� ���!" << endl;
    delete [] st->name;
    delete st;
    st = nullptr;

    _getch();

    
}

void MenuSearchDyName(const plansArray& a)
{
    
    planner* st = new planner;
    st->name = new char[100];
    cout << "������� �������� �����: ";
    cin.getline(st->name, 100);

    int index = FindNameIndex(a, st);
    if (index >= 0)
        SearchBySmth(a, index);
    else
        cout << "������ ����� � �������� ���!" << endl;

    delete[] st->name;
    delete st;
    st = nullptr;

}

void MenuSearchByDate(const plansArray& a)
{
    planner* searchDeal = new planner;
    cout << "������� ���: ";
    _getch();
    cin >> searchDeal->dateof.tm_year;
    cout << "������� �����: ";
    cin >> searchDeal->dateof.tm_mon;
    cout << "������� ����: ";
    cin >> searchDeal->dateof.tm_mday;
    cout << "������� ����: ";
    cin >> searchDeal->dateof.tm_hour;
    cout << "������� ������: ";
    cin >> searchDeal->dateof.tm_min;
    searchDeal->dateof.tm_sec = 0;
    searchDeal->dateof.tm_year -= 1900;
    searchDeal->dateof.tm_mon --;
    searchDeal->datesec = mktime(&searchDeal->dateof);
    int foundIndex = FindPlanByDateTime(a, searchDeal);
    if (foundIndex >= 0)
        SearchBySmth(a, foundIndex);
    else
        cout << "������ ����� � �������� ���!" << endl;

    delete searchDeal;

}

void MenuSearchByDscrb(const plansArray& a)
{
    
    planner* s = new planner;
    s->descrb = new char[100];
    cout << "������� �������� �����: ";
    cin.getline(s->descrb, 100);

    int index = FindDescriptionIndex(a, s);
    if (index >= 0)
        SearchBySmth(a, index);
    else
        cout << "������ ����� � �������� ���!" << endl;

    delete[] s->descrb;
    delete s;
    s = nullptr;
    
}

void MenuSearchByPriority(const plansArray& a)
{
    planner* searchDeal = new planner;
    cout << "������� ��������� ��� ������: ";
    cin >> searchDeal->priority;

    int foundIndexByPriority = FindIndex(a, searchDeal, CompareByPriority);
    SearchBySmth(a, foundIndexByPriority);
    delete searchDeal;
}

void MenuCoutWeek(plansArray& a)
{
    int ch, ch2;
    cout << "������������� ������� ����� �������? (1-��, 2-���)" << endl;
    cin >> ch;

    if (ch == 1)
    {
        cout << "������������� �� ���� (1) ��� �� ���������� (2)?" << endl;
        cin >> ch2;

        if (ch2 == 1)
        {
            SortDate(a);
            PlansThisWeek(a);
        }
        else if (ch2 == 2)
        {
            SortPriority(a);
            PlansThisWeek(a);
        }
    }
    else if (ch == 2)
    {
        PlansThisWeek(a);
    }
}

void MenuCoutMonth(plansArray& a)
{
    int ch, ch2;
    cout << "������������� ������� ����� �������? (1-��, 2-���)" << endl;
    cin >> ch;

    if (ch == 1)
    {
        cout << "������������� �� ���� (1) ��� �� ���������� (2)?" << endl;
        cin >> ch2;

        if (ch2 == 1)
        {
            SortDate(a);
            PlansForMonth(a);
        }
        else if (ch2 == 2)
        {
            SortPriority(a);
            PlansForMonth(a);
        }
    }
    else if (ch == 2)
    {
        PlansForMonth(a);
    }
}