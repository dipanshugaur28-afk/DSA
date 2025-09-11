#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    if (n == 0) {
        cout << 1 << "\n";
        return 0;
    }
    int zeroBits = 0;
    long long temp = n;
    while (temp) {
        if ((temp & 1LL) == 0) zeroBits++;
        temp >>= 1LL;
    }
    cout << (1LL << zeroBits) << "\n";
    return 0;
}
