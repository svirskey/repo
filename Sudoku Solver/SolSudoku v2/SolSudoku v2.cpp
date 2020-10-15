#include <iostream>
#include <vector>

using namespace std;

istream& operator >>(istream &io,vector<int> &v2)
{
	int temp;
	io >> temp;
	v2.push_back(temp);
	return io;
}

ostream& operator <<(ostream &io, const vector<vector<vector<int>>> &v)
{
	for (size_t i = 0; i< v.size(); i++) // строка
	{
		for (size_t j = 0; j < v[i].size(); j++) //столбец
	    {
			cout << v[i][j][0] << " ";
	    }
		cout << endl;
	}
	return io;
}

void MatrOut(const vector<vector<vector<int>>> &v)
{
	cout <<endl<<"Output Sudoku"<< endl << v;
}

void correct(bool pr, int& a)
{
	do
	{
		cin >> a;
		if (pr != cin.good())
			cout << "Invalid input data, repeat please!" << endl;

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (!pr);
}

void MatrIn(vector<vector<vector<int>>> &matr,const int a)
{
	cout << "Enter all numbers by spaces line by line" << endl;
	cout << "If there is no number enter 0" << endl << endl;
	
	cout << "Input Sudoku" << endl;

	cin >> matr[0][0] >> matr[0][1] >> matr[0][2] >> matr[0][3] >> matr[0][4] >> matr[0][5] >> matr[0][6] >> matr[0][7] >> matr[0][8]
		>> matr[1][0] >> matr[1][1] >> matr[1][2] >> matr[1][3] >> matr[1][4] >> matr[1][5] >> matr[1][6] >> matr[1][7] >> matr[1][8]
	    >> matr[2][0] >> matr[2][1] >> matr[2][2] >> matr[2][3] >> matr[2][4] >> matr[2][5] >> matr[2][6] >> matr[2][7] >> matr[2][8]
	    >> matr[3][0] >> matr[3][1] >> matr[3][2] >> matr[3][3] >> matr[3][4] >> matr[3][5] >> matr[3][6] >> matr[3][7] >> matr[3][8]
	    >> matr[4][0] >> matr[4][1] >> matr[4][2] >> matr[4][3] >> matr[4][4] >> matr[4][5] >> matr[4][6] >> matr[4][7] >> matr[4][8]
	    >> matr[5][0] >> matr[5][1] >> matr[5][2] >> matr[5][3] >> matr[5][4] >> matr[5][5] >> matr[5][6] >> matr[5][7] >> matr[5][8]
	    >> matr[6][0] >> matr[6][1] >> matr[6][2] >> matr[6][3] >> matr[6][4] >> matr[6][5] >> matr[6][6] >> matr[6][7] >> matr[6][8]
	    >> matr[7][0] >> matr[7][1] >> matr[7][2] >> matr[7][3] >> matr[7][4] >> matr[7][5] >> matr[7][6] >> matr[7][7] >> matr[7][8]
	    >> matr[8][0] >> matr[8][1] >> matr[8][2] >> matr[8][3] >> matr[8][4] >> matr[8][5] >> matr[8][6] >> matr[8][7] >> matr[8][8];

}

void Sq(vector<vector<vector<int>>>& matr, int x1, int x2, int y1, int y2,const int a,int &sch,const int str,const int sto)
{
	for (int i = x1; i < x2; i++)
	{
		for (int j = y1; j < y2; j++)
		{
			for (int k = matr[str][sto].size(); k > 1; k--)
			{
				if (matr[str][sto][k-1] == matr[i][j][0])
				{
					matr[str][sto].erase(matr[str][sto].begin() + k - 1);
					sch = 0;
				}
			}
		}
	}
}

bool Alg(vector<vector<vector<int>>>& matr,const int a)
{
ag:

	int sch = 0;
	while (sch < a*a )
	{
		for (int i = 0; i < a; i++) //  номер строки где мы сейчас
		{
			for (int j = 0; j < a; j++) // номер столбца где мы сейчас
			{
				if (matr[i][j][0] == 0)
				{
					if (matr[i][j].size() == 1)
					{
					  for (int k = 0; k < a; k++)   // вписываем маленькие числа в квадрат и затем вычеркиваем попадающиеся
					  {
						matr[i][j].push_back(k + 1);
					  }
				    }

					for (int k = 0; k < a; k++)
					{
						for (int l = matr[i][j].size(); l >1 ; l--) // идем по строчке и  проверяем каждое число
						{
							if (matr[i][j][l-1] == matr[i][k][0])
							{
								matr[i][j].erase(matr[i][j].begin()+l-1);
								sch = 0;
							}
  					    }

						for (int l = matr[i][j].size() ; l > 1; l--) // идем по столбцу и  проверяем каждое число
						{
							if (matr[i][j][l-1] == matr[k][j][0]) 
							{
								matr[i][j].erase(matr[i][j].begin() + l-1);
								sch = 0;
							}
						}
					}

					// по квадрату 3х3

					if (i < 3)
					{
						if (j < 3)
						{
							Sq(matr, 0, 3, 0, 3, a,sch,i,j);
						}
						else if (j >= 3 && j < 6)
						{
							Sq(matr, 0, 3, 3, 6, a,sch,i,j);
						}
						else if (j >= 6 && j < 9)
						{
							Sq(matr, 0, 3, 6, 9, a,sch, i, j);
						}

					}

					else if (i >= 3 && i < 6)
					{
						if (j < 3)
						{
							Sq(matr, 3, 6, 0, 3, a,sch, i, j);
						}
						else if (j >= 3 && j < 6)
						{
							Sq(matr, 3, 6, 3, 6, a,sch, i, j);
						}
						else if (j >= 6 && j < 9)
						{
							Sq(matr, 3, 6, 6, 9, a,sch, i, j);
						}

					}

					else if (i >= 6 && i < 9)
					{
						if (j < 3)
						{
							Sq(matr, 6, 9, 0, 3, a,sch, i, j);
						}
						else if (j >= 3 && j < 6)
						{
							Sq(matr, 6, 9, 3, 6, a,sch, i, j);
						}
						else if (j >= 6 && j < 9)
						{
							Sq(matr, 6, 9, 6, 9, a,sch, i, j);
						}

					}

					if (matr[i][j].size()==2)
					{
						matr[i][j].erase(matr[i][j].begin()); 
						sch = 0;
					}
					else if (matr[i][j].size() == 1 && matr[i][j][0]==0)
					{
						return false;
					}
					
				}
				sch++;

				
			}
		}
	}

	// ниже проверка на решенность судоку

	bool prov = true;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			if (matr[i][j].size() > 1)
			{
				prov = false;
				break;
			}
		}
	}

	if (prov)
	{
		return true;
	}
	
	// ниже находим квадрат с наименьшим количеством возможных решений
		int i0 = -1, j0 = -1, min = -1;
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < a; j++)
			{
				if (min == -1 && matr[i][j][0] == 0)
				{
					min = matr[i][j].size();
					i0 = i;
					j0 = j;
				}

				if (matr[i][j][0]==0  &&  min>(int)matr[i][j].size())
				{
					min = matr[i][j].size();
					i0 = i;
					j0 = j;
				}
			}
		}
		
		// ниже рекурсия

		 vector<int> tmp = matr[i0][j0]; // переменная для хранения старого набора возможных маленьких чисел
		
		 auto tmp2 = matr;// переменная для хранения старого судоку 

		matr[i0][j0].clear();
		matr[i0][j0].push_back(tmp[tmp.size()-1]);

		if (!Alg(matr, a))
		{
			matr = tmp2;
			matr[i0][j0].pop_back(); // нужна проверка на корректность после захода в рекурсию
			goto ag;
		}
		else
		{
			return true;
		}
	
		return false;
}


int main(int argc, char* argv[])
{
	const int a = 9; // можно добавить 6х6 (мини-судоку)

	cout << "Sudoku Solver" << endl << endl;

	vector<vector<vector<int>>> v;

	v.resize(a); // строк
	for (int i = 0; i < a; i++)
	{
		v[i].resize(a); // сколько клеток в строке
	}

	MatrIn(v, a);

	if (Alg(v, a))
	{
		MatrOut(v);
	}
	else
	{
		cout << endl<<"Sudoku is incorrect!" << endl;
	}

	char s;
	cin >> s;
}
