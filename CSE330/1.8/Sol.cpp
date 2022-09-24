

#include<bits/stdc++.h>



using namespace std;



#define ll long long

#define scn(n) scanf("%d",&n)

#define lscn(n) scanf("%lld",&n)

#define lpri(n) printf("%lld",n)

#define pri(n) printf("%d",n)

#define pln() printf("\n")

#define priln(n) printf("%d\n",n)

#define lpriln(n) printf("%lld\n",n)

#define rep(i,init,n) for(int i=init;i<n;i++)

#define pb push_back

#define mp make_pair

#define F first

#define S second

#define gcd __gcd

#define inf INT_MAX

#define ninf INT_MIN

#define inf INT_MAX

#define linf LLONG_MAX

#define lninf LLONG_MIN

const int mod = 1e9 + 7;

const int N = 1e6 + 4;

ll a[N]={};

ll sum[N]={};


 

void sive()

{

a[0]=1,a[1]=1;


 

for(ll i=2;i*i<=N;i++)

{

if(a[i]==0)

{

for(ll j=i*i;j<=N;j+=i )

a[j]=1;

}

}

sum[0]=0;

 

for(int i=1;i<=N;i++)

{

if(a[i]==1&&i!=4)

sum[i]=sum[i-1]+1;

else

sum[i]=sum[i-1];

}

}

int main()

{

ios_base::sync_with_stdio(false);

cin.tie(NULL); cout.tie(NULL);

sive();


 

ll t; cin>>t;

while(t--)

{

ll l,r; cin>>l>>r;

 

 

cout<<sum[r]-sum[l-1]<<"\n";

}

 

}


