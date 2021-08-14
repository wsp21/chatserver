#include"chatserver.hpp"
#include<iostream>
#include<signal.h>
#include"chatservice.hpp"

using namespace std;

//处理客户端和服务端异常中断，重置用户状态
void resetHandler(int){
    chatservice::instance()->reset();
    exit(0);
}

int main(int argc, char **argv){
    if (argc < 3)
    {
        cerr << "command invalid! example: ./ChatServer 127.0.0.1 6000" << endl;
        exit(-1);
    }

    // 解析通过命令行参数传递的ip和port
    char *ip = argv[1];
    uint16_t port = atoi(argv[2]);

    //接受异常信号
    signal(SIGINT,resetHandler);


    EventLoop loop;
    InetAddress addr(ip,port);
    ChatServer server(&loop,addr,"ChatServer");

    server.start();//listenfd epoll_ctl=>epoll 

    loop.loop();//epoll_wait()以阻塞方式等待新用户连接，已连接用户的读写事件

    return 0;
}