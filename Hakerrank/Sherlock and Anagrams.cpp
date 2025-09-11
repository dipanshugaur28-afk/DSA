#include <bits/stdc++.h>
using namespace std;

int sherlockAndAnagrams(string s) {
    unordered_map<string, int> freq;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        string sub = "";
        for (int j = i; j < n; j++) {
            sub.push_back(s[j]);
            string key = sub;
            sort(key.begin(), key.end()); // normalize
            freq[key]++;
        }
    }

    int ans = 0;
     for (auto &p : freq) {
        int f = p.second;
        ans += f * (f - 1) / 2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;             
    while (q--) {
        string s;
        cin >> s;
        cout << sherlockAndAnagrams(s) << "\n";
    }
    return 0;
}
