#include<iostream>
#include<string>
#include<algorithm>//for sort algorithm(excellent!)
using namespace std;

string biggerIsGreater(string w)
{
	bool find = false;
	for(int i = w.size() - 1; i >= 0; i--)
    {
        for(int j = i - 1; j >= 0; j--)
        {
            if(w[i]>w[j])
            {
                swap(w[i], w[j]);
                sort(w.begin() + j + 1, w.end());
                return w;
            }
        }
    }
    return "no answer";
}
int main()
{
	char c = 'a';
	string h;
	while (c != 'x')
	{
		cin >> h;
		cout << biggerIsGreater(h) << endl;
		cout << "enter c: ";
		cin >> c;
	}
}