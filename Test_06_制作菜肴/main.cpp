#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

typedef struct Myset
{
public:
	int i;
	int j;
}Myset, * pMyset;

//对Map按Value排序
bool compare(const pair<pMyset, int>& a, const pair<pMyset, int>& b)
{
	return a.second > b.second;
}

int main()
{
	int width = 0, height = 0, tempInt = 0;
	//并不是单纯的排序，而需要排序且把排序前的坐标全部保存下来
	unordered_map<pMyset, int> Garden;
	cin >> height >> width;
	while (getchar() != '\n') {};
	for (int i = 1; i <= height; ++i)
	{
		for (int j = 1; j <= width; ++j)
		{
			pMyset ptempSet = new Myset;
			ptempSet->i = i;
			ptempSet->j = j;
			cin >> tempInt;
			Garden.insert({ ptempSet,tempInt });
			if (cin.get() == '\n')
			{
				break;
			}
		}
	}
	vector<pair<pMyset, int>> GardenSortQueue(Garden.begin(), Garden.end());//将表中的pair拷贝进vector
	sort(GardenSortQueue.begin(), GardenSortQueue.end(), compare);

	//接下来要做的就是按照队列顺序，挑出四个象限内的元素

	for (int i = 1; i <= height; ++i)
	{
		for (int j = 1; j <= width; ++j)
		{//现在是要挑选小明的站位
			if (i == 1 || j == 1 || i == height || j == width)
			{
				printf("0 ");
			}
			else
			{
				int a = 0, b = 0, c = 0, d = 0;//左上 右上 左下 右下
				bool a1 = true, b1 = true, c1 = true, d1 = true;
				for (vector<pair<pMyset, int>>::iterator it = GardenSortQueue.begin(); (a1 || b1 || c1 || d1 ) & it != GardenSortQueue.end(); ++it)
				{
					if (it->first->i < i)
					{//左半区
						if (it->first->j > j && a1)
						{//左上
							a1 = false;
							a = it->second;
						}
						if (it->first->j < j && c1)
						{//左下
							c1 = false;
							c = it->second;
						}
					}
					if (it->first->i > i)
					{//右半区
						if (it->first->j > j && b1)
						{//右上
							b1 = false;
							b = it->second;
						}
						if (it->first->j < j && d1)
						{//右下
							d1 = false;
							d = it->second;
						}
					}
				}
				cout << a * b * c * d << ' ';
			}
		}
		printf("\n");
	}

	return 0;
}