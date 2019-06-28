#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {
    int n = w.length();
    if (n==1)
        return "no answer";
    int i = n-1;
    while (i>1 && w[i]<=w[i-1]) i--;
    if (w[i]<=w[i-1])
        return "no answer";
    else {
        --i;
        int j=n-1;
        while(w[j]<=w[i]) j--;
        string temp = w.substr(0, i);
        temp += w[j];
        for (int k=n-1; k>i; k--) {
            if (k==j) {
                temp += w[i];
            } else {
                temp += w[k];
            }
        }
        return temp;
    }

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
