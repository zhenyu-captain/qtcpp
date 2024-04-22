#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <memory>


class Resource {
public:
    //初始化区域
    Resource(int value1, const std::string& strValue, int value2 = 0); //Yami构造函数：接受一个整数、一个字符串引用和一个可选的整数，默认初始化对象
    ~Resource(); // Yami析构函数：清理资源和释放内存


    //方法区
    int doSomethingInt(); //Yami成员函数：执行某种操作并返回一个整数
    std::string& getStringValue(); //Yami成员函数：返回一个字符串引用


    //变量区
    std::unique_ptr<int> dataInt; //Yami成员变量：指向整数的独占指针
    std::unique_ptr<std::string> dataStr; //Yami成员变量：指向字符串的独占指针
};

#endif
