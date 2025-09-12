
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    int k;
    if (!(cin >> n >> m >> k)) return 0;
    unordered_map<ll, vector<pair<ll,ll>>> rows;
    rows.reserve(k * 2);
    for (int i = 0; i < k; ++i) {
        ll r, c1, c2;
        cin >> r >> c1 >> c2;
        rows[r].push_back({c1, c2});
    }
    long long occupied = 0;
    for (auto &entry : rows) {
        auto &vec = entry.second;
        sort(vec.begin(), vec.end()); 
        ll curL = -1, curR = -1;
        for (auto &pr : vec) {
            ll L = pr.first, R = pr.second;
            if (curL == -1) {
                curL = L; curR = R;
            } else {
                if (L <= curR + 1) { 
                    curR = max(curR, R);
                } else {
                    occupied += (curR - curL + 1);
                    curL = L; curR = R;
                }
            }
        }
        if (curL != -1) occupied += (curR - curL + 1);
    }
    long long total = n * m;
    cout << (total - occupied) << "\n";
    return 0;
}
