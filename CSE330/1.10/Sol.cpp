#include <bits/stdc++.h>
using namespace std;
#define ll long long 
long long mod=1000000009;
 
set<int> largeSet;
 
void getDivs() {
    int prime[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    int i, j, a, b, ab = 9, ad;
    int dv[1 << 9];
    ad = 1 << ab;
    for (i = 1; i < ad; i++) {
        dv[i] = 1;
        for (j = 0; j < ab; j++) {
            if (i & (1 << j))
                dv[i] *= prime[j];
        }
    }
    for(int i=1;i<ad;i++) {
        largeSet.insert(dv[i]);
    }       
}
 
int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    getDivs();
    while(t--) {
        ll a, temp, mg=INT_MIN;
        cin>>a;
        vector<int> v;
        for(int i=0;i<a;i++) {
            cin>>temp;
            v.push_back(temp);
            
            cout<<endl;
        }
        ll ans = 0, count = 0;
        for(auto it: largeSet) {
            int kk = it;
          
            ll gg = 0;
            for(int i=0;i<v.size();i++) {
                if(v[i]%kk==0) {
                    gg++;
                }
            }
            if(gg>ans) {
                ans=gg;
                count=1;
            } else if (ans==gg) {
                count++;
            }
        }
        
 
        cout<<ans<<" "<<count<<endl;
 
    }
    return 0;
}