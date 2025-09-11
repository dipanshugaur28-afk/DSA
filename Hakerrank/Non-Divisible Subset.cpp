#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> freq(k, 0);
    for (int x : a) freq[x % k]++;

    int res = min(1, freq[0]); 
    for (int i = 1; i <= k/2; i++) {
        if (i == k - i) res += 1; 
        else res += max(freq[i], freq[k-i]);
    }
    cout << res << "\n";
    return 0;
}
