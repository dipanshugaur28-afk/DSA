#include <bits/stdc++.h>
using namespace std;

// Convert day 'd' written in base 'b' into decimal value
long long toDecimal(int base, int day) {
    long long val = 0;
    long long powBase = 1;
    while(day > 0) {
        int digit = day % 10;
        if(digit >= base) return -1; // invalid digit for this base
        val += digit * powBase;
        powBase *= base;
        day /= 10;
    }
    return val;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    vector<pair<int,int>> events(n);
    for(int i=0;i<n;i++) cin >> events[i].first >> events[i].second;

    unordered_map<long long, long long> freq;
    long long jokes = 0;

    for(auto &e: events){
        int month = e.first, day = e.second;
        long long val = toDecimal(month, day);
        if(val != -1){
            jokes += freq[val]; // count pairs with same value
            freq[val]++;
        }
    }

    cout << jokes << "\n";
    return 0;
}

