
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s("heolloel");
    string p("el");
    int np=p.size(),ns=s.size(),i=0,j=0,len=0,start=0,windowSize=0,lenSoFar=10000,startIdx=-1;
    vector <int> SF(256,0);
    vector <int> PF(256,0);
    for(i;i<np;i++)
    {
        PF[p[i]]+=1;
    }
    for(i=0;i<ns;i++)
    {
        SF[s[i]]+=1;
     
        if(PF[s[i]]!=0 && PF[s[i]]>=SF[s[i]])
        {
            len++;
        }
        
        if(len==np)
        {
            //contract
          
            while(PF[s[start]]==0 || PF[s[start]]<SF[s[start]])
            {
                
                SF[s[start]]-=1;
                start++;
            }
            windowSize=i-start+1;
            if(windowSize<lenSoFar)
            {
                lenSoFar=windowSize;
                startIdx=start;
            }
            
        }
    }
        if(startIdx==-1)
        cout << "notFound";
        cout << s.substr(startIdx,lenSoFar);
       
    // if(len==t.size())
    //     {
    //         return final;
    //     }
    //     return "";



    return 0;
}