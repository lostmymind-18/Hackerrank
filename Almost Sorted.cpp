#include<iostream>
#include<vector>
#include<string.h>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
using namespace std;
bool swap(vector<int> arr, int i, int &a, int &b)
{
    //swapNear
    if (i == (int)arr.size() - 2)
    {
        a = i + 1;
        b = i + 2;
        return true;
    }
    if (i == 0 && arr[i] < arr[i + 2])
    {
        a = i + 1;
        b = i + 2;
        for (int j = i + 1; j < (int)arr.size() - 1; j++)
        {
            if (arr[j] > arr[j + 1]) return false;
        }
        return true;
    }
    if (arr[i] < arr[i + 2] && arr[i + 1] > arr[i - 1])
    {
        a = i + 1;
        b = i + 2;
        for (int j = i + 1; j < (int)arr.size() - 1; j++)
        {
            if (arr[j] > arr[j + 1]) return false;
        }
        return true;
    }
    //swapFar
    for (int j = i + 1; j < (int)arr.size() - 1; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            if (i == 0)
            {
                if (j + 1 == (int)arr.size() - 1)
                {
                    if (arr[j + 1] < arr[i + 1] && arr[i] > arr[j])
                    {
                        a = i + 1;
                        b = j + 2;
                        return true;
                    }
                }
                else
                {
                    if (arr[i] > arr[j] && arr[i] < arr[j + 2] && arr[j] < arr[i + 1])
                    {
                        for (int z = j + 1; z < (int)arr.size() - 1; z++)
                        {
                            if (arr[z] > arr[z + 1]) return false;
                        }
                        a = i + 1; b = j + 2;
                        return true;
                    }
                }
            }
            else {
                if (j + 1 == (int)arr.size() - 1)
                {
                    if (arr[i] > arr[j] && arr[j + 1] < arr[i + 1] && arr[j] > arr[i - 1])
                    {
                        a = i + 1; b = j + 2;
                        return true;
                    }
                }
                else {
                    if (arr[i] > arr[j] && arr[i] < arr[j + 2] && arr[j + 1] < arr[i + 1] && arr[j + 1] > arr[i - 1])
                    {
                        for (int z = j + 1; z < (int)arr.size() - 1; z++)
                        {
                            if (arr[z] > arr[z + 1]) return false;
                        }
                        a = i + 1; b = j + 2;
                        return true;
                    }
                }
            }
            return false;
        }
    }
    return false;
}
bool reverse(vector<int> arr, int i, int &a, int &b)
{
    int j = i + 1;
    while (j < (int)arr.size() && arr[j] < arr[j - 1]) j++;
    if (i == 0)
    {
        if (j == (int)arr.size())
        {
            a = i + 1; b = arr.size();
            return true;
        }
        else if(arr[i] < arr[j])
        {
            for (int z = j; z < (int)arr.size() - 1; z++)
            {
                if (arr[z] > arr[z + 1]) return false;
            }
            a = 1; b = j;
            return true;
        }
    }
    else
    {
        if (j == (int)arr.size() && arr[i - 1] < arr[j - 1])
        {
            a = i + 1; b = j;
            return true;
        }
        else if (j != (int)arr.size() && arr[i] < arr[j] && arr[j - 1] > arr[i - 1])
        {
            a = i + 1; b = j;
            return true;
        }
    }
    return false;
}
void almostSorted(vector<int> arr) {
   for (int i = 0; i < (int)arr.size() - 1; i++)
   {
       if (arr[i] > arr[i + 1])
       {
           int a = 0, b = 0;
           if (swap(arr, i, a, b))
           {
               cout << "yes" << endl <<"swap "<< a << " " << b;
               return;
           }
           else if (reverse(arr, i, a, b))
           {
               cout << "yes" << endl << "reverse " << a << " " << b;
               return;
           }
           cout << "no";
           return;
       }
   }
   cout << "yes";
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
    almostSorted(A);
    return 0;
}