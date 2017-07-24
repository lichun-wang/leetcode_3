/*120. Triangle*/
/*此题依旧采用动态规划算法*/
/*跟前面的动态规划很像*/
/*在下降的过程，比较上面以及上左的数据中较小的一个*/
/*最后，在最下面一行中找到最小的即可*/

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int m = triangle.size();
		if (m == 0)
			return 0;
		int n = triangle[0].size();

		vector<vector<int>> nums = triangle;

		for (int i = 1; i < m; i++)
			nums[i][0] += nums[i - 1][0];

		for (int i = 1; i < m; i++)
			nums[i][i] += nums[i - 1][i - 1];

		for (int i = 2; i < m; i++)
		{
			for (int j = 1; j < i; j++)
			{

				nums[i][j] = min(nums[i - 1][j - 1], nums[i - 1][j]) + nums[i][j];
			}
		}

		int min = INT_MAX;
		for (int i = 0; i < m; i++)
		{
			if (nums[m-1][i] < min)
				min = nums[m-1][i];
		}
		return min;
		
	}
};


int main()
{
	int a1[4] = { 2};
	int a2[4] = { 3,4 };
	int a3[4] = { 6,5,7};
	int a4[4] = { 4,1,8,3 };
	vector<int> aa1(a1, a1 + 1);
	vector<int> aa2(a2, a2 + 2);
	vector<int> aa3(a3, a3 + 3);
	vector<int> aa4(a4, a4 + 4);
	vector<vector<int>> matrix;
	matrix.push_back(aa1);
	matrix.push_back(aa2);
	matrix.push_back(aa3);
	matrix.push_back(aa4);

	Solution so;
	cout << so.minimumTotal(matrix) << endl;
	system("pause");
	return 0;
}