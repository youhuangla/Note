# Python

## Windows下Python版本的切换

<https://www.cnblogs.com/beginner-boy/p/7248399.html>

```cmd
PS C:\Users\Administrator> pip3 -V
Fatal error in launcher: Unable to create process using '"d:\python\python39\python.exe"  "D:\Python\Python39\Scripts\pip3.exe" -V': ???????????

PS C:\Users\Administrator> python -V
Python 2.7.5
PS C:\Users\Administrator> python3 -V
Python 3.9.1
PS C:\Users\Administrator> python3 -m pip install -U pip
Collecting pip
  Downloading pip-22.0.3-py3-none-any.whl (2.1 MB)
     |████████████████████████████████| 2.1 MB 731 kB/s
Installing collected packages: pip
  Attempting uninstall: pip
    Found existing installation: pip 20.2.3
    Uninstalling pip-20.2.3:
      Successfully uninstalled pip-20.2.3
Successfully installed pip-22.0.3
PS C:\Users\Administrator> pip3 -V
pip 22.0.3 from d:\python\python39\lib\site-packages\pip (python 3.9)
# pip install google-translate-for-goldendict error
PS C:\Users\Administrator> pip3 install google-translate-for-goldendict
WARNING: Retrying (Retry(total=4, connect=None, read=None, redirect=None, status=None)) after connection broken by 'SSLError(SSLEOFError(8, 'EOF occurred in violation of protocol (_ssl.c:1123)'))': /simple/google-translate-for-goldendict/
WARNING: Retrying (Retry(total=3, connect=None, read=None, redirect=None, status=None)) after connection broken by 'SSLError(SSLEOFError(8, 'EOF occurred in violation of protocol (_ssl.c:1123)'))': /simple/google-translate-for-goldendict/
WARNING: Retrying (Retry(total=2, connect=None, read=None, redirect=None, status=None)) after connection broken by 'SSLError(SSLEOFError(8, 'EOF occurred in violation of protocol (_ssl.c:1123)'))': /simple/google-translate-for-goldendict/
WARNING: Retrying (Retry(total=1, connect=None, read=None, redirect=None, status=None)) after connection broken by 'SSLError(SSLEOFError(8, 'EOF occurred in violation of protocol (_ssl.c:1123)'))': /simple/google-translate-for-goldendict/
WARNING: Retrying (Retry(total=0, connect=None, read=None, redirect=None, status=None)) after connection broken by 'SSLError(SSLEOFError(8, 'EOF occurred in violation of protocol (_ssl.c:1123)'))': /simple/google-translate-for-goldendict/
Could not fetch URL https://pypi.org/simple/google-translate-for-goldendict/: There was a problem confirming the ssl certificate: HTTPSConnectionPool(host='pypi.org', port=443): Max retries exceeded with url: /simple/google-translate-for-goldendict/ (Caused by SSLError(SSLEOFError(8, 'EOF occurred in violation of protocol (_ssl.c:1123)'))) - skipping
ERROR: Could not find a version that satisfies the requirement google-translate-for-goldendict (from versions: none)
ERROR: No matching distribution found for google-translate-for-goldendict
Could not fetch URL https://pypi.org/simple/pip/: There was a problem confirming the ssl certificate: HTTPSConnectionPool(host='pypi.org', port=443): Max retries exceeded with url: /simple/pip/ (Caused by SSLError(SSLEOFError(8, 'EOF occurred in violation of protocol (_ssl.c:1123)'))) - skipping


```

<https://blog.csdn.net/zkbaba/article/details/109188004>

```cmd
PS C:\Users\Administrator> pip install google-translate-for-goldendict -i http://pypi.douban.com/simple --trusted-host pypi.douban.com
Looking in indexes: http://pypi.douban.com/simple
Collecting google-translate-for-goldendict
  Downloading http://pypi.doubanio.com/packages/e9/95/6c1c569bce667267ca458a042998e45a1e0cc909882c0a4eec14e943b047/google_translate_for_goldendict-1.3.9-py3-none-any.whl (18 kB)
Requirement already satisfied: requests in d:\python\python39\lib\site-packages (from google-translate-for-goldendict) (2.25.1)
Requirement already satisfied: chardet<5,>=3.0.2 in d:\python\python39\lib\site-packages (from requests->google-translate-for-goldendict) (4.0.0)
Requirement already satisfied: idna<3,>=2.5 in d:\python\python39\lib\site-packages (from requests->google-translate-for-goldendict) (2.10)
Requirement already satisfied: certifi>=2017.4.17 in d:\python\python39\lib\site-packages (from requests->google-translate-for-goldendict) (2020.12.5)
Requirement already satisfied: urllib3<1.27,>=1.21.1 in d:\python\python39\lib\site-packages (from requests->google-translate-for-goldendict) (1.26.2)
Installing collected packages: google-translate-for-goldendict
Successfully installed google-translate-for-goldendict-1.3.9
```

- pip tips:
  - pip list
  - pip install
  - pip uninstall

```cmd
PS C:\Users\Administrator> pip install request -i http://pypi.douban.com/simple --trusted-host pypi.douban.com
Looking in indexes: http://pypi.douban.com/simple
Collecting request
  Downloading http://pypi.doubanio.com/packages/67/fc/30193d66338a12cc1389e799a4fa27d29763cb075ced80fa2be9b2571224/request-1.0.117.tar.gz (3.0 kB)
  Preparing metadata (setup.py) ... done
Requirement already satisfied: requests in d:\python\python39\lib\site-packages (from request) (2.25.1)
Requirement already satisfied: chardet<5,>=3.0.2 in d:\python\python39\lib\site-packages (from requests->request) (4.0.0)
Requirement already satisfied: idna<3,>=2.5 in d:\python\python39\lib\site-packages (from requests->request) (2.10)
Requirement already satisfied: urllib3<1.27,>=1.21.1 in d:\python\python39\lib\site-packages (from requests->request) (1.26.2)
Requirement already satisfied: certifi>=2017.4.17 in d:\python\python39\lib\site-packages (from requests->request) (2020.12.5)
Using legacy 'setup.py install' for request, since package 'wheel' is not installed.
Installing collected packages: request
  Running setup.py install for request ... done
Successfully installed request-1.0.117
```

python D:\PathTo\googletranslate.py zh-CN %GDWORD%
pip install --upgrade google-api-python-client
