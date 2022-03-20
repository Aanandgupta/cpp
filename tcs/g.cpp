#include<iostream>
#include<vector>
using namespace std;
string one[] = { "", "One ", "Two ", "Three ", "Four ","Five ", "Six ", "Seven", "Eight ","Nine ", "Ten ", "Eleven ", "Twelve ","Thirteen ", "Fourteen ", "Fifteen ","Sixteen ", "Seventeen ", "Eighteen ","Nineteen " };

string ten[] = { "", "", "Twenty ", "Thirty", "Forty ","Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety " };  

void stor()
{
    return ;
}
string n2w(int n, string s)
{
    string str = "";
    // if n is more than 19, divide it
    if (n > 19)
        str += ten[n / 10] + one[n % 10];
    else
        str += one[n];
 
    // if n is non-zero
    if (n)
        str += s;
 
    return str;
}
string convertWord(int n)
{
    string outside;
 
    
    outside += n2w((n / 10000000), "Crore ");
 
    outside += n2w(((n / 100000) % 100), "Lakh ");
 
    outside += n2w(((n / 1000) % 100), "Thousand ");
 
    outside += n2w(((n / 100) % 10), "Hundred ");
 
    if (n > 100 && n % 100)
        outside += "And ";
    outside += n2w((n % 100), "");
   
    //Handling the n=0 case
    if(outside=="")
    outside = "Zero";
 
    return outside;
}
bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
  
    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
  
    return true;
}
int solve(int n,vector<string>& ele,vector<string>& emotion)
{
    vector<int>freq;
    for(auto itm:ele)
    {
        string tempoary;
        for(unsigned int i=0;i<itm.size();i++)
        {
            if(isdigit(itm[i]))
            tempoary += itm[i];
        }
        freq.push_back(stoi(tempoary));
    }
    
    int totalScore=0;
    for(int i=0;i<n;i++)
    {
        if(emotion[i]=="Happy")
        {
            totalScore+=(freq[i]*10);
        }
        else if(emotion[i]=="Sad")
        {
            totalScore+=(freq[i]*5);
        }
        else if(emotion[i]=="Neutral")
        {
            totalScore+=(freq[i]*2);
        }
        else if(emotion[i]=="None")
        {
            totalScore+=(freq[i]*1);
        }
    }
    
    vector<int>vowel;
    for(auto item:ele)
    {
        int cnt = 0;
        for(unsigned int i=0;i<item.size();i++)
        {
            if(item[i]=='a' or item[i]=='A' or item[i]=='e' or item[i]=='E' or item[i]=='i' or  item[i]=='I' or  item[i]=='o' or  item[i]=='O' or item[i]=='u' or item[i]=='U')
            {
                cnt++;
            }
        }
        vowel.push_back(cnt);
    }
    int totalVowel = 0;
    for(int i=0;i<n;i++)
    {
        totalVowel += (freq[i]*vowel[i]);
    }

    return totalScore/totalVowel;
    

    
}
int main()
{
    int n;
    cin>>n;
    vector<string>ele(n);
    vector<string>emotion(n);
    for(int i=0;i<n;i++)
    {
        
        cin>>ele[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>emotion[i];
    }
    stor();
    int val = solve(n,ele,emotion);
    string tempoary;
    stor();
    if(isPrime(val))
    {
        tempoary+="Yes";
    }
    else
    {
        tempoary+="No";
    }
    cout<<tempoary<<" "<<convertWord(val)<<" ";
}