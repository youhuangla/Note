# git

```shell
git add .
git commit -a
# change the log
git push
```

[ Git 提交单个文件到指定分支 \- wangju003 \- 博客园](https://www.cnblogs.com/kaerxifa/p/12170223.html)

[拉取github报错 gnutls\_handshake\(\) failed: The TLS connection was non\-properly terminated\. \- 知乎](https://zhuanlan.zhihu.com/p/378894743)

## Github fatal

### 描述

首先，我代码感觉写得乱了，重新用 

```bash
git checkout commit-hash
```

把代码变到了之前commit的状态

然后 git push 出错

```bash
Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob ((47ed163...))
$ git add .

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob ((47ed163...))
$ git commit -m "Jump to login and registration pages from menu bar buttons"
[detached HEAD 2f3a8df] Jump to login and registration pages from menu bar buttons
 2 files changed, 17 insertions(+), 5 deletions(-)

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob ((2f3a8df...))
$ git push
fatal: You are not currently on a branch.
To push the history leading to the current (detached HEAD)
state now, use

    git push origin HEAD:<name-of-remote-branch>


Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob ((2f3a8df...))
$ git push origin HEAD:main
error: unable to push to unqualified destination: main
The destination refspec neither matches an existing ref on the remote nor
begins with refs/, and we are unable to guess a prefix based on the source ref.
error: failed to push some refs to 'git@git.acwing.com:youhuang/kob.git'

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob ((2f3a8df...))
$ git push origin HEAD:master
Enumerating objects: 19, done.
Counting objects: 100% (19/19), done.
Delta compression using up to 8 threads
Compressing objects: 100% (10/10), done.
Writing objects: 100% (10/10), 977 bytes | 977.00 KiB/s, done.
Total 10 (delta 8), reused 0 (delta 0)
To git.acwing.com:youhuang/kob.git
   47ed163..2f3a8df  HEAD -> master

```

一定要用 `git push origin HEAD:master` 才可以











### 解决

#### git push 到 master

**$ git push fatal: You are not currently on a branch. To push the history leading to the current (detached HEAD) state now, use git push origin HEAD:<name-of-remote-branch> 如果想下一次直接git push就能push到master该怎么做**

如果您想下一次直接git push就能push到master，您可以使用以下命令：

```
git push -u origin HEAD:master
```

这将把当前分支推送到远程的master分支，并将其设置为默认上游分支。这意味着，下一次您只需键入`git push`即可将更改推送到远程的master分支。[1](https://bing.com/search?q=如何将git+push到master)

#### 查看上游分支并更改为 master 分支

```bash
Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob ((e70c37a...))
$ git push -u origin HEAD:master
Enumerating objects: 15, done.
Counting objects: 100% (15/15), done.
Delta compression using up to 8 threads
Compressing objects: 100% (8/8), done.
Writing objects: 100% (8/8), 946 bytes | 946.00 KiB/s, done.
Total 8 (delta 6), reused 0 (delta 0)
To git.acwing.com:youhuang/kob.git
   2f3a8df..e70c37a  HEAD -> master

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob ((e70c37a...))
$ git add .

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob ((e70c37a...))
$ git commit -m "Finish 4.2"
[detached HEAD 814a94a] Finish 4.2
 1 file changed, 1 insertion(+)

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob ((814a94a...))
$ git push
fatal: You are not currently on a branch.
To push the history leading to the current (detached HEAD)
state now, use

    git push origin HEAD:<name-of-remote-branch>

```



**为什么我使用了这个命令还是不行？如何查看目前的默认上游分支？**

如果您使用了以下命令：

```
git push -u origin HEAD:master
```

但是仍然无法推送到master分支，您可以使用以下命令查看当前分支的上游分支：

```
git branch -vv
```

[这将显示当前分支的上游分支名称和链接的工作目录（如果链接的工作目录存在）](https://wonderlust91.github.io/2021/10/11/git查看与修改当前分支的upstream分支/)[1](https://wonderlust91.github.io/2021/10/11/git查看与修改当前分支的upstream分支/)。

如果您想将当前分支的上游分支更改为master分支，您可以使用以下命令：

```
git branch --set-upstream-to=origin/master
```

[这将把当前分支的上游分支更改为远程的master分支](https://blog.csdn.net/xjj1314/article/details/111269837)[2](https://blog.csdn.net/xjj1314/article/details/111269837)。

```bash
Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob ((814a94a...))
$ git branch -vv
* (HEAD detached from 47ed163) 814a94a Finish 4.2
  master                       9647c7c [origin/master: behind 5] Imply the frontend topic of Register and Login

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob ((814a94a...))
$ git branch
* (HEAD detached from 47ed163)
  master

```

这里我以为已经是 master 分支了

但是其实应该是这样的

```bash
$ git branch -vv
* master        b309d2c [remotes/origin/master] Have finished 4.2
  origin/master 9647c7c [remotes/origin/master: behind 6] Imply the frontend topic of Register and Login

```

#### HEAD detached from xxxxxx

**$ git push fatal: You are not currently on a branch. To push the history leading to the current (detached HEAD) state now, use git push origin HEAD:<name-of-remote-branch> 还是报错，怎么直接用git push？**

这个错误通常是由于您当前处于“分离的HEAD”状态而引起的。这意味着您的本地分支不再与远程分支关联。如果您想将本地分支与远程分支关联，您可以使用以下命令：

```
git branch -M <branch_name> origin/<branch_name>
```

[这将重命名本地分支并将其与远程分支关联](https://stackoverflow.com/questions/30471557/git-push-master-fatal-you-are-not-currently-on-a-branch)[1](https://stackoverflow.com/questions/30471557/git-push-master-fatal-you-are-not-currently-on-a-branch)。

如果您想直接将当前分支推送到远程分支，您可以使用以下命令：

```
git push -f origin HEAD:<name-of-remote-branch>
```

[请注意，这可能会覆盖远程分支上的任何更改。如果您不确定自己在做什么，请小心使用此命令](https://stackoverflow.com/questions/62568185/what-does-the-git-error-you-are-not-currently-on-a-branch-mean)[2](https://stackoverflow.com/questions/62568185/what-does-the-git-error-you-are-not-currently-on-a-branch-mean)。

```bash
Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob ((814a94a...))
$ git branch -M master origin/master

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob ((814a94a...))
$ git push
fatal: You are not currently on a branch.
To push the history leading to the current (detached HEAD)
state now, use

    git push origin HEAD:<name-of-remote-branch>

```

#### git checkout branch-name-you-want

[github - Git push master fatal: You are not currently on a branch - Stack Overflow](https://stackoverflow.com/questions/30471557/git-push-master-fatal-you-are-not-currently-on-a-branch)

然后在这里找到

>   have you ensured that you really in a branch? use `git branch` and check if you are in a branch. if not, just `git checkout branch-name-you-want` and then `git push` is fine!
>
>   While a very simple answer, this is usually what fixes most of the problems leading to the OP's question. In my case, I had reverted back to an earlier commit, fixed some issues, and did a few pushes — but forgot that the HEAD was still detached! Your solution fixed everything for me. Thanks 🙏 
>
>   – [Gwyneth Llewelyn](https://stackoverflow.com/users/1035977/gwyneth-llewelyn)
>
>    [Sep 25, 2019 at 19:27](https://stackoverflow.com/questions/30471557/git-push-master-fatal-you-are-not-currently-on-a-branch#comment102601528_53496177)

```bash
Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob ((814a94a...))
$ git checkout master
Warning: you are leaving 1 commit behind, not connected to
any of your branches:

  814a94a Finish 4.2

If you want to keep it by creating a new branch, this may be a good time
to do so with:

 git branch <new-branch-name> 814a94a

Switched to a new branch 'master'
Branch 'master' set up to track remote branch 'master' from 'origin'.

```

**$ git checkout master Warning: you are leaving 1 commit behind, not connected to any of your branches: 814a94a Finish 4.2 If you want to keep it by creating a new branch, this may be a good time to do so with: git branch <new-branch-name> 814a94a Switched to a new branch 'master' Branch 'master' set up to track remote branch 'master' from 'origin'. 如何保留这个commit？**

>   您可以使用以下命令将此提交添加到新分支：
>
>   ```
>   git branch <new-branch-name> 814a94a
>   ```
>
>   这将创建一个名为 `<new-branch-name>` 的新分支，并将其设置为指向提交 `814a94a`。这样，您就可以在新分支上继续工作，而不会影响原始分支。

**能将这个commit合并到原始分支吗？**

>   是的，您可以使用以下命令将此提交合并到原始分支：
>
>   ```
>   git merge <new-branch-name>
>   ```
>
>   这将将 `<new-branch-name>` 分支中的更改合并到当前分支中。请注意，如果存在冲突，则需要解决冲突并提交更改。
>
>   已收到消息. 是的，您可以使用以下命令将此提交合并到原始分支： ``` git merge <new-branch-name> ``` 这将将 `<new-branch-name>` 分支中的更改合并到当前分支中。请注意，如果存在冲突，则需要解决冲突并提交更改。

```bash
Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git merge master
Already up to date.

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git push
Everything up-to-date

```

**`Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob ((814a94a...)) $ git checkout master Warning: you are leaving 1 commit behind, not connected to any of your branches: 814a94a Finish 4.2 If you want to keep it by creating a new branch, this may be a good time to do so with: git branch <new-branch-name> 814a94a Switched to a new branch 'master' Branch 'master' set up to track remote branch 'master' from 'origin'. Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master) $ git merge master Already up to date. Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master) $ git push `Everything up-to-date 为啥我git push之后发现该commit没有同步？**

>   如果您在本地分支上进行了更改并提交了更改，但是在将更改推送到远程存储库时发现该提交未同步，则可能是因为您的本地分支不是从远程分支派生的。在这种情况下，您需要使用以下命令将本地分支与远程分支关联：
>
>   ```
>   git branch --set-upstream-to=origin/<remote-branch-name> <local-branch-name>
>   ```
>
>   请将 `<remote-branch-name>` 替换为远程分支的名称，将 `<local-branch-name>` 替换为本地分支的名称。然后，您可以使用 `git push` 命令将更改推送到远程存储库。

```bash
Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
git add .

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git commit -m "Have finished 4.2"
[master b309d2c] Have finished 4.2
 1 file changed, 1 insertion(+)

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git push
Enumerating objects: 11, done.
Counting objects: 100% (11/11), done.
Delta compression using up to 8 threads
Compressing objects: 100% (6/6), done.
Writing objects: 100% (6/6), 504 bytes | 504.00 KiB/s, done.
Total 6 (delta 4), reused 0 (delta 0)
To git.acwing.com:youhuang/kob.git
   e70c37a..b309d2c  master -> master

Administrator@DESKTOP-0O633M1 MINGW32 ~/Desktop/spring/kob (master)
$ git branch -vv
* master        b309d2c [remotes/origin/master] Have finished 4.2
  origin/master 9647c7c [remotes/origin/master: behind 6] Imply the frontend topic of Register and Login

```

这里我重新提交了一遍，结果就好了

#### git checkout commit-hash 和git checkout branch-name-you-want

之前我弄webui谷歌笔记的时候使用了 `checkout commit-hash` 

**git checkout branch-name-you-want 有什么用**

>   这个命令可以将您的工作目录切换到指定的分支。如果您想切换到名为“branch-name-you-want”的分支，您可以使用以下命令：
>
>   ```
>   git checkout branch-name-you-want
>   ```
>
>   这将使您的工作目录切换到指定的分支，并将其设置为当前分支。请注意，如果该分支不存在，则会出现错误。

**将工作目录切换到指定的分支，代码会改变吗**

>   是的，如果您将工作目录切换到另一个分支，则代码将会改变。请注意，如果您在切换分支之前对代码进行了更改，则可能会出现冲突。在这种情况下，您需要解决冲突并提交更改。

**git checkout commit-hash 和git checkout branch-name-you-want 有什么区别**

>   `git checkout <commit-hash>` 命令将您的工作树切换到指定的提交，而 `git checkout <branch-name>` 命令将您的工作树切换到指定的分支。如果您使用 `git checkout <commit-hash>` 命令，您将进入“分离的 HEAD”状态，这意味着您不再位于任何分支上。在这种情况下，如果您进行了更改并提交了更改，则这些更改将不会与任何分支相关联。
>
>   另一方面，如果您使用 `git checkout <branch-name>` 命令，则会将您的工作树切换到指定的分支，并且如果您进行了更改并提交了更改，则这些更改将与该分支相关联。

#### 总结

总之，虽然解决了问题，能直接`git push` 了, 但是之前的commit也没了, 并没有搞很懂捏（

待会玩玩那个git游戏试试看

## 更改上一个git commit -m 提交的信息

**怎么更改上一个git commit -m 提交的信息**

>   您好，这是必应。😊
>
>   [要更改上一个 git commit -m 提交的信息，您可以使用 --amend 标志来修改最近的一次提交的信息](https://melvingeorge.me/blog/change-last-commit-message-git)[1](https://melvingeorge.me/blog/change-last-commit-message-git)[2](https://www.git-tower.com/learn/git/faq/edit-fix-commit-message/)[3](https://linuxize.com/post/change-git-commit-message/)[4](https://docs.github.com/en/pull-requests/committing-changes-to-your-project/creating-and-editing-commits/changing-a-commit-message)。例如：
>
>   ```bash
>   git commit -m "新的提交信息" --amend
>   ```
>
>   [这个命令会用新的提交覆盖最近的一次提交。如果您想要更改已经推送到服务器的提交的信息，您需要使用 --force 标志来强制推送您的更改](https://www.w3docs.com/snippets/git/how-to-change-commit-message.html)[5](https://www.w3docs.com/snippets/git/how-to-change-commit-message.html)，否则您的推送会被拒绝。例如：
>
>   ```bash
>   git push origin main --force
>   ```

[Fix can't logout Bug in 'Refresh, the login page flash and go to home' (e05e7698) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/e05e76980c74327a04648c71c61c9f7696a4928d)

## js的Vue3项目Todolist小记

git 同步过程中，由于出现

>   Person: 
>   - PS E:\github\Todolist_Demo_Vue3> git remote show origin
>   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
>   @    WARNING: REMOTE HOST IDENTIFICATION HAS CHANGED!     @
>   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
>   IT IS POSSIBLE THAT SOMEONE IS DOING SOMETHING NASTY!
>   Someone could be eavesdropping on you right now (man-in-the-middle attack)!
>   It is also possible that a host key has just been changed.
>   The fingerprint for the RSA key sent by the remote host is
>   SHA256:uNiVztksCsDhcc0u9e8BujQXVUpKZIDTMcz。。。。。。。。.
>   Please contact your system administrator.
>   Add correct host key in /c/Users/Administrator/.ssh/known_hosts to get rid of this message.
>   Offending RSA key in /c/Users/Administrator/.ssh/known_hosts:1
>   RSA host key for github.com has changed and you have requested strict checking.
>   Host key verification failed.
>   fatal: Could not read from remote repository.
>
>   Please make sure you have the correct access rights
>   and the repository exists.
>
>   ChatGPT: 
>   - 根据您提供的错误信息，Git 报告了一个致命错误，指示远程主机的身份验证发生了变化，并且可能存在中间人攻击。这通常是由于远程主机的 SSH 密钥发生了变化而导致的。为了确保您的连接安全，Git 拒绝了与远程主机的连接。
>
>   解决这个问题的方法是更新本地计算机上与远程主机 `github.com` 相关的已知主机密钥。但在这之前，请确保您真的在意这个问题并了解发生的原因。此警告可能由以下原因之一引起： 
>   1. **远程主机更换了SSH密钥** ：GitHub 等服务提供商有时会更新其密钥。通常情况下，这是正常的，并不表示存在安全问题。 
>   2. **您连接到了恶意的中间人** ：在某些情况下，网络中的攻击者可能尝试进行中间人攻击。这是一种安全风险，应该避免连接到不受信任的网络。
>
>   为了解决此问题，您可以按照以下步骤操作： 
>   1. **备份 known_hosts 文件** ：首先，建议您备份 `/c/Users/Administrator/.ssh/known_hosts` 文件，这样以后可以恢复。 
>   2. **更新 known_hosts 文件** ：打开 `/c/Users/Administrator/.ssh/known_hosts` 文件，并删除第一行（Offending RSA key）。然后，尝试重新运行之前的 Git 命令。 
>   3. **进行安全检查** ：在确保远程主机的身份验证确实合法后，可以再次连接。确保您连接到真正的 GitHub 主机，而不是中间人。
>
>   如果您不确定如何解决此问题，建议您联系系统管理员或向 GitHub 支持寻求帮助，以确保您的连接安全。
>
>   Person: 
>   - 有没有可能是本机更换了密钥？
>
>   ChatGPT: 
>   - 是的，确实有可能是本机更换了密钥导致了这个问题。当您在本机连接到远程主机（例如 GitHub）时，会在本机的 `~/.ssh/known_hosts` 文件中保存远程主机的公钥信息。这样，下次连接时，Git 会验证远程主机的公钥是否匹配已保存的公钥信息，以确保连接的安全性。
>
>   如果您在本机更换了密钥或更新了远程主机的密钥（例如重新安装操作系统或重置SSH密钥），Git 将会提示警告，因为公钥信息不再匹配。
>
>   如果您确认在本机更换了密钥，可以按照以下步骤来解决问题： 
>   1. 备份 `known_hosts` 文件（可选）：如果您在更新之前还没有备份过 `known_hosts` 文件，请先备份该文件，以防止意外删除现有的公钥信息。 
>   2. 更新 `known_hosts` 文件：打开 `~/.ssh/known_hosts` 文件，并删除与 GitHub 相关的行（可能有多行）。然后，保存文件。 
>   3. 重新连接远程主机：运行之前的 Git 命令，例如 `git push -u origin main`，Git 会重新获取 GitHub 的公钥信息，并将其保存在 `known_hosts` 文件中。
>
>   请注意，更新 `known_hosts` 文件时，务必小心，确保删除正确的行，并且确保您在连接时是连接到真正的 GitHub 主机。确保您的密钥更新是合法和可信的，以防止中间人攻击。
>
>   如果您不确定如何处理此问题，或担心出现安全问题，请务必咨询系统管理员或向 GitHub 支持寻求帮助。他们将能够提供更准确的指导和解决方案。

在本机的`C:\Users\Administrator\.ssh`中删除了对应含有“github”行，最后发现仍然不行。然后根据IP删除了对应行。

>   ```powershell
>   PS E:\github\Todolist_Demo_Vue3> git push -u origin main
>   error: src refspec main does not match any.
>   error: failed to push some refs to 'git@github.com:youhuangla/Todolist_Demo_Vue3.git'
>   PS E:\github\Todolist_Demo_Vue3>
>   ```
>
>   ChatGPT:  根据您提供的输出信息，执行 `git push -u origin main` 命令时再次出现了错误：
>
>   ```
>   error: src refspec main does not match any.
>   error: failed to push some refs to 'git@github.com:youhuangla/Todolist_Demo_Vue3.git'
>   ```
>
>   这个错误通常意味着本地的 `main` 分支在您的本地仓库中存在，但没有与任何提交记录关联。Git 找不到与 `main` 分支相关的提交记录，因此无法推送。
>
>   出现这个错误的原因可能有以下几种情况：
>
>   1. **空的 `main` 分支**：`main` 分支可能存在于本地仓库中，但是没有进行任何提交，因此 Git 找不到提交记录。
>
>   2. **分支名错误**：在某些情况下，如果仓库的默认分支是 `main`，而不是 `master`，您可能需要将本地分支名更改为 `main`，然后再进行推送。
>
>   为了解决这个问题，您可以按照以下步骤操作：
>
>   1. 确认本地 `main` 分支存在：使用以下命令查看本地仓库中的分支列表，并确保 `main` 分支存在：
>
>      ```
>      git branch
>      ```
>
>      如果 `main` 分支不存在，请确认是否正确创建了该分支，并且在该分支上进行了一些提交操作。
>
>   2. 确认远程 `origin` 仓库：使用以下命令查看远程仓库列表，并确保远程仓库 `origin` 是正确的：
>
>      ```
>      git remote -v
>      ```
>
>      如果远程仓库不正确，您可以使用以下命令添加正确的远程仓库：
>
>      ```
>      git remote add origin <远程仓库URL>
>      ```
>
>   3. 确认分支关联：使用以下命令查看本地 `main` 分支是否与远程的 `origin/main` 分支正确关联：
>
>      ```
>      git branch -vv
>      ```
>
>      确保输出中的 `main` 分支有关联的远程分支。
>
>   4. 进行提交：如果本地的 `main` 分支为空，请先进行一些提交操作：
>
>      ```
>      git add .
>      git commit -m "Your initial commit message here"
>      ```
>
>      将 `"Your initial commit message here"` 替换为您的提交信息。
>
>   5. 进行推送：完成提交后，再次尝试推送：
>
>      ```
>      git push -u origin main
>      ```
>
>   请注意，执行推送操作前，请确保您在本地的 `main` 分支上进行了一些提交操作。如果您在推送之前尚未进行任何更改，Git会提示无法推送空的 `main` 分支。
>
>   如果您在执行以上操作时仍然遇到问题，请提供更多详细的错误信息，以便我能够更好地帮助您解决问题。

另在本地仓库中无文件直接push会出现以上报错，push前先确定仓库不为空。
