#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
vector<int> ranking;

int binarySearch(int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = (l + r) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (ranking[mid] == x) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (ranking[mid] > x) 
            return binarySearch(l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(mid + 1, r, x); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return r*(-1);
} 

// Complete the climbingLeaderboard function below.
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    int nscores = scores.size(), i=0;
    while (i<nscores) {
        ranking.push_back(scores[i]);
        while (i<nscores-1 && scores[i+1]==ranking.back()) i++;
        if (scores[i]==ranking.back()) {
            i++;
        }
    }

    int nalice = alice.size();
    vector<int> result;
    for (i=0; i<nalice; i++) {
        int rank = binarySearch(0, ranking.size(), alice[i]);
        if (rank>=0) {
            result.push_back(rank+1);
        } else {
            result.push_back(rank*(-1)+1);
            ranking.emplace(ranking.begin()+rank, alice[i]);
        }
    }

    return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int scores_count;
    cin >> scores_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    int alice_count;
    cin >> alice_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string alice_temp_temp;
    getline(cin, alice_temp_temp);

    vector<string> alice_temp = split_string(alice_temp_temp);

    vector<int> alice(alice_count);

    for (int i = 0; i < alice_count; i++) {
        int alice_item = stoi(alice_temp[i]);

        alice[i] = alice_item;
    }

    vector<int> result = climbingLeaderboard(scores, alice);

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

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
