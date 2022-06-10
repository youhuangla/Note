# jsoncpp

[open\-source\-parsers/jsoncpp: A C\+\+ library for interacting with JSON\.](https://github.com/open-source-parsers/jsoncpp)

[Building · open\-source\-parsers/jsoncpp Wiki](https://github.com/open-source-parsers/jsoncpp/wiki/Building#building-and-testing-with-cmake)

```shell
youhuangla@Ubuntu Software_Source_Code % cd jsoncpp-1.9.5/                                      [0]
youhuangla@Ubuntu jsoncpp-1.9.5 % ls                                                            [0]
AUTHORS            amalgamate.py  example                           pkg-config
BUILD.bazel        appveyor.yml   get_version.pl                    reformat.sh
CMakeLists.txt     cmake          include                           src
CONTRIBUTING.md    dev.makefile   jsoncpp-namespaced-targets.cmake  test
CTestConfig.cmake  devtools       jsoncppConfig.cmake.in            version.in
LICENSE            doc            meson.build
README.md          doxybuild.py   meson_options.txt
youhuangla@Ubuntu jsoncpp-1.9.5 % vcpkg                                                         [0]
zsh: command not found: vcpkg
youhuangla@Ubuntu jsoncpp-1.9.5 % mkdir -p build/debug                                        [127]

youhuangla@Ubuntu jsoncpp-1.9.5 % ls                                                            [0]
AUTHORS            README.md      devtools        jsoncpp-namespaced-targets.cmake  src
BUILD.bazel        amalgamate.py  doc             jsoncppConfig.cmake.in            test
CMakeLists.txt     appveyor.yml   doxybuild.py    meson.build                       version.in
CONTRIBUTING.md    build          example         meson_options.txt
CTestConfig.cmake  cmake          get_version.pl  pkg-config
LICENSE            dev.makefile   include         reformat.sh
youhuangla@Ubuntu jsoncpp-1.9.5 % cd build/debug/ 
youhuangla@Ubuntu debug % cmake -DCMAKE_BUILD_TYPE=debug -DBUILD_STATIC_LIBS=ON -DBUILD_SHARED_LIBS=OFF -DARCHIVE_INSTALL_DIR=. -G "Unix Makefiles" ../.. -DCMAKE_INSTALL_INCLUDEDIR=include/jsoncpp

-- JsonCpp Version: 1.9.5
-- Configuring done
-- Generating done
-- Build files have been written to: /home/youhuangla/Software_Source_Code/jsoncpp-1.9.5/build/debug
```

。。没装成