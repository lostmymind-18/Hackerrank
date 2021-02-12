#include<iostream>
#include<vector>
#include<string.h>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
using namespace std;
string larrysArray(vector<int> A) {
    int n = 0;
    for (int i = 0; i < (int)A.size() - 1; i++)
    {
        for (int j = i+1; j < (int)A.size(); j++)
        {
            if (A[i] > A[j]) n++;
        }
    }
    if (n % 2) return "NO";
    return "YES";
}

int main()
{
    ifstream file("testcase.txt");
    vector<int> A;
    int n;
    file >> n;
    A.resize(n);
    for (int i = 0; i < n; i++)
        file >> A[i];
    cout << larrysArray(A);
    return 0;
}