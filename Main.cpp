#define _CRT_SECURE_NO_WARNINGS 1
#include"Fraction.h"
#include<iostream>
#define N 1000
using namespace std;
//分数计算器开始界面
void showMenu()
{
	cout << "********************************" << endl;
	cout << "*** 请选择功能（输入1、2或3）***" << endl;
	cout << "***        1.分数计算        ***" << endl;
	cout << "***        2.分数排序        ***" << endl;
	cout << "***        3.退出程序        ***" << endl;
	cout << "********************************" << endl;
	cout << "********************************" << endl;
}

//选择一的界面
void showMenuSelect01()
{
	cout << "****************************************" << endl;
	cout << "***     输入#号键返回上一层目录      ***" << endl;
	cout << "***       输入&号继续进行计算        ***" << endl;
	cout << "*** 请输入分数计算式（如1/2+1/3回车）***" << endl;
	cout << "****************************************" << endl;
}

//选择二的界面
void showMenuSelect02()
{
	cout << "***************************************" << endl;
	cout << "***     输入#号键返回上一层目录     ***" << endl;
	cout << "***       输入&号继续进行计算       ***" << endl;
	cout << "*** 请输入一组分数，用英文逗号隔开  ***" << endl;
	cout << "***   如需由小到大排序用符号<结尾   ***" << endl;
	cout << "***     由大到小排序用符号>结尾     ***" << endl;
	cout << "***   (如1 / 2, 1 / 4, 3 / 5<回车)  ***" << endl;
	cout << "***************************************" << endl;
}

//计算时发生错误
void fault_cin()
{
	cout << "输入错误！" << endl;     //便于检查输入时出现的错误
	cin.clear();
	cin.ignore();  //清空流 
	system("pause");
}

//输入错误
void fail()
{
	cout << "分母不能为0！";
	cin.clear();
	cin.ignore();  //清空流 
	system("pause");
}

//选择一
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
			cout << "请输入：" << endl;
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
		else if (ch01 == '#')     //返回上一层
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

//选择二
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
			cout << "请输入：" << endl;
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

//进行选择
void function()
{
	//初始化选择
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
			cout << "欢迎您下次使用！" << endl;
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