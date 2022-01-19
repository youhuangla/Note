# Tmux
http://www.ruanyifeng.com/blog/2019/10/tmux.html
## What's tmux
命令行的典型使用方式是，打开一个终端窗口（terminal window，以下简称"窗口"），在里面输入命令。用户与计算机的这种临时的交互，称为一次"会话"（session） 。

会话的一个重要特点是，窗口与其中启动的进程是连在一起的。打开窗口，会话开始；关闭窗口，会话结束，会话内部的进程也会随之终止，不管有没有运行完。

一个典型的例子就是，SSH 登录远程计算机，打开一个远程窗口执行命令。这时，网络突然断线，再次登录的时候，是找不回上一次执行的命令的。因为上一次 SSH 会话已经终止了，里面的进程也随之消失了。

为了解决这个问题，会话与窗口可以"解绑"：窗口关闭时，会话并不终止，而是继续运行，等到以后需要的时候，再让会话"绑定"其他窗口。
## What can tmux do?
 Tmux 就是会话与窗口的"解绑"工具，将它们彻底分离。

（1）它允许在单个窗口中，同时访问多个会话。这对于同时运行多个命令行程序很有用。

（2） 它可以让新窗口"接入"已经存在的会话。

（3）它允许每个会话有多个连接窗口，因此可以多人实时共享会话。

（4）它还支持窗口任意的垂直和水平拆分。
## How to use tmux?
Tmux 窗口有大量的快捷键。所有快捷键都要通过前缀键唤起。默认的前缀键是Ctrl+b，即先按下Ctrl+b，快捷键才会生效。

举例来说，帮助命令的快捷键是Ctrl+b ?。它的用法是，在 Tmux 窗口中，先按下Ctrl+b，再按下?，就会显示帮助信息。

然后，按下 ESC 键或q键，就可以退出帮助。
### Enter
    $ tmux
### Exit
* ^d
* type "exit"
### Detach
在 Tmux 窗口中，按下Ctrl+b d或者输入tmux detach命令，就会将当前会话与窗口分离。
```zsh
$ tmux detach
```
上面命令执行后，就会退出当前 Tmux 窗口，但是会话和里面的进程仍然在后台运行。
## Kill
tmux kill-session命令用于杀死某个会话。
```shell
# 使用会话编号
$ tmux kill-session -t 0
```
### Switch
tmux switch命令用于切换会话。
```zsh
# 使用会话编号
$ tmux switch -t 0
```
## Easy mode
* 新建会话
```
tmux new -s my_session。
```
* 在 Tmux 窗口运行所需的程序。
* 按下快捷键Ctrl+b d将会话分离。
* 下次使用时，重新连接到会话
```
tmux attach-session -t my_session
```
## Pane Opt