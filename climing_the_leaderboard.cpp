/*
HACKERRANK: Climing the Leaderboard
https://www.hackerrank.com/challenges/climbing-the-leaderboard
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'climbingLeaderboard' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY ranked
 *  2. INTEGER_ARRAY player
 */

// tried with vector - too slow
// tried with list - too slow
// it seems finding the posiiton by iterrating the whole vector/list is not good

int FindPosition(list<int> &ranks, int play_result){
    int player_rank = 1;
    list<int>::iterator it, second;
    for (it = ranks.begin(), second = ranks.begin(); it != ranks.end(); ++it)
    {
        if ( it != ranks.begin() && *it == *second )
            continue;
        if (play_result < *it )
        {
            player_rank++;
            second = it;
        }
        if (play_result > *it)
            break;
    }

    ranks.insert(it, 1, play_result);
    return player_rank;
}

vector<int> climbingLeaderboard_slow(vector<int> ranked, vector<int> player) {
// takes 200 sec for 200,000 initial ranked and 30,000 player results
    vector<int> scores;
    list<int> ranks(ranked.begin(), ranked.end());
    for (auto play_result : player){
        int player_rank = FindPosition(ranks, play_result);
        scores.push_back(player_rank);
    }
    return scores;
}

// I wil  try somethign using sets
// it runs for 50sec (200,000 initial and 30,000 player ranks), still not good
vector<int> climbingLeaderboard_still_slow(vector<int> &ranked, vector<int> player) {
    set<int> ranking;
    set<int>::iterator it;
    vector<int>::reverse_iterator pos;

    vector<int> player_ranking (player.size());
    int position;

    it = ranking.begin();
    for (pos = ranked.rbegin(); pos != ranked.rend(); pos++)
        it = ranking.insert(it, *pos);

    it = ranking.begin();
    int i=0;
    for (auto p : player)
    {
        it = ranking.insert(it, p);
        position = distance(it, ranking.end());
        // player_ranking.push_back(position);
        player_ranking[i] = position;
        ++i;
    }
    
    return player_ranking;
}

// this one is fast enough, all test passed
vector<int> climbingLeaderboard(vector<int> &ranked, vector<int> player) {
    vector<int> player_rank;
    vector<int>::reverse_iterator ri;
    vector<int> dist;
    int pos = 0, len;

    dist.push_back(ranked.back());
    for(ri = ranked.rbegin(); ri != ranked.rend(); ++ri)
    {
        if (dist.back() != *ri)
            dist.push_back(*ri);
    }
    len = dist.size();
    for (auto p : player)
    {
        while (p >= dist[pos] && pos < len)
            ++pos;
        player_rank.push_back(len - pos + 1);
    }

    return player_rank;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string ranked_count_temp;
    getline(cin, ranked_count_temp);

    int ranked_count = stoi(ltrim(rtrim(ranked_count_temp)));

    string ranked_temp_temp;
    getline(cin, ranked_temp_temp);

    vector<string> ranked_temp = split(rtrim(ranked_temp_temp));

    vector<int> ranked(ranked_count);

    for (int i = 0; i < ranked_count; i++) {
        int ranked_item = stoi(ranked_temp[i]);

        ranked[i] = ranked_item;
    }

    string player_count_temp;
    getline(cin, player_count_temp);

    int player_count = stoi(ltrim(rtrim(player_count_temp)));

    string player_temp_temp;
    getline(cin, player_temp_temp);

    vector<string> player_temp = split(rtrim(player_temp_temp));

    vector<int> player(player_count);

    for (int i = 0; i < player_count; i++) {
        int player_item = stoi(player_temp[i]);

        player[i] = player_item;
    }

//
    time_t start, end;
    time(&start);
    vector<int> result = climbingLeaderboard(ranked, player);
    // vector<int> result = climbingLeaderboard_still_slow(ranked, player);
    // vector<int> result = climbingLeaderboard_slow(ranked, player);
    time(&end);
    cout << "Time taken by function is : " << fixed
         << double(end - start) << setprecision(5)
         << " sec " << endl;
//

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }

//        cout << ">>> " << result[i] << '\n';
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
