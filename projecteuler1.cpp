#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long solution (long long n) {
	long long n3 = n/3, n5 = n/5, n15 = n/15;
	return 3*(n3*(n3+1)/2) + 5*(n5*(n5+1)/2) - 15*(n15*(n15+1)/2);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
    	long long n;
    	cin >> n;
    	cout << solution(n-1) << endl;
    }   
    return 0;
}
