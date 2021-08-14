#include<muduo/net/TcpServer.h>
#include<muduo/net/EventLoop.h>
#include<iostream>
#include<functional>
#include<string>

using namespace std;
using namespace muduo;
using namespace muduo::net;
using namespace placeholders;

class ChatServer{
public:
    ChatServer(EventLoop* loop,//事件循环
            const InetAddress& listenAddr,//IP+Port
            const string& nameArg)//服务器名称
            :_server(loop,listenAddr,nameArg),
            _loop(loop){
                //给服务器注册用户连接的创建和断开回调
                _server.setConnectionCallback(std::bind(&ChatServer::onConnection,this,_1));//&ChatServer::onConnection,this传递指针,_1函数参数占位符

                //给服务器注册用户读写事件回调
                _server.setMessageCallback(std::bind(&ChatServer::onMessage,this,_1,_2,_3));

                //设置服务器端的线程数量  1个I/O线程 3个工作线程
                _server.setThreadNum(4);

                
            }

            //开启事件循环
            void start(){
                _server.start();
            }
private:
    //处理用户连接的创建和断开  epoll listenfd accept
    void onConnection(const TcpConnectionPtr& conn){
        //判断是否连接成功
        if(conn->connected()){
            cout<<conn->peerAddress().toIpPort()<<"->"<<conn->localAddress().toIpPort()<<"state:online"<<endl;
        }
        else{
            cout<<conn->peerAddress().toIpPort()<<"->"<<conn->localAddress().toIpPort()<<"state:offline"<<endl;
            conn->shutdown();
            //_loop->quit();
        }
    }
    //处理用户读写事件
    void onMessage(const TcpConnectionPtr& conn,//连接
                            Buffer* Buffer,//缓冲区
                            Timestamp time)//接受数据的时间信息
    {
        string buf =Buffer->retrieveAllAsString();
        cout<<"recv data:"<<buf<<"time:"<<time.toString()<<endl;
        conn->send(buf);//返回输入内容
    }
    TcpServer _server;
    EventLoop *_loop;

};

int main(){
    EventLoop loop;
    InetAddress addr("127.0.0.1",6000);
    ChatServer server(&loop,addr,"ChatServer");

    server.start();//listenfd epoll_ctl=>epoll 

    loop.loop();//epoll_wait()以阻塞方式等待新用户连接，已连接用户的读写事件


    return 0;
}