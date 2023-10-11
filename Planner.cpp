
#include "Planner.h"
#include "Menu.h"



void Destroy(plansArray& a)
{
    for (int i = 0; i < a.count; i++)
        delete a.list[i];
    delete[] a.list;
}

void CoutPlans(const plansArray& a)
{
    for (int i = 0; i < a.count; i++)
    {

        cout << "Название: " << a.list[i]->name << endl;
        cout << "Описание: " << a.list[i]->descrb << endl;
        cout << "Приоритетность: " << a.list[i]->priority << endl;
        cout << "Год: " << a.list[i]->dateof.tm_year + 1900 << endl;
        cout << "Месяц: " << a.list[i]->dateof.tm_mon + 1 << endl;
        cout << "День: " << a.list[i]->dateof.tm_mday << endl;
        cout << "Время: " << a.list[i]->dateof.tm_hour << " : " << a.list[i]->dateof.tm_min << endl << endl << endl;
        
    }
    cout << endl << endl;
}

void AddPlan(plansArray& a,  planner* newPlan)
{
    planner** temp = new planner * [a.count + 1];
    for (int i = 0; i < a.count; i++)
    {
        temp[i] = a.list[i];
    }
    delete[] a.list;
    a.list = temp;
    a.list[a.count++] = newPlan;

}


void InputDeal(planner* deal)
{
    deal->name = new char[100];
    cout << "Введите имя: ";
    cin.ignore();
    cin.getline(deal->name, 100);
    deal->descrb = new char[100];

    cout << "Введите описание: ";
    cin.getline(deal->descrb, 100);


    cout << "Введите дату в формате д.м.г : ";
    string dateInput;
    cin >> dateInput;

    istringstream dateSS(dateInput);
    char dateColon;
    dateSS >> deal->dateof.tm_mday >> dateColon >> deal->dateof.tm_mon >> dateColon >> deal->dateof.tm_year;
    deal->dateof.tm_year -= 1900;
    deal->dateof.tm_mon--;
    deal->dateof.tm_sec = 0;
    cout << "Введите время в формате HH:MM: ";
    string timeInput;
    cin >> timeInput;

    istringstream timeSS(timeInput);
    char timeColon;
    timeSS >> deal->dateof.tm_hour >> timeColon >> deal->dateof.tm_min;
    cin.ignore(); 
    deal->datesec = mktime(&deal->dateof);

    cout << "Введите приоритет: ";
    cin >> deal->priority;
}

bool CompareByPriority(const planner* a, const planner* b) //функция компоратор
{
    return a->priority == b->priority;
}

