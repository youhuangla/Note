# Python 编码风格指南

## 指南

### PEP8

#### 关键字参数中的等号

[PEP 8 – Style Guide for Python Code \| peps\.python\.org](https://peps.python.org/pep-0008/#whitespace-in-expressions-and-statements)

>   Don’t use spaces around the `=` sign when used to indicate a keyword argument, or when used to indicate a default value for an *unannotated* function parameter:
>
>   ```python
>   # Correct:
>   def complex(real, imag=0.0):
>       return magic(r=real, i=imag)
>   # Wrong:
>   def complex(real, imag = 0.0):
>       return magic(r = real, i = imag)
>   ```

>   Person: 
>   - 当使用关键字参数（keyword argument）时，通常习惯将等号紧密地连接到参数名，以增加代码的紧凑性和可读性。在https://docs.python.org/3/glossary.html#term-keyword-argument中帮我找到文档中对应的英文
>
>   ChatGPT: 
>   - Used WebPilot
>
>   
>
>
>   在Python官方文档中，关于"keyword argument"的定义如下：
>   > keyword argument: 见 argument。
>
>   这个定义指向了"argument"的定义，所以我们需要查看"argument"的定义来理解"keyword argument"。不过，这个定义并没有直接提供在你的请求中提到的关于等号紧密地连接到参数名以增加代码的紧凑性和可读性的信息。
>
>   如果你需要更多关于"keyword argument"的信息，或者有其他的问题，欢迎继续提问。
>
>   Person: 
>   - PEP 8（Python 编码风格指南）的官方文档链接？
>
>   ChatGPT: 
>   - Used WebPilot
>
>   
>
>
>   这是 PEP 8 - Python 代码风格指南 的官方文档链接：[PEP 8 – Style Guide for Python Code](https://peps.python.org/pep-0008/) 
>
>   这份指南由 Guido van Rossum, Barry Warsaw, 和 Nick Coghlan 创作，它提供了 Python 代码的编写规范，包括缩进、行长度、空格、注释、命名规范等方面的建议。这份风格指南随着时间的推移会不断演进，以适应 Python 语言本身的变化。
>
>   值得注意的是，这份指南强调了代码的可读性和一致性。尽管有时可能需要违反风格指南的建议，但在大多数情况下，遵循这些规则可以提高代码的可读性和一致性。
>
>   [python.org](https://peps.python.org/pep-0008/)