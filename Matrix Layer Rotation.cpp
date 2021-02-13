#include<iostream>
#include<string.h>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
void matrixRotation(vector<vector<int> > &matrix, int r) {
    int hei = matrix.size();
    int wei = matrix[0].size();
    int n = hei > wei? wei/2:hei/2;
    int i = 0, j = 0;
    while(n)
    {
        int numElement = 0;
        numElement+=(wei - 2*j + hei - 2*i - 2)*2;
        int m = r%numElement;
        while(m)
        {
            int hold = matrix[i][j];
            for(int a = j; a < wei - 1 - j; a++)
                matrix[i][a] = matrix[i][a+1];
            for(int a = i; a < hei - 1 - i; a++)
                matrix[a][wei - 1 - j] = matrix[a+1][wei - 1 - j];
            for(int a = wei - j - 1; a > j; a--)
                matrix[hei - 1 - i][a] = matrix[hei - 1 - i][a - 1];
            for(int a = hei - i - 1; a > i+1; a--)
                matrix[a][j] = matrix[a - 1][j];
            matrix[i+1][j] = hold;
            m--;   
        }
        n--; i++; j++;
    }
}

int main()
{
    ifstream file("testCase.txt");
    int hei = 0, wei = 0, r = 0;
    file >> hei >> wei >> r;
    vector<vector<int> > matrix;
    matrix.resize(hei);
    for(int i = 0; i <(int) matrix.size(); i++)
        matrix[i].resize(wei);
    for(int i = 0; i < (int)matrix.size(); i++)
    {
        for(int j = 0; j <(int) matrix[i].size(); j++)
            file>>matrix[i][j];
    }
    cout<<"before: "<<r<<endl;
    for(int i = 0; i < (int)matrix.size(); i++)
    {
        for(int j = 0; j < (int)matrix[0].size(); j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    matrixRotation(matrix, r);
    cout<<"after: "<<endl;
    for(int i = 0; i < (int)matrix.size(); i++)
    {
        for(int j = 0; j < (int)matrix[0].size(); j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}