#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define ll long long
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
 
        map<int, vector<ll>> mp;
        for (int i = 0; i < n; i++) {
            mp[a[i]].push_back(b[i]);
        }
 
        for (auto& [key, vec] : mp) {
            sort(vec.begin(), vec.end(), greater<ll>());
        }
 
        vector<ll> val(n + 2, 0);
        for(auto &[key,vec]:mp){
            int s=vec.size();
            vector<ll>pre(s+1,0);
            for(int i=0;i<s;i++){
                pre[i+1]=pre[i]+vec[i];
            }
            for(int k=1;k<=s;k++){
                int bl=(s/k)*k;
                val[k]+=pre[bl];
            }
        }
 
        for (int i = 1; i <= n; i++) {
            cout << val[i] << " ";
        }
        cout << endl;
    }
}
