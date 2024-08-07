class Solution {
  public:
    int threeSumClosest(vector<int> nums, int target) {
        int mini=INT_MAX;
        int ans=-1;
        //at first we have to sort the array
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int j=i+1;
            int k=nums.size()-1;
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                int diff=abs(sum-target);
                if(diff < mini || (diff == mini && sum > ans))
                {
                    mini=diff;
                    ans=sum;
                }
                if(sum < target)
                {
                    j++;
                }
                else if(sum > target)
                {
                    k--;
                }
                else
                {
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1])
                    {
                        j++;
                    }
                    while(j<k && nums[k]==nums[k+1])
                    {
                        k--;
                    }
                }
            
            }
        }
        return ans;
    }
};
