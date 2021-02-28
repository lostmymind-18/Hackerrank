#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<chrono>
using namespace std;
long long unsigned int shift = 0;
void mergeSort(int* start, int* end)
{
    if (end - start <= 1) return;
    int mid = (end - start) / 2;
    mergeSort(start, start + mid);
    mergeSort(start + mid, end);
    int* a = new int[mid];
    int* b = new int[end - start - mid];
    for (int i = 0; i < mid; i++)
        a[i] = *(start + i);
    for (int i = 0; i < end - start - mid; i++)
        b[i] = *(start + mid + i);
    int i = 0, j = 0;
    for (int n = 0; n < end - start; n++)
    {
        if (j == end - start - mid || (i < mid && a[i] <= b[j]))
        {
            start[n] = a[i];
            i++;
        }
        else if (i == mid || (j < end - start - mid && a[i] > b[j]))
        {
            start[n] = b[j];
            shift += (long long)mid + (long long)j - (long long)n;
            j++;
        }
    }
    delete[]a; delete[]b;
}
long long unsigned int insertionSort(vector<int> arr) {
    mergeSort(&arr[0], &arr[arr.size() - 1] + 1);
    return shift;
}
int main()
{
    ifstream file("testcase.txt");
    //Number of cases
    int n;  file >> n;
    vector<vector<int>> vector;
    vector.resize(n);
    for (int i = 0; i < n; i++)
    {
        int a; file >> a;
        vector[i].resize(a);
        for (int j = 0; j < a; j++)
            file >> vector[i][j];
    }
    auto start = chrono::steady_clock::now();
    for (int i = 0; i < n; i++)
    {
        shift = 0;
        cout << insertionSort(vector[i]) << endl;
    }
    auto end = chrono::steady_clock::now();
    cout << "Elapsed time in nanoseconds : "
        << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
        << " ns" << endl;
}