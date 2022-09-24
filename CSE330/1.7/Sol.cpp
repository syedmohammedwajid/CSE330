#include <iostream>

using namespace std;

#define ll long long int

#define endl "\n"

const ll N = 1e7+7;;

ll Isprime[N];

void sieve()

{

    for(int i = 0;i <= N;i++)

    {

        Isprime[i] = 0;

    }

   

 

    for(int i = 2;i <= N;i++)

    {

        if(Isprime[i] == 0)

        {

            for(int j = i ;j <= N;j+=i)

            {

                if(Isprime[j] == 0)

                Isprime[j] = i;

            }

 

        }

       

 

    }

}


 

int main()

{

   

    ios_base::sync_with_stdio(false);


 

    cin.tie(NULL); cout.tie(NULL);

   

    sieve();

   

    ll n,t;

    cin >> t;

    while(t--)

    {

       

        cin >> n;

        cout << n - Isprime[n] << endl;

     

 

    }

}


 