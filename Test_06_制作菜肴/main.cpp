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

//��Map��Value����
bool compare(const pair<pMyset, int>& a, const pair<pMyset, int>& b)
{
	return a.second > b.second;
}

int main()
{
	int width = 0, height = 0, tempInt = 0;
	//�����ǵ��������򣬶���Ҫ�����Ұ�����ǰ������ȫ����������
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
	vector<pair<pMyset, int>> GardenSortQueue(Garden.begin(), Garden.end());//�����е�pair������vector
	sort(GardenSortQueue.begin(), GardenSortQueue.end(), compare);

	//������Ҫ���ľ��ǰ��ն���˳�������ĸ������ڵ�Ԫ��

	for (int i = 1; i <= height; ++i)
	{
		for (int j = 1; j <= width; ++j)
		{//������Ҫ��ѡС����վλ
			if (i == 1 || j == 1 || i == height || j == width)
			{
				printf("0 ");
			}
			else
			{
				int a = 0, b = 0, c = 0, d = 0;//���� ���� ���� ����
				bool a1 = true, b1 = true, c1 = true, d1 = true;
				for (vector<pair<pMyset, int>>::iterator it = GardenSortQueue.begin(); (a1 || b1 || c1 || d1 ) & it != GardenSortQueue.end(); ++it)
				{
					if (it->first->i < i)
					{//�����
						if (it->first->j > j && a1)
						{//����
							a1 = false;
							a = it->second;
						}
						if (it->first->j < j && c1)
						{//����
							c1 = false;
							c = it->second;
						}
					}
					if (it->first->i > i)
					{//�Ұ���
						if (it->first->j > j && b1)
						{//����
							b1 = false;
							b = it->second;
						}
						if (it->first->j < j && d1)
						{//����
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