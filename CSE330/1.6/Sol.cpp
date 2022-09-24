#include<bits/stdc++.h>

using namespace std;

int main()

{

    long long int max=100000;

    long long int i,j,a[max+1];

    for(i=0;i<=max;i++)

    a[i]=1;

    a[0]=a[1]=0;

    for(i=2;i*i<=max;i++)

    {

        if(a[i]==1)

        {

            for(j=i*i;j<=max;j+=i)

            a[j]=0;

        }

    }

    long long int t;

    string s;

    cin>>t;

    while(t--)

    {

        cin>>s;

        long long int d,c=0,f=0;

        sort(s.begin(),s.end());

        for(i=0;i<s.length()-1;i++)

        {

            c=c+1;

            while(s[i+1]==s[i])

                i++;

        }

        for(i=0;i<s.length();i++)

        {

            d=1;

            while(s[i+1]==s[i])

            {

                d++; i++;

            }

            if(a[d]==0)

            {

                f=1; break;

            }

        }

        if(a[c]==0)

        f=1;

        if(f==0)

        cout<<"YES"<<"\n";

        else

        cout<<"NO"<<"\n";

    }

    return 0;

}