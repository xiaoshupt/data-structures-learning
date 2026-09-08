#pragma once

#include<iostream>

const int MaxLen = 100;

// 顺序表
template <class ElemType>
class SeqList
{
    private:
        ElemType data[MaxLen];
        int length;    
    public:
        SeqList(){length = 0;}        // 无参构造
        SeqList(ElemType a[], int n); // 有参构造
        ~SeqList(){}
        int GetLen();
        ElemType GetElem(int i);
        int Locate(ElemType x);
        void InsElem(int i, ElemType x);
        ElemType DelElem(int i);
        int DelElem2(ElemType x);
        void Display();
};


// 用数组初始化顺序表（传有参）
template <class ElemType>
SeqList <ElemType>::SeqList(ElemType a[], int n)
{
    // n 不能超过顺序表的最大容量
    if (n > MaxLen) 
        throw"参数非法";
    for(int i = 0; i < n; i++)
        data[i] = a[i];
    length = n;    
}

// 获取指定位置的元素
template <class ElemType>
ElemType SeqList <ElemType>::GetElem(int i)
{
    // 对外位置从 1 开始，数组下标从 0 开始
    if(i < 0 || i > length)
        std::cout << "Error" << std::endl;
    else 
        return data[i];
}

// 查找元素的位置
template <class ElemType>
int SeqList <ElemType>::Locate(ElemType x)
{
    // 查找元素，返回位置；找不到返回 0
    int i = 0 ;
    while(i < length && data[i] != x)
        i++;
    if(i < length)
        return i+1;
    else 
        return 0;
}

// 在指定位置插入元素
template <class ElemType>
void SeqList <ElemType>::InsElem(int i, ElemType x)
{
    // 插入前检查是否上溢，以及位置是否合法
    if(length >= MaxLen)
        throw "上溢！";
    if (i < 1 || i > length + 1)
        throw "位置非法";
    // 从后向前移动，避免覆盖原有元素
    for (int j = length; j >= i; j--)
        data[j] = data[j - 1];
    data[i-1] = x;
    length ++;
}

// 删除指定位置的元素，并返回被删除的元素
template <class ElemType>
ElemType SeqList <ElemType>::DelElem(int i)
{
    ElemType e;
    // 删除前检查是否下溢，以及位置是否合法
    if(length == 0)
        throw "下溢！";
    if (i < 1 || i > length + 1)
        throw "位置非法";
    e = data[i-1];
    for(int j = i; j<length; j++)
        data[j-1] = data[j];
    length--;
    return e;
}

// 按值删除第一个匹配的元素
template <class ElemType>
int SeqList <ElemType>::DelElem2(ElemType x)
{
    // 按值查找并删除第一个匹配的元素
    int i = 0;
    while (i < length && data[i] != x)
        i++;

    if (i == length)
        return 0;

    // 删除后将后续元素前移
    for (int j = i; j < length - 1; j++)
        data[j] = data[j + 1];

    length--;
    return i + 1;
}

// 输出顺序表中的所有元素
template <class ElemType>
void SeqList <ElemType>::Display()
{
    // 输出当前有效元素
    for(int i = 0; i < length; i++)
        std::cout<< data[i] << " ";
    std::cout<<std::endl;
}
