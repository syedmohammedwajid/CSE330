#include <iostream>

#include <map>

#include <set>

using namespace std;

#define endl "\n"

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int N = 1e6+7;

int Isprime[N];

typedef pair <int,int> pairs;

void sieve()

{

    for(int i = 0;i <= N;i++)

    {

        Isprime[i] = i;

    }

    Isprime[0] = 0;

    Isprime[1] = 1;


 

    for(int i = 2;i * i <= N;i++)

    {

        if(Isprime[i] == i)

        for(int j = i * i;j <= N; j += i)

        {

            Isprime[j] = i;

        }

    }


 

}

map<int,int> factorize(int n)

{

    map<int,int> cnt;

    int x = n;

    while(x!=1){

        cnt[Isprime[x]]++;

        x/=Isprime[x];

    }

    cnt[1]++;

    cnt[n]++;

    return cnt;


 

}

int main()

{

    sieve();

    int t;

    cin >> t;

    while(t--)

    {

        int n, xx[N], k = 0, sum = 0;

        cin >> n;


 

        map<int,int> cnt = factorize(n);

       

        for(auto i : cnt)

        {

            xx[k++] = i.first;

        }


 

        set<pairs>mp;

       

        for(int i = 0;i < k;i++)

        {

            if(i+1 == k )

            {

               pairs sx = make_pair(xx[i],xx[0]);

               mp.insert(sx);

               break;

            }

            else

            {

                pairs sx = make_pair(xx[i+1],xx[i]);

                mp.insert(sx);

            }

           

        }


 

        for(auto i : mp)

        {

           

            sum += i.first * i.second ;

        }

        cout << sum << endl;

       

    }

}