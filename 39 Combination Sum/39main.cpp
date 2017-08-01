class Solution {
public:
    void dfs(vector<int> nums,vector<vector<int > > &result,vector<int> temp, int sum, int target,int num)
    {
        if(sum > target)
            return;
        if(sum == target)
        {
            result.push_back(temp);
            return;
        }
        
        for(int i = num; i< nums.size();i++)
        {
            sum+= nums[i];
            temp.push_back(nums[i]);
            dfs(nums,result,temp,sum,target,i);
            sum-= nums[i];
            temp.pop_back();
        }
        return;
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        int sum = 0;
        vector<int> temp;
        if(candidates.size() == 0)
            return result;
        dfs(candidates,result,temp,sum,target,0);
        return result;
    }
};