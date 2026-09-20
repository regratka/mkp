@ECHO OFF
ECHO Deleting old build
rmdir build\Src /s /q

ECHO Building all TUs
ninja