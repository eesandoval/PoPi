A screenshot tool originally developed for GNU/Linux that auto uploads to Imgur

## Supported Operating Systems
- Linux/X11 - Tested on Kubuntu 18.04

## Requirements
- Qt 5
- gcc

## Building
Install [Qt 5](https://www.qt.io/download) and install the OpenGL libraries (if necessary):
- Debian: `sudo apt install build-essential libgl1-mesa-dev`
- Fedora/RHEL: `sudo yum groupinstall "C Development Tools and Libraries"` and `sudo yum install mesa-libGL-devel`
- openSUSE: `sudo zypper install -t pattern devel_basis`

Register an application at [Imgur](https://apidocs.imgur.com/):
- Register the client details [here](https://api.imgur.com/oauth2/addclient) and a client id will be given
- Replace the client id in mainwindow.cpp under the function `sendScreenshot()`

## Credit
Thanks to [hluk](https://github.com/hluk) for re-uploading and mainting the [Qtxglobalshortcut](https://github.com/hluk/qxtglobalshortcut)
