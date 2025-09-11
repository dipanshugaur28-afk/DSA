#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());

    int cnt=0;
    for(int i=0;i<n;i++){
        int start=a[i]; cnt++;
        int j=i+1;
        while(j<n && a[j]<=start+4) j++;
        i=j-1;
    }
    cout<<cnt<<"\n";
    return 0;
}
