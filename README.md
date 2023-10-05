Weather station - version 2 based on RPI2040
## Requirements
- Station is based on RPI2040 uC -> for dev purposes RPi Pico will be used
- Station is powered by 3.7V battery
- Station uses SIM800 or other GPRS module to send or receive data
- Station can use WiFi module to send or receive data
- Station is updated via micro-USB port
- Station supports OTA updates

## TODO
- [x] Set up CI to build project
- [x] Set up debugging locally
![rp2040_debug_view_vscode.png](https://krzysztofbrzozowski.com/media/2023/10/04/rp2040_debug_view_vscode.png)
- [x] Connect RPi Pico into prototype board
- [x] Run UART
- Connect to WiFi and get iot server time printed via e.g. UART

## Steps after download
- Build OpenOCD (If you using MacOS you can use below commands)
```console
<!-- skip if have brew installed -->
$ /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"

<!-- Install tools to build OpenOCD -->
$ brew install libtool automake libusb wget pkg-config gcc texinfo

<!-- Clone and build OpenOCD -->
$ git clone https://github.com/raspberrypi/openocd.git --branch rp2040-v0.12.0 --recursive --depth=1
$ cd openocd
$ ./bootstrap
$ ./configure --disable-werror
$ make -j4

<!-- Install GDB -->
$ brew install gdb
<!-- Install minicom -->
$ brew install minicom
<!-- run minicom -->
minicom -b 115200 -o -D /dev/cu.usbmodem1423402
```
- Set up .vscode folder with correct options and paths
Configure launch.json with 
```json
"serverpath": "...",
"searchDir": ["..."],
```

Example of launch.json:
```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Pico Debug",
            "cwd": "${workspaceRoot}",
            "executable": "${command:cmake.launchTargetPath}",
            "request": "launch",
            "type": "cortex-debug",
            "servertype": "openocd",
            // This may need to be "arm-none-eabi-gdb" for some previous builds
            "gdbPath" : "arm-none-eabi-gdb",
            "device": "RP2040",
            "configFiles": [
                "/Users/krzysztofbrzozowski/Tools/openocd/tcl/interface/cmsis-dap.cfg",
                "/Users/krzysztofbrzozowski/Tools/openocd/tcl/target/rp2040.cfg"
            ],
            "svdFile": "${env:PICO_SDK_PATH}/src/rp2040/hardware_regs/rp2040.svd",
            "runToEntryPoint": "main",
            // Work around for stopping at main on restart
            "postRestartCommands": [
                "break main",
                "continue"
            ],
            "showDevDebugOutput": true,
            "serverpath": "/Users/krzysztofbrzozowski/Tools/openocd/src/openocd",
            "searchDir": ["/Users/krzysztofbrzozowski/Tools/openocd/tcl"]
        }
    ]
}
```
Example of settings.json:
```json
{
    "cmake.environment": {
        "PICO_SDK_PATH": "/Users/krzysztofbrzozowski/Documents/PROJECTS/SOFTWARE/rpi_pico.nosync/pico-sdk"
    },
    "cmake.statusbar.advanced": {
        "debug": {
            "visibility": "hidden"
        },
        "launch": {
            "visibility": "hidden"
        },
        "build": {
            "visibility": "default"
        },
        "buildTarget": {
            "visibility": "hidden"
        }
    },
    "cmake.buildBeforeRun": true,
    "C_Cpp.default.configurationProvider": "ms-vscode.cmake-tools",
    "cortex-debug.openocdPath": "/Users/krzysztofbrzozowski/Tools/openocd/src/openocd"
}
```

