class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
      bool flag=false;
      int n=nums.size();
      for(int i=0;i<n;i++) nums[i]%=k;
      vector<int> pre(n+1);
      map<int,int> num;
      int now=0;
      for(int i=0;i<n;i++) {
        
        pre[i+1]=(pre[i]+nums[i])%k;
        if(nums[i]==0) {
          now++;
          if(now>=2) flag=true;
          continue;
        }
        else now=0;
        if(pre[i+1]==0&&i!=0) flag=true;
        num[pre[i+1]]++;
        if(num[pre[i+1]]>=2) flag=true;
      }
      return flag;
    }
};
