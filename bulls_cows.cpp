#include<iostream>
using  namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        
        int bulls=0,cows=0;
        for(int i=0;i<secret.length();i++)
        {
            if(secret[i]==guess[i])
            {
                secret[i]='B';
                guess[i]='B';
                bulls++;
            }

        }
        for(int i=0;i<secret.length();i++)
        {
              for(int j=0;j<guess.length();j++)
 if(secret[i]==guess[j] && secret[i]!='C' && secret[i]!='B' && guess[j]!='C' && guess[j]!='B')
            {
                secret[i]='C';
                guess[j]='C';
                cows++;
                break;
            }

        }
        
        secret="";
        secret.append(to_string(bulls));
        secret.append("A");
        secret.append(to_string(cows));
        secret.append("B");

        return secret;
    }
};


int main(int argc, char const *argv[])
{   
    string secret,guess;
    cin>>secret>>guess;
    Solution s;
    cout<<s.getHint(secret,guess)<<endl;
    return 0;
}
