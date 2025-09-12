#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<ll> price(n);
    for (int i = 0; i < n; ++i) cin >> price[i];

    vector<pair<ll,int>> arr; arr.reserve(n);
    for (int i = 0; i < n; ++i) arr.push_back({price[i], i});
    sort(arr.begin(), arr.end(), [](const pair<ll,int>& a, const pair<ll,int>& b) {
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });

    ll ans = LLONG_MAX;
    for (int i = 0; i + 1 < n; ++i) {
          if (arr[i].second < arr[i+1].second) {
            ll loss = arr[i].first - arr[i+1].first;
            if (loss > 0 && loss < ans) ans = loss;
        }
    }
    cout << ans << "\n";
    return 0;
}
