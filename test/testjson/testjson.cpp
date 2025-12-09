#include "json.hpp"
using json=nlohmann::json;
#include<iostream>
#include<vector>
#include<map>
using namespace std;
//序列化
string func1(){
    json js;
    js["msg_tytpe"]=2;
    js["from"]="张三";
    js["to"]="李四";
    js["msg"]="what are you doing";
    //cout<<js<<endl;
    string sendBuf=js.dump();
    return sendBuf;
}
//序列化2
void func2(){
    json js;
    //添加数组
    js["id"]={1,2,3,4,5};
    //添加key-value
    js["name"]="zhangsan";
    //添加对象
    js["msg"]["zhangsan"]="hello world";
    js["msg"]["liu shuo"]="hello china";
    cout<<js<<endl;
}
int main(){
    string recvBuf=func1();
    json jsBuf=json::parse(recvBuf);
    cout<<"序列化:"<<recvBuf<<endl;
    cout<<"反序列化:"<<jsBuf;
}