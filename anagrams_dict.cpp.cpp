#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

// are strings anagrams ? 
// character counting method
// not needed in map-based solution
bool areAnagram(string str1, string str2)
{
    int count[250] = { 0 };
    int i;

    for (i = 0; str1[i] && str2[i]; i++) 
    {
        count[str1[i]]++;
        count[str2[i]]--;
    }
 
    if (str1[i] || str2[i])
        return false;
 
    for (i = 0; i < 250; i++)
        if (count[i])
            return false;
    return true;
}

/*
// how many anagrams of string from query are in dictionary
// return vector of nuber of anagrams of each query item in dictionary
//
// naive !!! and time consuming
vector<int> stringAnagram(vector<string> dictionary, vector<string> query) {
    
    //cout << "Is anagram |cold| and |codl| : " << areAnagram("cold", "codl");
    vector<int> res;
    int i, j;
    for (i=0; i<query.size(); i++)
        res.push_back(-1);
    for (i=0; i<query.size(); i++)
    {
        for (j=0; j<dictionary.size(); j++)
        if (areAnagram(query[i], dictionary[j]))
        {
            res[i]++;
        }
    }
    return res;
}
*/

// how many anagrams of string from query are in dictionary
// return vector of nuber of anagrams of each query item in dictionary
//
// sort every string from query and dictioanry
// bild a map of dictionary items (each string is sorted so if anagram, it will show in map several times)
// build a vector by searching the map for a items of query list
vector<int> stringAnagram(vector<string> dictionary, vector<string> query) 
{
    vector<int> res;
    unordered_map<string, int> m;
    int i;

    for (i=0; i<query.size(); i++)
    {
        res.push_back(0);
        sort(query[i].begin(), query[i].end());
    }

    for (i=0; i<dictionary.size(); i++)
        sort(dictionary[i].begin(), dictionary[i].end());

    for (i=0; i<dictionary.size(); i++)
        m[dictionary[i]]++;

    for (i=0; i<query.size(); i++)
        res[i] = m[query[i]];

    return res;
}

int main(void)
{
    vector<string> dict = { "heater", "cold", "clod", "reheat", "docl"};
    vector<string> query = { "codl", "heater", "abc"};
    vector<int> res = stringAnagram(dict, query);
    for(int i=0; i<res.size(); i++)
        cout << "[ " << i << " ] : " << query[i] << " -> " << res[i] << endl; 

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