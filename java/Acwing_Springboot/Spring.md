# Spring

## 1.项目设计

![image-20230304160833103](img/image-20230304160833103.png)

## 2.配置git环境与项目创建

### 公钥

```bash
Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring
$ ssh-keygen
Generating public/private rsa key pair.
Enter file in which to save the key (/c/Users/Administrator/.ssh/id_rsa):
/c/Users/Administrator/.ssh/id_rsa already exists.
Overwrite (y/n)? n

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring
$ cat /c/Users/Administrator/.ssh/id_rsa.pub
ssh-rsa x...... Administrator@DESKTOP-0O633M1

```

复制到 acgit 平台中，保存公钥

### 本地创建项目

```bash
Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring
$ mkdir kob

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring
$ ls
kob/

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring
$ cd kob

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob
$ git init
Initialized empty Git repository in C:/Users/Administrator/Desktop/spring/kob/.git/

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ ls

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ ls -a
./  ../  .git/

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ vim README.md

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git status
On branch master

No commits yet

Untracked files:
  (use "git add <file>..." to include in what will be committed)

        README.md

nothing added to commit but untracked files present (use "git add" to track)

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git add .
warning: LF will be replaced by CRLF in README.md.
The file will have its original line endings in your working directory

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git status
On branch master

No commits yet

Changes to be committed:
  (use "git rm --cached <file>..." to unstage)

        new file:   README.md


Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git commit -m "Init project"
[master (root-commit) f07d5e3] Init project
 1 file changed, 1 insertion(+)
 create mode 100644 README.md

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git status
On branch master
nothing to commit, working tree clean

```

### 保存到云端

#### 创建仓库

![image-20230301130255003](img/image-20230301130255003.png)

![image-20230301130313760](img/image-20230301130313760.png)

![image-20230301130349135](img/image-20230301130349135.png)

![image-20230301130609860](img/image-20230301130609860.png)



### 本地设置 git config

```bash
Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git config user.email "1063615427@qq.com"

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git config user.name "you huang"


```



### push 到云端

![image-20230301131401483](img/image-20230301131401483.png)

```bash
Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git remote add origin git@git.acwing.com:youhuang/kob.git

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git push -u origin main
error: src refspec main does not match any.
error: failed to push some refs to 'git@git.acwing.com:youhuang/kob.git'

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git push -u origin master
The authenticity of host 'git.acwing.com (47.93.222.173)' can't be established.
ECDSA key fingerprint is SHA256:OxENYBI4n6Nd8yOqmEdMazWuvBldKlP6ZJnOAAbCaeM.
Are you sure you want to continue connecting (yes/no)? yes
Warning: Permanently added 'git.acwing.com,47.93.222.173' (ECDSA) to the list of known hosts.
Enumerating objects: 3, done.
Counting objects: 100% (3/3), done.
Writing objects: 100% (3/3), 239 bytes | 239.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0)
To git.acwing.com:youhuang/kob.git
 * [new branch]      master -> master
Branch 'master' set up to track remote branch 'master' from 'origin'.


```

