# proxy

* An attempt was made to access a socket in a way forbidden by its access perm
<https://blog.csdn.net/qq_40646143/article/details/79593958>

## Change port

### Git

Change to port: 4780:

```shell
PS E:\github\Note> git config --global http.proxy http://127.0.0.1:4780
PS E:\github\Note> git config --global https.proxy http://127.0.0.1:4780
```

[Vscode解决 Failed to connect to github\.com port 443:connection timed out\_小牲口online的博客\-CSDN博客\_vscode登不上github](https://blog.csdn.net/M_Edison/article/details/114186264)

[git \- GitHub \- failed to connect to github 443 windows/ Failed to connect to gitHub \- No Error \- Stack Overflow](https://stackoverflow.com/questions/18356502/github-failed-to-connect-to-github-443-windows-failed-to-connect-to-github)

```
git config --global https.proxy https://127.0.0.1:7890
git config --global http.proxy http://127.0.0.1:7890 
```

[【已解决】OpenSSL SSL\_connect: Connection was reset in connection to github\.com:443\_雷恩Layne的博客\-CSDN博客\_openssl ssl\_connect: connection was reset in conne](https://blog.csdn.net/qq_37555071/article/details/114260533)

### mktemp error

```
PS E:\github\Note> git push
mktemp: failed to create file via template ‘/c/Users/Public/Documents/Wondershare/CreatorTemp/tmp.XXXXXXXXXX’: No such file or directory
```

The error 'mktemp: failed to create file via template' while using Git push on Windows can occur when the temporary files required by Git are not able to be created. This can happen due to various reasons such as incorrect file permissions, limited storage space, or antivirus software interference.

Here are a few steps you can try to resolve this issue:

1.  Upgrade Git to the latest version.
2.  Disable the antivirus software temporarily and try again.
3.  Increase the temporary file space available on your system.
4.  Run Git as an administrator.

If these steps do not resolve the issue, try searching for solutions specific to your operating system and Git version.
