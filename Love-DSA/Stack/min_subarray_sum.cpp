vector<int> NSL(vector<int>arr,int n)
    {
        vector<int>v;
        stack<pair<int,int>>s;
        for(int i=0;i<n;i++)
        {
            while(s.size()!=0 && arr[i]<=(s.top()).first)
            s.pop();  
            if(s.size()==0 )
            {
                if(i==0)
                v.push_back(0);
                else
                v.push_back(-1);
            }
            else
            v.push_back((s.top()).second);
            s.push({arr[i],i});
        }
        return v; 
    }
    vector<int> NSR(vector<int>arr,int n)
    {
        vector<int>v;
        stack<pair<int,int>>s;
        for(int i=n-1;i>=0;i--)
        {
            while(s.size()!=0 && arr[i]<=(s.top()).first)
            s.pop();  
            if(s.size()==0 )
            {
                v.push_back(n);
            }
            else
            v.push_back((s.top()).second);
            s.push({arr[i],i});
        }
        reverse(v.begin(),v.end());
        return v; 
    }