int FindNameIndex(const plansArray& a, const planner* st)
{
    int index = -1;
    for (int i = 0; i < a.count; i++)
    {

        if (strcmp(a.list[i]->name, st->name) == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}



int FindDescriptionIndex(const plansArray& a, const planner* st)
{
    int index = -1;
    for (int i = 0; i < a.count; i++)
    {
    
        if (strcmp(a.list[i]->descrb, st->descrb) == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

int FindPlanByDateTime(const plansArray& a, const planner* st)
{
    int index = -1;
    for (int i = 0; i < a.count; i++)
    {
        if (a.list[i]->datesec == st->datesec)
        {
            index = i;
            break;
        }
    }
    return index;
}


int FindIndex(const plansArray& a, planner* st, bool (*comparator)(const planner*, const planner*)) 
{
    int index = -1;
    for (int i = 0; i < a.count; i++)
    {
        if (comparator(a.list[i], st))
        {
            index = i;
            break;
        }
    }
    return index;
}

void CoutOnePlan(const plansArray& a, int index)
{
    if (index >= 0 && index < a.count)
    {
        cout << "Название: " << a.list[index]->name << endl;
        cout << "Описание: " << a.list[index]->descrb << endl;
        cout << "Приоритетность: " << a.list[index]->priority << endl;
        cout << "Год: " << a.list[index]->dateof.tm_year + 1900 << endl;
        cout << "Месяц: " << a.list[index]->dateof.tm_mon + 1 << endl;
        cout << "День: " << a.list[index]->dateof.tm_mday << endl;
        cout << "Время: " << a.list[index]->dateof.tm_hour << " : " << a.list[index]->dateof.tm_min << endl;
        cout << "-----------------------------" << endl;
    }
    else
    {
        cout << "Неверный индекс плана." << endl;
    }
}


void SearchBySmth(const plansArray& a, int index)
{
    bool found = false;

    for (int i = 0; i < a.count; i++)
    {
        if (index == i)
        {
            CoutOnePlan(a,i);


            found = true;
        }
    }

    if (!found)
    {
        cout << "План не найден." << endl;
    }
}

void PlansToday(const plansArray& a) 
{
    time_t currentTime = time(nullptr);
    struct tm today;
    if (localtime_s(&today, &currentTime) != 0) 
    {
        cerr << "Ошибка при получении текущей даты и времени." << endl;
        return;
    }

    cout << "Планы на сегодня (" << today.tm_mday << '.' << today.tm_mon + 1 << '.' << today.tm_year + 1900 << "):" << endl;
    for (int i = 0; i < a.count; ++i) 
    {
        if (a.list[i]->datesec == currentTime)
        {
            CoutPlans(a);
        }
    }
}

void PlansThisWeek(const plansArray& a) 
{
 
    time_t currentTime = time(nullptr);
    struct tm today;
    if (localtime_s(&today, &currentTime) != 0)
    {
        cerr << "Ошибка при получении текущей даты и времени." << endl;
        return;
    }

    cout << "Планы на текущую неделю (" << today.tm_mday << '.' << today.tm_mon + 1 << '.' << today.tm_year + 1900 << "):" << endl;
    for (int i = 0; i < a.count; ++i) 
    {
        time_t planTime = mktime(&a.list[i]->dateof);
        double diffDays = difftime(planTime, currentTime) / (60 * 60 * 24); // difftime - разница между текущем временем и будущем в сутках
        if (diffDays >= 0 && diffDays < 7) 
        {
            CoutPlans(a);
        }
    }
}

void PlansForMonth(const plansArray& a)
{
    time_t currentTime;
    time(&currentTime);

    tm currentLocalTime;
    localtime_s(&currentLocalTime, &currentTime);//проверка на корректность текущей даты, безопасная версия

    for (int i = 0; i < a.count; ++i)
    {
        tm planLocalTime;
        localtime_s(&planLocalTime, &a.list[i]->datesec);

        if (currentLocalTime.tm_year == planLocalTime.tm_year &&
            currentLocalTime.tm_mon == planLocalTime.tm_mon &&
            currentLocalTime.tm_mday == a.list[i]->dateof.tm_mday)
        {
            CoutPlans(a);
        }
    }
}



bool CompareByPriority2(const planner* a, const planner* b) 
{
    return a->priority < b->priority;
}


void SortPriority(plansArray& a) 
{
   sort(a.list, a.list + a.count, CompareByPriority2);
}

bool CompareByDate(const planner* a, const planner* b) //функция сравнения, возвращает true - если верно, false - если нет
{

    time_t timeA = mktime(const_cast<struct tm*>(&a->dateof));
    time_t timeB = mktime(const_cast<struct tm*>(&b->dateof));
    return timeA < timeB;
}

void SortDate(plansArray& a) 
{
    sort(a.list, a.list + a.count, CompareByDate); //принимает начальный указатель конечный указатель, функцию сравнения
}

void EditPlan(plansArray & a, int index)
{
    {
        if (index >= 0 && index < a.count)
        {
            InputDeal(a.list[index]);
        }
        else
        {
            cout << "Невернoe имя студента." << endl;
        }
    }

}

void RemovePlan(plansArray& a, int index) ////Тут была ошибка с работой с памятью
{
    if (index >= 0 && index < a.count)
    {
        delete[] a.list[index]->name;
        delete[] a.list[index]->descrb;

        delete a.list[index];

        for (int i = index; i < a.count - 1; i++)
        {
            a.list[i] = a.list[i + 1];
        }

        a.list[a.count - 1] = nullptr;
        a.count--;
        planner** newList = new planner * [a.count];
        for (int i = 0; i < a.count; ++i)
        {
            newList[i] = a.list[i];
        }
        delete[] a.list;
        a.list = newList;
    }
}