/*
HACKERRANK: Day of Programmer
https://www.hackerrank.com/challenges/day-of-the-programmer
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */

string dayOfProgrammer(int year) {
    char dop[11];
    int day = 0;
    int month = 9;
    if (year <= 1917)
    {
        if (year % 4)
            day = 13;

        else
            day = 12;

    }

    if (year == 1918)
        day = 26;

    if (year >= 1919)
    {
        if ( year % 400 == 0)
            day = 12;
        else
        {
            if ( year % 100 )
            {
                if ( year % 4 )
                    day = 13;
                else 
                    day = 12; 
            }
            else
                day = 13;
        }
    }

    sprintf(dop, "%02d.%02d.%04d", day, month, year);
    return string(dop);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

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