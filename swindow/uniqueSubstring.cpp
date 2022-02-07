
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestSubstrDistinctChars (string S)
{
    // your code here
    vector <int> arr(26,-1);
    int len=0,i=0,j=0;
    for(;j<S.size();j++)
    {
        if(arr[S[j]-'a']>=i)
        {
            if(len<j-i)
            {
                len=j-i;
            }
            i=arr[S[j]-'a']+1;
            arr[S[j]-'a']=j;
        }
        else{
            arr[S[j]-'a']=j;
        }
    }
        
        if(len<j-i)
        {
            return (j-i);
        }
        return len;

}



// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;

// int main()
// {
//     string s("prateeekbhaiyx");
//     int n=s.size(),i=0,j=0,len=0;
//     vector <int> freq(26,0);
//     vector <int> ans(2,0);
    
//     while(j<n)
//     {
//         if(freq[s[j]-'a']>i)
//         {
//             //push in vector
//             if(len<j-i+1)
//             {
//             ans[0]=i;
//             ans[1]=j-1; 
//             len=j-i+1;
//             }
//             i=freq[s[j]-'a'];
//             freq[s[j]-'a']=j+1;
//         }
//         else{
//             freq[s[j]-'a']=j+1;
//         }
//         j+=1;
//     }
//     if(len<j-i+1)
//     {
//     ans[0]=i;
//     ans[1]=j-1; 
//     len=j-i+1;
//     }
    
//     cout <<ans[0]<<','<<ans[1];
//     return 0;
// }