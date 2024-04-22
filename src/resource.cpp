#include "resource.h"

Resource::~Resource() {} //Yami析构函数用于清理资源

Resource::Resource(int value1, const std::string& strValue, int value2) {//Yami实现构造函数的定义
    dataInt = std::make_unique<int>(value1);
    dataStr = std::make_unique<std::string>(strValue);
}

int Resource::doSomethingInt() {//Yami实现类方法定义的具体实现
    return *dataInt;
}

std::string& Resource::getStringValue() {//Yami实现类方法定义的具体实现
    return *dataStr;
}
