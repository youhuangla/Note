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
git config --global https.proxy https://127.0.0.1:7890 && git config --global http.proxy http://127.0.0.1:7890 
```

[【已解决】OpenSSL SSL\_connect: Connection was reset in connection to github\.com:443\_雷恩Layne的博客\-CSDN博客\_openssl ssl\_connect: connection was reset in conne](https://blog.csdn.net/qq_37555071/article/details/114260533)

### mktemp error

```
PS E:\github\Note> git push
mktemp: failed to create file via template ‘/c/Users/Public/Documents/Wondershare/CreatorTemp/tmp.XXXXXXXXXX’: No such file or directory
```

#### Chatgpt

**when I use git push on windows, error 'mktemp: failed to create file via template'**

>The error 'mktemp: failed to create file via template' while using Git push on Windows can occur when the temporary files required by Git are not able to be created. This can happen due to various reasons such as incorrect file permissions, limited storage space, or antivirus software interference.
>
>Here are a few steps you can try to resolve this issue:
>
>1.  Upgrade Git to the latest version.
>2.  Disable the antivirus software temporarily and try again.
>3.  Increase the temporary file space available on your system.
>4.  Run Git as an administrator.
>
>If these steps do not resolve the issue, try searching for solutions specific to your operating system and Git version.

[mktemp: failed to create file via template ‘/tmp/setup\.sh\.XXXXXXXXXX\_步印的博客\-CSDN博客\_temp/setup\.sh](https://blog.csdn.net/weixin_43046653/article/details/104036505)

I make a directory and solve the problem



**When I use git push, I want a file to exist locally on my computer but not on github?**

>You can use a .gitignore file to specify files or directories that should not be tracked by Git and thus not be pushed to GitHub.
>
>Here's how to do it:
>
>1.  Create a .gitignore file in your local repository.
>
>2.  Add the file name or directory path that you want to exclude from version control to the .gitignore file. For example, if you want to exclude a file named "secret.txt", add the following line to the .gitignore file:
>
>    ```
>    Copy code
>    secret.txt
>    ```
>
>3.  Commit the changes to the .gitignore file and push it to the remote repository.
>
>From this point on, Git will ignore the specified files or directories, and they will not be included in future pushes to GitHub. Note that the exclusion will only apply to future changes, so if the file has already been tracked and pushed to GitHub, it will need to be removed manually.
>
>
>
>





**on windows10, I want to ignore a file in the subfolder.File's named and path is 'E:\github\Note\AI\NovelAI\novelai.md'.How should I write gitignore?**



>To ignore a file in a subfolder in Windows, you can use the relative path of the file in the .gitignore file.
>
>Here's how to ignore the file "novelai.md" located in the subfolder "E:\github\Note\AI\NovelAI":
>
>1.  Create a .gitignore file in the root of your local repository if you don't already have one.
>
>2.  Open the .gitignore file in a text editor.
>
>3.  Add the following line to the file:
>
>    ```
>    AI/NovelAI/novelai.md
>    ```
>
>4.  Save and close the .gitignore file.
>
>5.  Commit the changes to the .gitignore file and push it to the remote repository.
>
>From this point on, Git will ignore the specified file and it will not be included in future pushes to GitHub. Note that the exclusion will only apply to future changes, so if the file has already been tracked and pushed to GitHub, it will need to be removed manually.



```
git push To https://github.com/youhuangla/Note.git ! [rejected]        main -> main (fetch first) error: failed to push some refs to 'https://github.com/youhuangla/Note.git' hint: Updates were rejected because the remote contains work that you do hint: not have locally. This is usually caused by another repository pushing hint: to the same ref. You may want to first integrate the remote changes
```

>   The error message "Updates were rejected because the remote contains work that you do not have locally" means that the remote repository on GitHub has been updated with new changes that you do not have on your local repository. This can happen when multiple people are working on the same repository and pushing changes at the same time.
>
>   To resolve this issue, you'll need to first fetch and merge the remote changes into your local repository and then try pushing again. Here's how to do it:
>
>   1.  Run the following command in your terminal:
>
>       ```
>       git fetch origin
>       ```
>
>       This will retrieve the latest changes from the remote repository on GitHub.
>
>   2.  Run the following command to merge the remote changes into your local repository:
>
>       ```
>       git merge origin/main
>       ```
>
>       If there are any conflicts, resolve them in your local repository.
>
>   3.  Once you have successfully merged the remote changes, try pushing your local changes again:
>
>       ```
>       git push origin main
>       ```
>
>   By following these steps, you should be able to push your changes to the remote repository on GitHub.
>
>   



