#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

//感觉整个思路就错了，写你妈的二分查找- -。
//谢谢，有被网上的思路误导到！！！这题就是双指针啊，两个迭代器遍历1遍就完事儿！！！！我浪费的时间啊！！！！
//void Search(vector<int>Numbers, int low, int high, int target, int& count)
//{
//	if (target > Numbers[high] || target < Numbers[low])
//	{
//		return;
//	}
//	int mid = (low + high) / 2;
//	if (Numbers[mid] == target)
//	{
//		++count;
//		int i = mid - 1;
//		while (i > low && Numbers[i] == target)
//		{
//			++count;
//			--i;
//		}
//		i = mid + 1;
//		while (i < high && Numbers[i] == target)
//		{
//			++count;
//			++i;
//		}
//		return;
//	}
//	else if (target > Numbers[mid])
//	{
//		low = mid + 1;
//		Search(Numbers, low, high, target, count);
//	}
//	else
//	{
//		high = mid - 1;
//		Search(Numbers, low, high, target, count);
//	}
//	if (low == high)
//	{
//		return;
//	}
//	return;
//}

long long factorial(int n)
{
	long long result = 1;
	for (int i = 1; i <= n; ++i)
	{
		result *= i;
	}
	return result;
}

int main()
{
	int Nouse = 0, width = 0;
	cin >> Nouse >> width;
	vector<int> Numbers;
	Numbers.resize(Nouse);
	//读到回车再进入下一行
	while (getchar() != '\n') {}
	int i = 0;
	char tempc = 0;
	//unordered_map<int, int> NumberMap;
	while (tempc != '\n')
	{
		tempc = getchar();
		if (tempc != '-' && (tempc < '0' || tempc > '9'))
		{
			continue;
		}//是空格就直接进入下一个循环
		int x = 0, w = 1;
		char c = tempc;//将tempc传给c，则不需要将流指针前置一格
		while (c < '0' || c > '9') {
			if (c == '-') w = -1;
			c = getchar();
		}
		while (c >= '0' && c <= '9') {
			x = x * 10 + (c - '0');
			c = getchar();
		}
		Numbers[i] = x * w;
		++i;
		if (c == '\n')
		{
			break;
		}
	}
	if (Nouse <= 1)
	{
		cout << 0;
		return 0;
	}

	sort(Numbers.begin(), Numbers.end());
	//for (int i = 0; i < Numbers.size() - 1; ++i)//最后一个不用找了
	//{
	//	int low = i + 1, high = Numbers.size() - 1;
	//	int target = Numbers[i] + width;
	//	Search(Numbers, low, high, target, count);
	//}

	int count = 0;
	int x = 0, y = 1;
	int size = Numbers.size();

	if (width)
	{//宽度不为0
		while (x < size - 1 && y < size)
		{
			if (Numbers[y] < Numbers[x] + width)
			{
				++y;
			}
			else if (Numbers[y] == Numbers[x] + width)
			{

				int a = 1, b = 1, flaga = Numbers[x], flagb = Numbers[y];
				//下面这样写的好处是不走回头路，一步到底，复杂度为O(n) 只走两遍
				while (x < size - 2 && Numbers[x + 1] == flaga)//x<y-1因为这两个数不可以重叠；而且必须先判断x再判断y
				{
					++a;
					++x;
				}
				while (y < size - 1 && Numbers[y + 1] == flagb)//越界条件写前面避免访问越界错
				{
					++b;
					++y;
				}
				count += a * b;//没有相同就是1*1
				++x;//判断完了 下一位
			}
			else
			{
				++x;
			}
		}
	}
	else
	{//宽度为0；
		//注意这里并不需要判断是否接壤，当宽度是0的时候，x和y必然是始终接壤的。此时只需要一个指针
		int flag = Numbers[x], N = 0;
		while (x < size)
		{
			if (x < size - 1 && Numbers[x + 1] == flag)
			{//如果后一个元素与前一个元素相同
				++x;
				++N;
			}
			else
			{//不同，或是到达了数组的末端
				count += N*(N+1);//计数加上这一堆数的阶乘
				N = 0;
				++x;
				if (x < size)
				{//没有到达末端
					flag = Numbers[x];
				}
			}
		}
	}

	cout << count;
	return 0;
}