# Clion

* MinGW sh.exe must NOT be in your path
  <https://stackoverflow.com/questions/41333215/mingw-sh-exe-must-not-be-in-your-path>

  

  Just add

  > ```
  > set(DCMAKE_SH="CMAKE_SH-NOTFOUND")
  > ```

  to your

  > CMakeLists.txt file

  and reload project

  <img src="img/image-20220321171451442.png" alt="image-20220321171451442" style="zoom:33%;" />

## Force step into

Steps into the function even if it is skipped by the regular Step Into by default.

Click the Force step into button Force Step Into icon or press Alt+Shift+F7.

In case the source code of the function that you want to step into is unavailable, you can debug disassembled code in a dedicated view.

<https://www.jetbrains.com/help/clion/stepping-through-the-program.html#force-step-into>
