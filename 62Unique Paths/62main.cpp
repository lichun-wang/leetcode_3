#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


/*方法一：深度优先搜索，结果超时了*/
//class Solution {
//public:
//	int result = 0;
//	int uniquePaths(int m, int n) {
//		if (m == 0 || n == 0)
//			return 0;
//
//		dfs(0, 0, m, n);
//		return result;
//	}
//	void dfs(int row,int col,int m, int n)
//	{
//		if (row == m - 1 && col == n - 1)
//		{
//			result++;
//			return;
//		}
//		if (row > m-1 || col > n-1)
//			return;
//
//		dfs(row + 1, col, m, n);
//		dfs(row, col + 1, m, n);
//
//	}
//};

class Solution {
public:

	int uniquePaths(int m, int n) {

		if (m == 0 || n == 0)
			return 0;
		if (m == 1 || n == 1)
			return 1;
		int** arrays = new int* [m];
		for (int i = 0; i < m; i++)
			arrays[i] = new int[n];

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				arrays[i][j] = 1;
		}

		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
				arrays[i][j] = arrays[i-1][j] + arrays[i][j-1];
		}

		return arrays[m - 1][n - 1];



	}

};


int main()
{
	Solution so;
	cout << so.uniquePaths(3, 3) << endl;;
	system("pause");
	return 0;
}