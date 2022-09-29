# ClamAV

[Configuration \- ClamAV Documentation](https://docs.clamav.net/manual/Usage/Configuration.html)

[ClamAV - Ubuntu中文](https://wiki.ubuntu.com.cn/ClamAV#ClamAV_.E5.AE.89.E8.A3.85.E8.AE.BE.E7.BD.AE)

## 更新病毒库

```shell

youhuangla@Ubuntu ~ % sudo freshclam                                            [0]
ERROR: /var/log/clamav/freshclam.log is locked by another process
ERROR: Problem with internal logger (UpdateLogFile = /var/log/clamav/freshclam.log).
ERROR: initialize: libfreshclam init failed.
ERROR: Initialization error!
youhuangla@Ubuntu ~ %  clamscan -r /                                            [2]
WARNING: Failed to set locale
^C
youhuangla@Ubuntu ~ % sudo systemctl stop clamav-freshclam.service            [130]
youhuangla@Ubuntu ~ % sudo freshclam                                            [0]
Sat Jul 30 10:56:03 2022 -> ClamAV update process started at Sat Jul 30 10:56:03 2022
Sat Jul 30 10:56:03 2022 -> ^Your ClamAV installation is OUTDATED!
Sat Jul 30 10:56:03 2022 -> ^Local version: 0.103.6 Recommended version: 0.103.7
Sat Jul 30 10:56:03 2022 -> DON'T PANIC! Read https://docs.clamav.net/manual/Installing.html
Sat Jul 30 10:56:03 2022 -> daily.cvd database is up-to-date (version: 26615, sigs: 1992518, f-level: 90, builder: raynman)
Sat Jul 30 10:56:03 2022 -> main.cvd database is up-to-date (version: 62, sigs: 6647427, f-level: 90, builder: sigmgr)
Sat Jul 30 10:56:03 2022 -> bytecode.cvd database is up-to-date (version: 333, sigs: 92, f-level: 63, builder: awillia2)

```

[malware \- clamav \- ERROR: /var/log/clamav/freshclam\.log is locked by another process? \- Ask Ubuntu](https://askubuntu.com/questions/909273/clamav-error-var-log-clamav-freshclam-log-is-locked-by-another-process)

## 扫描

[Linux病毒扫描工具ClamAV（Clam AntiVirus）安装使用 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/266731354)

```shell
youhuangla@Ubuntu ~ % sudo clamscan -r -i /home  --remove  -l /home/youhuangla/clamav.log
```





扫描过程中

```shell

Network error: Software caused connection abort

────────────────────────────────────────────────────────────────────────────────────

Session stopped
    - Press <return> to exit tab
    - Press R to restart session
    - Press S to save terminal output to file


```

[Mobaxterm: how to prevent ssh session from exiting? \- Stack Overflow](https://stackoverflow.com/questions/57385896/mobaxterm-how-to-prevent-ssh-session-from-exiting)