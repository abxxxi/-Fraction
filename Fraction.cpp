#define _CRT_SECURE_NO_WARNINGS 1
#include"Fraction.h"
#include<algorithm>
#include<iostream>
using namespace std;
#define N 1000

//无参造函数
Fraction::Fraction() {}

//带参造函数
Fraction::Fraction(int n, int d)
{
	numer = n;
	deno = d;
}

//复制造函数
Fraction::Fraction(const Fraction& f)
{
	numer = f.numer;
	deno = f.deno;
}

//设置分数的分子和分母
void Fraction::setFraction(int n, int d)
{
	Fraction frac;
	frac.numer = n;
	frac.deno = d;
}

//获取分数的分子
int Fraction::getNumer()
{
	return numer;
}

//获取分数的分母
int Fraction::getDeno()
{
	return deno;
}

//当前分数约分
int ComDiv(int num1, int num2)
{
	return num2 ? ComDiv(num2, num1 % num2) : num1;
}
void Fraction::RdcFrc()
{
	int comdiv = ComDiv(numer, deno);
	numer /= comdiv;
	deno /= comdiv;
}

//显示当前分数
void  Fraction::Display()
{
	if (deno != 0 && numer == 0) { cout << numer << " "; }    //分母为1、分子为0时直接输出分子
	else if (deno == 0) { cout << "分母不能为0！" << endl; }
	else{ cout << numer << "/" << deno << " "; }

}

//析构函数
Fraction::~Fraction() {};

//重载+运算符
Fraction operator+(const Fraction& frac1, const Fraction& frac2)
{
	Fraction result;
	result.deno = frac1.deno * frac2.deno;
	result.numer = frac1.numer * frac2.deno + frac2.numer * frac1.deno;
	result.RdcFrc();
	return result;
}

//重载-运算符
Fraction operator-(const Fraction& frac1, const Fraction& frac2)
{
	Fraction result;
	result.deno = frac1.deno * frac2.deno;
	result.numer = frac1.numer * frac2.deno - frac2.numer * frac1.deno;
	result.RdcFrc();
	return result;
}

//重载*运算符
Fraction operator*(const Fraction& frac1, const Fraction& frac2)
{
	Fraction result;
	result.deno = frac1.deno * frac2.deno;
	result.numer = frac1.numer * frac2.numer;
	result.RdcFrc();
	return result;
}

//重载/运算符
Fraction operator/(const Fraction& frac1, const Fraction& frac2)
{
	Fraction result;
	result.deno = frac1.deno * frac2.numer;
	result.numer = frac1.numer * frac2.deno;
	result.RdcFrc();
	return result;
}

//重载==运算符
bool operator==(Fraction frac1, Fraction frac2)
{
	int ret = (frac1.numer * frac2.deno)/ (frac1.deno * frac2.numer);
	if (ret == 1)
		return true;
	else
		return false;
}

//重载>运算符
bool operator>(const Fraction& frac1, const Fraction& frac2)
{
	if ((frac1.numer * frac2.deno) > (frac1.deno * frac2.numer))
	{
		return true;
	}
	return false;
	
}

//重载<运算符
bool operator<(const Fraction& frac1, const Fraction& frac2)
{
	if ((frac1.numer * frac2.deno) < (frac1.deno * frac2.numer))
	{
		return true;
	}
	return false;
}

//重载<<运算符
ostream& operator<<(ostream& out, const Fraction& frac)
{	
	if (frac.deno != 0)
	{
		out << " = " << frac.numer << "/" << frac.deno << endl;
	}
	return out;
}

//重载>>运算符
istream& operator>>(istream& in, Fraction& frac)
{
	char ch1;
	in >> frac.numer >> ch1 >> frac.deno;
	if (frac.deno == 0)
	{
		cout << "分母不能为0！" << endl;
	}
	return in;
}

//对分数数组排序
void sortFraction(Fraction frac[], int len)
{
	//从小到大
	Fraction temp;
	for (int i = 0; i <= len - 1; i++)
	{
		for (int j = 0; j <= len - i - 1; j++)
		{
			if (frac[j]>frac[j+1])
			{
				temp = frac[j];
				frac[j] = frac[j + 1];
				frac[j + 1] = temp;
				//swap(frac[j], frac[j + 1]);
			}
		}
	}
}