#ifndef CHATSERVICE_H
#define CHATSERVICE_H

#include <unordered_map>
#include <functional>
#include <muduo/net/TcpServer.h>
#include <mutex>

#include "offlinemessagemodel.hpp"
#include "friendmodel.hpp"
#include "groupmodel.hpp"
#include "usermodel.hpp"
#include "json.hpp"
#include "redis.hpp"

using namespace muduo;
using namespace muduo::net;
using namespace std;

using json = nlohmann::json;
//回调的方法类型
using MsgHandler = std::function<void(const TcpConnectionPtr &conn, json &js, Timestamp)>;

//聊天服务器业务类
class chatservice
{
private:
    chatservice();
    
    //互斥锁保证_userConnMap线程安全
    mutex _connMutex;

    //存储
    unordered_map<int, MsgHandler> _msgHandlerMap;//存储消息id和对应方法
    unordered_map<int, TcpConnectionPtr> _userConnMap;// 存储在线用户的通信连接
   
    //操作接口
    UserModel _userModel; //数据操作对象
    OfflineMsgModel _offlineMsgModel;//离线存储对象
    FriendModel _friendModel;//好友信息表
    GroupModel _groupModel;//群组信息的操作

    // redis操作对象
    Redis _redis;
    
public:
    //获取单例对象的接口函数
    static chatservice *instance();
    //获取消息对应的处理器
    MsgHandler getHandler(int msgid);

    //登录
    void login(const TcpConnectionPtr &conn, json &js, Timestamp time);
    //注册
    void reg(const TcpConnectionPtr &conn, json &js, Timestamp time);
    
    //一对一聊天
    void oneChat(const TcpConnectionPtr &conn, json &js, Timestamp time);
    //添加好友
    void addFriend(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 创建群组业务
    void createGroup(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 加入群组业务
    void addGroup(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 群组聊天业务
    void groupChat(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 处理注销业务
    void loginout(const TcpConnectionPtr &conn, json &js, Timestamp time);

    // 从redis消息队列中获取订阅的消息
    void handleRedisSubscribeMessage(int, string);

    // 处理客户端异常退出
    void clientCloseException(const TcpConnectionPtr &conn);
    //服务器异常重置
    void reset();
};

#endif