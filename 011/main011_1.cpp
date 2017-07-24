#include <math.h>
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

#define max(a,b)            (((a) >= (b)) ? (a) : (b))
#define min(a,b)            (((a) <= (b)) ? (a) : (b))

class Solution {
public:
	int maxArea(vector<int>& height) {
		int res = 0;
		int l = 0, r = height.size() - 1;
		for (; l != r;)
		{
			res = max( (r-l) * min(height[l], height[r]) , res );
			if (height[l] < height[r])
			{
				l++;
			}
			else
			{
				r--;
			}
		}
		return res;
	}

};

int main()
{
	vector<int> heights;
	heights.push_back(1);
	heights.push_back(1);
	Solution so;
	cout<<so.maxArea(heights);
	int a;
	cin >> a;
	return 0;
}