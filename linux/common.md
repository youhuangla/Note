# Common

## Install and unistall

* Search for software to be installed

```zsh
sudo apt-cache search
```

* <https://www.cnblogs.com/SunshineKimi/p/12291982.html>

apt-get remove: 卸载软件

apt-get purge: 卸载软件和配置文件

apt-get autoremove: 移除没有使用的依赖

[command line \- What is the correct way to completely remove an application? \- Ask Ubuntu](https://askubuntu.com/questions/187888/what-is-the-correct-way-to-completely-remove-an-application)

## Copy folder

[cp \- How do I copy folder with files to another folder in Unix/Linux? \- Stack Overflow](https://stackoverflow.com/questions/14922562/how-do-i-copy-folder-with-files-to-another-folder-in-unix-linux)

## Listing files by file extension

The **ls** command doesn’t analyze file types by content, but works with file names. There is, however, a command option that can list files by extension. If you add the **-X** option, **ls** will sort files by name within each extension category. For example, it will list files without extensions first (in alphanumeric order) followed by files with extensions like .1, .bz2, .c and so on.

## Ps command

ps - report a snapshot of the current processes.

```shell
youhuangla@Ubuntu c_lab % ps                                                                                        [0]
  PID TTY          TIME CMD
  333 pts/10   00:00:00 ps
22949 pts/10   00:00:00 zsh
32318 pts/10   00:00:00 cgdb
```

Find suspended use `bg`:

[suspend \- List only processes that are in suspended mode \- Ask Ubuntu](https://askubuntu.com/questions/897392/list-only-processes-that-are-in-suspended-mode)

kill suspended :

[signals \- Kill a suspended process? \- Unix & Linux Stack Exchange](https://unix.stackexchange.com/questions/223408/kill-a-suspended-process)

```shell
youhuangla@Ubuntu c_lab % kill -KILL %1                                                                             [0]
[1]  + 32318 killed     cgdb a.out                                                                                      
youhuangla@Ubuntu c_lab % bg                                                                                        [0]
bg: no current job
```

## sysstat

### Sar

由于阿里云莫名 cpu 占用过高导致打不开故查看 cpu 情况。

top 命令可以实时查看。

[How to Check Linux CPU Usage or Utilization? \{Easy Way\}](https://phoenixnap.com/kb/check-cpu-usage-load-linux)

[Linux命令之sar——查看服务器某一段时间内的CPU情况【系统性能检测】\_听说唐僧不吃肉的博客\-CSDN博客\_sar命令查看cpu](https://blog.csdn.net/xu710263124/article/details/117437977)

[Linux : sar command return “Cannot open /var/log/sysstat/sa27: No such file or directory” \| ITechLounge\.net](https://www.itechlounge.net/2020/08/linux-sar-command-return-cannot-open-var-log-sysstat-sa27-no-such-file-or-directory/)

```shell
youhuangla@Ubuntu ~ % sar -u                                                                                                 [2]
Cannot open /var/log/sysstat/sa14: No such file or directory
Please check if data collecting is enabled
youhuangla@Ubuntu ~ % vim /etc/default/sysstat                                                                               [2]
youhuangla@Ubuntu ~ % sudo vim /etc/default/sysstat                                                                          [0]
youhuangla@Ubuntu ~ % /etc/init.d/sysstat restart                                                                            [0]
[....] Restarting sysstat (via systemctl): sysstat.serviceFailed to restart sysstat.service: The name org.freedesktop.PolicyKit1 was not provided by any .service files
See system logs and 'systemctl status sysstat.service' for details.
 failed!
youhuangla@Ubuntu ~ % sudo /etc/init.d/sysstat restart                                                                       [1]
[ ok ] Restarting sysstat (via systemctl): sysstat.service.
youhuangla@Ubuntu ~ % sar -u                                                                                                 [0]
Linux 4.15.0-139-generic (Ubuntu)       06/14/22        _x86_64_        (2 CPU)

13:34:06     LINUX RESTART      (2 CPU)
```



```shell
sar -o datafile interval count >/dev/null 2>&1 &

       All data are captured in binary form and saved to a file (datafile).  The data can then be selective
ly displayed  with
       the  sar command using the -f option. Set the interval and count parameters to select count records 
at interval second
       intervals. If the count parameter is not set, all the records saved in the file will be selected.  C
ollection of  data
       in this manner is useful to characterize system usage over a period of time and determine peak usage
 hours.

```

[shell \- What is /dev/null 2>&1? \- Stack Overflow](https://stackoverflow.com/questions/10508843/what-is-dev-null-21)

[Linux Crash Course \- The sar Command \- YouTube](https://www.youtube.com/watch?v=_4WVPSfGqos&ab_channel=LearnLinuxTV)

## Ps

```shell
youhuangla@Ubuntu sysstat % sudo ps -eo pcpu,pid,user,args| sort  -k 1 -r | head -10                               [0]
CPU   PID USER     COMMAND
 2.5  1074 root     /usr/local/aegis/aegis_client/aegis_11_27/AliYunDun
 2.0  2698 youhuan+ /usr/bin/clangd-9 -j 48
 1.1  2653 youhuan+ /home/youhuangla/.vscode-server/bin/30d9c6cd9483b2cc586687151bcbcd635f373630/node /home/youhuangla/.vscode-server/bin/30d9c6cd9483b2cc586687151bcbcd635f373630/out/bootstrap-fork --type=extensionHost --transformURIs --useHostProxy=false
 0.8  2868 youhuan+ /usr/bin/zsh
 0.8  2540 youhuan+ /home/youhuangla/.vscode-server/bin/30d9c6cd9483b2cc586687151bcbcd635f373630/node /home/youhuangla/.vscode-server/bin/30d9c6cd9483b2cc586687151bcbcd635f373630/out/server-main.js --start-server --host=127.0.0.1 --accept-server-license-terms --enable-remote-auto-shutdown --port=0 --telemetry-level all --connection-token-file /home/youhuangla/.vscode-server/.30d9c6cd9483b2cc586687151bcbcd635f373630.token
 0.5  2055 youhuan+ -zsh
 0.4  2614 youhuan+ /home/youhuangla/.vscode-server/bin/30d9c6cd9483b2cc586687151bcbcd635f373630/node /home/youhuangla/.vscode-server/bin/30d9c6cd9483b2cc586687151bcbcd635f373630/out/bootstrap-fork --type=ptyHost
 0.2   890 root     CmsGoAgent-Worker start
 0.1  2664 youhuan+ /home/youhuangla/.vscode-server/bin/30d9c6cd9483b2cc586687151bcbcd635f373630/node /home/youhuangla/.vscode-server/bin/30d9c6cd9483b2cc586687151bcbcd635f373630/out/bootstrap-fork --type=fileWatcher
```

[Find Processes Using Most CPU Linux](https://linuxhint.com/find-processes-using-cpu-linux/)
