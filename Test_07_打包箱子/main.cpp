#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
	int n = 0, l = 0;
	cin >> n >> l;
	vector<int> length;
	length.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> length[i];
	}
	sort(length.begin(), length.end());
	int x = 0, y = n-1, count = 0;
	while (x <= y)
	{
		if (x == y)
		{
			++count;
			break;
		}
		if (length[x] + length[y] <= l)
		{
			++count;
			++x;
			--y;
		}
		else
		{
			++count;
			--y;
		}
	}
	cout << count;
	return 0;
}