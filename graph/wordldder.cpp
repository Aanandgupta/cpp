class Solution {
public:
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,bool> store;
        for(string it:wordList)
             store[it]=false;
         if(store.find(endWord)==store.end())
            return 0;   
        queue<pair<string,int>> q;
        q.push({beginWord,0});
        if(store.find(beginWord)!=store.end())
            store[beginWord]=true;   
        while(!q.empty())
        {
          string s=q.front().first;
          int ans=q.front().second;
            q.pop();
            for(int i=0;i<s.size();i++)
            {
                string pre=s.substr(0,i);
                string post=s.substr(i+1);
                char t=s[i];
                while(t>97)
                {
                    t--;
                    if(store.find(pre+t+post)!=store.end() and !store[pre+t+post])
                    {
                        if((pre+t+post)==endWord)
                            return ans+2;
                        store[pre+t+post]=true;
                        q.push({pre+t+post,ans+1});
                    }
                }
                t=s[i];
                while(t<122)
                {
                    t++;
                    if(store.find(pre+t+post)!=store.end() and !store[pre+t+post])
                    {
                         if((pre+t+post)==endWord)
                            return ans+2;
                        store[pre+t+post]=true;
                        q.push({pre+t+post,ans+1});
                    }
                }
            }
            
        }
        return 0;
        
    }
};