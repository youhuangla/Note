<!--
⚠ Before proceeding:

Search for existing issues. It would be best to also review the closed ones.

Check FAQ:
https://github.com/yzhang-gh/vscode-markdown#faq

Read the reporting guide, especially when you encountered lag, unresponsiveness, or other performance issues:
https://markdown-all-in-one.github.io/docs/contributing/issue.html

Test the latest dev build if needed:
https://github.com/yzhang-gh/vscode-markdown/actions/workflows/main.yml?query=event%3Apush+is%3Asuccess
-->
# A topic will disappear in TOC under  certain circumstance

Hello, thanks for great extension,it helps me a lot as I'm new to markdown and vscode. But I have little issue about table of contents.

## Problem

I find that a topic like `##this topic is not in TOC` will disappear in TOC sometimes.When a `- ` is before a code block like`code block 1` and the topic is in front of another code block like`code block 2`.
I wonder if it's a bug or some syntax rules?I check markdownlint but it didn't warn me angything

![](https://raw.githubusercontent.com/youhuangla/images/main/202202182040651.png)

<!--
A clear and concise description of what you expected and what actually happened.
-->

## How to reproduce

    # Bug Report

    - [Bug Report](#bug-report)
    - [Test](#test)

    ## Test

    - ```c
    code block 1
    ```

    ## this topic is not in TOC

    ```c
    code block 2
    ```

Type this in markdown and create TOC.
<!--
It's best to show it in steps.
You can also capture screenshots and videos when needed.
-->

## Configuration

I think it's default because I don't remember I change it.I'm new to vscode so if there is a way to find out,please tell me,thanks.
<!--
Copy modified settings as JSON, and paste them into the code block below.

If you didn't change anything, delete the code block and say:
Default.
-->

```jsonc

```

## Environment

Vscode with markdown all in one.
Windows 10.
<!--
Please provide the following at least, as described in the reporting guide:

* The version or commit SHA of Markdown All in One
* The basic environment information (VS Code's About)

If you're reporting a problem about our interaction with other software, please also include their information.
-->

## Diagnostic data

Nothing.
<!--
Usually some suspicious error messages from the Console of the Developer Tools.
If you're reporting a performance issue, please check the guide carefully.
-->

```log

```
