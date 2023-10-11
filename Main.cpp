
#include "Planner.h"
#include "Menu.h"
#include <locale>

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // ��������� �����������

void d(short x, short y) // ����������� ������� �� �������
{
    SetConsoleCursorPosition(h, { x, y });
}

void ConsoleCursorVisible(bool show, short size) //���������� � ������ �������
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
    ConsoleCursorVisible(false, 100); //������ ���������

    //1 ����
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
    newPlan->name = new char[strlen("����� ����") + 1];
    strcpy_s(newPlan->name, strlen("����� ����") + 1, "����� ����");

    newPlan->descrb = new char[strlen("�������� ������ �����") + 1];
    strcpy_s(newPlan->descrb, strlen("�������� ������ �����") + 1, "�������� ������ �����");
    AddPlan(plans, newPlan);

    //2 ����
    planner* newPlan2 = new planner;
    newPlan2->dateof.tm_year = 2023 - 1900;
    newPlan2->dateof.tm_mon = 10 - 1;
    newPlan2->dateof.tm_mday = 4;
    newPlan2->dateof.tm_hour = 11;
    newPlan2->dateof.tm_min = 30;
    newPlan2->dateof.tm_sec = 0;
    newPlan2->datesec = mktime(&newPlan2->dateof);
    newPlan2->name = new char[strlen("����� ����2") + 1];
    newPlan2->priority = 2;
    strcpy_s(newPlan2->name, strlen("����� ����2") + 1, "����� ����2");

    newPlan2->descrb = new char[strlen("�������� ������ �����2") + 1];
    strcpy_s(newPlan2->descrb, strlen("�������� ������ �����2") + 1, "�������� ������ �����2");
    AddPlan(plans, newPlan2);


    string T[] = { "������� ��� ����", "�������� ����!", "�������� ���� � ��������", "������� ����", "����� �� ��������"
    , "����� �� ����" , "����� �� ��������" , "����� �� ����������", "������� ���� �� ��������� ������", "������� ���� �� ��������� �����", "������� ����� �� �������"};
    char aT = 0;
    char c;

    do
    {
        char x = 50, y = 12; //��������� ���������� ��� ������ ������ �� �������
        d(x, y);

        for (char i = 0; i < size(T); i++)
        {
            if (i == aT) SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //����������� �����
            else SetConsoleTextAttribute(h, FOREGROUND_GREEN); //�������������
            d(x, y++); // ������������ �� ��� �
            cout << T[i] << endl;
        }

        c = _getch(); //��� ����

        if (c == -32) // ������� ������� �� ������
        {
            c = _getch();
        }

        switch (c) //������
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
