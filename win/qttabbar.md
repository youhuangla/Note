# qttabbar

[大佬魔改后的中文优化版，终于解决我多年的难题！ (qq.com)](https://mp.weixin.qq.com/s?__biz=MzA5NjEwNjE0OQ==&mid=2247501894&idx=1&sn=0f796b90543cad39a3c8bbd99ed7810c&chksm=90b7ab8ca7c0229a197bec8bdc5d6ead6429ea7ea74a3bc6549da3ceae012ac685a4748943c3#rd)

[indiff/qttabbar: Qttabbar is a small tool that allows you to use tab multi label function in Windows Explorer\. https://yuque\.com/indiff/qttabbar/zqtdig](https://github.com/indiff/qttabbar)

[希望能在文档中写明Internet Explorer中的加载项可能会禁用qttabbar · Issue \#259 · indiff/qttabbar](https://github.com/indiff/qttabbar/issues/259)

我用了一年多，最近突然发现qttabbar不能使用了，安装或者重新安装后都无法在资源管理器->查看->选项中看到qttabbar。搜索Issue后没发现对应情况，检查.NET也已经启用，后发现[win10 qttabbar不可用 - iyonghua的个人空间 - OSCHINA - 中文开源技术交流社区](https://my.oschina.net/u/2485283/blog/3124486#:~:text=解决 win10 系统 qttabbar 按钮不可用 1.,打开 ie 浏览器 internet 选项的程序页签 2.)符合我的情况。原因是Internet Explorer中的右上角设置->Internet选项->程序->管理加载项->工具栏和扩展中qttabbar被禁用，启用对应选项后可以正常使用