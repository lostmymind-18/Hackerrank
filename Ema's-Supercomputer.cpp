#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<cmath>
using namespace std;

vector<vector<int>> validPlus(vector<string> grid)
{
	vector<vector<int>> theReturn;
	
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[i].size(); j++)
		{
			int a = 0;
			while ((j+a) < grid[0].size())
			{
				if (grid[i][j + a] != 'G')
					break;
				if ((a + 1) % 2 == 1)
					theReturn.push_back({ i, j, a });
				a++;
			}	
		}
	}
	
	for (int i = 0; i < theReturn.size(); i++)
	{
		int a = theReturn[i][2] / 2;
		if (theReturn[i][0] < a)
		{
			theReturn.erase(theReturn.begin() + i);
			i--;
		}
		else if ((grid[0].size() - 1 - theReturn[i][1]) < theReturn[i][2])
		{
			theReturn.erase(theReturn.begin() + i);
			i--;
		}
		
		else if (grid.size() - 1 - theReturn[i][0] < a)
		{
			theReturn.erase(theReturn.begin() + i);
			i--;
		}

		else
		{
			for (int j = 0; j <= a; j++)
			{
				if (grid[theReturn[i][0] + j][theReturn[i][1] + a] != 'G')
				{
					theReturn.erase(theReturn.begin() + i);
					i--;
					break;
				}
				if (grid[theReturn[i][0] - j][theReturn[i][1] + a] != 'G')
				{
					theReturn.erase(theReturn.begin() + i);
					i--;
					break;
				}
			}
		}
	}

	return theReturn;
}

bool checkOverlap(vector<int> a, vector<int> b)
{
	a[2] = a[2] / 2;//2
	b[2] = b[2] / 2;//2
	a[1] += a[2];//2
	b[1] += b[2];//4
	if (a[0] == b[0] && abs(a[1] - b[1]) <= (a[2]+b[2]))
		return false;
	if (a[1] == b[1] && abs(a[0] - b[0] <= (a[2] + b[2])))
		return false;
				
	if (abs(a[0] - b[0]) <= a[2] && abs(a[1] - b[1]) <= b[2])
		return false;
	if (abs(a[0] - b[0]) <= b[2] && abs(a[1] - b[1]) <= a[2])
		return false;
	return true;
}

int twoPluses(vector<string> grid)
{
	vector<vector<int>> Pluses = validPlus(grid);
	int max = 0;
	for (int i = 0; i < Pluses.size() - 1; i++)
	{
		for (int j = i+1; j < Pluses.size(); j++)
		{
			if (checkOverlap(Pluses[i], Pluses[j]))
			{
				int c = (Pluses[i][2] * 2 + 1) * (Pluses[j][2] * 2 + 1);
				if (max < c)
				{
					cout << "Find max:" << endl;
					cout << "Pluses1: " << Pluses[i][0] << " " << Pluses[i][1] + Pluses[i][2] / 2 << " " << Pluses[i][2] / 2 << endl;
					cout << "Pluses2: " << Pluses[j][0] << " " << Pluses[j][1] + Pluses[j][2] / 2 << " " << Pluses[j][2] / 2 << endl;
					max = c;
				}
			}
		}
	}
	return max;
}
int main()
{
	ifstream ifs;
	ifs.open("Input.txt");
	vector<string> grid;
	if (ifs.is_open())
	{
		cout << "open file successful" << endl;
		while (!ifs.eof())
		{
			string line;
			ifs >> line;
			grid.push_back(line);
		}
		for (string i : grid)
		{
			cout << i << endl;
		}
	}
	ifs.close();
	cout << "The result is: "<<twoPluses(grid);
	return 0;
}