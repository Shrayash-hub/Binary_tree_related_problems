class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        map<int,int> mpp;
        vector<int> ans;
        
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        
        for(auto it:mpp){
            if(it.second>1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};