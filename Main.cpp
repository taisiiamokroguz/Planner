
#include "Planner.h"
#include "Menu.h"
#include <locale>

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // получение дескриптора

void d(short x, short y) // перемещение курсора по консоли
{
    SetConsoleCursorPosition(h, { x, y });
}

void ConsoleCursorVisible(bool show, short size) //видиомость и размер курсора
{
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(h, &structCursorInfo);
    structCursorInfo.bVisible = show;
    structCursorInfo.dwSize = size;
    SetConsoleCursorInfo(h, &structCursorInfo);
}


int main()
{
    SetConsoleTitle(L"Planner");
    system("CLS");
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ConsoleCursorVisible(false, 100); //курсор невидимый

    //1 план
    plansArray plans;
    planner* newPlan = new planner;
    newPlan->dateof.tm_year = 2023 - 1900; 
    newPlan->dateof.tm_mon = 10 - 1;         
    newPlan->dateof.tm_mday = 10;
    newPlan->dateof.tm_hour = 10;
    newPlan->dateof.tm_min = 30;
    newPlan->dateof.tm_sec = 0;
    newPlan->datesec = mktime(&newPlan->dateof);
    newPlan->priority = 1;
    newPlan->name = new char[strlen("Новый план") + 1];
    strcpy_s(newPlan->name, strlen("Новый план") + 1, "Новый план");

    newPlan->descrb = new char[strlen("Описание нового плана") + 1];
    strcpy_s(newPlan->descrb, strlen("Описание нового плана") + 1, "Описание нового плана");
    AddPlan(plans, newPlan);

    //2 план
    planner* newPlan2 = new planner;
    newPlan2->dateof.tm_year = 2023 - 1900;
    newPlan2->dateof.tm_mon = 10 - 1;
    newPlan2->dateof.tm_mday = 4;
    newPlan2->dateof.tm_hour = 11;
    newPlan2->dateof.tm_min = 30;
    newPlan2->dateof.tm_sec = 0;
    newPlan2->datesec = mktime(&newPlan2->dateof);
    newPlan2->name = new char[strlen("Новый план2") + 1];
    newPlan2->priority = 2;
    strcpy_s(newPlan2->name, strlen("Новый план2") + 1, "Новый план2");

    newPlan2->descrb = new char[strlen("Описание нового плана2") + 1];
    strcpy_s(newPlan2->descrb, strlen("Описание нового плана2") + 1, "Описание нового плана2");
    AddPlan(plans, newPlan2);


    string T[] = { "Вывести все дела", "Добавить дело!", "Изменить план в планнере", "Удалить план", "Поиск по названию"
    , "Поиск по дате" , "Поиск по описанию" , "Поиск по приоритету", "Вывести план на ближайшую неделю", "Вывести план на ближайший месяц", "Вывести планы на сегодня"};
    char aT = 0;
    char c;

    do
    {
        char x = 50, y = 12; //начальный координаты для вывода текста на консоль
        d(x, y);

        for (char i = 0; i < size(T); i++)
        {
            if (i == aT) SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //подсвеченый текст
            else SetConsoleTextAttribute(h, FOREGROUND_GREEN); //неподсвеченый
            d(x, y++); // перемещаемся по оси у
            cout << T[i] << endl;
        }

        c = _getch(); //ждём ввод

        if (c == -32) // клавиша стрелки не нажата
        {
            c = _getch();
        }

        switch (c) //нажата
        {
        case ESC:
            exit(0);
        case UP:
            if (aT > 0)
                --aT;
            break;
        case DOWN:
            if (aT < size(T) - 1)
                ++aT;
            break;
        case ENTER:
            switch (aT)
            {
            case 0:

                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                MenuCoutPlans(plans);
                _getch();
                system("CLS");
                break;
            case 1:

                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                MenuAddPlan(plans);
                _getch();
                system("CLS");
                break;
            case 2:

                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                MenuEditPlan(plans);
                _getch();
                system("CLS");
                break;
            case 3:

                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                MenuRemovePlan(plans);
                _getch();
                system("CLS");
                break;
            case 4:

                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                MenuSearchDyName(plans);
                _getch();
                system("CLS");
                break;
            case 5:

                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                MenuSearchByDate(plans);
                _getch();
                system("CLS");
                break;
            case 6:

                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                MenuSearchByDscrb(plans);
                _getch();
                system("CLS");
                break;
            case 7:

                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                MenuSearchByPriority(plans);
                _getch();
                system("CLS");
                break;
            case 8:

                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                MenuCoutWeek(plans);
                _getch();
                system("CLS");
                break;
            case 9:

                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                MenuCoutMonth(plans);
                _getch();
                system("CLS");
                break;
            case 10:
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                PlansToday(plans);
                _getch();
                system("CLS");
                break;

            case 11:

                exit(0);
                break;
            default:
                cout << "" << (char)c << endl;
            }
        }
    } while (true);


   Destroy(plans);
}
