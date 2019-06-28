#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> scores(n);
	for (auto& e : scores) cin >> e;

	int m;
	scanf("%d", &m);
	vector<int> alice(m);
	for (auto& e : alice) cin >> e;

	// for (auto it = alice.cbegin(); it != alice.cend(); it++) {
 //    	cout << *it << endl;
 //    }

	vector<int> ranking;
    int i=0;
    while (i<n) {
        ranking.push_back(scores[i]);
        int temp = scores[i];
        // cout << "score = " << scores[i] << endl;
        ++i;
        while (i<n-1 && scores[i]==temp) {
        	// cout << "score = " << scores[i] << endl;
        	i++;
        }
        if (scores[i]==temp) {
            i++;
        }
    }
    ranking.push_back(-1);

    // for (auto it = ranking.cbegin(); it != ranking.cend(); it++) {
    // 	cout << *it << endl;
    // }

    int checkpoint = ranking.size() - 1;
    // cout << "checkpoint / ranking size = " << ranking.size() << endl;
    vector<int> result;
    for (i=0; i<m; i++) {
        // cout << alice[i] << " < " << ranking[checkpoint] << endl;
        while (checkpoint>-1 && alice[i] > ranking[checkpoint]) {
        	// cout << "inside loop: " << alice[i] << " < " << ranking[checkpoint] << endl;
        	checkpoint--;
        }
        // cout << "checkpoint = " << checkpoint << endl;
        if (checkpoint == -1)
        	result.push_back(1);
        else {
        	if (alice[i]==ranking[checkpoint])
        		result.push_back(checkpoint+1);
        	else
        		result.push_back(checkpoint+2);
        }
    }

    // print the result
    int nresult = result.size();
    for (i=0; i<nresult; i++) {
    	cout << result[i] << endl;
    }

	return 0;
}