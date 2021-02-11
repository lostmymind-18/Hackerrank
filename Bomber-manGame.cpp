#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
void resetPosBom(vector<vector<int>>& posBom, vector<string> grid)
{
    posBom.resize(0);
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 'O')
                posBom.push_back({ i,j });
        }
    }
}

void detroy(vector<string>& grid, vector<vector<int>>& posBom)
{
    resetPosBom(posBom, grid);
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
                grid[i][j] = 'O';
        }
        for (int i = 0; i < posBom.size(); i++)
        {
            //check Bomb's raw
            grid[posBom[i][0]][posBom[i][1]] = '.';
            if (posBom[i][0] != 0)
                grid[posBom[i][0] - 1][posBom[i][1]] = '.';
            if (posBom[i][0] != grid.size() - 1)
                grid[posBom[i][0] + 1][posBom[i][1]] = '.';
            //check Bomb's column
            if (posBom[i][1] != 0)
                grid[posBom[i][0]][posBom[i][1] - 1] = '.';
            if (posBom[i][1] != grid[0].size() - 1)
                grid[posBom[i][0]][posBom[i][1] + 1] = '.';
        }

}
vector<string> bomberMan(int n, vector<string> grid) {

    vector<vector<int>> posBom;//posBom is 2D array contains positions of Boms plant 3s ago.
    resetPosBom(posBom, grid);
    if (n == 0 || n == 1) return grid;
    if (n % 2 == 0)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
                grid[i][j] = 'O';
        }
        return grid;
    }
    if (n % 4 == 3)
    {
       
        detroy(grid, posBom);
        return grid;
    }
    if (n % 4 == 1)
    {
        for (int i = 0; i < 2; i++)
        {
            detroy(grid, posBom);
        }
        return grid;
    }
}
int main()
{
    ifstream ifs("Input.txt");
    vector<string> grid;
    if (ifs.is_open())
    {
        while (!ifs.eof())
        {
            string line;
            ifs >> line;
            grid.push_back(line);
        }
    }
    ifs.close();
    for (string i : grid) cout << i << '\n';
    char c = 'y';
    while (c != 'n')
    {
        vector<string> a = grid;
        cout << "Enter time: ";
        int n; cin >> n;
        cout << "The grid after " << n << "s: " << '\n';
        grid = bomberMan(n, a);
        for (string i : grid) cout << i << '\n';
        cin >> c;
    }
}