A screenshot tool originally developed for GNU/Linux that auto uploads to Imgur

## Supported Operating Systems
- Linux/X11 - Tested on Kubuntu 18.04
- Windows - Tested on Windows 10

## Requirements
- Qt 5
- gcc on Linux
- MinGW on Windows, preferably 5.3 and higher

## Building
Install [Qt 5](https://www.qt.io/download) and install the OpenGL libraries (if necessary):
- Debian: `sudo apt install build-essential libgl1-mesa-dev`
- Fedora/RHEL: `sudo yum groupinstall "C Development Tools and Libraries"` and `sudo yum install mesa-libGL-devel`
- openSUSE: `sudo zypper install -t pattern devel_basis`

Register an application at [Imgur](https://apidocs.imgur.com/):
- Register the client details [here](https://api.imgur.com/oauth2/addclient) and a client id will be given
- Replace the client id in mainwindow.cpp under the function `sendScreenshot()`

On Linux 
- Install linuxdeployqt [here](https://github.com/probonopd/linuxdeployqt) and follow the installation [instructions](https://github.com/probonopd/linuxdeployqt)
- Build using qmake 
- Run linuxdeployqt `linuxdeployqt <path to binary file>`

On Windows
- Build using qmake. If you receive an SSL error or missing dll error, download [Win32 OpenSSL v1.10h Light](https://slproweb.com/products/Win32OpenSSL.html) and install. Take the following dll and paste them to the root directory: `libeay32.dll` `ssleay32.dll`
- Run windeployqt `windeployqt <path\to\PoPi.exe>` in the command prompt in the Qt SDK directory `Qt\5.10.1\mingw\bin\`
- Go to the Qt SDK path `Qt\5.10.1\mingw\bin\` and copy the following files to the directory where the binary/executable is: `libstdc++-6.dll` `libwinpthread-1.dll` `libgcc_s_dw2-1.dll`

## Credit
Thanks to [mitei](https://github.com/mitei) for the [qglobalshortcut](https://github.com/mitei/qglobalshortcut) library used to capture global hotkeys across multiple operating systems
