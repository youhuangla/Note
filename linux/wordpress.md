## Ubuntu Wordpress

https://blog.csdn.net/songziqi98/article/details/82932127
* sudo apt-get install apache2
* sudo apt-get install php7.0
* sudo apt-get install libapache2-mod-php7.2
* sudo apt-get install mysql-server
(As I have installed it before)
* sudo apt-get install php7.2-mysql
![](https://raw.githubusercontent.com/youhuangla/images/main/20220126223916.png)
* enter a password?(forget to snipaste)![](https://raw.githubusercontent.com/youhuangla/images/main/20220126224552.png)
![](https://raw.githubusercontent.com/youhuangla/images/main/20220126223956.png)
* sudo service mysql restart
* sudo systemctl restart apache2.service
* mysql>
    (password hide)
    * set password for USERTEST=password("*********");
    * create user USERTEST;
    * grant all privileges on DATABASETEST.* to USERTEST identified by"*********";
* 
``` bash
youhuangla@Ubuntu html % ls                                                                    [0]
index.html   wp-activate.php       wp-config-sample.php  wp-links-opml.php  wp-settings.php
index.php    wp-admin              wp-content            wp-load.php        wp-signup.php
license.txt  wp-blog-header.php    wp-cron.php           wp-login.php       wp-trackback.php
readme.html  wp-comments-post.php  wp-includes           wp-mail.php        xmlrpc.php
youhuangla@Ubuntu html % vim wp-config-sample.php                                              [0]
youhuangla@Ubuntu html % cp wp-config-sample.php wp-config.php 

```

* visit http://39.96.76.106/index.php
    * change aliyun security
    
    https://developer.aliyun.com/ask/104886?spm=a2c6h.13159736

* http://39.96.76.106/phpmyadmin/
The requested URL was not found on this server. Apache/2.4.29 (Ubuntu) Server


https://stackoverflow.com/questions/7584876/apache-2-the-requested-url-was-not-found-on-this-server


If you want to make it work without changing port you can follow these steps

sudo nano /etc/apache2/apache2.conf
and add following line at end

Include /etc/phpmyadmin/apache.conf
then restart apache

/etc/init.d/apache2 restart
Better explain here https://askubuntu.com/questions/55280/phpmyadmin-is-not-working-after-i-installed-it
* http://39.96.76.106/phpmyadmin/
建立数据库连接时出错
    * 解决WordPress建立数据库连接时出错
      https://www.wpdaxue.com/error-establishing-a-database-connection.html
    ![](https://raw.githubusercontent.com/youhuangla/images/main/20220127001151.png)
    ![](https://raw.githubusercontent.com/youhuangla/images/main/20220127001344.png)
    ![](https://raw.githubusercontent.com/youhuangla/images/main/20220127001450.png)![](https://raw.githubusercontent.com/youhuangla/images/main/20220127001527.png)
* User:park
* Password:************
