# Jupyter notebook

## Start

```powershell
PS C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Anaconda3 (64-bit)> ls


    目录: C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Anaconda3 (64-bit)


Mode                 LastWriteTime         Length Name
----                 -------------         ------ ----
-a----          2023/1/6     21:47           1199 Anaconda Navigator (Anaconda3).lnk
-a----          2023/1/6     21:47           2512 Anaconda Powershell Prompt (Anaconda3).lnk
-a----          2023/1/6     21:47           2038 Anaconda Prompt (Anaconda3).lnk
-a----          2023/1/6     21:47           1168 Jupyter Notebook (Anaconda3).lnk
-a----          2023/1/6     21:47           1180 Reset Spyder Settings (Anaconda3).lnk
-a----          2023/1/6     21:47           1163 Spyder (Anaconda3).lnk
```

Open  Anaconda Powershell Prompt 

Use cd to Enter a dir

```powershell
(base) PS C:\Users\Administrator> cd E:\Study\数学\程序员数学\源代码文件\Math-for-Programmers-master
(base) PS E:\Study\数学\程序员数学\源代码文件\Math-for-Programmers-master> jupyter notebook
```

## Bug	

jupyter连接不到内核

>   # 3、jupyter连接不到内核
>
>   如果遇到jupyter连接不到内核等其他问题，升级下jupyter。升级命令：pip install -U jupyter，然后升级notebook，升级命令：pip install -U notebook --upgrade。如果还是不行的话，就重启下jupyter或者电脑，也许有惊喜噢，重启大法好！
>
>   
>
>   作者：Python进阶者
>   链接：https://juejin.cn/post/7107131869216374820
>   来源：稀土掘金
>   著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。