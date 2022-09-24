#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool isPrime(ll n)

{

    if(n==1)

    return true;

    for(ll i=2;i*i<=(n);i++)

        if(n%i==0)

        return false;

    

    return true;

}

int main() {

    ll test;

    cin>>test;

    while(test--)

    {

        ll n;

        cin>>n;

        if(isPrime(n))

        cout<<"No\n";

        else

        cout<<"Yes\n";

    }

    return 0;

}


 