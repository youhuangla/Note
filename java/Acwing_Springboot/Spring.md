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













作者：yxc
链接：https://www.acwing.com/blog/content/20724/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
