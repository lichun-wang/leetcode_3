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


����һ�����飬�Լ�һ��Ŀ�꣬������������Щ���ĺͻ����������

������������������еݹ�
�ݹ��ʱ��ע�⣬forѭ��Ҫ��num��ʼ���㡣

  for(int i = num; i< nums.size();i++)
      sum+= nums[i];
      temp.push_back(nums[i]);
      dfs(nums,result,temp,sum,target,i);
      sum-= nums[i];
      temp.pop_back();