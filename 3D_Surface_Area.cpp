#include<iostream>
#include<vector>
#include<string.h>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
using namespace std;
int columnSerface(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 6;
    if (n == 2) return 10;
    if (n > 2) return 10 + (n - 2) * 4;
    return 0;
}
int surfaceArea(vector<vector<int>> A) {
    int result = 0;
    for (int i = 0; i < (int)A.size(); i++)
    {
        for (int j = 0; j < (int)A[i].size(); j++)
        {
            if (i == 0 && j == 0) result += columnSerface(A[i][j]);
            else if (i == 0) result += columnSerface(A[i][j]) - 2 * (A[i][j - 1] < A[i][j] ? A[i][j - 1] : A[i][j]);
            else if (j == 0) result += columnSerface(A[i][j]) - 2 * (A[i - 1][j] < A[i][j] ? A[i - 1][j] : A[i][j]);
            else {
                result += columnSerface(A[i][j]) - 2 * (A[i][j - 1] < A[i][j] ? A[i][j - 1] : A[i][j])
                    - 2 * (A[i - 1][j] < A[i][j] ? A[i - 1][j] : A[i][j]);
            }
        }
    }
    return result;
}
int main()
{
    ifstream file("testcase.txt");
    int hei, wei;
    file>>hei;  file>>wei;
    vector<vector<int>> A;
    A.resize(hei);
    for(int i = 0; i < hei; i++)
        A[i].resize(wei);
    for(int i = 0 ; i < hei; i++)
    {
        for(int j = 0; j < wei; j++)
            file>>A[i][j];
    }

    cout<<surfaceArea(A);
}