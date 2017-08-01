Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]


给定一个数组，以及一个目标，求在数组中哪些数的和会是这个数。

利用深度优先搜索进行递归
递归的时候注意，for循环要从num开始计算。

  for(int i = num; i< nums.size();i++)
      sum+= nums[i];
      temp.push_back(nums[i]);
      dfs(nums,result,temp,sum,target,i);
      sum-= nums[i];
      temp.pop_back();