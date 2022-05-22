# Common

* Search for software to be installed

```zsh
sudo apt-cache search
```

* <https://www.cnblogs.com/SunshineKimi/p/12291982.html>

apt-get remove: 卸载软件

apt-get purge: 卸载软件和配置文件

apt-get autoremove: 移除没有使用的依赖

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

