# neovim

<https://jdhao.github.io/2018/11/16/neovim_configuration_windows-zh/#fnref:1>

```powershell
PS C:\WINDOWS\system32> md ~\AppData\Local\nvim\autoload


    目录: C:\Users\Administrator\AppData\Local\nvim


Mode                 LastWriteTime         Length Name
----                 -------------         ------ ----
d-----         2022/2/15     14:22                autoload


PS C:\WINDOWS\system32> $uri = 'https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim'
PS C:\WINDOWS\system32> (New-Object Net.WebClient).DownloadFile(
>>   $uri,
>>   $ExecutionContext.SessionState.Path.GetUnresolvedProviderPathFromPSPath(
>>     "~\AppData\Local\nvim\autoload\plug.vim"
>>   )
>> )
```

- After many efforts, successfully add nvim into PATH.

[add nvim to path](https://raw.githubusercontent.com/youhuangla/images/main/202202152253614.png)

- type nvim to enter
