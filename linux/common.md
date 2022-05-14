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
