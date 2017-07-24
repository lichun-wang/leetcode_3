#include<iostream>
#include<vector>
using namespace std;



class Solution {
public:
	vector<vector<int>> generate(int numRows) {

		vector< vector<int>> result;
		vector<int> temp;
		for (int i = 1; i <= numRows; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				if (j == 1 || j == i)
					temp.push_back(1);
				else
					temp.push_back((result[i - 2][j - 2] + result[i - 2][j-1]));
			}
			result.push_back(temp);
			temp.clear();
		}
		return result;
	}
};


int main()
{
	Solution so;
	so.generate(1);
	system("pause");
	return 0;
}