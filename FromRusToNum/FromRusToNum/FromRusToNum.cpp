#include <iostream>
#include <string>
#include <vector>
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
void TranslateToNumbers(vector<string>& lst, string num)
{

}

int main()
{
    setlocale(LC_ALL, "rus");

    vector<string> lst;
    char buff[256] = { "" };
    int sizeofbuff = 0;
    string num;

    cout << "Введите название числа: ";
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


}