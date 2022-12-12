#pragma once
#include<iostream>
using namespace std;
class Fraction
{
    //重载+运算符
    friend Fraction operator+(const Fraction& frac1, const Fraction& frac2); 

    //重载-运算符
    friend Fraction operator-(const Fraction& frac1, const Fraction& frac2); 

    //重载*运算符
    friend Fraction operator*(const Fraction& frac1, const Fraction& frac2); 

    //重载/运算符
    friend Fraction operator/(const Fraction& frac1, const Fraction& frac2); 

    //重载==运算符
    friend bool operator==(Fraction frac1, Fraction frac2);                 

    //重载>运算符
    friend bool operator>(const Fraction& frac1, const Fraction& frac2);    

    //重载<运算符
    friend bool operator<(const Fraction& frac1, const Fraction& frac2);     

    //重载<<运算符
    friend ostream& operator<<(ostream& out, const Fraction& frac);         

    //重载>>运算符
    friend istream& operator>>(istream& in, Fraction& frac);   

    //对分数数组排序
    friend void sortFraction(Fraction frac[], int lenth);     //参数列表自行设计

public:
    //无参造函数
    Fraction();     

    //带参造函数
    Fraction(int n, int d);          

    //复制造函数
    Fraction(const Fraction& f);

    //设置分数的分子和分母
    void setFraction(int n, int d);  

    //获取分数的分子
    int getNumer();                  

    //获取分数的分母
    int getDeno();

    //当前分数约分
    void RdcFrc();  

    //显示分数
    void Display();

    //析构函数
    ~Fraction();

private:
    //分子
    int numer; 

    //分母    
    int deno; 
};
