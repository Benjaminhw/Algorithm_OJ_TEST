#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>

using namespace std;

//�Զ���ȽϺ������Ӹ�λ�ȵ���λ���в�ͬλ���˳������һ����������һ������λ������ôλ����С
bool MyCmp(string a, string b)//����true��a��ǰ�棬����false��a�ź���
{
	//������һ����û�б�Ҫ�ģ����Ǽ���֮���ٶȿ��Կ�2-3��
	for (int i = 0; i < a.size() && i < b.size(); ++i)
	{
		if (a[i]!=b[i])
		{
			return a[i] > b[i];//ϣ��ʲô����ʲô
		}
	}
	//��û�б�Ҫ�жϣ��жϲ���
	////��ǰ�����бȽ϶�һ��,��λ������Ҫ�ж�
	//if (a.size() < b.size())
	//{
	//	int flag = a[0];//a����λ
	//	for (int j = a.size(); j < b.size(); ++j)
	//	{
	//		if (b[j] > flag)//��������ĳһλ�ȹ������һλ��,b��ǰ��
	//		{
	//			return false;
	//		}
	//		if (b[j] < flag)
	//		{
	//			return true;//��֮a��ǰ��
	//		}
	//		//���һֱ��ȣ�����Ҫ��λ���ţ���������������
	//	}
	//	return true;//������ܶ�
	//}
	//else//a��λ������
	//{
	//	int flag = b[0];//b����λ
	//	for (int j = b.size(); j < a.size(); ++j)
	//	{
	//		if (a[j] > flag)//��������ĳһλ�ȹ������һλ��,a��ǰ��
	//		{
	//			return true;
	//		}
	//		if (a[j] < flag)
	//		{
	//			return false;//��֮b��ǰ��
	//		}
	//		//���һֱ��ȣ�����Ҫ��λ���ţ���������������
	//	}
	//	return false;
	//}

	//ֱ�ӱȽ�ƴ����һ��˭����
	return a + b > b + a;
}

int main()
{
	vector<string> Numbers;
	string tempNumber;
	char NoUse[40];
	cin.getline(NoUse,50);
	while (cin >> tempNumber)
	{
		Numbers.push_back(tempNumber);
		if (cin.get() == '\n')
		{
			break;
		}
	}
	sort(Numbers.begin(), Numbers.end(),MyCmp);//����
	string result;
	for (vector<string>::iterator it = Numbers.begin(); it != Numbers.end(); ++it)
	{
		/*cout << *it <<" ";*/
		result.append(*it);
	}
	//int resulti=atoi(result.c_str());
	cout << result;
	return 0;
}

