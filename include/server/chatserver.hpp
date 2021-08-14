#ifndef CHATSERVER_H
#define CHATSERVER_H


#include<muduo/net/TcpServer.h>
#include<muduo/net/EventLoop.h>

using namespace muduo;
using namespace muduo::net;

//聊天服务器主类
class ChatServer{
public:
    ChatServer(EventLoop* loop,//事件循环
            const InetAddress& listenAddr,//IP+Port
            const string& nameArg);//服务器名称

    //启动
    void start();
private:
    //处理用户连接的创建和断开  epoll listenfd accept
    void onConnection(const TcpConnectionPtr& conn);

    //处理用户读写事件
    void onMessage(const TcpConnectionPtr& conn,//连接
                            Buffer* Buffer,//缓冲区
                            Timestamp time);//接受数据的时间信息

    TcpServer _server; //服务器类对象
    EventLoop *_loop;  //事件循环指针

};




#endif