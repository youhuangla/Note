# chatgpt\_academic



[binary\-husky/chatgpt\_academic: 科研工作专用ChatGPT拓展，特别优化学术Paper润色体验，支持自定义快捷按钮，支持自定义函数插件，支持markdown代码块表格显示，Tex公式双显示，新增Python/C\+\+项目剖析/自译解功能，PDF/LaTex论文翻译/总结功能，兼容ChatGLM等本地模型](https://github.com/binary-husky/chatgpt_academic)

```powershell

PS E:\github> git clone https://github.com/binary-husky/chatgpt_academic.git
Cloning into 'chatgpt_academic'...
remote: Enumerating objects: 1955, done.
remote: Counting objects: 100% (235/235), done.
remote: Compressing objects: 100% (98/98), done.
remote: Total 1955 (delta 146), reused 220 (delta 136), pack-reused 1720
Receiving objects: 100% (1955/1955), 23.79 MiB | 3.17 MiB/s, done.
Resolving deltas: 100% (1219/1219), done.
PS E:\github> cd chatgpt_academic
PS E:\github\chatgpt_academic> python -m pip install -r requirements.txt
Collecting gradio>=3.23
  Downloading gradio-3.25.0-py3-none-any.whl (17.5 MB)
     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 17.5/17.5 MB 878.3 kB/s eta 0:00:00
Requirement already satisfied: requests[socks] in d:\python310\lib\site-packages (from -r requirements.txt (line 2)) (2.25.1)
Requirement already satisfied: transformers in d:\python310\lib\site-packages (from -r requirements.txt (line 3)) (4.19.2)
Collecting python-markdown-math
  Downloading python_markdown_math-0.8-py3-none-any.whl (5.9 kB)
Requirement already satisfied: beautifulsoup4 in d:\python310\lib\site-packages (from -r requirements.txt (line 5)) (4.11.1)
Collecting latex2mathml
  Downloading latex2mathml-3.75.2-py3-none-any.whl (73 kB)
     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 73.1/73.1 kB 2.0 MB/s eta 0:00:00
Collecting python-docx
  Downloading python-docx-0.8.11.tar.gz (5.6 MB)
     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 5.6/5.6 MB 1.0 MB/s eta 0:00:00
  Preparing metadata (setup.py) ... done
Collecting mdtex2html
  Downloading mdtex2html-1.2.0-py3-none-any.whl (13 kB)
Requirement already satisfied: colorama in d:\python310\lib\site-packages (from -r requirements.txt (line 9)) (0.4.5)
Collecting tiktoken
  Downloading tiktoken-0.3.3-cp310-cp310-win_amd64.whl (579 kB)
     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 579.4/579.4 kB 638.8 kB/s eta 0:00:00
Requirement already satisfied: Markdown in d:\python310\lib\site-packages (from -r requirements.txt (line 11)) (3.4.1)
Collecting pygments
  Downloading Pygments-2.15.0-py3-none-any.whl (1.1 MB)
     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 1.1/1.1 MB 865.1 kB/s eta 0:00:00
Collecting pymupdf
  Downloading PyMuPDF-1.21.1-cp310-cp310-win_amd64.whl (11.7 MB)
     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 11.7/11.7 MB 630.0 kB/s eta 0:00:00
Collecting openai
  Downloading openai-0.27.4-py3-none-any.whl (70 kB)
     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 70.3/70.3 kB 545.9 kB/s eta 0:00:00
Requirement already satisfied: numpy in d:\python310\lib\site-packages (from -r requirements.txt (line 15)) (1.23.4)
Collecting arxiv
  Downloading arxiv-1.4.4-py3-none-any.whl (12 kB)
Requirement already satisfied: aiohttp in d:\python310\lib\site-packages (from gradio>=3.23->-r requirements.txt (line 1)) (3.8.3)
Requirement already satisfied: pillow in d:\python310\lib\site-packages (from gradio>=3.23->-r requirements.txt (line 1)) (9.2.0)
Requirement already satisfied: httpx in d:\python310\lib\site-packages (from gradio>=3.23->-r requirements.txt (line 1)) (0.23.0)
Requirement already satisfied: uvicorn in d:\python310\lib\site-packages (from gradio>=3.23->-r requirements.txt (line 1)) (0.19.0)
Requirement already satisfied: python-multipart in d:\python310\lib\site-packages (from gradio>=3.23->-r requirements.txt (line 1)) (0.0.4)
Requirement already satisfied: jinja2 in d:\python310\lib\site-packages (from gradio>=3.23->-r requirements.txt (line 1)) (3.1.2)
Collecting semantic-version
  Downloading semantic_version-2.10.0-py2.py3-none-any.whl (15 kB)
Requirement already satisfied: pydantic in d:\python310\lib\site-packages (from gradio>=3.23->-r requirements.txt (line 1)) (1.10.2)
Collecting altair>=4.2.0
  Downloading altair-4.2.2-py3-none-any.whl (813 kB)
     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 813.6/813.6 kB 635.1 kB/s eta 0:00:00
Collecting gradio-client>=0.0.8
  Downloading gradio_client-0.0.10-py3-none-any.whl (23 kB)
Requirement already satisfied: markupsafe in d:\python310\lib\site-packages (from gradio>=3.23->-r requirements.txt (line 1)) (2.1.1)
Requirement already satisfied: typing-extensions in d:\python310\lib\site-packages (from gradio>=3.23->-r requirements.txt (line 1)) (4.4.0)
Requirement already satisfied: matplotlib in d:\python310\lib\site-packages (from gradio>=3.23->-r requirements.txt (line 1)) (3.6.1)
Requirement already satisfied: pandas in d:\python310\lib\site-packages (from gradio>=3.23->-r requirements.txt (line 1)) (1.5.1)
Requirement already satisfied: pydub in d:\python310\lib\site-packages (from gradio>=3.23->-r requirements.txt (line 1)) (0.25.1)
Requirement already satisfied: pyyaml in d:\python310\lib\site-packages (from gradio>=3.23->-r requirements.txt (line 1)) (6.0)
Requirement already satisfied: mdit-py-plugins<=0.3.3 in d:\python310\lib\site-packages (from gradio>=3.23->-r requirements.txt (line 1)) (0.3.1)
Requirement already satisfied: markdown-it-py[linkify]>=2.0.0 in d:\python310\lib\site-packages (from gradio>=3.23->-r requirements.txt (line 1)) (2.1.0)
Requirement already satisfied: ffmpy in d:\python310\lib\site-packages (from gradio>=3.23->-r requirements.txt (line 1)) (0.3.0)
Requirement already satisfied: websockets>=10.0 in d:\python310\lib\site-packages (from gradio>=3.23->-r requirements.txt (line 1)) (10.3)
Collecting aiofiles
  Downloading aiofiles-23.1.0-py3-none-any.whl (14 kB)
Requirement already satisfied: fastapi in d:\python310\lib\site-packages (from gradio>=3.23->-r requirements.txt (line 1)) (0.85.1)
Requirement already satisfied: orjson in d:\python310\lib\site-packages (from gradio>=3.23->-r requirements.txt (line 1)) (3.8.0)
Collecting huggingface-hub>=0.13.0
  Downloading huggingface_hub-0.13.4-py3-none-any.whl (200 kB)
     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 200.1/200.1 kB 675.8 kB/s eta 0:00:00
Requirement already satisfied: certifi>=2017.4.17 in d:\python310\lib\site-packages (from requests[socks]->-r requirements.txt (line 2)) (2022.9.24)
Requirement already satisfied: chardet<5,>=3.0.2 in d:\python310\lib\site-packages (from requests[socks]->-r requirements.txt (line 2)) (4.0.0)
Requirement already satisfied: idna<3,>=2.5 in d:\python310\lib\site-packages (from requests[socks]->-r requirements.txt (line 2)) (2.10)
Requirement already satisfied: urllib3<1.27,>=1.21.1 in d:\python310\lib\site-packages (from requests[socks]->-r requirements.txt (line 2)) (1.26.12)
Requirement already satisfied: PySocks!=1.5.7,>=1.5.6 in d:\python310\lib\site-packages (from requests[socks]->-r requirements.txt (line 2)) (1.7.1)
Requirement already satisfied: packaging>=20.0 in c:\users\administrator\appdata\roaming\python\python310\site-packages (from transformers->-r requirements.txt (line 3)) (23.0)
Requirement already satisfied: regex!=2019.12.17 in d:\python310\lib\site-packages (from transformers->-r requirements.txt (line 3)) (2022.9.13)
Requirement already satisfied: tokenizers!=0.11.3,<0.13,>=0.11.1 in d:\python310\lib\site-packages (from transformers->-r requirements.txt (line 3)) (0.12.1)
Requirement already satisfied: tqdm>=4.27 in d:\python310\lib\site-packages (from transformers->-r requirements.txt (line 3)) (4.64.1)
Requirement already satisfied: filelock in d:\python310\lib\site-packages (from transformers->-r requirements.txt (line 3)) (3.8.0)
Requirement already satisfied: soupsieve>1.2 in d:\python310\lib\site-packages (from beautifulsoup4->-r requirements.txt (line 5)) (2.3.2.post1)
Collecting lxml>=2.3.2
  Downloading lxml-4.9.2-cp310-cp310-win_amd64.whl (3.8 MB)
     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 3.8/3.8 MB 743.4 kB/s eta 0:00:00
Collecting tiktoken
  Downloading tiktoken-0.3.2-cp310-cp310-win_amd64.whl (578 kB)
     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 579.0/579.0 kB 910.0 kB/s eta 0:00:00
  Downloading tiktoken-0.3.1-cp310-cp310-win_amd64.whl (581 kB)
     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 581.1/581.1 kB 913.3 kB/s eta 0:00:00
  Downloading tiktoken-0.3.0-cp310-cp310-win_amd64.whl (581 kB)
     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 581.1/581.1 kB 1.1 MB/s eta 0:00:00
Collecting blobfile>=2
  Downloading blobfile-2.0.1-py3-none-any.whl (73 kB)
     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 73.5/73.5 kB 1.3 MB/s eta 0:00:00
Collecting tiktoken
  Downloading tiktoken-0.2.0-cp310-cp310-win_amd64.whl (577 kB)
     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 577.8/577.8 kB 1.2 MB/s eta 0:00:00
  Downloading tiktoken-0.1.2-cp310-cp310-win_amd64.whl (575 kB)
     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 575.1/575.1 kB 556.0 kB/s eta 0:00:00
  Downloading tiktoken-0.1.1-cp310-cp310-win_amd64.whl (575 kB)
     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 575.0/575.0 kB 977.2 kB/s eta 0:00:00
Collecting feedparser
  Downloading feedparser-6.0.10-py3-none-any.whl (81 kB)
     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 81.1/81.1 kB 4.7 MB/s eta 0:00:00
Collecting entrypoints
  Downloading entrypoints-0.4-py3-none-any.whl (5.3 kB)
Collecting toolz
  Downloading toolz-0.12.0-py3-none-any.whl (55 kB)
     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 55.8/55.8 kB 1.5 MB/s eta 0:00:00
Requirement already satisfied: jsonschema>=3.0 in d:\python310\lib\site-packages (from altair>=4.2.0->gradio>=3.23->-r requirements.txt (line 1)) (4.16.0)
Collecting pycryptodomex~=3.8
  Downloading pycryptodomex-3.17-cp35-abi3-win_amd64.whl (1.7 MB)
     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 1.7/1.7 MB 1.0 MB/s eta 0:00:00
Requirement already satisfied: fsspec in d:\python310\lib\site-packages (from gradio-client>=0.0.8->gradio>=3.23->-r requirements.txt (line 1)) (2022.10.0)
Requirement already satisfied: mdurl~=0.1 in d:\python310\lib\site-packages (from markdown-it-py[linkify]>=2.0.0->gradio>=3.23->-r requirements.txt (line 1)) (0.1.2)
Requirement already satisfied: linkify-it-py~=1.0 in d:\python310\lib\site-packages (from markdown-it-py[linkify]>=2.0.0->gradio>=3.23->-r requirements.txt (line 1)) (1.0.3)
Requirement already satisfied: pytz>=2020.1 in d:\python310\lib\site-packages (from pandas->gradio>=3.23->-r requirements.txt (line 1)) (2022.5)
Requirement already satisfied: python-dateutil>=2.8.1 in d:\python310\lib\site-packages (from pandas->gradio>=3.23->-r requirements.txt (line 1)) (2.8.2)
Requirement already satisfied: attrs>=17.3.0 in d:\python310\lib\site-packages (from aiohttp->gradio>=3.23->-r requirements.txt (line 1)) (22.1.0)
Requirement already satisfied: multidict<7.0,>=4.5 in d:\python310\lib\site-packages (from aiohttp->gradio>=3.23->-r requirements.txt (line 1)) (6.0.2)
Requirement already satisfied: frozenlist>=1.1.1 in d:\python310\lib\site-packages (from aiohttp->gradio>=3.23->-r requirements.txt (line 1)) (1.3.1)
Requirement already satisfied: async-timeout<5.0,>=4.0.0a3 in d:\python310\lib\site-packages (from aiohttp->gradio>=3.23->-r requirements.txt (line 1)) (4.0.2)
Requirement already satisfied: aiosignal>=1.1.2 in d:\python310\lib\site-packages (from aiohttp->gradio>=3.23->-r requirements.txt (line 1)) (1.2.0)
Requirement already satisfied: yarl<2.0,>=1.0 in d:\python310\lib\site-packages (from aiohttp->gradio>=3.23->-r requirements.txt (line 1)) (1.8.1)
Requirement already satisfied: charset-normalizer<3.0,>=2.0 in d:\python310\lib\site-packages (from aiohttp->gradio>=3.23->-r requirements.txt (line 1)) (2.1.1)
Requirement already satisfied: starlette==0.20.4 in d:\python310\lib\site-packages (from fastapi->gradio>=3.23->-r requirements.txt (line 1)) (0.20.4)
Requirement already satisfied: anyio<5,>=3.4.0 in d:\python310\lib\site-packages (from starlette==0.20.4->fastapi->gradio>=3.23->-r requirements.txt (line 1)) (3.6.2)
Collecting sgmllib3k
  Downloading sgmllib3k-1.0.0.tar.gz (5.8 kB)
  Preparing metadata (setup.py) ... done
Requirement already satisfied: sniffio in d:\python310\lib\site-packages (from httpx->gradio>=3.23->-r requirements.txt (line 1)) (1.3.0)
Requirement already satisfied: httpcore<0.16.0,>=0.15.0 in d:\python310\lib\site-packages (from httpx->gradio>=3.23->-r requirements.txt (line 1)) (0.15.0)
Requirement already satisfied: rfc3986[idna2008]<2,>=1.3 in d:\python310\lib\site-packages (from httpx->gradio>=3.23->-r requirements.txt (line 1)) (1.5.0)
Requirement already satisfied: kiwisolver>=1.0.1 in d:\python310\lib\site-packages (from matplotlib->gradio>=3.23->-r requirements.txt (line 1)) (1.4.4)
Requirement already satisfied: contourpy>=1.0.1 in d:\python310\lib\site-packages (from matplotlib->gradio>=3.23->-r requirements.txt (line 1)) (1.0.5)
Requirement already satisfied: pyparsing>=2.2.1 in d:\python310\lib\site-packages (from matplotlib->gradio>=3.23->-r requirements.txt (line 1)) (3.0.9)
Requirement already satisfied: fonttools>=4.22.0 in d:\python310\lib\site-packages (from matplotlib->gradio>=3.23->-r requirements.txt (line 1)) (4.38.0)
Requirement already satisfied: cycler>=0.10 in d:\python310\lib\site-packages (from matplotlib->gradio>=3.23->-r requirements.txt (line 1)) (0.11.0)
Requirement already satisfied: six>=1.4.0 in d:\python310\lib\site-packages (from python-multipart->gradio>=3.23->-r requirements.txt (line 1)) (1.16.0)
Requirement already satisfied: h11>=0.8 in d:\python310\lib\site-packages (from uvicorn->gradio>=3.23->-r requirements.txt (line 1)) (0.12.0)
Requirement already satisfied: click>=7.0 in d:\python310\lib\site-packages (from uvicorn->gradio>=3.23->-r requirements.txt (line 1)) (8.1.3)
Requirement already satisfied: pyrsistent!=0.17.0,!=0.17.1,!=0.17.2,>=0.14.0 in d:\python310\lib\site-packages (from jsonschema>=3.0->altair>=4.2.0->gradio>=3.23->-r requirements.txt (line 1)) (0.18.1)
Requirement already satisfied: uc-micro-py in d:\python310\lib\site-packages (from linkify-it-py~=1.0->markdown-it-py[linkify]>=2.0.0->gradio>=3.23->-r requirements.txt (line 1)) (1.0.1)
Building wheels for collected packages: python-docx, sgmllib3k
  Created wheel for python-docx: filename=python_docx-0.8.11-py3-none-any.whl size=184489 sha256=5fcab0b8d82e21af006c7003449f4fbfc6c3f272eaae67454781ef3a11bee03d
  Stored in directory: c:\users\administrator\appdata\local\pip\cache\wheels\65\e1\9b\0c38fe6cfe02a9fe31cb6b4efd90985f17354d7f77872f2def
  Building wheel for sgmllib3k (setup.py) ... done
  Created wheel for sgmllib3k: filename=sgmllib3k-1.0.0-py3-none-any.whl size=6048 sha256=2f3564b06534f7d245e8318dae860a32c19dc0691dde5f863d85813a0fab4a70
  Stored in directory: c:\users\administrator\appdata\local\pip\cache\wheels\3b\24\68\f82c1fe16fe6cc7c6f9f67fe4bbf2a4ce527dea6b14a4b34ee
Successfully built python-docx sgmllib3k
Installing collected packages: sgmllib3k, toolz, semantic-version, python-markdown-math, pymupdf, pygments, pycryptodomex, lxml, latex2mathml, feedparser, entrypoints, aiofiles, python-docx, mdtex2html, huggingface-hub, blobfile, arxiv, tiktoken, openai, altair, gradio-client, gradio
  Attempting uninstall: huggingface-hub
    Found existing installation: huggingface-hub 0.10.1
    Uninstalling huggingface-hub-0.10.1:
      Successfully uninstalled huggingface-hub-0.10.1
  Attempting uninstall: gradio
    Found existing installation: gradio 3.5
    Uninstalling gradio-3.5:
      Successfully uninstalled gradio-3.5
Successfully installed aiofiles-23.1.0 altair-4.2.2 arxiv-1.4.4 blobfile-2.0.1 entrypoints-0.4 feedparser-6.0.10 gradio-3.25.0 gradio-client-0.0.10 huggingface-hub-0.13.4 latex2mathml-3.75.2 lxml-4.9.2 mdtex2html-1.2.0 openai-0.27.4 pycryptodomex-3.17 pygments-2.15.0 pymupdf-1.21.1 python-docx-0.8.11 python-markdown-math-0.8 semantic-version-2.10.0 sgmllib3k-1.0.0 tiktoken-0.1.1 toolz-0.12.0

[notice] A new release of pip available: 22.3 -> 23.0.1
[notice] To update, run: python.exe -m pip install --upgrade pip
PS E:\github\chatgpt_academic> python main.py
 [PROXY] 网络代理状态：已配置。配置信息如下： {'http': 'socks5h://localhost:7890', 'https': 'socks5h://localhost:7890'}
 [API_KEY] 您的 API_KEY 是: sk-lTmiNb1yso0p*** API_KEY 导入成功
所有问询记录将自动保存在本地目录./gpt_log/chat_secrets.log, 请注意自我隐私保护哦！
代理配置 socks5h://localhost:7890, 代理所在地查询超时，代理可能无效
如果浏览器没有自动打开，请复制并转到以下URL：
        （亮色主题）: http://localhost:15521
        （暗色主题）: http://localhost:15521/?__dark-theme=true
Running on local URL:  http://0.0.0.0:15521

To create a public link, set `share=True` in `launch()`.
```

