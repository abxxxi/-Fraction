#define _CRT_SECURE_NO_WARNINGS 1
#include"Fraction.h"
#include<iostream>
#define N 1000
using namespace std;
//������������ʼ����
void showMenu()
{
	cout << "********************************" << endl;
	cout << "*** ��ѡ���ܣ�����1��2��3��***" << endl;
	cout << "***        1.��������        ***" << endl;
	cout << "***        2.��������        ***" << endl;
	cout << "***        3.�˳�����        ***" << endl;
	cout << "********************************" << endl;
	cout << "********************************" << endl;
}

//ѡ��һ�Ľ���
void showMenuSelect01()
{
	cout << "****************************************" << endl;
	cout << "***     ����#�ż�������һ��Ŀ¼      ***" << endl;
	cout << "***       ����&�ż������м���        ***" << endl;
	cout << "*** �������������ʽ����1/2+1/3�س���***" << endl;
	cout << "****************************************" << endl;
}

//ѡ����Ľ���
void showMenuSelect02()
{
	cout << "***************************************" << endl;
	cout << "***     ����#�ż�������һ��Ŀ¼     ***" << endl;
	cout << "***       ����&�ż������м���       ***" << endl;
	cout << "*** ������һ���������Ӣ�Ķ��Ÿ���  ***" << endl;
	cout << "***   ������С���������÷���<��β   ***" << endl;
	cout << "***     �ɴ�С�����÷���>��β     ***" << endl;
	cout << "***   (��1 / 2, 1 / 4, 3 / 5<�س�)  ***" << endl;
	cout << "***************************************" << endl;
}

//����ʱ��������
void fault_cin()
{
	cout << "�������" << endl;     //���ڼ������ʱ���ֵĴ���
	cin.clear();
	cin.ignore();  //����� 
	system("pause");
}

//�������
void fail()
{
	cout << "��ĸ����Ϊ0��";
	cin.clear();
	cin.ignore();  //����� 
	system("pause");
}

//ѡ��һ
void Select01()
{
	while (true)
	{
		system("cls");
		showMenuSelect01();
		char ch01;
		cin >> ch01;
		if (ch01 == '&')
		{
			cout << "�����룺" << endl;
			char op;
			Fraction frac1, frac2;
			cin >> frac1 >> op >> frac2;
			switch (op)
			{
			case '+':
				cout << (frac1 + frac2) << endl;
				system("pause");
				break;
			case '-':
				cout << (frac1 - frac2) << endl;
				system("pause");
				break;
			case '*':
				cout << (frac1 * frac2) << endl;
				system("pause");
				break;
			case '/':
				cout << (frac1 / frac2) << endl;
				system("pause");
				break;
			default:
				break;
			}
		}
		else if (ch01 == '#')     //������һ��
		{
			break;
		}
		else
		{
			fault_cin();
			Select01();
		}
	}
}

//ѡ���
void Select02()
{
	while (1)
	{
		system("cls");
		showMenuSelect02();
		char c1;
		cin >> c1;
		if (c1 == '#') { break; }
		else if (c1 == '&')
		{
			cout << "�����룺" << endl;
			int a[500], b[500], m = 500;
			char d[500], c[500];
			cin >> a[0] >> c[0] >> b[0] >> d[0];
			if (cin.good() && c[0] == '/' && d[0] == ',')
			{
				if (b[0] == 0)
				{
					fail(); 
					return Select02();
				}
				else
				{
					int sum = 0;
					for (int i = 1; i < m; i++)
					{
						sum++;
						cin >> a[i] >> c[i] >> b[i] >> d[i];
						if (cin.good() && c[i] == '/' && d[i] == ',')
						{
							if (b[i] == 0)
							{
								fail(); 
								return Select02();
							}
							else 
							{ 
								continue; 
							}
						}
						else if (cin.good() && c[i] == '/' && (d[i] == '<' || d[i] == '>'))
						{
							break;
						}
						else
						{
							fault_cin(); return Select02();
						}
					}
					Fraction frac[500];
					for (int z = 0; z <= sum; z++)
					{
						frac[z] = Fraction(a[z], b[z]);
					}
					sortFraction(frac, sum);
					if (d[sum] == '<')
					{
						for (int i = 0; i <= sum; i++)
						{
							frac[i].Display();
						}
					}
					else
					{
						for (int i = sum; i >= 0; i--)
						{
							frac[i].Display();
						}
					}
					system("pause");
				}
			}
			else
			{
				fault_cin(); 
				return Select02();
			}
		}
	}
}

//����ѡ��
void function()
{
	//��ʼ��ѡ��
	while (true)
	{
		system("cls");
		showMenu();
		int select;
		cin >> select;
		if (select == 1)
		{
			Select01();
		}
		else if (select == 2)
		{
			Select02();
		}
		else if (select == 3)
		{
			system("cls");
			cout << "��ӭ���´�ʹ�ã�" << endl;
			exit(0);
		}
		else
		{
			fault_cin();
		}
	}
}

int main()
{
	function();
	return 0;
}