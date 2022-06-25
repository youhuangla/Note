# Vim

## Undo and redo

- use u and Ctrl + R to undo and redo

- press Ctrl + semicolon(';') to exit insert mode(can't work in vscode),so better Ctrl + '[' to exit

## Find and replace

<https://harttle.land/2016/08/08/vim-search-in-file.html>

## Use K for man

[manuals \- How do you use the "K"\-button in the normal mode of VIM? \- Stack Overflow](https://stackoverflow.com/questions/843823/how-do-you-use-the-k-button-in-the-normal-mode-of-vim#:~:text=Simply%20put%2C%20K%20runs%20the,the%20'iskeyword'%20option).)

## Search for selected

[How to search for selected text in Vim? \- Super User](https://superuser.com/questions/41378/how-to-search-for-selected-text-in-vim)

> you can simply yank the selected text with **y** and go to search mode **/**, then you can paste the last yanked text with **Ctrl+R 0**
>
> [viemu \- Search for selection in Vim \- Stack Overflow](

## Delete a character

[How do I delete the previous character in vim? \- Stack Overflow](https://stackoverflow.com/questions/41491763/how-do-i-delete-the-previous-character-in-vim)

simply use `X` (which is shift+x)

## Souce and config

If I want to add a title to a file with a specific suffic like "cpp" or "c".

```.vimrc
func SetTitle() 
......
if &filetype == 'c'
	call append(line(".")+6, "#include <stdio.h>")
	call append(line(".")+7, "")
	call append(line(".")+8, "int main() {")
	call append(line(".")+9, "	")
	call append(line(".")+10, "	return 0;")
	call append(line(".")+11, "}")
```

[vim - Vimrc error: "syntax: command not found" - Stack Overflow](https://stackoverflow.com/questions/49217453/vimrc-error-syntax-command-not-found)

Save and source it inside vim:

```vim
:source ~/.vimrc
```

If something like [vim - How to fix this error "E122: Function MyDiff already exists, add ! to replace it" after I source a vimrc file? - Stack Overflow](https://stackoverflow.com/questions/39706615/how-to-fix-this-error-e122-function-mydiff-already-exists-add-to-replace-it) appears.

Add a `!` after `func` .

```.vimrc
func! SetTitle() 
```

And notice that the line should be continuous.

Enjoy!
