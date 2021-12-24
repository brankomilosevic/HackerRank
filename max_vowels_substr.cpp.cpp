#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

bool isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// find first substring which has most vovels and it is not longer than k (or return "Not Foun !")
//
// sliding window, updating max number of vowels 
string findSubstring(string s, int k) 
{
    int maxCount = 0;
    int count = 0;
    int index = -1;
    
    for (int i=0; i<k; i++)
    {
        if (isVowel(s[i]))
            count++;
    }
    maxCount = count;
    
    if (maxCount > 0) 
        index = 0;
    
    for (int i=k; i < s.size(); ++i)
    {
        
        if (maxCount == k) break;

        if (isVowel(s[i]) && !isVowel(s[i-k]))
            count++;
        if (!isVowel(s[i]) && isVowel(s[i-k]))
            count--;
        
        if (count > maxCount)
        {
            maxCount = count;
            index = i-k+1;
        }
        
    }

    if (maxCount > 0)
        return s.substr(index, k);

    return "Not Found!";

}

int main(void)
{
   
    string str;
    str = "caberqiitefg"; // answer is "erqii"
    str = "aoiaoiuouueeioai"; // answer is "aoiao"
    int k = 5;
    cout << findSubstring(str, k);   

   return 0;
}
/*
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string dictionary_count_temp;
    getline(cin, dictionary_count_temp);

    int dictionary_count = stoi(ltrim(rtrim(dictionary_count_temp)));

    vector<string> dictionary(dictionary_count);

    for (int i = 0; i < dictionary_count; i++) {
        string dictionary_item;
        getline(cin, dictionary_item);

        dictionary[i] = dictionary_item;
    }

    string query_count_temp;
    getline(cin, query_count_temp);

    int query_count = stoi(ltrim(rtrim(query_count_temp)));

    vector<string> query(query_count);

    for (int i = 0; i < query_count; i++) {
        string query_item;
        getline(cin, query_item);

        query[i] = query_item;
    }

    vector<int> result = stringAnagram(dictionary, query);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

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
*/