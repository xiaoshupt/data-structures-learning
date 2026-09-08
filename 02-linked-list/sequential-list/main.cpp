#include "SeqList.h"
#include <iostream>

int main()
{
    try
    {
        // 初始化顺序表
        int values[] = {10, 20, 30, 40};
        SeqList<int> list(values, 4);

        // 显示初始内容
        std::cout << "初始顺序表：";
        list.Display();

        // 测试查找功能
        std::cout << "30 的位置：" << list.Locate(30) << std::endl;
        std::cout << "查找 99 的结果：" << list.Locate(99) << std::endl;

        // 测试插入功能
        list.InsElem(2, 15);
        std::cout << "在第 2 个位置插入 15 后：";
        list.Display();

        // 测试按位置删除
        int deleted = list.DelElem(3);
        std::cout << "删除第 3 个元素（删除了 " << deleted << "）后：";
        list.Display();

        // 测试按值删除
        int deletedPosition = list.DelElem2(40);
        std::cout << "删除元素 40（原位置为 "
                  << deletedPosition << "）后：";
        list.Display();
    }
    catch (const char* error)
    {
        std::cout << "发生错误：" << error << std::endl;
    }

    return 0;
}