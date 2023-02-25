# Setting

## Error

[Cannot open Local Terminal Failed to start powershell.exe in C:\\Users\\\.\.\.\.\.\.\.的原因（高效解决）_MengYa\_DreamZ的博客\-CSDN博客](https://blog.csdn.net/MengYa_Dream/article/details/121142905)



### Turn cmd to bash

[让 windows 10 拥有高颜值的 terminal 和 linux shell 的命令_phenhorlin2的博客-CSDN博客_windows terminal linux state](https://blog.csdn.net/phenhorlin2/article/details/103584788)

```bash
E:\JavaSE_Code\hello\idea_test>bash

Administrator@DESKTOP-0O633M1 MINGW32 /e/JavaSE_Code/hello/idea_test
$ ls
idea_test.iml  src

```

## Github

**how to create git repo and push to github.com? where can i find the above information on  github's document?**

Here are the steps to create a Git repository and push it to GitHub:

1.  Initialize a Git repository in your local machine:

```
$ git init
```

1.  Add files to the repository:

```
$ git add .
```

1.  Commit the changes:

```
$ git commit -m "Initial commit"
```

1.  Create a new repository on GitHub.com and copy the repository URL.
2.  Add the remote repository to your local repository:

```
$ git remote add origin <repository-URL>
```

1.  Push the changes to the remote repository:

```
$ git push -u origin master
```

You can find this information and more in the official documentation at https://docs.github.com/en/github/getting-started-with-github/create-a-repo.



git remote add origin git@github.com:youhuangla/AcwingJavaCode.git     fatal: remote origin already exists.

**The error message "fatal: remote origin already exists" indicates that you have already added a remote named "origin" to your Git repository.**

To resolve this issue, you can either:

1.  Remove the existing "origin" remote and add a new one with the desired URL:

```
rubyCopy code$ git remote remove origin
$ git remote add origin git@github.com:youhuangla/AcwingJavaCode.git
```

1.  Or, you can rename the existing "origin" remote to a different name and add a new "origin" remote with the desired URL:

```
rubyCopy code$ git remote rename origin old-origin
$ git remote add origin git@github.com:youhuangla/AcwingJavaCode.git
```

You can check the remotes associated with your Git repository by running `git remote -v`, which will show you the names and URLs of all the remotes.