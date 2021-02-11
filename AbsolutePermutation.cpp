#include<iostream>
#include<vector>

using namespace std;

void swap(int& a, int& b)
{
	int hold = a;
	a = b;
	b = hold;
}

vector<int> permutation(int n, int k)
{
	vector<int> theReturn;
	theReturn.resize(n);
	bool* check = new bool[n];
	for (int i = 0; i < n; i++)
	{
		theReturn[i] = i + 1;
		check[i] = false;
	}
	for (int i = 0; i < n; i++)
	{
		if (check[i] == false && (i + k) < n)
		{
			swap(theReturn[i], theReturn[i + k]);
			check[i] = true;
			check[i + k] = true;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (check[i] == false)
		{
			vector<int> fail = { -1 };
			return fail;
		}
	}
	return theReturn;
}

int main()
{
	int n, k;
	cout << "Enter n: "; cin >> n;
	cout << "Enter k: "; cin >> k;
	vector<int> display = permutation(n, k);
	for (auto i : display)
		cout << i <<" ";
}