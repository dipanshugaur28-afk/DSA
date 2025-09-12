

#include <bits/stdc++.h>
using namespace std;

string highestValuePalindrome(string s, int n, int k) {
    vector<bool> changed(n, false);
    int need = 0;
     for (int i = 0; i < n/2; ++i) {
        if (s[i] != s[n-1-i]) {
            ++need;
            char mx = max(s[i], s[n-1-i]);
            s[i] = s[n-1-i] = mx;
            changed[i] = changed[n-1-i] = true;
        }
    }
    if (need > k) return "-1";
    int rem = k - need;
    for (int i = 0; i < n/2 && rem > 0; ++i) {
        if (s[i] == '9') continue;
        if (changed[i] || changed[n-1-i]) {
              s[i] = s[n-1-i] = '9';
            --rem;
        } else if (rem >= 2) {
            s[i] = s[n-1-i] = '9';
            rem -= 2;
        }
    }
    if (n % 2 == 1 && rem > 0) {
        s[n/2] = '9';
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    string s;
    if (!(cin >> n >> k)) return 0;
    cin >> s;
    cout << highestValuePalindrome(s, n, k) << "\n";
    return 0;
}
