#pragma once
#include<iostream>
using namespace std;
class Fraction
{
    //����+�����
    friend Fraction operator+(const Fraction& frac1, const Fraction& frac2); 

    //����-�����
    friend Fraction operator-(const Fraction& frac1, const Fraction& frac2); 

    //����*�����
    friend Fraction operator*(const Fraction& frac1, const Fraction& frac2); 

    //����/�����
    friend Fraction operator/(const Fraction& frac1, const Fraction& frac2); 

    //����==�����
    friend bool operator==(Fraction frac1, Fraction frac2);                 

    //����>�����
    friend bool operator>(const Fraction& frac1, const Fraction& frac2);    

    //����<�����
    friend bool operator<(const Fraction& frac1, const Fraction& frac2);     

    //����<<�����
    friend ostream& operator<<(ostream& out, const Fraction& frac);         

    //����>>�����
    friend istream& operator>>(istream& in, Fraction& frac);   

    //�Է�����������
    friend void sortFraction(Fraction frac[], int lenth);     //�����б��������

public:
    //�޲��캯��
    Fraction();     

    //�����캯��
    Fraction(int n, int d);          

    //�����캯��
    Fraction(const Fraction& f);

    //���÷����ķ��Ӻͷ�ĸ
    void setFraction(int n, int d);  

    //��ȡ�����ķ���
    int getNumer();                  

    //��ȡ�����ķ�ĸ
    int getDeno();

    //��ǰ����Լ��
    void RdcFrc();  

    //��ʾ����
    void Display();

    //��������
    ~Fraction();

private:
    //����
    int numer; 

    //��ĸ    
    int deno; 
};
