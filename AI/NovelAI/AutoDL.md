# AutoDL

[NovelAI云端部署系列教程-目前最好最简单的NovelAI云端快速部署教程(AutoDL平台)_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1kG4y1n7Va/?spm_id_from=333.788&vd_source=187217104dfd0bc027cc65f8420627b0)

算力市场 -> 租一个GPU 

3090

```bash
root@autodl-container-3d5811a0ae-4aa79bba:~/stable-diffusion-webui/models/hypernetworks# nvidia-smi
Tue Jan 17 19:39:19 2023       
+-----------------------------------------------------------------------------+
| NVIDIA-SMI 495.44       Driver Version: 495.44       CUDA Version: 11.5     |
|-------------------------------+----------------------+----------------------+
| GPU  Name        Persistence-M| Bus-Id        Disp.A | Volatile Uncorr. ECC |
| Fan  Temp  Perf  Pwr:Usage/Cap|         Memory-Usage | GPU-Util  Compute M. |
|                               |                      |               MIG M. |
|===============================+======================+======================|
|   0  NVIDIA GeForce ...  On   | 00000000:81:00.0 Off |                  N/A |
| 30%   26C    P8    31W / 350W |   4105MiB / 24268MiB |      0%      Default |
|                               |                      |                  N/A |
+-------------------------------+----------------------+----------------------+
                                                                               
+-----------------------------------------------------------------------------+
| Processes:                                                                  |
|  GPU   GI   CI        PID   Type   Process name                  GPU Memory |
|        ID   ID                                                   Usage      |
|=============================================================================|
+-----------------------------------------------------------------------------+
```

```
镜像
AUTOMATIC1111/stable-diffusion-webui/Stable-Diffusion-for-NovelAI
GPU
RTX 3090(24GB) * 1
CPU
15 vCPU AMD EPYC 7543 32-Core Processor
内存
80GB
硬盘
系统盘:25 GB
数据盘:免费:50GB SSD  付费:0GB
```

## 部署镜像

[AUTOMATIC1111/stable-diffusion-webui/Stable-Diffusion-for-NovelAI: 基于Stable Diffusion与NovelAI预训练模型进行的复现 - CG (codewithgpu.com)](https://www.codewithgpu.com/i/AUTOMATIC1111/stable-diffusion-webui/Stable-Diffusion-for-NovelAI)

### 学术加速

内蒙A区的实例

```
export http_proxy=http://192.168.1.174:12798 && export https_proxy=http://192.168.1.174:12798
```



### 更新

```
cd ~/stable-diffusion-webui/
git pull
```



## 启动

```
cd ~/stable-diffusion-webui/
rm -rf outputs && ln -s /root/autodl-tmp outputs
python launch.py --disable-safe-unpickle --port=6006 --deepdanbooru --share --gradio-debug --enable-insecure-extension-access

```

#"--share --gradio-debug --xformers --deepdanbooru --enable-insecure-extension-access"

小李启动器

```
export http_proxy=http://192.168.1.174:12798 && export https_proxy=http://192.168.1.174:12798
cd /root/autodl-tmp/stable-diffusion-webui && /root/miniconda3/envs/xl_env/bin/python launch.py --disable-safe-unpickle  --port=6006 --xformers --enable-insecure-extension-access --api --cors-allow-origins=https://www.painthua.com --no-half-vae --share --listen

```

允许扩图

## 版本

当前版本分支：master

当前版本SHA：2c1bb46c7ad5b4536f6587d327a03f0ff7811c5d

分支选择:请先刷新



## 上传下载模型

### Huggingface

原本想从抱脸上下载，但是太慢了，给个下载方法

[Quick start](https://huggingface.co/docs/huggingface_hub/quick-start)

### 阿里云盘

[NovelAI云端部署系列教程-换上你的7G模型吧！_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1dR4y1D7bK/?spm_id_from=333.999.0.0&vd_source=187217104dfd0bc027cc65f8420627b0)

IDM比较快（



```
cd ~/stable-diffusion-webui/extensions/
git clone https://github.com/yfszzx/stable-diffusion-webui-images-browser
git clone https://github.com/animerl/novelai-2-local-prompt
git clone https://github.com/KutsuyaYuki/ABG_extension
git clone https://github.com/d8ahazard/sd_dreambooth_extension
git clone https://github.com/kohya-ss/sd-webui-additional-networks
```

### 系统盘空间不足

[系统盘空间不足](https://www.autodl.com/docs/qa1/)

以下操作均在 jupyter notebook中

```bash
source ~/.bashrc
```

查看

```bash
root@autodl-container-3d5811a0ae-4aa79bba:~/stable-diffusion-webui/models/Stable-diffusion# source ~/.bashrc
+--------------------------------------------------AutoDL--------------------------------------------------------+
目录说明:
╔═════════════════╦══════╦════╦═════════════════════════════════════════════════════════════════════════╗
║目录             ║名称  ║速度║说明                                                                     ║
╠═════════════════╬══════╬════╬═════════════════════════════════════════════════════════════════════════╣
║/                ║系统盘║快  ║实例关机数据不会丢失，可存放代码等。会随保存镜像一起保存。               ║
║/root/autodl-tmp ║数据盘║快  ║实例关机数据不会丢失，可存放读写IO要求高的数据。但不会随保存镜像一起保存 ║
║/root/autodl-nas ║网盘  ║慢  ║可以实现多实例间的文件同步共享，不受实例开关机和保存镜像的影响。         ║
╚═════════════════╩══════╩════╩═════════════════════════════════════════════════════════════════════════╝
CPU ：15 核心
内存：80 GB
GPU ：NVIDIA GeForce RTX 3090, 1
存储：
  系统盘/               ：100% 25G/25G
  数据盘/root/autodl-tmp：16% 7.9G/50G
  网  盘/root/autodl-nas：
```

#### 数据盘和系统盘区分

列出root下占用

```
du -sh /root/*
```



```bash
0       /root/autodl-nas
1.5T    /root/autodl-pub
19G     /root/autodl-tmp
6.8G    /root/miniconda3
324K    /root/novelai-2-local-prompt
3.6G    /root/stable-diffusion-webui
0       /root/tf-logs
```

比较坑的点是这里不能显示回收站占用大小

#### 回收站

在 jupyter notebook 中删除的文件会放到 /root/.local/share/Trash 中，请使用以下命令查看、删除

```bash
du -sh /root/.local/share/Trash # jupyterlab的回收站
rm -rf /root/.local/share/Trash   

```

