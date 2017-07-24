/*此题的关键在于设置第一行与第一列
 然后又路障的地方直接设为0就可以了*/


#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.size() == 0)
			return 0;

		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();


		if (m == 1 || n == 1)
		{
			for (int i = 0; i < m;i++)
			for (int j = 0; j < n; j++)
			{
				if (obstacleGrid[i][j] == 1)
					return 0;
			}
			return 1;
		}

		vector<vector<int>> obCopy = obstacleGrid;
		bool gird = false;
		for (int i = 0; i < n; i++)  //设置行
		{
			if (obstacleGrid[0][i] == 0 && gird == false)
				obCopy[0][i] = 1;
			else
			{
				obCopy[0][i] = 0;
				gird = true;
			}

		}
		gird = false;
		for (int i = 0; i < m; i++)  //设置列
		{
			if (obstacleGrid[i][0] == 0 && gird == false)
				obCopy[i][0] = 1;
			else
			{
				obCopy[i][0] = 0;
				gird = true;
			}

		}

	
		for (int i = 1; i < obstacleGrid.size(); i++)

		{
			for (int j = 1; j < obstacleGrid[0].size(); j++)
			if (obstacleGrid[i][j] == 1)
				obCopy[i][j] = 0;
			else
				obCopy[i][j] = obCopy[i-1][j] + obCopy[i][j-1];
		}

		return obCopy[m - 1][n - 1];
	}
};


int main()
{
	int a1[3] = { 0, 0 };
	int a2[3] = { 1, 1 };
	int a3[3] = { 0, 0 };
	
	vector<int> aa1(a1, a1 + 2);
	vector<int> aa2(a2, a2 + 2);
	vector<int> aa3(a3, a3 + 2);

	vector<vector<int>> matrix;
	matrix.push_back(aa1);
	matrix.push_back(aa2);
	matrix.push_back(aa3);
	
	Solution so;
	cout << so.uniquePathsWithObstacles(matrix) << endl;
	system("pause");
	return 0;
}