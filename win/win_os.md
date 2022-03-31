# Windows

## 虚拟内存

1. 右键计算机->属性->高级系统设置->高级->性能->设置->高级->虚拟内存->更改

![设置](https://raw.githubusercontent.com/youhuangla/images/main/202202092011899.png)

![高级](https://raw.githubusercontent.com/youhuangla/images/main/202202092017347.png)
2. 更改虚拟内存后要点击设置才算保存

[如何配置Windows实例的虚拟内存](https://help.aliyun.com/document_detail/40995.htm?spm=a2c4g.11186623.0.0.71af1323T7fTtH)
[Windows虚拟内存不足问题的处理](https://help.aliyun.com/document_detail/41046.html#kzGCz)

## 语言

- win输入法快捷键"Ctrl +　,"、"Ctrl + space"总是与vscode冲突的解决方案

![](https://raw.githubusercontent.com/youhuangla/images/main/202202172227165.png)

![](https://raw.githubusercontent.com/youhuangla/images/main/202202172229549.png)

![](https://raw.githubusercontent.com/youhuangla/images/main/202202172257583.png)

![](https://raw.githubusercontent.com/youhuangla/images/main/202202172258712.png)

![](https://raw.githubusercontent.com/youhuangla/images/main/202202172258369.png)

- 现在vscode中'ctrl + space'就可以显示代码补全选项了

## USB

### USB占用后如何弹出

- 提示程序占用USB设备
- 使用[在Windows中，U盘或者移动硬盘关不掉时，怎么知道是被哪个程序占用了呢？ - 张大侠的回答 - 知乎](https://www.zhihu.com/question/22579281/answer/1883600510)的最后一个方法
- 右键左下角win图标，打开事件查看器

![](https://raw.githubusercontent.com/youhuangla/images/main/202202232143389.png)

- 从上图中可知一个程序HiSuite停止删除或弹出一个USB设备，容易得知该程序为华为手机助手，pid（进程号）为7528
- 从[windows使用命令行杀进程](https://www.cnblogs.com/shindo/p/5959329.html)中，得知应使用taskkill命令，但是直接在cmd中可能拒绝访问

```powershell
PS C:\Users\Administrator> taskkill /pid 7528 -t -f;
错误: 无法终止 PID 7528 (属于 PID 21260 子进程)的进程。
原因: 拒绝访问。
```

- 应右键左下角win图标打开Powershell(管理员)，并成功杀死进程
- 成功拔出！

## Kill-Shift-Space

[Svtter/Kill\-Shift\-Space: 屏蔽掉 win10 的 shift\+space](https://github.com/Svtter/Kill-Shift-Space)

[在 Windows 10 中添加在启动时自动运行的应用](https://support.microsoft.com/zh-cn/windows/%E5%9C%A8-windows-10-%E4%B8%AD%E6%B7%BB%E5%8A%A0%E5%9C%A8%E5%90%AF%E5%8A%A8%E6%97%B6%E8%87%AA%E5%8A%A8%E8%BF%90%E8%A1%8C%E7%9A%84%E5%BA%94%E7%94%A8-150da165-dcd9-7230-517b-cf3c295d89dd)

[Win10 取消百度输入法 Shift\+Space 全角半角切换\_锦夏挽秋的博客\-CSDN博客\_百度输入法shift](https://blog.csdn.net/qq1337715208/article/details/103334455)
