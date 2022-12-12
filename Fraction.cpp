#define _CRT_SECURE_NO_WARNINGS 1
#include"Fraction.h"
#include<algorithm>
#include<iostream>
using namespace std;
#define N 1000

//�޲��캯��
Fraction::Fraction() {}

//�����캯��
Fraction::Fraction(int n, int d)
{
	numer = n;
	deno = d;
}

//�����캯��
Fraction::Fraction(const Fraction& f)
{
	numer = f.numer;
	deno = f.deno;
}

//���÷����ķ��Ӻͷ�ĸ
void Fraction::setFraction(int n, int d)
{
	Fraction frac;
	frac.numer = n;
	frac.deno = d;
}

//��ȡ�����ķ���
int Fraction::getNumer()
{
	return numer;
}

//��ȡ�����ķ�ĸ
int Fraction::getDeno()
{
	return deno;
}

//��ǰ����Լ��
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

//��ʾ��ǰ����
void  Fraction::Display()
{
	if (deno != 0 && numer == 0) { cout << numer << " "; }    //��ĸΪ1������Ϊ0ʱֱ���������
	else if (deno == 0) { cout << "��ĸ����Ϊ0��" << endl; }
	else{ cout << numer << "/" << deno << " "; }

}

//��������
Fraction::~Fraction() {};

//����+�����
Fraction operator+(const Fraction& frac1, const Fraction& frac2)
{
	Fraction result;
	result.deno = frac1.deno * frac2.deno;
	result.numer = frac1.numer * frac2.deno + frac2.numer * frac1.deno;
	result.RdcFrc();
	return result;
}

//����-�����
Fraction operator-(const Fraction& frac1, const Fraction& frac2)
{
	Fraction result;
	result.deno = frac1.deno * frac2.deno;
	result.numer = frac1.numer * frac2.deno - frac2.numer * frac1.deno;
	result.RdcFrc();
	return result;
}

//����*�����
Fraction operator*(const Fraction& frac1, const Fraction& frac2)
{
	Fraction result;
	result.deno = frac1.deno * frac2.deno;
	result.numer = frac1.numer * frac2.numer;
	result.RdcFrc();
	return result;
}

//����/�����
Fraction operator/(const Fraction& frac1, const Fraction& frac2)
{
	Fraction result;
	result.deno = frac1.deno * frac2.numer;
	result.numer = frac1.numer * frac2.deno;
	result.RdcFrc();
	return result;
}

//����==�����
bool operator==(Fraction frac1, Fraction frac2)
{
	int ret = (frac1.numer * frac2.deno)/ (frac1.deno * frac2.numer);
	if (ret == 1)
		return true;
	else
		return false;
}

//����>�����
bool operator>(const Fraction& frac1, const Fraction& frac2)
{
	if ((frac1.numer * frac2.deno) > (frac1.deno * frac2.numer))
	{
		return true;
	}
	return false;
	
}

//����<�����
bool operator<(const Fraction& frac1, const Fraction& frac2)
{
	if ((frac1.numer * frac2.deno) < (frac1.deno * frac2.numer))
	{
		return true;
	}
	return false;
}

//����<<�����
ostream& operator<<(ostream& out, const Fraction& frac)
{	
	if (frac.deno != 0)
	{
		out << " = " << frac.numer << "/" << frac.deno << endl;
	}
	return out;
}

//����>>�����
istream& operator>>(istream& in, Fraction& frac)
{
	char ch1;
	in >> frac.numer >> ch1 >> frac.deno;
	if (frac.deno == 0)
	{
		cout << "��ĸ����Ϊ0��" << endl;
	}
	return in;
}

//�Է�����������
void sortFraction(Fraction frac[], int len)
{
	//��С����
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