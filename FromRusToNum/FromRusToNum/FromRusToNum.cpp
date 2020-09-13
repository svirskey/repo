#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

void ToPart(char* buff, int sizeofbuff, vector<string>& lst)
{
    int begin = 0;
    string tmp;
    for (int i = 0; i < sizeofbuff; i++)
    {
        if (buff[i] == ' ')
        {
            for (int j = begin; j < i; j++)
            {
                tmp += buff[j];
            }
            lst.push_back(tmp);
            tmp.clear();
            begin = i + 1;
        }
        if (i == sizeofbuff - 1 and buff[sizeofbuff - 1] != ' ')
        {
            for (int j = begin; j <= i; j++)
            {
                tmp += buff[j];
            }
            lst.push_back(tmp);
        }
    }
}

bool Hundreds(string word, int& num)
{
    if (word == "Сто" or word == "сто")
    {
        num = 100; return true;
    }
    else if (word == "Двести" or word == "двести")
    {
        num = 200; return true;
    }
    else if (word == "Триста" or word == "триста")
    {
        num = 300; return true;
    }
    else if (word == "Четыреста" or word == "четыреста")
    {
        num = 400; return true;
    }
    else if (word == "Пятьсот" or word == "пятьсот")
    {
        num = 500; return true;
    }
    else if (word == "Шестьсот" or word == "шестьсот")
    {
        num = 600; return true;
    }
    else if (word == "Семьсот" or word == "семьсот")
    {
        num = 700; return true;
    }
    else if (word == "Восемьсот" or word == "восемьсот")
    {
        num = 800; return true;
    }
    else if (word == "Девятьсот" or word == "девятьсот")
    {
        num = 900; return true;
    }
    return false;
}

bool Decades(string word, int& num)
{
    if (word == "Двадцать" or word == "двадцать")
    {
        num = 20; return true;
    }
    else if (word == "Тридцать" or word == "тридцать")
    {
        num = 30; return true;
    }
    else if (word == "Сорок" or word == "сорок")
    {
        num = 40; return true;
    }
    else if (word == "Пятьдесят" or word == "пятьдесят")
    {
        num = 50; return true;
    }
    else if (word == "Шестьдесят" or word == "шестьдесят")
    {
        num = 60; return true;
    }
    else if (word == "Семьдесят" or word == "семьдесят")
    {
        num = 70; return true;
    }
    else if (word == "Восемьдесят" or word == "восемьдесят")
    {
        num = 80; return true;
    }
    else if (word == "Девяносто" or word == "девяносто")
    {
        num = 90; return true;
    }
    return false;
}

bool Units(string word, int& num)
{
    if (word == "Один" or word == "один")
    {
        num = 1; return true;
    }
    else if (word == "Два" or word == "два")
    {
        num = 2; return true;
    }
    else if (word == "Три" or word == "три")
    {
        num = 3; return true;
    }
    else if (word == "Четыре" or word == "четыре")
    {
        num = 4; return true;
    }
    else if (word == "Пять" or word == "пять")
    {
        num = 5; return true;
    }
    else if (word == "Шесть" or word == "шесть")
    {
        num = 6; return true;
    }
    else if (word == "Семь" or word == "семь")
    {
        num = 7; return true;
    }
    else if (word == "Восемь" or word == "восемь")
    {
        num = 8; return true;
    }
    else if (word == "Девять" or word == "девять")
    {
        num = 9; return true;
    }
    else if (word == "Десять" or word == "десять")
    {
        num = 10; return true;
    }
    else if (word == "Одиннадцать" or word == "одиннадцать")
    {
        num = 11; return true;
    }
    else if (word == "Двенадцать" or word == "двенацдать")
    {
        num = 12; return true;
    }
    else if (word == "Тринадцать" or word == "тринадцать")
    {
        num = 13; return true;
    }
    else if (word == "Четырнадцать" or word == "четырнадцать")
    {
        num = 14; return true;
    }
    else if (word == "Пятнадцать" or word == "пятнадцать")
    {
        num = 15; return true;
    }
    else if (word == "Шестнадцать" or word == "шестнадцать")
    {
        num = 16; return true;
    }
    else if (word == "Семнадцать" or word == "семнадцать")
    {
        num = 17; return true;
    }
    else if (word == "Восемнадцать" or word == "восемнадцать")
    {
        num = 18; return true;
    }
    else if (word == "Девятнадцать" or word == "девятнадцать")
    {
        num = 19; return true;
    }
    return false;
}

bool TranslateToNumbers(vector<string>& lst, int& num)
{
    bool flag100 = false, flag10 = false, flag1 = false;
    int tmp=0;
    for (int i = 0; i < lst.size(); i++)
    {
        if ( Hundreds(lst[i], tmp)) // ок
        {
            if (flag100 or flag10 or flag1) return false;
            flag100 = true;
            num += tmp;
            continue;
        }

        if ( Decades(lst[i], tmp)) // проверка на корректность нужна, пример: тридцать двадцать один
        {
            if (flag10 or flag1) return false;
            flag10 = true; flag100 = true;
            num += tmp;
            continue;
        }

        if (Units(lst[i], tmp))
        {
            if (flag1) return false;
            flag1 = true; flag10 = true; flag100 = true;
            num += tmp;
            continue;    
        }       
    }
    return true;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<string> lst;
    char buff[256] = { "" };
    int sizeofbuff = 0;
    int num=0;
    bool flag = false;
    cout << "Введите название числа: "<<endl;
    cin.getline(buff, 256);

    for (int i = 0; i < sizeof(buff) / sizeof(char); i++)
    {
        if (buff[i] == '\0')
        {
            sizeofbuff = i;
            break;
        }
    }

    ToPart(buff, sizeofbuff, lst);

    if (TranslateToNumbers(lst, num))
    {
        cout << num << endl;
    }
    else
    {
        cout << "Дядя Петя, вы дурак" << endl;
    }
    system("pause");
}