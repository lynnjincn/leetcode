mkdir %1
cd %1
XCOPY ..\base\.vscode .vscode /s/e
XCOPY ..\base\.clang-format .clang-format
XCOPY ..\base\base.c %1.c