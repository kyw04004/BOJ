#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<functional>
#include<stack>
using namespace std;
void go(int depth, int end, string str)
{
	if (depth == end)
	{
		cout << str + "\"����Լ��� ������?\"" << "\n";
		cout << str + "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << "\n";
		cout << str + "��� �亯�Ͽ���." << "\n";
		return;
	}
	cout <<str+"\"����Լ��� ������?\""<<"\n";
	cout << str + "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���."<< "\n";
	cout << str + "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���."<< "\n";
	cout << str + "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\""<<"\n";
	go(depth+1,end,str+"____");
	cout << str + "��� �亯�Ͽ���."<<"\n";
}
int main() {
	int n;
	scanf("%d", &n);
	printf("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n");
	printf("\"����Լ��� ������?\"\n");
	printf("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n");
	printf("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n");
	printf("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n");
	go(1,n,"____");
	printf("��� �亯�Ͽ���.\n");
	return 0;
}