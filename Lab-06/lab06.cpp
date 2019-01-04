#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define pb push_back
#define mp make_pair
#define PI 3.14159265358979323
#define debug(x) cout<<"Case "<<x<<": "
#define For(i,n) for(long long i=0;i<n;i++)
#define Frabs(i,a,b) for(long long i = a; i < b; i++)
#define Frabr(i,a,b) for(long long i = a; i >=b; i--)
#define sync ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long int           ll;
typedef long double             ld;
typedef unsigned long long int ull;
typedef vector <int>            vi;
typedef vector <ll>            vll;
typedef pair <int, int>        pii;
typedef pair <ll, ll>          pll;
typedef vector < pii >        vpii;
typedef vector < pll >        vpll;
typedef vector <string>         vs;

//Handle:cyber_rajat


int main()
{
    sync;
    ll t;
    cin>>t;   //Taking input
    while(t--)
    {
        //+', '-', '' and '/' have left associativity and '^' has right associativity.
        stack<char> s;
        string s1;
        cin>>s1;
        string s2="";
        s1=s1+')';  //adding closing bracket at end
        s.push('(');//pushing opening bracket in stack
        ll i=0;
        while(i<s1.size())
        {
            if(s1[i]=='(') //if opening then push it
            {
                s.push('(');
            }
            else if(s1[i]=='+')//if +
            {
                if(s.size()!=0){
                char c=s.top();
                if(c=='-')
                {
                    while(c=='-' || c=='*' || c=='/' || c=='^' || c=='+'){//Checking precedence
                    s.pop();
                    s2=s2+c;
                    c=s.top();
                    }
                    s.push('+');
                }
                else if(c=='*')
                {
                    while(c=='-' || c=='*' || c=='/' || c=='^' || c=='+'){
                    s.pop();
                    s2=s2+c;
                    c=s.top();
                    }
                    s.push('+');
                }
                else if(c=='/')
                {
                    while(c=='-' || c=='*' || c=='/' || c=='^' || c=='+'){
                    s.pop();
                    s2=s2+c;
                    c=s.top();
                    }
                    s.push('+');
                }
                else if(c=='^')
                {
                    while(c=='-' || c=='*' || c=='/' || c=='^' || c=='+'){
                    s.pop();
                    s2=s2+c;
                    c=s.top();
                    }
                    s.push('+');
                }
                else if(c=='+')
                {
                    while(c=='-' || c=='*' || c=='/' || c=='^' || c=='+'){
                    s.pop();
                    s2=s2+c;
                    c=s.top();
                    }
                    s.push('+');
                }
                else
                {
                    s.push('+');
                }
            }
            else
            {
                s.push('+');    
            }
            }
            else if(s1[i]=='-')//if -
            {
                char c=s.top();
                if(s.size()!=0){
                if(c=='*')
                {
                    while(c=='*' || c=='/' || c=='^' || c=='-'){//checking precedence
                    s.pop();
                    s2=s2+c;
                    c=s.top();
                    }
                    s.push('-');

                }
                else if(c=='-')
                {
                    while(c=='*' || c=='/' || c=='^' || c=='-'){
                    s.pop();
                    s2=s2+c;
                    c=s.top();
                    }
                    s.push('-'); 
                }
                else if(c=='/')
                {
                    while(c=='*' || c=='/' || c=='^' || c=='-'){
                    s.pop();
                    s2=s2+c;
                    c=s.top();
                    }
                    s.push('-');

                }
                else if(c=='^')
                {
                    while(c=='*' || c=='/' || c=='^' || c=='-' ){
                    s.pop();
                    s2=s2+c;
                    c=s.top();
                    }
                    s.push('-');

                }
                else
                {
                    s.push('-');
                }
                }
                else
                {
                    s.push('-');
                }
            }
            else if(s1[i]=='*')//if *
            {
                if(s.size()!=0){
                char c=s.top();
                if(c=='/')
                {
                    while(c=='/' || c=='^' || c=='*'){//checking precedence
                    s.pop();
                    s2=s2+c;
                    c=s.top();
                    }
                    s.push('*');
                }
                else if(c=='*')
                {
                    while(c=='/' || c=='^' || c=='*'){
                    s.pop();
                    s2=s2+c;
                    c=s.top();
                    }
                    s.push('*');
                }
                else if(c=='^')
                {
                    while(c=='/' || c=='^' || c=='*'){
                    s.pop();
                    s2=s2+c;
                    c=s.top();
                    }
                    s.push('*');
                }
                else
                {
                    s.push('*');
                }
                }
                else
                {
                    s.push('*');
                }
            }
            else if(s1[i]=='/')//if /
            {
                if(s.size()!=0){
                char c=s.top();
                 if(c=='^')
                {
                    while(c=='^' || c=='/'){//checking precedence
                    s.pop();
                    s2=s2+c;
                    c=s.top();
                    }
                    s.push('/');
                }
                else if(c=='/')
                {
                    while(c=='^' || c=='/' ){
                    s.pop();
                    s2=s2+c;
                    c=s.top();
                    }
                    s.push('/');
                }
                else
                {
                    s.push('/');
                }
                }
                else
                {
                    s.push('/');
                }
            }
            else if(s1[i]=='^')// if ^ right associativity
            {
                s.push('^');
            }
            else if(s1[i]==')')//if closing bracket is reached then popping it
            {
                while(s.top()!='(')
                {
                    char x=s.top();
                    s.pop();
                    s2=s2+x;
                }
                s.pop();
            }
            else
            {
                s2=s2+s1[i];//adding in the string
            }
            i++;
        }
        cout<<s2<<endl;//outputting string
    }
    return 0;
}
