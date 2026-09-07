#pragma once

#include<iostream>

const int MaxLen = 100;
template <class ElemType>
class SeqList
{
    private:
        ElemType data[MaxLen];
        int length;
    public:
        SeqList(){length = 0;}
        SeqList(ElemType a[], int n);  //有参 无参
        ~SeqList(){}
        int GetLen();
        ElemType GetElem(int i);
        int Locate(ElemType x);
        void InsElem(int i, ElemType x);
        ElemType DelElem(int i);
        int DelElem2(ElemType x);
        void Display();
};


template <class ElemType>
SeqList <ElemType>::SeqList(ElemType a[], int n)
{
    if (n > MaxLen) 
        throw"参数非法";
    for(int i = 0; i < n; i++)
        data[i] = a[i];
    length = n;    
}

template <class ElemType>
ElemType SeqList <ElemType>::GetElem(int i)
{
    if(i < 0 || i > length)
        std::cout << "Error" << std::endl;
    else 
        return data[i];
}

template <class ElemType>
int SeqList <ElemType>::Locate(ElemType x)
{
    int i = 0 ;
    while(i < length && data[i] != x)
        i++;
    if(i < length)
        return i+1;
    else 
        return 0;
}

template <class ElemType>
void SeqList <ElemType>::InsElem(int i, ElemType x)
{
    if(length >= MaxLen)
        throw "上溢！";
    if (i < 1 || i > length + 1)
        throw "位置非法";
    for (int j = length; j >= i; j--)
        data[j] = data[j - 1];
    data[i-1] = x;
    length ++;
}

template <class ElemType>
ElemType SeqList <ElemType>::DelElem(int i)
{
    ElemType e;
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

template <class ElemType>
int SeqList <ElemType>::DelElem2(ElemType x)
{
    int i = 0;
    while (i < length && data[i] != x)
        i++;

    if (i == length)
        return 0;

    for (int j = i; j < length - 1; j++)
        data[j] = data[j + 1];

    length--;
    return i + 1;
}

template <class ElemType>
void SeqList <ElemType>::Display()
{
    for(int i = 0; i < length; i++)
        std::cout<< data[i] << " ";
    std::cout<<std::endl;
}
