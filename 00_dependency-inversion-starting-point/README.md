Engineering Internship code and resources will be shared here.

Check the branches for content.

This is a dummy VS Code project for compiling all existing .cpp files in the directory where the .vscode directory is placed.
Copy the .vscode directory to a directory created by you that will be used as a workspace directory.
In VSCode, opening a directory is more or less equivalent with opening a project file in another IDE (e.g. Visual Studio).
The .sln file in VSCode would actually be the .vscode directory.

Make sure to check the compiler paths in the .json files are correct.

Currently used compiler path: C:\mingw-w64\x86_64-12.1.0-release-posix-seh-rt_v10-rev3\mingw64\bin\g++.exe

Get compiler from here and place it in `C:\mingw-w64\` so that the path above is valid:
* https://github.com/niXman/mingw-builds-binaries/releases
* https://github.com/niXman/mingw-builds-binaries/releases/download/12.1.0-rt_v10-rev3/x86_64-12.1.0-release-posix-seh-rt_v10-rev3.7z

How to run a build: in VSCode go to the Debug tab (left side) and "play" the "Debug Executable" task.
Also, for just building without running you can press Ctrl+Shift+B.

For compiling GTest unit tests:
```
g++ <codeFileName.cpp> -c
g++ <testFileName.cpp> -c
g++ <codeFileName.o> <testFileName.o> -L./lib -lgtest -lgtest_main -lpthread
```