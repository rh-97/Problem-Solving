#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

typedef pair<int, int> pii;

struct Comp {
    bool operator()(pii a, pii b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    } 
};

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        mp[x]++;
    }
    priority_queue<pii, vector<pii>, Comp> pq;
    for (pii p: mp) {
        pq.push({p.second, p.first});
    }
    vector<int> res;
    while (!pq.empty()) {
        for (int i = 0; i < pq.top().first; ++i) {
            res.push_back(pq.top().second);
        }
        pq.pop();
    }
    
    for (int& x: res) {
        cout << x << ' ';
    }
    cout << '\n';
}



int main() {
	int q = 1, Q = 1;
	cin >> Q;
	while (q <= Q) {
	    solve();
	    q++;
	}
	return 0;
}