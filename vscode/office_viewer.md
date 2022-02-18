# office viewer

## open md by default

- 在workbench中添加一行使得md文件打开方式为默认而不是office viewer，在office viewer中打开可右键，并选中"open with"，再选择对应选项。注意，如果"workbench.editorAssociations"有重复会报错。

```json
"workbench.editorAssociations": {
        "*.ipynb": "jupyter.notebook.ipynb",
        "*.md": "default"//office viewer
},
```
