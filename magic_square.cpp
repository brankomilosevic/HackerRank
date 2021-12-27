/*
HACKERRANK: MagicSquare
https://www.hackerrank.com/challenges/magic-square-forming
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'formingMagicSquare' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY s as parameter.
 */

int sum_3(int a, int b, int c)
{
    return a + b + c;
}

int my_abs(int a)
{
    if (a < 0) 
        return -a;
    return a;
}

int formingMagicSquare_old(vector<vector<int>> s) {
    int TOTAL = 15;
    int cost = 0;

    int hor = 0;
    int ver = 0;
    int diag = 0;

    for (int i=0; i<3; ++i)
    {
        int sum = 0;
        for (int j=0; j<3; ++j)
            sum += s[i][j];
        hor += abs(TOTAL - sum);
    }

    for (int i=0; i<3; ++i)
    {
        int sum = 0;
        for (int j=0; j<3; ++j)
            sum += s[j][i];
        ver += abs(TOTAL - sum);
    }

    int sum = 0;
    for (int i=0; i<3; ++i)
        sum += s[i][i];
    diag += abs(TOTAL - sum);

    if (hor >= ver && hor >= diag)
        return hor;

    if (ver >= hor && ver >= diag)
        return ver;

    if (diag >= ver && diag >= hor)
        return diag;
    
    return -1;
}

void print_array(int a[])
{
    cout << "\n";
    for (int i=0; i<9; ++i)
        cout << a[i] << " ";
    
}
int formingMagicSquare_bruteforce(vector<vector<int>> s) {
    int cost = 1000;
    int min_cost = 1000;

    int arr[9];
    int perm[9];

    for (int i=0; i<3; ++i)
        for (int j=0; j<3; ++j)
            arr[i*3+j] = s[i][j];

    for (int i=0; i<9; ++i)
        perm[i] = i+1;

    do 
    {
        if ( perm[0] + perm[1] + perm[2] == 15 &&
             perm[3] + perm[4] + perm[5] == 15 &&
             perm[6] + perm[7] + perm[8] == 15 &&
             perm[0] + perm[3] + perm[6] == 15 &&
             perm[1] + perm[4] + perm[7] == 15 &&
             perm[2] + perm[5] + perm[8] == 15 &&
             perm[0] + perm[4] + perm[8] == 15 &&
             perm[2] + perm[4] + perm[6] == 15 
           )
        {
            cost = 0;
            for (int i=0; i<9; ++i)
                cost += my_abs(arr[i] - perm[i]);
            if (min_cost > cost)
            {
                min_cost = cost;
                print_array(arr);
                print_array(perm);
                cout << "\n";
            }
        }
    } 
    while (next_permutation(perm, perm + 9));
    return min_cost;
}

int formingMagicSquare(vector<vector<int>> s)
{
    int cost = 1000;
    int min_cost = 1000;

    int perm[8][9] = {
        {4,9,2,3,5,7,8,1,6},
        {4,3,8,9,5,1,2,7,6},
        {2,9,4,7,5,3,6,1,8},
        {2,7,6,9,5,1,4,3,8},
        {8,1,6,3,5,7,4,9,2},
        {8,3,4,1,5,9,6,7,2},
        {6,7,2,1,5,9,8,3,4},
        {6,1,8,7,5,3,2,9,4},
    };  // all of the magic squares

    int arr[9];
    for (int i=0; i<3; ++i)
        for (int j=0; j<3; ++j)
            arr[i*3+j] = s[i][j];

    for (int i=0; i<8; ++i)
    {
        cost = 0;
        for (int j=0; j<9; ++j)
            cost += my_abs(perm[i][j] - arr[j]);
        if (cost < min_cost)
            min_cost = cost;
    } 
    return min_cost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);

    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        string s_row_temp_temp;
        getline(cin, s_row_temp_temp);

        vector<string> s_row_temp = split(rtrim(s_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int s_row_item = stoi(s_row_temp[j]);

            s[i][j] = s_row_item;
        }
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();
    cout << "Solution: " << result;
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