本地看不到 .git 参考[在 Windows 中查看隐藏的文件和文件夹 \- Microsoft 支持](https://support.microsoft.com/zh-cn/windows/%E5%9C%A8-windows-%E4%B8%AD%E6%9F%A5%E7%9C%8B%E9%9A%90%E8%97%8F%E7%9A%84%E6%96%87%E4%BB%B6%E5%92%8C%E6%96%87%E4%BB%B6%E5%A4%B9-97fbc472-c603-9d90-91d0-1166d1d9f4b5)

刷新 acgit 出现修改后的界面

![image-20230301131454363](img/image-20230301131454363.png)

即成功。

### 克隆项目

```bash
Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ ls
README.md

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ cd ../

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring
$ ls
kob/

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring
$ mkdir tmp

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring
$ cd tmp

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/tmp
$ ls

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/tmp
$ git clone git@git.acwing.com:youhuang/kob.git
Cloning into 'kob'...
remote: Enumerating objects: 3, done.
remote: Counting objects: 100% (3/3), done.
remote: Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
Receiving objects: 100% (3/3), done.
Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/tmp
$ ls
kob/

```

### 修改项目并 push 到云端

```bash
Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/tmp
$ cd ../

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring
$ ls
kob/  tmp/

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring
$ cd kob

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ ls
README.md

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ vim test.txt

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git add .
warning: LF will be replaced by CRLF in test.txt.
The file will have its original line endings in your working directory

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git commit -m "test push"
[master f07d9a0] test push
 1 file changed, 1 insertion(+)
 create mode 100644 test.txt

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git status
On branch master
Your branch is ahead of 'origin/master' by 1 commit.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git push
Enumerating objects: 4, done.
Counting objects: 100% (4/4), done.
Delta compression using up to 8 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (3/3), 272 bytes | 272.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0)
To git.acwing.com:youhuang/kob.git
   f07d5e3..f07d9a0  master -> master

```

### pull 到本地

```bash
Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ cd ../tmp

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/tmp
$ ls
kob/

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/tmp
$ git pull
fatal: not a git repository (or any of the parent directories): .git

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/tmp
$ cd kob

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/tmp/kob (master)
$ ls
README.md

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/tmp/kob (master)
$ git pull
remote: Enumerating objects: 4, done.
remote: Counting objects: 100% (4/4), done.
remote: Compressing objects: 100% (2/2), done.
remote: Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
Unpacking objects: 100% (3/3), done.
From git.acwing.com:youhuang/kob
   f07d5e3..f07d9a0  master     -> origin/master
Updating f07d5e3..f07d9a0
Fast-forward
 test.txt | 1 +
 1 file changed, 1 insertion(+)
 create mode 100644 test.txt

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/tmp/kob (master)
$ ls
README.md  test.txt


```

### 删除 test 并在云端同步

```bash
Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/tmp/kob (master)
$ rm test.txt

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/tmp/kob (master)
$ ls
README.md

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/tmp/kob (master)
$ git add .

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/tmp/kob (master)
$ git status
On branch master
Your branch is up to date with 'origin/master'.

Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

        deleted:    test.txt


Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/tmp/kob (master)
$ git commit -m "delete test"
[master b19d7d3] delete test
 1 file changed, 1 deletion(-)
 delete mode 100644 test.txt

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/tmp/kob (master)
$ git push
Enumerating objects: 3, done.
Counting objects: 100% (3/3), done.
Delta compression using up to 8 threads
Compressing objects: 100% (1/1), done.
Writing objects: 100% (2/2), 229 bytes | 229.00 KiB/s, done.
Total 2 (delta 0), reused 1 (delta 0)
To git.acwing.com:youhuang/kob.git
   f07d9a0..b19d7d3  master -> master

```



```bash
Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/tmp/kob (master)
$ cd ../../

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring
$ ls
kob/  tmp/

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring
$ cd kob

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git pull
remote: Enumerating objects: 3, done.
remote: Counting objects: 100% (3/3), done.
remote: Compressing objects: 100% (1/1), done.
remote: Total 2 (delta 0), reused 0 (delta 0), pack-reused 0
Unpacking objects: 100% (2/2), done.
From git.acwing.com:youhuang/kob
   f07d9a0..b19d7d3  master     -> origin/master
Updating f07d9a0..b19d7d3
Fast-forward
 test.txt | 1 -
 1 file changed, 1 deletion(-)
 delete mode 100644 test.txt

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ ls
README.md

```

### 查看历史版本

![image-20230301132956271](img/image-20230301132956271.png)

![image-20230301133041359](img/image-20230301133041359.png)

![image-20230301133055690](img/image-20230301133055690.png)

看到第二个版本的代码



## 3.创建项目后端

### 前后端分离与不分离

#### 前后端不分离

![image-20230301134040400](img/image-20230301134040400.png)

html 在服务器端生成： 前后端不分离

#### 前后端分离

![image-20230301135124910](img/image-20230301135124910.png)

前后端分离的好处：同一个后端支持多个端口



负责向用户返回数据的控制器：controller

### 创建

![image-20230301135700796](img/image-20230301135700796.png)

![image-20230301135830641](img/image-20230301135830641.png)

这里y总没有选到 kob ，而是选了 spring 导致后面 1h25min 时重新移动项目

![image-20230301140019396](img/image-20230301140019396.png)

连不上可以换成阿里云的源，这里我先不换试试（注：最后还是换了）

https://start.spring.io/加载慢的话，可以换成：https://start.aliyun.com

![image-20230301140147259](img/image-20230301140147259.png)

![image-20230301140156100](img/image-20230301140156100.png)



![image-20230301140533963](img/image-20230301140533963.png)

![image-20230301140540290](img/image-20230301140540290.png)

结果还是弹，将 java 版本从 11 改成 8 。

![image-20230301140529504](img/image-20230301140529504.png)



![image-20230301140748479](img/image-20230301140748479.png)

Thymeleaf 用于演示前后端不分离的写法，其他用不上

#### 网络问题无法通过原地址创建项目的解决方法

```
Spring Initializr
Error: Cannot download 'https://start.spring.io/starter.zip?type=maven-project&bootVersion=3.0.3&groupId=com.example&artifactId=demo&name=demo&version=0.0.1-SNAPSHOT&language=java&packageName=com.example.demo&javaVersion=1.8&packaging=jar&description=demo&dependencies=thymeleaf&dependencies=web': connect timed out
```

[Intellij IDEA 设置代理_喵代王-香菜的博客-CSDN博客](https://blog.csdn.net/chen15369337607/article/details/103822464)

![image-20230301141503390](img/image-20230301141503390.png)

7890 替换为自己的端口，懂的都懂

***以下为失败案例，请跳过***

创建成功（个鬼啊）！

![image-20230301141937427](img/image-20230301141937427.png)

这里直接没有选择 spring 的版本，并且可能因为是新版的原因，将 java 版本也切换到了17。。。

等了一会发现版本是 3 。。

![image-20230301142727605](img/image-20230301142727605.png)

>   来日方长hh   2个月前       22           回复
>   踩坑避雷：如果用的是jdk8，那么springboot的版本要小于3，
>
>   AIK64   2个月前       3           回复
>   SpringBoot 3.0 最低要求是 Java 17，所以需要使用 2.x 的版本。另外最好按照楼下大佬给出的教程对Maven3.8.6进行本地配置。
>
>   ——Acwing

放弃，回到阿里源。

#### 阿里源

y总用的是 2.3.7release版

**springboot的release版本和其他版本区别**



>   Spring Boot是一个基于Spring框架的快速开发框架，由于其快速上手和易用性得到了广泛应用。Spring Boot按照发行版本的时间周期分为以下几个版本：
>
>   1.  Snapshot版本：开发中的预览版，包含最新的功能和改进，但是不稳定，不能用于生产环境。
>   2.  Milestone版本：开发中的阶段性版本，比Snapshot版本更加稳定，包含所有计划实现的功能和改进。
>   3.  RC（Release Candidate）版本：候选版本，表示该版本已经非常接近最终版本，如果没有发现任何问题，该版本将成为正式版本。
>   4.  GA（General Availability）版本：正式版本，该版本已经经过了充分的测试和验证，并被确认为稳定可用的版本，可以放心使用。
>   5.  SR（Service Release）版本：补丁版本，用于修复已知的漏洞和问题。
>
>   在正式版本中，通常会有三个版本号，如1.5.6.RELEASE，其中RELEASE是指该版本是一个正式的、可供使用的版本。这个版本的内容是经过严格测试和验证的，是一个稳定的版本。而其他两个版本号，1.5是主版本号，6是次版本号。通常情况下，主版本号的变化意味着在新版本中可能有一些不向后兼容的API改变；次版本号的变化意味着新版本中增加了一些新功能，但是与上一个版本是兼容的；而第三个版本号则表示一些小的变化或者是修复bug。
>
>   总之，对于Spring Boot框架来说，RELEASE版本是一个稳定可用的版本，而其他版本则是处于开发、测试或者修复漏洞的状态。
>
>   

我没找到，用了 2.3.12 release版

![image-20230301143510236](img/image-20230301143510236.png)

![image-20230301145553308](img/image-20230301145553308.png)

#### 打开

Console中出现

```

2023-03-01 14:52:45.538  INFO 18092 --- [           main] com.example.backend.BackendApplication   : Started BackendApplication in 3.099 seconds (JVM running for 5.783)

```

说明在 [127.0.0.1:8080](http://127.0.0.1:8080/) 中打开了 127.0.0.1 等价于 localhost 。 

浏览器打开 127.0.0.1:8080 中显示

```
Whitelabel Error Page
This application has no explicit mapping for /error, so you are seeing this as a fallback.

Wed Mar 01 14:53:06 CST 2023
There was an unexpected error (type=Not Found, status=404).
```

即打开成功



##### 新建一个包

![image-20230301150024546](img/image-20230301150024546.png)

![image-20230301150113870](img/image-20230301150113870.png)

![image-20230301150147552](img/image-20230301150147552.png)

项目分为四大块：见 1.项目设计

##### 包中新建一个 pk 包

![image-20230301150321041](img/image-20230301150321041.png)

##### 包中新建一个类

![image-20230301150348605](img/image-20230301150348605.png)

##### 注解

![image-20230301150518130](img/image-20230301150518130.png)

```java
package com.example.backend.controller.pk;

import org.springframework.stereotype.Controller;

@Controller
public class IndexController {
}

```

##### 父目录

![image-20230301150643681](img/image-20230301150643681.png)

```
package com.example.backend.controller.pk;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
@RequestMapping
public class IndexController {
}

```

#####  Hello world 页面

![image-20230301151211188](img/image-20230301151211188.png)

![image-20230301151243607](img/image-20230301151243607.png)

html叫 index

```
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
</head>
<body>
<h1>Hello World!</h1>
</body>
</html>
```

让 pk 的 index 返回刚刚写的 Hello world 页面

IndexController.java

```java
package com.example.backend.controller.pk;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
@RequestMapping("/pk/")
public class IndexController {
    @RequestMapping("index/")
    public String index() {
        return "pk/index.html";
    }
}

```

重启，注意最后的 `/`

![image-20230301152028972](img/image-20230301152028972.png)

###### push

```bash
Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git status
On branch master
Your branch is up to date with 'origin/master'.

Untracked files:
  (use "git add <file>..." to include in what will be committed)

        backend/

nothing added to commit but untracked files present (use "git add" to track)

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git add .
warning: LF will be replaced by CRLF in backend/.gitignore.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in backend/.mvn/wrapper/MavenWrapperDownloader.java.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in backend/.mvn/wrapper/maven-wrapper.properties.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in backend/README.md.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in backend/mvnw.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in backend/mvnw.cmd.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in backend/pom.xml.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in backend/src/main/java/com/example/backend/BackendApplication.java.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in backend/src/main/resources/application.properties.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in backend/src/test/java/com/example/backend/BackendApplicationTests.java.
The file will have its original line endings in your working directory

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git commit -m "Hello World!"
[master 9ac8c05] Hello World!
 13 files changed, 785 insertions(+)
 create mode 100644 backend/.gitignore
 create mode 100644 backend/.mvn/wrapper/MavenWrapperDownloader.java
 create mode 100644 backend/.mvn/wrapper/maven-wrapper.jar
 create mode 100644 backend/.mvn/wrapper/maven-wrapper.properties
 create mode 100644 backend/README.md
 create mode 100644 backend/mvnw
 create mode 100644 backend/mvnw.cmd
 create mode 100644 backend/pom.xml
 create mode 100644 backend/src/main/java/com/example/backend/BackendApplication.java
 create mode 100644 backend/src/main/java/com/example/backend/controller/pk/IndexController.java
 create mode 100644 backend/src/main/resources/application.properties
 create mode 100644 backend/src/main/resources/templates/pk/index.html
 create mode 100644 backend/src/test/java/com/example/backend/BackendApplicationTests.java

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git push
Enumerating objects: 35, done.
Counting objects: 100% (35/35), done.
Delta compression using up to 8 threads
Compressing objects: 100% (21/21), done.
Writing objects: 100% (34/34), 53.82 KiB | 1.99 MiB/s, done.
Total 34 (delta 0), reused 0 (delta 0)
To git.acwing.com:youhuang/kob.git
   b19d7d3..9ac8c05  master -> master

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git status
On branch master
Your branch is up to date with 'origin/master'.

nothing to commit, working tree clean

```

##### 放入一个图片

![image-20230301152430733](img/image-20230301152430733.png)

![image-20230301152813827](img/image-20230301152813827.png)

![image-20230301152835324](img/image-20230301152835324.png)

以上是前后端不分离的写法



新建一个类

![image-20230301154602077](img/image-20230301154602077.png)

返回数据

```java
package com.example.backend.controller.pk;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController //return static?
@RequestMapping("/pk/")
public class BotInfoController {
    @RequestMapping("getbotinfo/")
    //write eht string below first
    public String getBotInfo(){
        return "hhhhh";
    }
}

```



![image-20230301155200821](img/image-20230301155200821.png)

```bash
Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git add .

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git commit -m "Separation of front-end and backend.Print hhhhhh"
[master af109b9] sSparation of front-end and backend..Print hhhhhh
 3 files changed, 17 insertions(+), 1 deletion(-)
 create mode 100644 backend/src/main/java/com/example/backend/controller/pk/BotInfoController.java
 create mode 100644 backend/src/main/resources/static/image/img.png

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git push
Enumerating objects: 33, done.
Counting objects: 100% (33/33), done.
Delta compression using up to 8 threads
Compressing objects: 100% (11/11), done.
Writing objects: 100% (19/19), 49.63 KiB | 4.13 MiB/s, done.
Total 19 (delta 1), reused 0 (delta 0)
To git.acwing.com:youhuang/kob.git
   9ac8c05..af109b9  master -> master

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$

```

##### git 查看上一次 commit

>   查看 Git 上一次 commit 的命令是：
>
>   ```
>   git show HEAD
>   ```
>
>   或者可以使用短选项：
>
>   ```
>   git show -1
>   ```
>
>   更多关于 `git show` 命令的使用可以查看官方文档：https://git-scm.com/docs/git-show

##### 返回一串字符串链表

页面

[127.0.0.1:8080/pk/getbotinfo/](http://127.0.0.1:8080/pk/getbotinfo/)

```java
package com.example.backend.controller.pk;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.LinkedList;
import java.util.List;

@RestController //return static?
@RequestMapping("/pk/")
public class BotInfoController {
    @RequestMapping("getbotinfo/")
    //write string below first
    /*
    public String getBotInfo() {
        return "hhhhh";
    }

     */
    public List<String> getBotInfo() {
        List<String> list = new LinkedList<>();
        list.add("sword");
        list.add("tiger");
        list.add("apple");
        return list;
    }

}

```



```
["sword","tiger","apple"]
```



java代码中List与LinkedList的区别与联系

>   在Java中，List是集合类接口，用于存储一组元素，提供了一些基本的操作方法，例如添加元素、删除元素、查找元素等，具体的实现类有ArrayList、LinkedList、Vector等。
>
>   LinkedList是List接口的一个具体实现类，它以双向链表的形式存储数据，因此支持高效的插入和删除操作，但随机访问元素的效率较低。
>
>   因此，List和LinkedList之间的区别在于实现方式，List是接口，由Java提供不同的实现类，而LinkedList是List的一个具体实现类，它的底层实现是基于双向链表的，支持高效的插入和删除操作，但不支持随机访问元素的操作。
>
>   [List \(Java SE 16 & JDK 16\)](https://docs.oracle.com/en/java/javase/16/docs/api/java.base/java/util/List.html)
>
>   [LinkedList \(Java SE 17 & JDK 17\)](https://docs.oracle.com/en/java/javase/17/docs/api/java.base/java/util/LinkedList.html)
>
>   在Java中，List和LinkedList都是用来存储元素集合的。然而，它们之间有一些区别。
>
>   List是一个接口，代表一个有序的元素集合。它允许重复元素，并且可以通过它们的索引访问元素。Java提供了几个List接口的实现，如ArrayList、LinkedList和Vector。
>
>   LinkedList是实现List接口的一个类。它表示一个链表数据结构，其中每个元素通过链接连接到下一个元素。它提供了一种有效地从列表的开头、结尾或中间插入和删除元素的方式。但是，在LinkedList中通过索引访问元素比在ArrayList中更慢。
>
>   ArrayList和LinkedList之间的主要区别在于它们的底层数据结构。ArrayList使用数组来存储其元素，这允许快速的随机访问，但插入和删除操作比较慢。另一方面，LinkedList使用双向链表来存储其元素，这允许快速的插入和删除，但随机访问速度较慢。
>
>   总之，List是一个接口，代表一个有序的元素集合，而LinkedList是一个使用链表数据结构实现List接口的类。LinkedList提供了有效的元素插入和删除，而ArrayList提供了有效的元素随机访问。

>   The book "Core Java" covers the List and LinkedList topics in Chapter 8: Collections.
>
>   The concept of `List` is introduced in Chapter 6 of "Core Java". In that chapter, the authors discuss the `Collection` framework, of which `List` is a part. They introduce the different types of collections, such as `List`, `Set`, and `Map`, and discuss the basic operations that are common to all collections. Then they move on to discuss the specific characteristics and features of each collection type, including `List`.

##### 返回一个Map

```java
package com.example.backend.controller.pk;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

@RestController //return static?
@RequestMapping("/pk/")
public class BotInfoController {
    @RequestMapping("getbotinfo/")
    //write string below first
    /*
    public String getBotInfo() {
        return "hhhhh";
    }

     */
    public Map<String> getBotInfo() {
        Map<String, String> map = new HashMap<>();
        map.put("name", "tiger");
        map.put("rating", "1500");
        return map;
    }

}

```

网页显示

```json
{"name":"tiger","rating":"1500"}
```



##### 返回a List of Map<String, String>

```java
package com.example.backend.controller.pk;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

@RestController //return static?
@RequestMapping("/pk/")
public class BotInfoController {
    @RequestMapping("getbotinfo/")
    //write string below first
    /*
    public String getBotInfo() {
        return "hhhhh";
    }

     */
    public List<Map<String, String>> getBotInfo() {
        List<Map<String, String>> list = new LinkedList<>();
        Map<String, String> bot1 = new HashMap<>();
        bot1.put("name", "tiger");
        bot1.put("rating", "1500");
        Map<String, String> bot2 = new HashMap<>();
        bot2.put("name", "apple");
        bot2.put("rating", "1800");
        list.add(bot1);
        list.add(bot2);
        return list;
    }

}

```

网页显示

```json
[{"name":"tiger","rating":"1500"},{"name":"apple","rating":"1800"}]
```

#### 修改端口

Vue的默认端口也是 8080

backend/src/main/resources/application.properties

```java
# åºç¨åç§°
spring.application.name=backend
# åºç¨æå¡ WEB è®¿é®ç«¯å£
server.port=8080
```

到这里，后端创建完成了。

## 4.创建项目前端

#### 安装 vue 环境

##### 安装 Nodejs

[Node\.js](https://nodejs.org/en/)

装 LTS 版的，Long Term Support。

为保证版本一致性，在 Other Downloads 中下载 16.15.1 LTS 版本。

[Index of /dist/](https://nodejs.org/dist/)中搜索 v16.15.1 下载 [node-v16.15.1-x64.msi ](https://nodejs.org/dist/v16.15.1/node-v16.15.1-x64.msi)

##### 安装 vue

[Vue官网](https://vuejs.org/)

##### 终端

Linux和Mac上可以用自带的终端。

Windows上推荐用powershell或者cmd。Git Bash有些指令不兼容。

安装@vue/cli

打开Git Bash，执行：

```powershell
npm i -g @vue/cli
```

```
PS C:\Windows\System32> npm i -g @vue/cli
npm WARN config global `--global`, `--local` are deprecated. Use `--location=global` instead.
npm WARN config global `--global`, `--local` are deprecated. Use `--location=global` instead.
......

PS C:\Windows\System32> vue -V
@vue/cli 5.0.8
PS C:\Windows\System32> vue ui
🚀  Starting GUI...
🌠  Ready on http://localhost:8000
```

可以打开，我用了最新版本。

在windows存在vue最新版本的情况下， 如何安装vue的旧版本？

如果执行后面的操作有bug，可能是最新版有问题，可以尝试安装早期版本，比如：

```powershell
npm i -g @vue/cli@4
```

###### Vue的安装问题

```powershell
npm ERR! code ENOENT
npm ERR! syscall spawn C:\Program Files\PowerShell\7\pwsh.exe
npm ERR! path C:\Users\Administrator\AppData\Roaming\npm\node_modules\@vue\cli\node_modules\@apollo\protobufjs
npm ERR! errno -4058
npm ERR! enoent spawn C:\Program Files\PowerShell\7\pwsh.exe ENOENT
npm ERR! enoent This is related to npm not being able to find a file.
npm ERR! enoent

npm ERR! A complete log of this run can be found in:
npm ERR!     C:\Users\Administrator\AppData\Local\npm-cache\_logs\2023-03-02T16_10_52_801Z-debug-0.log
```

[pwsh\.exe Not recognized, even after adding path? \- Microsoft Community Hub](https://techcommunity.microsoft.com/t5/windows-powershell/pwsh-exe-not-recognized-even-after-adding-path/m-p/3680174)

安装到后面，乱搞吧pwsh搞崩了。。学到了两种pwsh的不同

[Release v7\.3\.3 Release of PowerShell · PowerShell/PowerShell](https://github.com/PowerShell/PowerShell/releases/tag/v7.3.3)下载了最新版

##### Vue 的版本问题（可跳过）

**在windows存在vue最新版本的情况下， 如何安装vue的旧版本？ 可以同时安装多个版本吗？**

>   
>
>   可以通过使用npm来安装vue的旧版本，具体步骤如下：
>
>   1.  打开命令提示符或PowerShell窗口，并进入项目的根目录。
>
>   2.  输入以下命令安装指定版本的Vue：
>
>       ```
>       npm install vue@2.6.10
>       ```
>
>       其中，2.6.10是你想要安装的Vue版本号。可以通过npm官网或Vue官网查看可用的版本号。
>
>   3.  等待安装完成后，就可以在项目中使用指定版本的Vue了。
>
>   另外，可以同时安装多个版本的Vue。只需要在安装命令中指定不同的版本号即可。例如，你可以同时安装2.6.10和2.6.11两个版本的Vue：
>
>   ```
>   npm install vue@2.6.10
>   npm install vue@2.6.11
>   ```
>
>   在项目中使用不同版本的Vue时，需要在项目的package.json文件中分别指定不同版本的Vue依赖，以避免版本冲突。

```powershell
PS C:\Windows\System32> vue -V
@vue/cli 4.5.19
```

windows 中输入 npm list vue报错

```powershell
npm WARN config global `--global`, `--local` are deprecated. Use `--location=global` instead.
```

而且不显示我安装了哪个版本的vue

>   这个警告是因为使用了已经废弃的参数，可以尝试使用新的参数`--location`来替代。另外，如果使用`npm list vue`命令无法显示已安装的Vue版本，可以尝试使用`npm ls vue`命令来查看。
>
>   另外，如果在全局安装Vue的情况下，仍然无法通过`npm list`或`npm ls`命令查看Vue版本，可以尝试使用以下命令查看全局安装的包列表，并搜索Vue相关的包：
>
>   ```bash
>   npm list -g --depth=0 | grep vue
>   ```
>
>   这个命令将显示全局安装的所有包列表，并过滤出包含“vue”关键字的包。如果有多个版本的Vue安装在计算机上，则可以看到多个相关的包。

```bash
PS C:\Windows\System32> bash

Administrator@DESKTOP-0O633M1 MINGW32 /c/Windows/System32
$ npm list -g --depth=0 | grep vue
npm WARN config global `--global`, `--local` are deprecated. Use `--location=global` instead.
npm WARN config global `--global`, `--local` are deprecated. Use `--location=global` instead.
`-- @vue/cli@4.5.19
```

**你说的npm list -g --depth=0 | grep vue只能用在linux的bash里面吧，能改正吗**

>   是的，我之前的回答确实只适用于 Linux Bash 环境下。在 Windows 环境下，你可以尝试以下命令来查看全局安装的 Vue 版本：
>
>   ```
>   npm list -g vue
>   ```
>
>   这将会列出全局安装的 Vue 及其依赖包的信息，包括版本号。如果你想查看本地项目的 Vue 版本，可以在项目目录下执行以下命令：
>
>   ```
>   npm list vue
>   ```
>
>   这将会列出当前项目安装的 Vue 及其依赖包的信息。

```powershell
PS C:\Windows\System32> npm list -g vue
npm WARN config global `--global`, `--local` are deprecated. Use `--location=global` instead.
npm WARN config global `--global`, `--local` are deprecated. Use `--location=global` instead.
C:\Users\Administrator\AppData\Roaming\npm
`-- @vue/cli@4.5.19
  `-- vue@2.7.14
```

启动vue自带的图形化项目管理界面

```powershell
vue ui
```


常见问题1：Windows上运行vue，提示无法加载文件，表示用户权限不足。

解决方案：用管理员身份打开终端，输入set-ExecutionPolicy RemoteSigned，然后输入y

##### 安装依赖

vue-router, vuex

这里我一开始没装，所以到后面使用vue-router前都缺少依赖

![image-20230305213155590](img/image-20230305213155590.png)

#### 创建 vue 项目

如果在 c 的 systems 文件夹中打开 powershell 会卡住，还行是因为文件太多？其实不是。我用最新版vue，将 systems 加入环境变量后问题消失了。

##### Bug

![image-20230302213738426](img/image-20230302213738426.png)

我的电脑里有两个 Powershell ![image-20230302214405973](img/image-20230302214405973.png)

报错

```powershell
PS C:\Users\Administrator\Desktop\spring\kob> vue ui
🚀  Starting GUI...
🌠  Ready on http://localhost:8000
node:events:505
      throw er; // Unhandled 'error' event
      ^

Error: spawn cmd ENOENT
    at Process.ChildProcess._handle.onexit (node:internal/child_process:283:19)
    at onErrorNT (node:internal/child_process:478:16)
    at processTicksAndRejections (node:internal/process/task_queues:83:21)
Emitted 'error' event on ChildProcess instance at:
    at Process.ChildProcess._handle.onexit (node:internal/child_process:289:12)
    at onErrorNT (node:internal/child_process:478:16)
    at processTicksAndRejections (node:internal/process/task_queues:83:21) {
  errno: -4058,
  code: 'ENOENT',
  syscall: 'spawn cmd',
  path: 'cmd',
  spawnargs: [ '/c', 'start', '""', '/b', 'http://localhost:8000' ]
}
```



 cd 进入项目目录，在项目中 `vue ui` ，结果还是报一样的错。

所以在 `C:\Windows\System32` 才能运行？

根据[node\.js \- npm nodejs vue/cli problem can't run 'vue ui' \- Stack Overflow](https://stackoverflow.com/questions/70482373/npm-nodejs-vue-cli-problem-cant-run-vue-ui)在高级系统设置中添加 C:\Windows\System32 环境变量

![image-20230303003349434](img/image-20230303003349434.png)

重启终端成功开启

```powershell
PS C:\Windows\System32> npm ls @vue/cli-ui
npm WARN config global `--global`, `--local` are deprecated. Use `--location=global` instead.
```

-g选项和-l选项的区别？

>   在npm命令中，-g选项表示全局安装，即将包安装在全局环境中，可在任意位置使用；而-l选项表示本地安装，即将包安装在当前目录中，只能在当前目录中使用。
>
>   注意：在新版本的npm中，使用-g选项全局安装已经是默认行为，可以不加-g选项进行全局安装。

```powershell
PS C:\Windows\System32> npm ls @vue/cli-ui --location=global
npm WARN config global `--global`, `--local` are deprecated. Use `--location=global` instead.
C:\Users\Administrator\AppData\Roaming\npm
`-- @vue/cli@4.5.19
  `-- @vue/cli-ui@4.5.19
  PS C:\Windows\System32> npm ls @vue/cli-ui-i18n --location=global
npm WARN config global `--global`, `--local` are deprecated. Use `--location=global` instead.
C:\Users\Administrator\AppData\Roaming\npm
`-- (empty)
```

##### 继续创建项目 web

![image-20230303092456987](img/image-20230303092456987.png)

![image-20230303092613496](img/image-20230303092613496.png)

选择 Vue3 。

##### 安装依赖

![image-20230303092936033](img/image-20230303092936033.png)

![image-20230303093004055](img/image-20230303093004055.png)

![image-20230303093043924](img/image-20230303093043924.png)

##### 运行与打开

![image-20230303093329762](img/image-20230303093329762.png)

![image-20230303093414438](img/image-20230303093414438.png)



![image-20230303093456499](img/image-20230303093456499.png)

##### 创建新项目 acapp

先停止之前的 Vue 项目

![image-20230303093607962](img/image-20230303093607962.png)

回到项目管理器

![image-20230303093806819](img/image-20230303093806819.png)

在 C:\Users\Administrator\Desktop\spring\kob 创建 acapp 项目，然后和 web 一样

##### 安装插件

![image-20230303094229827](img/image-20230303094229827.png)

##### 运行 acapp

![image-20230303094602008](img/image-20230303094602008.png)

由于 vue 项目比较大，运行慢

也可以在 vscode 中

```bash
npm run serve
```



##### git 同步

```bash
Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git status
On branch master
Your branch is up to date with 'origin/master'.

Untracked files:
  (use "git add <file>..." to include in what will be committed)

        acapp/
        npminstall-debug.log
        web/

nothing added to commit but untracked files present (use "git add" to track)

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git add .
warning: LF will be replaced by CRLF in acapp/.gitignore.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in acapp/README.md.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in acapp/babel.config.js.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in acapp/jsconfig.json.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in acapp/package-lock.json.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in acapp/package.json.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in acapp/public/index.html.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in acapp/src/App.vue.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in acapp/src/components/HelloWorld.vue.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in acapp/src/store/index.js.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in acapp/vue.config.js.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in npminstall-debug.log.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in web/.gitignore.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in web/README.md.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in web/babel.config.js.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in web/jsconfig.json.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in web/package-lock.json.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in web/package.json.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in web/public/index.html.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in web/src/App.vue.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in web/src/components/HelloWorld.vue.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in web/src/main.js.
The file will have its original line endings in your working directory
warning: LF will be replaced by CRLF in web/vue.config.js.
The file will have its original line endings in your working directory

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git commit -m "Create web and acapp"
[master 2f11f6c] Create web and acapp
 28 files changed, 39783 insertions(+)
 create mode 100644 acapp/.gitignore
 create mode 100644 acapp/README.md
 create mode 100644 acapp/babel.config.js
 create mode 100644 acapp/jsconfig.json
 create mode 100644 acapp/package-lock.json
 create mode 100644 acapp/package.json
 create mode 100644 acapp/public/favicon.ico
 create mode 100644 acapp/public/index.html
 create mode 100644 acapp/src/App.vue
 create mode 100644 acapp/src/assets/logo.png
 create mode 100644 acapp/src/components/HelloWorld.vue
 create mode 100644 acapp/src/main.js
 create mode 100644 acapp/src/store/index.js
 create mode 100644 acapp/vue.config.js
 create mode 100644 npminstall-debug.log
 create mode 100644 web/.gitignore
 create mode 100644 web/README.md
 create mode 100644 web/babel.config.js
 create mode 100644 web/jsconfig.json
 create mode 100644 web/package-lock.json
 create mode 100644 web/package.json
 create mode 100644 web/public/favicon.ico
 create mode 100644 web/public/index.html
 create mode 100644 web/src/App.vue
 create mode 100644 web/src/assets/logo.png
 create mode 100644 web/src/components/HelloWorld.vue
 create mode 100644 web/src/main.js
 create mode 100644 web/vue.config.js

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git push
Enumerating objects: 30, done.
Counting objects: 100% (30/30), done.
Delta compression using up to 8 threads
Compressing objects: 100% (26/26), done.
Writing objects: 100% (29/29), 207.41 KiB | 4.61 MiB/s, done.
Total 29 (delta 5), reused 0 (delta 0)
To git.acwing.com:youhuang/kob.git
   b2d4dc6..2f11f6c  master -> master

```



#### 编辑 vue 项目

C:\Users\Administrator\Desktop\spring\kob\web 用 VsCode 打开，简称 VC

需要装个 vue 的 VC 插件 Vue Language Features (Volar) 。

![image-20230303095039722](img/image-20230303095039722.png)

关掉 acapp 项目，打开 web 项目

删掉 src\components\HelloWorld.vue 还有一些代码。。但是我这里好像不太一样，没有 router 文件夹

src\App.vue

```vue
<template>
  <div>
    Hello World!
  </div>
</template>


<style>
</style>

```



虽然不太一样，但是还是跑起来了

`Hello World!`

[web](http://localhost:8080/)

##### 修改后端

[127.0.0.1:3000/pk/getbotinfo/](http://127.0.0.1:3000/pk/getbotinfo/)

```
{"name":"tiger","rating":"1500"}
```

##### 实现前后端通信

修改 web 项目时自动编译，老弹错误，所以打开win的专注中心

修改src\App.vue

```vue
<template>
  <!--html-->
  <div>
    <div>Bot昵称：{{ bot_name }}</div>
    <div>Bot战力：{{ bot_rating }}</div>

  </div>
</template>

<script>
// js

import { ref } from 'vue';// ? if commented , delete produce below error? 定义变量引入

/*
Compiled with problems:X

ERROR

[eslint] 
C:\Users\Administrator\Desktop\spring\kob\web\src\App.vue
  31:22  error  'ref' is not defined  no-undef
  32:24  error  'ref' is not defined  no-undef

✖ 2 problems (2 errors, 0 warnings)
*/

import $ from 'jquery';// add this or error
/*
Compiled with problems:X

ERROR

[eslint] 
C:\Users\Administrator\Desktop\spring\kob\web\src\App.vue
  21:7  error  '$' is not defined  no-undef

✖ 1 problem (1 error, 0 warnings)

*/
export default {
  name: "App", // 对象名字
  setup: () => { //函数入口
      let bot_name = ref("");
      let bot_rating = ref("");

      $.ajax({
        url: "http://127.0.0.1:3000/pk/getbotinfo/",
        type: "get",
        success: resp => {
          console.log(resp);
        }
      });

      return {
        bot_name,
        bot_rating
      }
  }
}
</script>

<style>
/* css */
</style>

```



[web](http://localhost:8080/)

```
Bot昵称：
Bot战力：
```



##### 跨域问题 CORS

一个 8080 一个 3000 ，两个不同端口通信
        

```js
  Access to XMLHttpRequest at 'http://127.0.0.1:3000/pk/getbotinfo/' from origin 'http://localhost:8080' has been blocked by CORS policy: No 'Access-Control-Allow-Origin' header is present on the requested resource.
```

**给我Spring官方文档中有关跨域问题的文档链接**

>   以下是 Spring 官方文档中有关跨域问题的文档链接：
>
>   -   CORS support in Spring Framework: https://docs.spring.io/spring-framework/docs/current/reference/html/web.html#cors
>
>   这篇文档中介绍了 Spring Framework 中关于 CORS 的实现，包括基于注解的方式和基于配置的方式。
>
>   -   Enabling Cross Origin Requests for a RESTful Web Service: https://spring.io/guides/gs/rest-service-cors/
>
>   这篇文档是 Spring 官方提供的一个基础的 RESTful Web Service 示例，其中包含了如何开启 CORS 的示例。
>
>   希望对你有帮助！

###### 添加配置类：CorsConfig

```java
添加配置类：CorsConfig

package com.kob.backend.config;

import org.springframework.context.annotation.Configuration;

import javax.servlet.*;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@Configuration
public class CorsConfig implements Filter {
    @Override
    public void doFilter(ServletRequest req, ServletResponse res, FilterChain chain) throws IOException, ServletException {
        HttpServletResponse response = (HttpServletResponse) res;
        HttpServletRequest request = (HttpServletRequest) req;

        String origin = request.getHeader("Origin");
        if(origin!=null) {
            response.setHeader("Access-Control-Allow-Origin", origin);
        }

        String headers = request.getHeader("Access-Control-Request-Headers");
        if(headers!=null) {
            response.setHeader("Access-Control-Allow-Headers", headers);
            response.setHeader("Access-Control-Expose-Headers", headers);
        }

        response.setHeader("Access-Control-Allow-Methods", "*");
        response.setHeader("Access-Control-Max-Age", "3600");
        response.setHeader("Access-Control-Allow-Credentials", "true");

        chain.doFilter(request, response);
    }

    @Override
    public void init(FilterConfig filterConfig) {

    }

    @Override
    public void destroy() {
    }
}
```


###### Bug

发现名字不是 kob 而是example，重构 Refractor 重命名，然后直接运行报错

```
错误: 找不到或无法加载主类 com.example.backend.BackendApplication
```

**当IDEA编译springboot错误: 找不到或无法加载主类 com.example.backend.BackendApplication时，如何debug找到错误？**

>   
>
>   
>
>   出现"找不到或无法加载主类"的错误通常是因为编译时出现了问题。在这种情况下，您可以尝试以下步骤来debug：
>
>   1.  检查您的代码是否有语法错误或其他编译错误。在您的IDE中检查控制台输出，查看是否有任何错误消息。
>   2.  检查您的类路径是否正确设置。确保所有必需的类文件和库文件都在类路径中，并且没有任何重复项。您可以在IDEA中检查您的类路径设置。
>   3.  检查您的代码是否正确地打包成jar文件。如果您的代码是通过jar文件运行的，则确保您的代码被正确地打包到jar文件中。您可以检查您的构建脚本或构建配置以确认jar文件是否被正确地构建。
>   4.  检查您的启动命令是否正确。确保您的启动命令正确地指定了您的主类，并且没有任何错误的参数或选项。您可以检查您的启动脚本或IDEA配置以确认启动命令是否正确。
>   5.  尝试手动运行您的应用程序。如果您的应用程序是通过命令行运行的，则尝试手动运行它，以查看是否有任何错误消息。您可以检查您的应用程序的日志文件或控制台输出以获取更多信息。
>
>   如果您仍然无法解决问题，请考虑寻求更高级的debugging工具或专业支持。

![image-20230304165605533](img/image-20230304165605533.png)

![image-20230304165626361](img/image-20230304165626361.png)

这里也要改

###### 回到跨域问题

![image-20230304170124450](img/image-20230304170124450.png)

现在前端已经能获取值了，现在如何显示出来？

```vue
<template>
  <!--html-->
  <div>
    <div>Bot昵称：{{ bot_name }}</div>
    <div>Bot战力：{{ bot_rating }}</div>

  </div>
</template>

<script>
// js

import { ref } from 'vue';// ? if commented , delete produce below error? 定义变量引入

/*
Compiled with problems:X

ERROR

[eslint] 
C:\Users\Administrator\Desktop\spring\kob\web\src\App.vue
  31:22  error  'ref' is not defined  no-undef
  32:24  error  'ref' is not defined  no-undef

✖ 2 problems (2 errors, 0 warnings)
*/

import $ from 'jquery';// add this or error
/*
Compiled with problems:X

ERROR

[eslint] 
C:\Users\Administrator\Desktop\spring\kob\web\src\App.vue
  21:7  error  '$' is not defined  no-undef

✖ 1 problem (1 error, 0 warnings)

*/
export default {
  name: "App", // 对象名字
  setup: () => { //函数入口
      let bot_name = ref("");
      let bot_rating = ref("");

      $.ajax({
        url: "http://127.0.0.1:3000/pk/getbotinfo/",
        type: "get",// 请求类型 2: get post ，restful多2种
        success: resp => {
          //console.log(resp); //print in console
          bot_name.value = resp.name;
          bot_rating.value = resp.rating;
        }
      });

      return {
        bot_name,
        bot_rating
      }
  }
}
</script>

<style>
/* css */
</style>

```

```
Bot昵称：tiger
Bot战力：1500
```

Vue 中的代码全在用户浏览器中执行。

![image-20230304185719922](img/image-20230304185719922.png)

"[/js/app.js](http://localhost:8080/js/app.js)"

###### 添加背景图片

src\assets\background.png

![image-20230304194051401](img/image-20230304194051401.png)



## 5.创建菜单与游戏页面



前端使用 Bootstrap 。

将导航栏封装成一个可以复用的组件。

src\components\NavBar.vue

**Vue 对组件的命名要求实什么？给出文档链接**

>   Vue对组件的命名有以下要求：
>
>   -   组件名应该始终是多个单词的，根组件 App 除外。
>   -   组件名应该始终使用 PascalCase（首字母大写的驼峰命名法）命名规则。
>   -   组件名应该是自定义元素的形式，以避免和当前以及未来的 HTML 元素相冲突。
>
>   你可以在官方文档中查看更多关于Vue组件命名的详细信息：[https://cn.vuejs.org/v2/style-guide/index.html#%E7%BB%84%E4%BB%B6%E5%90%8D%E5%BF%85%E9%A1%BB%E5%A4%9A%E5%8D%95%E8%AF%8D%E5%B9%B6%E4%BD%BF%E7%94%A8%E5%A4%A7%E5%86%99%E5%BC%8F%E5%91%BD%E5%90%8D](https://cn.vuejs.org/v2/style-guide/index.html#组件名必须多单词并使用大写式命名)

```vue
```

#### 导入 NavBar

[Bootstrap · The most popular HTML, CSS, and JS library in the world\.](https://getbootstrap.com/) => Docs => 搜索 Navbar 

[Navbar · Bootstrap v5\.3](https://getbootstrap.com/docs/5.3/components/navbar/#how-it-works)

搜索 w/ text

```html
<nav class="navbar navbar-expand-lg bg-body-tertiary">
  <div class="container-fluid">
    <a class="navbar-brand" href="#">Navbar w/ text</a>
    <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarText" aria-controls="navbarText" aria-expanded="false" aria-label="Toggle navigation">
      <span class="navbar-toggler-icon"></span>
    </button>
    <div class="collapse navbar-collapse" id="navbarText">
      <ul class="navbar-nav me-auto mb-2 mb-lg-0">
        <li class="nav-item">
          <a class="nav-link active" aria-current="page" href="#">Home</a>
        </li>
        <li class="nav-item">
          <a class="nav-link" href="#">Features</a>
        </li>
        <li class="nav-item">
          <a class="nav-link" href="#">Pricing</a>
        </li>
      </ul>
      <span class="navbar-text">
        Navbar text with an inline element
      </span>
    </div>
  </div>
</nav>
```

App.vue

```vue
<template>
  <!--html-->
  <NavBar />
</template>

<script>
// js
import NavBar from './components/NavBar.vue'

export default {
  components: {
    NavBar
  }
}
</script>

<style>
/* css */
body {
  background-image: url(@/assets/background.png);
  background-size: cover;
}
</style>

```



App.vue

```vue
<template>
  <!--html-->
  <NavBar />
</template>

<script>
// js
import NavBar from './components/NavBar.vue'

export default {
  components: {
    NavBar
  }
}
</script>

<style>
/* css */
body {
  background-image: url(@/assets/background.png);
  background-size: cover;
}
</style>

```



Bootstrap not defined

![image-20230304201056629](img/image-20230304201056629.png)

#### 导入 Bootstrap

```js
import NavBar from './components/NavBar.vue'

import "bootstrap/dist/css/bootstrap.min.css"
import "bootstrap/dist/js/bootstrap"
```



```
Compiled with problems:X

ERROR in ./node_modules/bootstrap/dist/js/bootstrap.js 8:90-115

Module not found: Error: Can't resolve '@popperjs/core' in 'C:\Users\Administrator\Desktop\spring\kob\web\node_modules\bootstrap\dist\js'

```



在 vue cli 的依赖 => 安装依赖 中搜索 `@popperjs/core` 并安装

![image-20230304202021064](img/image-20230304202021064.png)



![image-20230304202104650](img/image-20230304202104650.png)



```html
<nav class="navbar navbar-expand-lg navbar-dark bg-dark">
```



![image-20230304202749743](img/image-20230304202749743.png)



```html
<template>

<nav class="navbar navbar-expand-lg navbar-dark bg-dark">
  <div class="container-fluid">
    <a class="navbar-brand" href="#">King of Bots</a>
    <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarText" aria-controls="navbarText" aria-expanded="false" aria-label="Toggle navigation">
      <span class="navbar-toggler-icon"></span>
    </button>
    <div class="collapse navbar-collapse" id="navbarText">
      <ul class="navbar-nav me-auto mb-2 mb-lg-0">
        <li class="nav-item">
          <a class="nav-link active" aria-current="page" href="#">对战</a>
        </li>
        <li class="nav-item">
          <a class="nav-link" href="#">对局列表</a>
        </li>
        <li class="nav-item">
          <a class="nav-link" href="#">排行榜</a>
        </li>
      </ul>
      <span class="navbar-text">
        Navbar text with an inline element
      </span>
    </div>
  </div>
</nav>
</template>
```

![image-20230304203125779](img/image-20230304203125779.png)

```html
          <a class="nav-link active" aria-current="page" href="#">对战</a>
<!-- active 是高亮-->
```

#### 实现下拉菜单 dropdown

注意在 navbar 中搜索，而不是全局搜索，全局搜索的样式不匹配导航栏



![image-20230305101915275](img/image-20230305101915275.png)

#### 写页面

views 文件夹

中创建四个界面

#### Router-view

##### 网址打开对应页面

src\router\index.js

define   `<router-view></router-view>` in App.vue

如果 vue-router 没安装就会报错

```js
app.js:434 
        
       Uncaught Error: Cannot find module 'vue-router'
```

现在打开一个网址对应了一个页面

[Imply views.Fix router-vue problem, install router-vue and vuex. (d04a6dbc) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/d04a6dbca8396ac5758e44f0aa09fb5d8bc82a0e)

##### 点击跳转网址

[Click navbar and Jump to url (ec1f5112) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/ec1f51125150ec4bd64108355cb6a8363bfa22b7

观察到每点击一次，就刷新一次，那如何实现点击不刷新

```css
            <!--a class="nav-link" aria-current="page" href="/pk/">对战</a-->
            <router-link class="nav-link" :to="{name: 'pk_index'}">对战</router-link>  
```

[No reflesh (9277b9e4) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/9277b9e45edf6777e6b453fe22e4473097de4810)

##### 实现card

Bootstrap 里面搜，加入边框

src\components\ContentField.vue

![image-20230306144347750](img/image-20230306144347750.png)

[Add card (990f2b3b) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/990f2b3b2c1fe5c95346b603cd371643e9346e4d)

##### 实现导航栏点击页面高亮

![image-20230306145236322](img/image-20230306145236322.png)

[Highlight when jump (e0254c8b) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/e0254c8b72d9468ae4d22ae4955894a995e9d5f3)







#### 实现地图

![image-20230307104936589](img/image-20230307104936589.png)



基类：基本功能，每秒钟画 60 次

代码脚本放入 assets 中





##### requestAnimationFrame



传入一个函数，该函数在浏览器下一帧渲染之前返回

##### 设置地图大小

![image-20230309143603524](img/image-20230309143603524.png)

[Set PK index background area's size (3258f3ed) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/3258f3ed884dbb45e7d1f0286fd3e68ac8f04155)

##### Canvas

[Canvas - Web API 接口参考 | MDN (mozilla.org)](https://developer.mozilla.org/zh-CN/docs/Web/API/Canvas_API)

###### 画蓝色长方形中最大的绿色正方形

[Canvas print a green square inside a rectangle (35a938c9) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/35a938c9bb4d892e7dd9ac16bb31aab3e1becae0)

正方形是动态变化的

###### 调试

New BIng

[在 VS Code 中调试 — Vue.js (vuejs.org)](https://v2.cn.vuejs.org/v2/cookbook/debugging-in-vscode.html)

[vscode配置使vue项目支持断点调试 - 掘金 (juejin.cn)](https://juejin.cn/post/6844904144457695245)

```
如果你使用的是 Vue CLI 3，请设置并更新 vue.config.js 内的 devtool property：

module.exports = {
  configureWebpack: {
    devtool: 'source-map'
  }
}

如果我的  vue.config.js 内容如下 
const { defineConfig } = require('@vue/cli-service')
module.exports = defineConfig({
  transpileDependencies: true
}) 
如何添加上述代码？

```

```
const { defineConfig } = require('@vue/cli-service')
module.exports = defineConfig({
  transpileDependencies: true,
  configureWebpack: {
    devtool: 'source-map'
  }
})
```

结果最后发现是 client 打错了。。

**vscode中为vue打断点出现unbound breakpoint**

```
根据搜索结果，unbound breakpoint 是指一个断点无法绑定到相应的源代码位置。² 这可能是因为源代码文件的路径或名称与断点的路径或名称不匹配，或者因为源代码文件没有被加载或执行。¹³
```

**this.L = Math.min(this.parent.cilentWidth / this.cols, this.parent.clientHeight / this.rows);// 求 canvas 中最小正方形的长宽 想在 console.log(""); 中输出this.L怎么做？**

>   如果您想在 console.log 中输出 this.L 的值，您可以使用以下语句：
>
>   console.log(this.L);
>
>   这将在控制台中显示 this.L 的数值。

**his.L = Math.min(this.parent.cilentWidth / this.cols, this.parent.clientHeight / this.rows);// 求 canvas 中最小正方形的长宽 //console.log(this.L); console.log("start"); console.log(this.parent.clientWidth); console.log(this.parent.clientHeight); console.log(this.cols); console.log(this.rows); console.log(this.L); console.log("end"); 打印出的结果start 372 460 13 13 NAN end 为什么打印出NAN?**

>   [NaN 是一个英文单词，它是 Not a Number 的缩写，表示一个不是数字的值，或者是无法表示的值，特别是在浮点运算中](https://en.wikipedia.org/wiki/NaN)[1](https://en.wikipedia.org/wiki/NaN)[2](https://en.wikipedia.org/wiki/NaN)[3](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/NaN)。您打印出 NaN 的原因可能是您的代码中有一个 typo， cilentWidth 应该是 clientWidth。如果您用一个 undefined 的值去做除法运算，那么结果就会是 NaN。您可以检查一下您的代码，看看是否有拼写错误。

###### 画草地

[Print Green odd and even grids (032ab9e5) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/032ab9e5342a1f0b4f8ab6fde6148b268cb41034)

![image-20230310181533005](img/image-20230310181533005.png)



###### 画墙

![image-20230311145515200](img/image-20230311145515200.png)

[Create a block of wall in (0,0) (98d638f9) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/98d638f94b9c7c29d1dbb4024b6ace61baa436c8)



![image-20230311150316710](img/image-20230311150316710.png)

[Add walls around 4 sides (de573808) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/de573808d195fdcba42a371dddc8fe23722f6af0)







![image-20230311150742883](img/image-20230311150742883.png)

[Add walls around all 4 sides but not perfect (03dc7a59) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/03dc7a597d691a7bb0df9105587a0c30fc0738e1)

![image-20230311150900700](img/image-20230311150900700.png)

[Add walls around all 4 sides perfectly (559c22d6) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/559c22d65de5a0f11e1205598dc56c87833dbb76)

###### 随机添加障碍物（墙）

![image-20230311152706940](img/image-20230311152706940.png)



[Add Obstacles randomly (304ab02f) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/304ab02fa0209fac780ffea90c921d7eb817e52e)







![image-20230311153046363](img/image-20230311153046363.png)



[The squares in the upper left and lower right corners of the map are empty (c7002a7b) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/c7002a7b93ca88a5bee31a716ad041c41ab0ad0a)



###### 连通函数（BFS）

![image-20230311155934199](img/image-20230311155934199.png)

[Conectivity function of begin position of two snakes (231949e9) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/231949e964ebbce72f79b0f67a4ebe6dde23a961)

#### 换图标

![image-20230311155953489](img/image-20230311155953489.png)

to ![image-20230311160101330](img/image-20230311160101330.png)

public\favicon.ico

[Finish 3.1 and Change icon (1f5824cc) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/1f5824cc759b6f5508e41df27a04b1801e8913d5)



#### 蛇头在同一时间不会在同一个格子相遇





蛇头在同一时间不会在同一个格子相遇

![image-20230311175359861](img/image-20230311175359861.png)

将地图长宽列数增加1.

将正方形变为长方形，地图障碍物对称也要从轴对称改成中心对称

![image-20230311180305860](img/image-20230311180305860.png)

未来的地图逻辑应该转移到后端，现在浏览器刷新地图也刷新为了方便调试

#### 画蛇

##### 起点

![image-20230313123233094](img/image-20230313123233094.png)

[Print Snake in starting point (a2a58f2c) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/a2a58f2ca5779f8c0504cad59e7289d9e45b21a1)

##### 一个方向移动

![image-20230313124651159](img/image-20230313124651159.png)

[Move in a direction (823c7c7b) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/823c7c7b6056d74aa73a93227fcdac4e7f83383d)



##### 用键盘操控蛇移动

![image-20230318204232920](img/image-20230318204232920.png)

[Keyboard control snake (2ef8ef6b) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/2ef8ef6bba1245fd1f032c2e6a0d8eaf2ff932de)





##### 让蛇变小

![image-20230319020551033](img/image-20230319020551033.png)

[Make snake smaller (bc99adb4) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/bc99adb4c2f748722d997290c4b377f1efb21844)

##### 判断蛇是否撞墙

![image-20230319022058264](img/image-20230319022058264.png)

![image-20230319022221929](img/image-20230319022221929.png)

[Judge if a snake hits a wall (00d63eb7) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/00d63eb78ac364e74a121b9d0c59cad368743346)

##### 画蛇头

![image-20230319103656949](img/image-20230319103656949.png)

[Print snake's head (8d56f0fb) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/8d56f0fb8b5680fa6f22e8ee333a9f0277f430e0)

## 6.配置Mysql与注册登录模块

### 配置

mysql-installer-community-8.0.30.0.msi

```powershell
PS D:\Program Files\MySQL\MySQL Server 8.0\bin> .\mysql --version
D:\Program Files\MySQL\MySQL Server 8.0\bin\mysql.exe  Ver 8.0.30 for Win64 on x86_64 (MySQL Community Server - GPL)
```

密码：@

加入环境变量

### 启动与停止

```powershell
PS C:\Users\Administrator\Desktop> net stop mysql80
MySQL80 服务正在停止.
MySQL80 服务已成功停止。

PS C:\Users\Administrator\Desktop> net start mysql80
MySQL80 服务正在启动 .
MySQL80 服务已经启动成功。
```

如果出现报错，将 [C:\Windows\System32](https://stackoverflow.com/questions/35591669/net-is-not-recognized-as-an-internal-or-external-command-operable-program-or) 加入环境变量后重启终端

### 常见SQL命令

![image-20230319155628309](img/image-20230319155628309.png)

命令行使用 Mysql

```powershell
mysql -uroot -p
```



```sql
PS C:\Users\Administrator\Desktop> mysql -uroot -p
Enter password: **********
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 8
Server version: 8.0.30 MySQL Community Server - GPL

Copyright (c) 2000, 2022, Oracle and/or its affiliates.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> show databases
    -> ;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| mysql              |
| performance_schema |
| sys                |
+--------------------+
4 rows in set (0.01 sec)

mysql> create database kob;
Query OK, 1 row affected (0.01 sec)

mysql> show databases;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| kob                |
| mysql              |
| performance_schema |
| sys                |
+--------------------+
5 rows in set (0.00 sec)

mysql> use kob;
Database changed
mysql> show tables;
Empty set (0.00 sec)

mysql> drop database kob;
Query OK, 0 rows affected (0.01 sec)

mysql> show databases
    -> ;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| mysql              |
| performance_schema |
| sys                |
+--------------------+
4 rows in set (0.00 sec)

mysql> create database kob;
Query OK, 1 row affected (0.00 sec)

mysql> use kob;
Database changed
mysql> create table user(id int, username varchar(100), password varchar(100));
Query OK, 0 rows affected (0.02 sec)

mysql> show tables;
+---------------+
| Tables_in_kob |
+---------------+
| user          |
+---------------+
1 row in set (0.00 sec)

mysql> drop table user;
Query OK, 0 rows affected (0.01 sec)

mysql> show tables;
Empty set (0.00 sec)

mysql> create table user(id int, username varchar(100), password varchar(100));
Query OK, 0 rows affected (0.02 sec)

mysql> use kob;
Database changed
mysql> show tables;
+---------------+
| Tables_in_kob |
+---------------+
| user          |
+---------------+
1 row in set (0.00 sec)

mysql> insert into user values(1, 'yxc', 'pyxc');
Query OK, 1 row affected (0.01 sec)

mysql> select * from user
    -> ;
+------+----------+----------+
| id   | username | password |
+------+----------+----------+
|    1 | yxc      | pyxc     |
+------+----------+----------+
1 row in set (0.00 sec)

mysql> insert into user values(2, 'b', 'pb');
Query OK, 1 row affected (0.00 sec)

mysql> insert into user values(3, 'c', 'pc');
Query OK, 1 row affected (0.00 sec)

mysql> select * from user;
+------+----------+----------+
| id   | username | password |
+------+----------+----------+
|    1 | yxc      | pyxc     |
|    2 | b        | pb       |
|    3 | c        | pc       |
+------+----------+----------+
3 rows in set (0.00 sec)

mysql> select * from user where id=1;
+------+----------+----------+
| id   | username | password |
+------+----------+----------+
|    1 | yxc      | pyxc     |
+------+----------+----------+
1 row in set (0.00 sec)

mysql> select * from user where id=2;
+------+----------+----------+
| id   | username | password |
+------+----------+----------+
|    2 | b        | pb       |
+------+----------+----------+
1 row in set (0.00 sec)

mysql> select * from user where username=yxc;
ERROR 1054 (42S22): Unknown column 'yxc' in 'where clause'
mysql> select * from user where username='yxc';
+------+----------+----------+
| id   | username | password |
+------+----------+----------+
|    1 | yxc      | pyxc     |
+------+----------+----------+
1 row in set (0.00 sec)

mysql> delete from user where id=2;
Query OK, 1 row affected (0.01 sec)

mysql> select * from user;
+------+----------+----------+
| id   | username | password |
+------+----------+----------+
|    1 | yxc      | pyxc     |
|    3 | c        | pc       |
+------+----------+----------+
2 rows in set (0.00 sec)

mysql>
```

### IDEA连接Mysql

![image-20230319155944836](img/image-20230319155944836.png)

![image-20230319160032337](img/image-20230319160032337.png)



![image-20230319160149010](img/image-20230319160149010.png)

![image-20230319160206073](img/image-20230319160206073.png)

![image-20230319160312426](img/image-20230319160312426.png)

![image-20230319160418093](img/image-20230319160418093.png)

![image-20230319160704313](img/image-20230319160704313.png)

### Maven仓库

Maven仓库[Maven Repository: Search/Browse/Explore](https://mvnrepository.com/)

>   在pom.xml文件中添加依赖：
>   Spring Boot Starter JDBC
>   Project Lombok
>   MySQL Connector/J
>   mybatis-plus-boot-starter
>   mybatis-plus-generator
>   spring-boot-starter-security
>   jjwt-api
>   jjwt-impl
>   jjwt-jackson

#### 配置 Maven 库

![image-20230319160952983](img/image-20230319160952983.png)



[Maven Repository: org\.springframework\.boot » spring\-boot\-starter\-jdbc » 2\.7\.1](https://mvnrepository.com/artifact/org.springframework.boot/spring-boot-starter-jdbc/2.7.1)

从![image-20230319161100737](img/image-20230319161100737.png)复制

```xml
<!-- https://mvnrepository.com/artifact/org.springframework.boot/spring-boot-starter-jdbc -->
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-jdbc</artifactId>
    <version>2.7.1</version>
</dependency>

```

到 pom.xml 的 dependencies 中

![image-20230319161254122](img/image-20230319161254122.png)



在pom.xml文件中添加依赖：
Spring Boot Starter JDBC
Project Lombok
MySQL Connector/J
mybatis-plus-boot-starter
mybatis-plus-generator

后面的两个先别装

字体为红色，打开 Maven 栏点刷新

![image-20230319203616989](img/image-20230319203616989.png)

[【SpringBoot】Plugin ‘org.springframework.boot:spring-boot-maven-plugin:‘ not found_猿人林克的博客-CSDN博客](https://blog.csdn.net/ooppookid/article/details/120182049)

#### 添加数据库配置

>   在application.properties中添加数据库配置：
>
>   ```
>   spring.datasource.username=root
>   spring.datasource.password=123456
>   spring.datasource.url=jdbc:mysql://localhost:3306/kob?serverTimezone=Asia/Shanghai&useUnicode=true&characterEncoding=utf-8
>   spring.datasource.driver-class-name=com.mysql.cj.jdbc.Driver
>   ```

src/main/resources/application.properties





![image-20230319205330686](img/image-20230319205330686.png)

![image-20230319205233455](img/image-20230319205233455.png)

![image-20230319205353853](img/image-20230319205353853.png)





### SpringBoot中的常用模块

>   SpringBoot中的常用模块
>   pojo层：将数据库中的表对应成Java中的Class
>   mapper层（也叫Dao层）：将pojo层的class中的操作，映射成sql语句
>   service层：写具体的业务逻辑，组合使用mapper中的操作
>   controller层：负责请求转发，接受页面过来的参数，传给Service处理，接到返回值，再传给页面



![image-20230319210109291](img/image-20230319210109291.png)



#### 实现pojo层

![image-20230319210936253](img/image-20230319210936253.png)

也就是在上面中添加注解后

下面的 User.class 中会生成一堆代码



#### 实现 Mapper 层

[MyBatis-Plus (baomidou.com)](https://baomidou.com/)

![image-20230320092143886](img/image-20230320092143886.png)

[Query all user (71cbfedc) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/71cbfedc2f1be4e399fc43fbf5b2df700c1493d1)

查询所有用户

![image-20230320092637432](img/image-20230320092637432.png)

![image-20230320092700457](img/image-20230320092700457.png)

[Query by id (7a2bd8bd) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/7a2bd8bd9fe16634d010435f759255ad25aa1a57)

![image-20230320103734210](img/image-20230320103734210.png)

[Query with condition (f6071795) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/f6071795028298cf0c879b077b1f38524bcac83d)

![image-20230320104250399](img/image-20230320104250399.png)

[Query more condition and return a list (ddf60c44) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/ddf60c44d8c00d71c8e5d4c90773809b0301df80)

![image-20230320152511144](img/image-20230320152511144.png)

[Add user in browser's bar (3036e5bb) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/3036e5bbae2396c1fc2df640e3f99744983f5c13)

##### 未设置主键前加入重复数据的删除

![image-20230320162201780](img/image-20230320162201780.png)

加入重复数据后，不能直接删除

![image-20230321104001514](img/image-20230321104001514.png)

```sql
DELETE FROM user WHERE id = 5 AND username = 'e' limit 1;
```

![image-20230321104256740](img/image-20230321104256740.png)



##### 设置主键

![image-20230321104447406](img/image-20230321104447406.png)

![image-20230321104547162](img/image-20230321104547162.png)

![image-20230321104603222](img/image-20230321104603222.png)

现在添加重复 id 就会报错

![image-20230321104729109](img/image-20230321104729109.png)

![image-20230321104823786](img/image-20230321104823786.png)

##### 实现 deleteUser

[127.0.0.1:3000/user/all/](http://127.0.0.1:3000/user/all/)

```json
[{"id":1,"username":"yxc","password":"pyxc"},{"id":2,"username":"b","password":"pb"},{"id":3,"username":"c","password":"pc"},{"id":4,"username":"d","password":"pd"},{"id":5,"username":"e","password":"pe"},{"id":6,"username":"f","password":"pf"}]
```

![image-20230321105537266](img/image-20230321105537266.png)

[127.0.0.1:3000/user/all/](http://127.0.0.1:3000/user/all/)

```json
[{"id":1,"username":"yxc","password":"pyxc"},{"id":2,"username":"b","password":"pb"},{"id":3,"username":"c","password":"pc"},{"id":4,"username":"d","password":"pd"},{"id":5,"username":"e","password":"pe"}]
```

MyBatis-Plus 集成了许多数据库，可以将 SQL 语句统一转换为 Java 语句



Maven仓库[Maven Repository: Search/Browse/Explore](https://mvnrepository.com/)安装

#### spring-boot-starter-security

PS: 每次引入一个新 Maven 项目，都要在 Maven 选项卡中重新加载 `Reload All Maven Projects`

重新启动项目，然后进入任意页面显示要登入

![image-20230321135200910](img/image-20230321135200910.png)

每次会动态生成一个密码

![image-20230321135401455](img/image-20230321135401455.png)



![image-20230321135429011](img/image-20230321135429011.png)



[Confirm Log Out?](http://127.0.0.1:3000/logout)

![image-20230321135601489](img/image-20230321135601489.png)

原理：

![image-20230321140108718](img/image-20230321140108718.png)

JWT：不在数据库里存东西就可以保持验证、





Alt + Enter 补全

Alt + Insert 查找接口所有实现方法

![image-20230321140705491](img/image-20230321140705491.png)

![image-20230321140737128](img/image-20230321140737128.png)







![image-20230321164202356](img/image-20230321164202356.png)

`{noop}`表示未加密的明文

```
1,yxc,{noop}pyxc
2,b,pb
3,c,pc
4,d,pd
5,e,pe

```





出现“用户账号已过期”：

![image-20230321175240872](img/image-20230321175240872.png)

backend/src/main/java/com/kob/backend/service/impl/utils/UserDetailsImpl.java

```java
    public boolean isAccountNonExpired() {
        return false;
    }
```

应为

```java
    public boolean isAccountNonExpired() {
        return true;
    }
```

修改之后正常登录

##### 实现加密密码，判断密码长度



![image-20230321210341583](img/image-20230321210341583.png)

[Password too short, finish l4.1 (41dc7524) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/41dc75245b236589ce8ad2c6d25b314d397c274b)





##### 更改验证方式

![image-20230322152923909](img/image-20230322152923909.png)



###### Jwt验证方式

利于跨域验证

![image-20230322153402489](img/image-20230322153402489.png)

![image-20230322153337787](img/image-20230322153337787.png)

项目中只验证 14 天的 access_token 。

>   在pom.xml文件中添加依赖：
>
>   jjwt-api
>   jjwt-impl
>   jjwt-jackson

```java
import io.jsonwebtoken.Claims;
import io.jsonwebtoken.JwtBuilder;
import io.jsonwebtoken.Jwts;
import io.jsonwebtoken.SignatureAlgorithm;
import org.springframework.stereotype.Component;

import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;
import java.util.Base64;
import java.util.Date;
import java.util.UUID;

@Component
public class JwtUtil {
    public static final long JWT_TTL = 60 * 60 * 1000L * 24 * 14;  // 有效期14天
    public static final String JWT_KEY = "SDFGjhdsfalshdfHFdsjkdsfds121232131afasdfac";

    public static String getUUID() {
        return UUID.randomUUID().toString().replaceAll("-", "");
    }

    public static String createJWT(String subject) {
        JwtBuilder builder = getJwtBuilder(subject, null, getUUID());
        return builder.compact();
    }

    private static JwtBuilder getJwtBuilder(String subject, Long ttlMillis, String uuid) {
        SignatureAlgorithm signatureAlgorithm = SignatureAlgorithm.HS256;
        SecretKey secretKey = generalKey();
        long nowMillis = System.currentTimeMillis();
        Date now = new Date(nowMillis);
        if (ttlMillis == null) {
            ttlMillis = JwtUtil.JWT_TTL;
        }

        long expMillis = nowMillis + ttlMillis;
        Date expDate = new Date(expMillis);
        return Jwts.builder()
                .setId(uuid)
                .setSubject(subject)
                .setIssuer("sg")
                .setIssuedAt(now)
                .signWith(signatureAlgorithm, secretKey)
                .setExpiration(expDate);
    }

    public static SecretKey generalKey() {
        byte[] encodeKey = Base64.getDecoder().decode(JwtUtil.JWT_KEY);
        return new SecretKeySpec(encodeKey, 0, encodeKey.length, "HmacSHA256");
    }

    public static Claims parseJWT(String jwt) throws Exception {
        SecretKey secretKey = generalKey();
        return Jwts.parserBuilder()
                .setSigningKey(secretKey)
                .build()
                .parseClaimsJws(jwt)
                .getBody();
    }
}

作者：yxc
链接：https://www.acwing.com/blog/content/23255/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```



关于 [IDEA中Maven项目导入依赖包，出现红线波浪线的问题（补充）_idea的maven依赖红线_迷茫君的博客-CSDN博客](https://blog.csdn.net/qq_41610418/article/details/119758410)





![image-20230323154056937](img/image-20230323154056937.png)





#### 编写api



>   根据搜索结果[1](https://docs.spring.io/spring-framework/docs/3.0.0.M4/reference/html/ch15s03.html) [2](https://stackoverflow.com/questions/65944372/why-do-we-need-to-call-service-layer-using-interface-instead-of-direct-service-c)，Spring框架中写接口的步骤大致如下：
>
>   -   在Service层定义一个接口，声明需要提供的业务方法。
>   -   在Service层实现该接口，编写具体的业务逻辑。
>   -   在Controller层注入该接口的实例，使用@Autowired或@Resource注解。
>   -   在Controller层调用该接口的方法，处理用户请求和响应。
>
>   您还有其他问题吗？



##### 实现用户的授权认证



[127.0.0.1:3000/user/account/token/](http://127.0.0.1:3000/user/account/token/)

```
Whitelabel Error Page
This application has no explicit mapping for /error, so you are seeing this as a fallback.

Thu Mar 23 18:46:36 CST 2023
There was an unexpected error (type=Method Not Allowed, status=405).
```

在 LoginController.java 中，使用的是 Post 类型的请求

```java

    @PostMapping("/user/account/token/")
    public Map<String, String> getToken(@RequestParam Map<String, String> map) {
        String username = map.get("username");
        String password = map.get("password");
        return loginService.getToken(username, password);
    }
```

浏览器中是 GET ，所以会报 405 方法错误

![image-20230323185714620](img/image-20230323185714620.png)





[JSON Web Tokens - jwt.io](https://jwt.io/)

```
"eyJhbGciOiJIUzI1NiJ9.eyJqdGkiOiJkNDFjOTJlMGIxNzY0NGQ5OGE2YWM0N2U4ZDIwNWE1ZCIsInN1YiI6IjEiLCJpc3MiOiJzZyIsImlhdCI6MTY3OTU2OTAyNCwiZXhwIjoxNjgwNzc4NjI0fQ.1Vgrmr_eapPhS5NseoX9DXirN3-Q4mL51O__Hy-3vds"
```

out:

```
{
  "jti": "d41c92e0b17644d98a6ac47e8d205a5d",
  "sub": "1",
  "iss": "sg",
  "iat": 1679569024,
  "exp": 1680778624
}
```





![image-20230323200143876](img/image-20230323200143876.png)

注：这里的 Error 是由于屏蔽广告扩展，换了一个无扩展浏览器就好了



将 ajax 中用户名和密码更改，然后改 Token ，可以看到，返回的是第二个用户的信息

![image-20230323200904848](img/image-20230323200904848.png)



##### 实现用户注册

```javascript
    $.ajax({
      url: "http://127.0.0.1:3000/user/account/register/",
      type: "post",
      data: {
        username: "yxc",
        password: "123",
        confirmedPassword: "123",
      },
      success(resp) {
        console.log(resp);
      },
      error(resp) {
        console.log(resp);
      }
    })
```



![image-20230324150842554](img/image-20230324150842554.png)

插入成功

![image-20230324151925918](img/image-20230324151925918.png)



[Finish backend register (62dbbd65) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/62dbbd65397f2abeaf0f32b3115287170bfb045a)

### 前端用户账户实现

注册和登录

#### 实现注册和登录界面标题

![image-20230324153634831](img/image-20230324153634831.png)

![image-20230324153648473](img/image-20230324153648473.png)

[Imply the frontend topic of Register and Login (9647c7ce) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/9647c7ce0a709facf8e4c6fd99cb46e379ccee5c)

#### 注册界面

表格

[Grid system · Bootstrap v5\.3](https://getbootstrap.com/docs/5.3/layout/grid/#example)

表格中文字居中

[Grid system · Bootstrap v5\.3](https://getbootstrap.com/docs/5.3/layout/grid/#variable-width-content)

表单样式

[Form controls · Bootstrap v5\.3](https://getbootstrap.com/docs/5.3/forms/form-control/)

按钮

[Buttons · Bootstrap v5\.3](https://getbootstrap.com/docs/5.3/components/buttons/#examples)

[web](http://localhost:8080/user/account/login)

![image-20230324184121667](img/image-20230324184121667.png)

[Imply forms frame of Login page's front end (f9b77886) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/f9b778865de2c80c04994cbadf530040368a028f)





![image-20230325131141305](img/image-20230325131141305.png)





![image-20230325131522940](img/image-20230325131522940.png)

这里三个 Object 是因为调试代码还没有注释。



#### 登录成功后自动跳转到主界面

![image-20230327103548814](img/image-20230327103548814.png)

[Login and jump to home page (25e62897) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/25e6289789eac4a5525af7e61a21b34c500e2606)

#### 返回登录成功信息

![image-20230327120123511](img/image-20230327120123511.png)

[Login and show user info in browser's console (47ed1630) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/47ed1630da9056c30d66bb23c506def1a7100ef8)



#### 从菜单栏按钮跳转到登录和注册页面

![image-20230328120706501](img/image-20230328120706501.png)

![image-20230328120802594](img/image-20230328120802594.png)

[Jump to login and registration pages from menu bar buttons (2f3a8df1) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/2f3a8df19a9c6a64eaa1848d4aa463574f6dc3c2)

#### 从菜单栏退出按钮退出

![image-20230328140047488](img/image-20230328140047488.png)



![image-20230328140102973](img/image-20230328140102973.png)

4.2 结束





#### 前端页面授权

##### 如果没有登录，点击栏中的任意按钮将跳转到默认页面

![image-20230329095303134](img/image-20230329095303134.png)

[Click any button in bar will jump to default page if not login (3b60dba7) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/3b60dba79b4785b06fd2ee63a07b56defd460b6d)

#### 实现注册页面

##### 使用重复的用户名注册时在控制台打印 error_message

![image-20230329143301285](img/image-20230329143301285.png)

[Register with repeated username and print error_message in console (ba3b8ab8) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/ba3b8ab86f36718d06208182d602e68eb5c724a4)

##### 注册失败在浏览器中打印错误信息

![image-20230329144420497](img/image-20230329144420497.png)

![image-20230329144542388](img/image-20230329144542388.png)

![image-20230329144556303](img/image-20230329144556303.png)

![image-20230329144635191](img/image-20230329144635191.png)

![image-20230329145047909](img/image-20230329145047909.png)

##### 成功实现注册功能

![image-20230329151726554](img/image-20230329151726554.png)

123

![image-20230329151752932](img/image-20230329151752932.png)

[Finish register (9f3e9b36) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/9f3e9b366fbaf642106085fa1e72ca1b2a8bb253)

##### 注释掉调试中在控制台的输出

全局搜索

![image-20230329152558308](img/image-20230329152558308.png)

##### 注释掉调试时的输出

[Comment the debug output, like pringf and console.log (7d5dfe06) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/7d5dfe069067104af1d2bf844b98bc6e18b40e6b)



#### 登录状态持久化

每次刷新时，登录状态就会消失，原因：

src\store\user.js 中的 token 是放到内存里的

>   by Cursor:
>
>   看起来每次刷新后登录状态消失的原因是因为 src\store\user.js 中的 token 是存储在内存中的。这可能是因为 token 存储在 Vuex store 中，而 Vuex 是一个用于 Vue.js 应用程序的状态管理模式和库。
>
>   当页面刷新时，Vuex store 的状态会重置为其初始值，这意味着 token 会丢失。为了在页面刷新后保持 token，您可以考虑将其存储在更持久的存储机制中，例如本地存储或 cookie。
>
>   以下是如何修改 src\store\user.js 中的 login action 以将 token 存储在本地存储中的示例：
>
>   ```javascript
>   login(context, data) {
>     $.ajax({
>       url: "https://app2703.acapp.acwing.com.cn/api/user/account/token/",
>       type: "post",
>       data: {
>         username: data.username,
>         password: data.password,
>       },
>       success(resp) {
>         if (resp.error_message === "success") {
>           localStorage.setItem("jwt_token", resp.token); // 将 token 存储在本地存储中
>           context.commit("updateToken", resp.token);
>           data.success(resp);
>         } else {
>           data.error(resp);
>         }
>       },
>       error(resp) {
>         data.error(resp);
>       }
>     });
>   },
>   
>   ```
>
>   











作者：yxc
链接：https://www.acwing.com/blog/content/20724/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
