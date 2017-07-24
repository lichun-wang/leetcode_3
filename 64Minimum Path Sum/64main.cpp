
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {

		if (grid.size() == 0)
			return 0;
		int m = grid.size();
		int n = grid[0].size();

		vector<vector<int>>& grid_cp = grid;
		int sum = 0;
		if (m == 1)
		{
			for (int i = 0; i < n; i++)
				sum = sum + grid[0][i];
			return sum;
		}
		sum = 0;  //清零
		if (n == 1)
		{
			for (int i = 0; i <m; i++)
				sum = sum + grid[i][0];
			return sum;
		}

		for (int i = 1; i < n; i++)   //准备 行
		{
			grid_cp[0][i] = grid_cp[0][i - 1] + grid_cp[0][i];
		}

		for (int i = 1; i < m; i++)   //准备 列
		{
			grid_cp[i][0] = grid_cp[i-1][0] + grid_cp[i][0];
		}

		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				grid_cp[i][j] = min(grid_cp[i - 1][j], grid_cp[i][j - 1]) + grid_cp[i][j];
			}
		}

		return grid_cp[m - 1][n - 1];

	}
};

int main()
{
	int a1[3] = { 0, 0 ,0};
	int a2[3] = { 1, 1 ,1};
	int a3[3] = { 0, 0 ,0};

	vector<int> aa1(a1, a1 + 3);
	vector<int> aa2(a2, a2 + 3);
	vector<int> aa3(a3, a3 + 3);

	vector<vector<int>> matrix;
	matrix.push_back(aa1);
	matrix.push_back(aa2);
	matrix.push_back(aa3);

	Solution so;
	cout << so.minPathSum(matrix) << endl;
	system("pause");
	return 0;
}