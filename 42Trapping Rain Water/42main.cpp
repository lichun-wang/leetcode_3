#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int trap(vector<int>& height) {
		if (height.size() == 0)
			return 0;
		int max = -1;
		int margin = 0;
		int sum = 0;
		for (int i = 0; i < height.size(); i++)
		{
			sum += height[i];
		}
		for (int i = 0; i < height.size(); i++)
		{
			if (height[i]> max)
				max = height[i];
		}
		for (int floor = 1; floor <= max; floor++)
		{
			int left = 0;
			int right = height.size() - 1;
			for (left = 0; left < height.size(); left++)
			{
				if (height[left] >= floor)
					break;
			}
			for (right = height.size() - 1; right >=0; right--)
			{
				if (height[right] >= floor)
					break;
			}

			if (left == right)
				margin += height.size() -1;
			else
				margin = margin +  height.size() - ( right - left + 1);
		}
		return height.size() * max - margin - sum;
	}
};

int main()
{
	int aa[12] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	vector <int > height(aa,aa+12);
	Solution so;
	cout<<so.trap(height);
	system("pause");
	return 0;
}