#include<bits/stdc++.h>
using namespace std;
vector<int> vec,prime;
int t,a,b;
void gen();
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    gen();
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        int k1=lower_bound(prime.begin(),prime.end(),a)-prime.begin();
        int k2=upper_bound(prime.begin(),prime.end(),b)-prime.begin();
        cout << k2-k1 << "\n";
    }
}

void gen()
{
    int cnt = 0;
    vec.emplace_back(2);
    for(int i1=3; i1<=9; i1+=2)
        vec.emplace_back(i1);
    for(int i1=1; i1<=9; i1+=2)
    {
        int tmp = i1*1e1 + i1;
        vec.emplace_back(tmp);
    }

    for(int i1=1; i1<=9; i1+=2)
    {
        for(int i2=0; i2<=9; i2++)
        {
            int tmp = i1*1e2 + i2*1e1 + i1;
            vec.emplace_back(tmp);
        }
    }
    for(int i1=1; i1<=9; i1+=2)
    {
        for(int i2=0; i2<=9; i2++)
        {
            int tmp = i1*1e3 + i2*1e2 + i2*1e1 + i1;
            vec.emplace_back(tmp);


        }
    }
    for(int i1=1; i1<=9; i1+=2)
    {
        for(int i2=0; i2<=9; i2++)
        {
            for(int i3=0; i3<=9; i3++)
            {

                int tmp = i1*1e4 + i2*1e3 + i3*1e2 + i2*1e1 + i1;
                vec.emplace_back(tmp);
            }
        }
    }
    for(int i1=1; i1<=9; i1+=2)
    {
        for(int i2=0; i2<=9; i2++)
        {
            for(int i3=0; i3<=9; i3++)
            {

                int tmp = i1*1e5 + i2*1e4 + i3*1e3 + i3*1e2 + i2*1e1 + i1;
                vec.emplace_back(tmp);


            }
        }
    }
    for(int i1=1; i1<=9; i1+=2)
    {
        for(int i2=0; i2<=9; i2++)
        {
            for(int i3=0; i3<=9; i3++)
            {
                for(int i4=0; i4<=9; i4++)
                {

                    int tmp = i1*1e6 + i2*1e5 + i3*1e4 + i4*1e3 + i3*1e2 + i2*1e1 + i1;
                    vec.emplace_back(tmp);

                }
            }
        }
    }
    for(int i1=1; i1<=9; i1+=2)
    {
        for(int i2=0; i2<=9; i2++)
        {
            for(int i3=0; i3<=9; i3++)
            {
                for(int i4=0; i4<=9; i4++)
                {

                    int tmp = i1*1e7 + i2*1e6 + i3*1e5 + i4*1e4 + i4*1e3 + i3*1e2 + i2*1e1 + i1;
                    vec.emplace_back(tmp);

                }
            }
        }
    }
    for(int i1=1; i1<=9; i1+=2)
    {
        for(int i2=0; i2<=9; i2++)
        {
            for(int i3=0; i3<=9; i3++)
            {
                for(int i4=0; i4<=9; i4++)
                {
                    for(int i5=0; i5<=9; i5++)
                    {
                        int tmp = i1*1e8 + i2*1e7 + i3*1e6 + i4*1e5 +i5*1e4 + i4*1e3 + i3*1e2 + i2*1e1 + i1;
                        vec.emplace_back(tmp);
                    }
                }
            }
        }
    }
    /*for(int i2=0; i2<=9; i2++){
        for(int i3=0; i3<=9; i3++){
            for(int i4=0; i4<=9; i4++){
                for(int i5=0; i5<=9; i5++){
                    int tmp = 1*1e9 + i2*1e8 + i3*1e7 + i4*1e6 +i5*1e5 + i5*1e4 + i4*1e3 + i3*1e2 + i2*1e1 + 1;
                    vec.emplace_back(tmp);
                }
            }
        }
    }*/
    //cout << vec.size() << " " << (double)sqrt(2e9) << "\n";
    for(int v : vec)
    {
        bool cd = false;
        for(int i=3, n=sqrt(v); i<=n; i+=2)
        {
            cnt++;
            if(v%i == 0)
            {
                cd = true;
                break;
            }
        }
        if(!cd)
        {
            prime.emplace_back(v);
            //cout << v << "\n";
        }
    }
    //cout << prime.size() << " " << cnt << "\n";
}
