
setlocal
set workdir=%~dp0
echo off
if exist "%USERPROFILE%\Python\python.exe" (
	set PYTHONHOME=%USERPROFILE%\Python
	set PYTHONPATH=%USERPROFILE%\Python
)
PATH=%PATH%;%workdir%;%USERPROFILE%\.platformio\penv\Scripts;%PYTHONPATH%;
@chcp 1251>nul


:m1
cls
color 47
Echo  #------------------------------------------#
Echo  *    #####               #     #####  ###  *
Echo  *   #                   #     #      #  ## *
Echo  *  ### # ### ###       #     #####  #   #  *
Echo  * #   # #   ####      #     #      #   #   *
Echo  *#   # #    #        ##### #####  ####     *
Echo  #------------------------------------------#
Echo  *                COMMANDS                  *
Echo  #------------------------------------------#
Echo  *             Build and flash              *
Echo  *  Build and upload - ATMEGA328P    - (u)  *
Echo  #------------------------------------------#
Echo  *                  DEBUG                   *
Echo  *  Serial port monitor              - (d)  *
Echo  #------------------------------------------#
Echo  *  Erase Flash                      - (e)  *
Echo  #------------------------------------------#
Echo  *  Update libs and PIO Core         - (g)  *
Echo  *  Clean up temp files .pio         - (c)  *
Echo  *------------------------------------------#
Echo  *  CMD window                       - (m)  *
Echo  *------------------------------------------#
Echo  *  Remove Platformio installation   - (r)  *
Echo  #------------------------------------------#
Echo.
Set /p choice="Your choice: "
cls 
color 0a
Echo  #------------------------------------------#
Echo  *    #####               #     #####  ###  *
Echo  *   #                   #     #      #  ## *
Echo  *  ### # ### ###       #     #####  #   #  *
Echo  * #   # #   ####      #     #      #   #   *
Echo  *#   # #    #        ##### #####  ####     *
Echo  #------------------------------------------#

if "%choice%"=="1" (
	call update-DEV-from-Git.cmd 1
	"%USERPROFILE%\.platformio\penv\Scripts\pio.exe" lib update
)
if "%choice%"=="2" (
	call update-DEV-from-Git.cmd 2
	"%USERPROFILE%\.platformio\penv\Scripts\pio.exe" lib update
)
if "%choice%"=="3" call update-DEV-from-Git.cmd 3
if "%choice%"=="u" ("%USERPROFILE%\.platformio\penv\Scripts\pio.exe" run --target upload --environment uno)
if "%choice%"=="d" (start %workdir%\SerialMonitor.cmd)

if "%choice%"=="c" (
	pio system prune -f
	rmdir /S /Q %workdir%\.pio
)
if "%choice%"=="g" (
	"%USERPROFILE%\.platformio\penv\Scripts\pio.exe" upgrade
	"%USERPROFILE%\.platformio\penv\Scripts\pio.exe" update
	"%USERPROFILE%\.platformio\penv\Scripts\pio.exe" lib update
)
if "%choice%"=="m" (start cmd)
if "%choice%"=="r" (rmdir /S "%USERPROFILE%\.platformio")
if "%choice%"=="q" (exit)
Echo.
Echo.
Echo.
pause
del %workdir%\resources\.wget-hsts
goto m1


exit 