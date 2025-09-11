#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; getline(cin,s);
    if(s.empty()) getline(cin,s);
    string t; for(char c: s) if(c!=' ') t.push_back(c);

    int L=t.size();
    int r=floor(sqrt(L)), c=ceil(sqrt(L));
    if(r*c<L) r++;
    vector<string> cols(c);
    for(int i=0;i<L;i++) cols[i%c].push_back(t[i]);

    for(int i=0;i<c;i++){
        if(i) cout<<' ';
        cout<<cols[i];
    }
    cout<<"\n";
    return 0;
}
