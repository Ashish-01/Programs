#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int shortlength(string a, string b , set<string > &s)
{
    if(s.find(b) == s.end())
    {
        return 0;
    }
    int level=0 , wordlength=a.size();
    queue<string> q;
    q.push(a);
    while(!q.empty())
    {
        ++level;
        int size=q.size();
        for(int i=0;i<size ;i++)
        {
            string word=q.front();
            q.pop();

            for(int j=0 ;j<wordlength ;j++)
            {
                char ch= word[j];
                for(char k='a' ;k<='z' ;k++)
                {
                    word[j]=k;
                    if(word==b)
                    {
                        return level+1;
                    }
                    if(s.find(word) == s.end())
                    {
                        continue;
                    }
                    s.erase(word);
                    q.push(word);       

                }
                word[j]=ch;
            }
        }
    }
    return 0;

}
int main()
{
    set<string> s;
    int t;
    string a,b,z;
    cin>>t;
    cin>>a>>b;
    while(t--)
    {
        cin>>z;
        s.insert(z);
        
    }
    
     int ans=shortlength(a,b,s);
     cout<<ans<<endl;
    
    
}
