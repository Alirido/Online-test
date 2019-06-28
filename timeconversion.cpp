#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    
        if (s[8] == 'A') {
            if (s.substr(0,2) == "12")
                return "00" + s.substr(2,6);
            else
                return s.substr(0, 8);
        } else {
            if (s.substr(0,2) == "12")
                return s.substr(0,8);
            else {
                string temp = s.substr(0,2);
                int n = stoi(temp) + 12;
                return to_string(n) + s.substr(2,6);
            }
        }
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
