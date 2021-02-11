#include<iostream>
#include<string.h>
#include<string>
#include<vector>
using namespace std;
int tem = 0;//HOld the position+1 of Substring
bool check;
bool checkSubString(string a, string b){
	check = true;
	for (int i = tem; i < a.size() - b.size() + 1; i++)
	{
		check = true;
		for (int j = 0; j < b.size(); j++)
		{
			if (a[i + j] != b[j]) check = false;
		}
		if (check) {
			tem = i + 1;
			return true;
		}
	}
	return false;
}
string gridSearch(vector<string> G, vector<string> P)
{
	int C = G[0].size();//G columns
	int c = P[0].size();//P columns
	for(int i = 0; i < G.size() - P.size()+1; i++)
		{
		vector<int> pos;
		tem = 0;
		while (checkSubString(G[i], P[0]))
			pos.push_back(tem - 1);//Pos is the array contains postions of Substring
		if (pos.size() > 0)
		{
			for (auto j : pos)
			{
				bool b = true;
				for (int k = 1; k < P.size(); k++)
				{
					tem = 0;
					if (!checkSubString(G[i + k].substr(j, j+P[0].size() - 1), P[k]))
						b = false;
				}
				if (b) return "YES";
			}
		}
	}
	return "NO";
}
int main()
{
	vector<string> G, P;
	int R, r;
	cout << "Enter R: "; cin >> R;
	cout << "Enter r: "; cin >> r;
	G.resize(R);
	P.resize(r);
	cout << "Enter G" << endl;
	for (int i = 0; i < R; i++)
		cin >> G[i];
	cout << "Oke, now enter P" << endl;
	for (int i = 0; i < r; i++)
		cin >> P[i];
	cout << gridSearch(G, P);
	
}