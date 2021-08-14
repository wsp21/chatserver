#include "chatserver.hpp"
#include"json.hpp"
#include "chatservice.hpp"
#include <functional>

using namespace std;
using namespace placeholders;
using json=nlohmann::json;

ChatServer::ChatServer(EventLoop *loop,               //事件循环
                       const InetAddress &listenAddr, //IP+Port
                       const string &nameArg)         //服务器名称
    : _server(loop, listenAddr, nameArg),
      _loop(loop)
{
    //给服务器注册用户连接的创建和断开回调
    _server.setConnectionCallback(std::bind(&ChatServer::onConnection, this, _1)); //&ChatServer::onConnection,this传递指针,_1函数参数占位符

    //给服务器注册用户读写事件回调
    _server.setMessageCallback(std::bind(&ChatServer::onMessage, this, _1, _2, _3));

    //设置服务器端的线程数量  1个I/O线程 3个工作线程
    _server.setThreadNum(4);
}

//开启事件循环
void ChatServer::start()
{
    _server.start();
}

//处理用户连接的创建和断开  epoll listenfd accept
void ChatServer::onConnection(const TcpConnectionPtr &conn)
{
    //判断是否连接成功
    if (!conn->connected())
    {
        //网络异常断开
        chatservice::instance()->clientCloseException(conn);
        conn->shutdown();
    }
}
//处理用户读写事件
void ChatServer::onMessage(const TcpConnectionPtr &conn, //连接
                           Buffer *Buffer,               //缓冲区
                           Timestamp time)               //接受数据的时间信息
{
    //json反序列化
    string buf =Buffer->retrieveAllAsString();
    json js=json::parse(buf);

    auto msgHandler = chatservice::instance()->getHandler(js["msgid"].get<int>());
   
    //回调消息绑定好的事件处理器，来执行相应的业务处理
    msgHandler(conn,js,time);
}


