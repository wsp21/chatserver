# 聊天服务器

## 项目介绍

1. **环境准备**：win10 +Ubuntu+vscode

2. **项目准备**：Msql+Nginx+Redis

3. **项目功能**：

   客户端：登录、注册、退出，登陆之后，添加好友、单聊、群聊、创建组、加入组、注销。

   服务端：转发消息、存储消息。

4. **项目结构：**

   bin可执行文件

   build中间编译文件

   include头文件

   src编译资源文件

   test测试文件

   thirdparty第三方库

   CMakeLists.txt Cmake识别文件

5. **Nginx**

   配置nginx.conf  

   添加tcp连接

   ```nginx
   #ngnix tcp loadbalance config
   stream {
       upstream MyServer{
           #hash $remote_addr consistent;#提供一致性哈希用于短连接
           #默认轮序
           server 127.0.0.1:6000 weight=1 max_fails=3 fail_timeout=30s;
           server 127.0.0.1:6002 weight=1 max_fails=3 fail_timeout=30s;
       }
       server {
           listen 127.0.0.1:8000;
           proxy_pass MyServer;
           #proxy_timeout 600s;
           proxy_connect_timeout 1s;
           tcp_nodelay on;
       }
   }
   ```

   **nginx操作**

   启动nginx

   ```shell
   cd nginx-1.12.2/
   cd /home/wsp/Downloads/nginx-1.16.0/objs
   ./nginx
   ```

   停止

   ```shell
   nginx -s stop
   ```

   重启

   ```shell
   nginx -c /etc/nginx/nginx.conf
   ./nginx -s reload
   ```

   查看

   ```shell
   netstat -tanp
   ```

   启动服务端

   ```shell
   ./ChatServer 127.0.0.1 6000
   ./ChatServer 127.0.0.1 6002
   ```

   登录客户端

   ```shell
   ./ChatClient 127.0.0.1 8000
   ```

   异常关闭

   ```shell
   lsof -i:6000#查看6000端口
   kill pidnum
   ```

6. **创建数据库**

   ```sql
   CREATE TABLE `user` (
     `id` int(11) NOT NULL AUTO_INCREMENT,
     `name` varchar(50) DEFAULT NULL,
     `password` varchar(50) DEFAULT NULL,
     `state` enum('online','offline') CHARACTER SET latin1 DEFAULT 'offline',
     PRIMARY KEY (`id`),
     UNIQUE KEY `name` (`name`)
   ) ENGINE=InnoDB AUTO_INCREMENT=22 DEFAULT CHARSET=utf8;
   
   CREATE TABLE `friend` (
     `userid` int(11) NOT NULL,
     `friendid` int(11) NOT NULL,
     KEY `userid` (`userid`,`friendid`)
   ) ENGINE=InnoDB DEFAULT CHARSET=utf8;
   
   CREATE TABLE `allgroup` (
     `id` int(11) NOT NULL AUTO_INCREMENT,
     `groupname` varchar(50) CHARACTER SET latin1 NOT NULL,
     `groupdesc` varchar(200) CHARACTER SET latin1 DEFAULT '',
     PRIMARY KEY (`id`),
     UNIQUE KEY `groupname` (`groupname`)
   ) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
   
   CREATE TABLE `groupuser` (
     `groupid` int(11) NOT NULL,
     `userid` int(11) NOT NULL,
     `grouprole` enum('creator','normal') CHARACTER SET latin1 DEFAULT NULL,
     KEY `groupid` (`groupid`,`userid`)
   ) ENGINE=InnoDB DEFAULT CHARSET=utf8;
   
   CREATE TABLE `offlinemessage` (
     `userid` int(11) NOT NULL,
     `message` varchar(500) NOT NULL
   ) ENGINE=InnoDB DEFAULT CHARSET=latin1;
   ```

7. **测试**

   ```shell
   {"msgid":1,"id":45,"password":"123456"}
   {"msgid":1,"id":22,"password":"123456"}
   {"msgid":4,"name":"wei","password":"123456"}//注册
   {"msgid":1,"id":22,"password":"123456"}//登录
   {"msgid":1,"id":23,"password":"123456"}//登录
   {"msgid":6,"id":22,"from":"wsp","toid":23,"msg":"hello!"}//一对一聊天
   {"msgid":6,"id":23,"from":"wei","toid":22,"msg":"嗨！"}//一对一聊天回复
   {"msgid":7,"id":22,"friendid":23}//添加好友
   ```

   





------



## 其他

### git操作

**创建仓库**

- git clone 仓库地址
- mv 本地文件 *.git
- git status//查看情况
- git add .//添加到暂存区
- git commit -m "项目提交描述"
- git push origin main//提交到远程主分支
