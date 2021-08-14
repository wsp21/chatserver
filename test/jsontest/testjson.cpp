#include <iostream>
#include "json.hpp"
#include<string>
using json = nlohmann::json;
using namespace std;

//json序列化
string func1(){
    json js;
    js["msg_type"]="int";
    js["value"]=2;  
    string res=js.dump();
    //cout<<res.c_str()<<endl;
    return res;
}

int main() {
    string recv_buf=func1();
    //数据反序列化 
    json jsbuf=json::parse(recv_buf);
    cout<<jsbuf["msg_type"]<<endl;
    cout<<jsbuf["value"]<<endl;
    return 0;
}