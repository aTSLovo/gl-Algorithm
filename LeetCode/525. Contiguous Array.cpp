class Solution {
public:
    int findMaxLength(vector<int>& nums) {
      int n=nums.size();
      int ans=0,pre=0;
      map<int,int> ma;
      ma[pre]=-1;
      for(int i=0;i<n;i++) {
        if(nums[i]==0) pre+=-1;
        else pre+=1;
        
        if(ma.count(pre)) {//
          ans=max(ans,i-ma[pre]);
        }
        else ma[pre]=i;
      }
      return ans;
    }
};
