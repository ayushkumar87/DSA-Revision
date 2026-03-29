bool comp(pair<int,int>a,pair<int,int>b){
    return a.second>b.second;
}
class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        vector<pair<int,int>>m;
        for(int i=0;i<deadline.size();i++){
            m.push_back(make_pair(deadline[i],profit[i]));
        }
        
        sort(m.begin(),m.end(),comp);
        
        int dead=0;
        for(int i=0;i<deadline.size();i++){
            dead=max(dead,m[i].first);
        }
        
        vector<bool>Task(dead+1,false);
        vector<int> ans(2,0);
        
        for(int i=0;i<deadline.size();i++){
            for(int j=m[i].first;j>0;j--){
                if(Task[j]==false){
                    Task[j]=true;
                    ans[0]++;
                    ans[1]+=m[i].second;
                    break;
                }
            }
        }
        return ans;
    }
};