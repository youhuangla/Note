# extension

## Run Snippets in Markdown

[Run Snippets in Markdown \- Visual Studio Marketplace](https://marketplace.visualstudio.com/items?itemName=statiolake.vscode-markdown-run-snippet)

Select a snippets and Ctrl+Shift+P, runRun Snippets in Markdown.

## C/C++ Compile Run

[VScode tasks\.json和launch\.json的设置 \- 知乎](https://zhuanlan.zhihu.com/p/92175757)

今天搞个链接数学库函数搞了半天，才发现是tasks.json和launch.json理解有问题。

tasks用于在launch前执行任务，launch用于读取执行文件。

另外，在搜索框里输入 C_Cpp.errorSquiggles，将错误提醒设置为打开状态或关闭状态（有一次试图quick fix不小心关了。。要记得看好选项）

[Get Started with C\+\+ on Linux in Visual Studio Code](https://code.visualstudio.com/docs/cpp/config-linux)

## Clangd

<img src="img/image-20220509231010301.png" alt="image-20220509231010301" style="zoom: 50%;" />

提示和微软冲突

<img src="img/image-20220509230943413.png" alt="image-20220509230943413" style="zoom:50%;" />

disable一波

![image-20220509230847704](img/image-20220509230847704.png)

![image-20220509231244425](img/image-20220509231244425.png)

### 安装clangd

[远程开发C++_4.Linux下如何打造C++完美开发IDE：clangd_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV16g411N77i?spm_id_from=333.337.search-card.all.click)

[Getting started](https://clangd.llvm.org/installation.html)

```shell
sudo apt-get install clangd-9

youhuangla@Ubuntu 4-0 % clangd-9                                                                             [0]
clangd is a language server that provides IDE-like features to editors.

It should be used via an editor plugin rather than invoked directly. For more information, see:
        https://clang.llvm.org/extra/clangd/
        https://microsoft.github.io/language-server-protocol/

clangd accepts flags on the commandline, and in the CLANGD_FLAGS environment variable.

I[23:20:38.320] clangd version 9.0.0-2~ubuntu18.04.2 (tags/RELEASE_900/final)
I[23:20:38.321] Working directory: /home/youhuangla/accelerated_cpp/4/4-0
I[23:20:38.321] argv[0]: clangd-9
I[23:20:38.321] Starting LSP over stdin/stdout
^C
```

#### 配置

<img src="img/image-20220509232603109.png" alt="image-20220509232603109" style="zoom:33%;" />

<img src="img/image-20220509232629210.png" alt="image-20220509232629210" style="zoom:50%;" />

#### Path

```shell
youhuangla@Ubuntu 4-0 % where clangd-9                                                                       [1]
/usr/bin/clangd-9
```

<img src="img/image-20220509232953793.png" alt="image-20220509232953793" style="zoom:50%;" />

<img src="img/image-20220509233040593.png" alt="image-20220509233040593" style="zoom:50%;" />

可以了！

### clang-format

The 'clang-format' command is not available.

```shell
sudo apt install clang-format
```

![image-20220510165442591](img/image-20220510165442591.png)

#### help

```shell
clang-format -help
```

### auto complete function

After auto complete function, use Tab key to switch to the next argument.

### .clang-format

In ~ directory:

[VS Code \+ Clang\-format 格式化代码 \- 知乎](https://zhuanlan.zhihu.com/p/356143396#:~:text=VS%20Code%20C%2B%2B%20%E4%BB%A3%E7%A0%81%E6%A0%BC%E5%BC%8F%E5%8C%96%E6%96%B9%E6%B3%95&text=2.%20%E6%89%93%E5%BC%80%E9%A6%96%E9%80%89%E9%A1%B9%E8%AE%BE%E7%BD%AE,%E6%A0%BC%E5%BC%8F%E8%87%AA%E5%8A%A8%E6%A0%BC%E5%BC%8F%E5%8C%96%E4%BB%A3%E7%A0%81%E3%80%82)

### 
