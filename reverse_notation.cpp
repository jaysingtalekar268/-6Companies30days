#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    int evalRPN(vector<string>& tokens) {
        
        vector<int>num;
        for(int i=0;i<tokens.size();i++)
      { 
          if(tokens[i]!="+" && tokens[i]!="*" && tokens[i]!="/" && tokens[i]!="-"   )
        { int s= stoi(tokens[i]);
            num.push_back(s);
        //  cout<<s<<endl;
         }
         else
         {
           string op[]{"/","*","-","+"};
           for(int j=0;j<4;j++)
           {
               string  y=tokens[i];
               if(op[j]==tokens[i])
               {

                       int b =num.back();
                       num.pop_back();
                    //    cout<<"b="<<b<<endl;
                    
                       int a=num.back();
                       num.pop_back();
                        //   cout<<"a="<<a<<endl;
                          
                   if(j==0)
                   {

                       num.push_back(a/b);
                   }
                   else if(j==1)
                   {

                        num.push_back(a*b);
                   }
                   else if(j==2)
                   {

                       num.push_back(a-b);
                   }else
                   {
                        num.push_back( a+b);
                   }
                   break;
               }
           }
         }

      }
        return num.back();
    }
};

int main()
{   
    string str;
    cin>>str;
    vector<string>s;

    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='"')
        {   int k=i+1;
            string t="";
            while (str[k]!='"')
            {   
                t+=(str[k]);
                k++;
                
            }
            i=k+1;
            s.push_back(t);
        }
    }

    
    Solution p;
    cout<<p.evalRPN(s)<<endl;
   
    return 0;
}