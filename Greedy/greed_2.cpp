#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCookies(vector<int>& scores) {
    int n = scores.size();
    if (n <= 1) return n;

    vector<int> cookies(n, 1);
    for (int i = 1; i < n; ++i) {
        if (scores[i] > scores[i - 1]) {
            cookies[i] = cookies[i - 1] + 1;
        }
    }

    for (int i = n - 2; i >= 0; --i) {
        if (scores[i] > scores[i + 1]) {
            cookies[i] = max(cookies[i], cookies[i + 1] + 1);
        }
    }

    int total = 0;
    for(size_t i=0;i < cookies.size();i++){
        total += cookies[i];
    }
    return total-1;
}

int main()
{
    int a;
    vector<int> scores;
    while(1){
        cin >> a;
        if(a == -1){break;}
        scores.push_back(a);
    }
    cout << minCookies(scores) << endl;
}

// 3 3 2 1 1