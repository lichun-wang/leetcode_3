#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		if (matrix.size() == 0)
			return;
		vector<int > row = matrix[0];
		int n = row.size();  //¿í¶È
		int N = n;
		for (int i = 0; i < N-1; i++)
		{
			for (int j = i; j < N-1; j++)
			{
				int src = matrix[i][j];
				matrix[i][j] = matrix[n - j - 1][i];  //4
				matrix[n-j-1][i] = matrix[n - i - 1][n - j - 1];//3
				matrix[n - i - 1][n - j - 1] = matrix[j][n-i-1];
				matrix[j][n-i-1]  = src;
			}
			N--;
		}
	}
};

int main()
{
	int a1[4] = { 1, 2, 3, 4 };
	int a2[4] = { 5, 6, 7, 8 };
	int a3[4] = { 9, 10, 11, 12 };
	int a4[4] = { 13, 14, 15, 16 };
	vector<int> aa1(a1, a1 + 4);
	vector<int> aa2(a2, a2 + 4);
	vector<int> aa3(a3, a3 + 4);
	vector<int> aa4(a4, a4 + 4);
	vector<vector<int>> matrix;
	matrix.push_back(aa1);
	matrix.push_back(aa2);
	matrix.push_back(aa3);
	matrix.push_back(aa4);
	Solution so;
	so.rotate(matrix);

	system("pause");
	return 0;
}