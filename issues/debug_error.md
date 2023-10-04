### Problem:
Unable to run picoprobe debugger in VS Studio Code on MacOS. Below error is shown
```
Failed to launch OpenOCD GDB Server
```

## #Analysis:
- Manually running openocd working
```
./openocd -c "gdb_port 50000" -c "tcl_port 50001" -c "telnet_port 50002" -s /Users/krzysztofbrzozowski/Tools/openocd/tcl -f /Users/krzysztofbrzozowski/.vscode/extensions/marus25.cortex-debug-1.12.1/support/openocd-helpers.tcl -f /Users/krzysztofbrzozowski/Tools/openocd/tcl/interface/cmsis-dap.cfg -f /Users/krzysztofbrzozowski/Tools/openocd/tcl/target/rp2040.cfg -c "adapter speed 5000"
```
- OpenOCD is not able to start from Cortex-Debug extention in VS Studio Code
- Downloaded old branch from GitHub of OpenOCD 


### Solution:
- Download latest branch with OpenOCD from GitHub and build it
```
$ git clone https://github.com/raspberrypi/openocd.git --branch rp2040-v0.12.0 --recursive --depth=1
$ cd openocd
$ ./bootstrap
$ ./configure --disable-werror
$ make -j4
```

- Configure launch.json with 
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
