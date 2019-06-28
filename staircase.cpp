#include <bits/stdc++.h>

using namespace std;

// Complete the staircase function below.
void staircase(int n) {
	int n_hashtag = 1;
 	while(n--) {
 		for (int i=0; i<n; i++) {
 			printf(" ");
 		}
 		for (int i=0; i<n_hashtag; i++)
 			printf("#");
 		printf("\n");
 		n_hashtag++;
 	}   

}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}