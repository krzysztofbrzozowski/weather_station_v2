### PROBLEM:
```
CMake Error at /usr/local/Cellar/cmake/3.27.5/share/cmake/Modules/CMakeTestCCompiler.cmake:67 (message):
  The C compiler

    "/usr/local/bin/arm-none-eabi-gcc"

  is not able to compile a simple test program.

  It fails with the following output:

    Change Dir: '/Users/krzysztofbrzozowski/Documents/PROJECTS/SOFTWARE/weather_station_v2/build/CMakeFiles/CMakeScratch/TryCompile-qUGIP6'
    
    Run Build Command(s): /usr/local/Cellar/cmake/3.27.5/bin/cmake -E env VERBOSE=1 /usr/bin/make -f Makefile cmTC_336e5/fast
    /Library/Developer/CommandLineTools/usr/bin/make  -f CMakeFiles/cmTC_336e5.dir/build.make CMakeFiles/cmTC_336e5.dir/build
    Building C object CMakeFiles/cmTC_336e5.dir/testCCompiler.c.o
    /usr/local/bin/arm-none-eabi-gcc   -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX13.3.sdk -o CMakeFiles/cmTC_336e5.dir/testCCompiler.c.o -c /Users/krzysztofbrzozowski/Documents/PROJECTS/SOFTWARE/weather_station_v2/build/CMakeFiles/CMakeScratch/TryCompile-qUGIP6/testCCompiler.c
    Linking C executable cmTC_336e5
    /usr/local/Cellar/cmake/3.27.5/bin/cmake -E cmake_link_script CMakeFiles/cmTC_336e5.dir/link.txt --verbose=1
    /usr/local/bin/arm-none-eabi-gcc  -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX13.3.sdk -Wl,-search_paths_first -Wl,-headerpad_max_install_names CMakeFiles/cmTC_336e5.dir/testCCompiler.c.o -o cmTC_336e5 
    /Applications/ArmGNUToolchain/12.3.rel1/arm-none-eabi/bin/../lib/gcc/arm-none-eabi/12.3.1/../../../../arm-none-eabi/bin/ld: Error: unable to disambiguate: -search_paths_first (did you mean --search_paths_first ?)
    collect2: error: ld returned 1 exit status
    make[1]: *** [cmTC_336e5] Error 1
    make: *** [cmTC_336e5/fast] Error 2
```
### SOLUTION:
Download fresh SDK + optionally examples
```
    git clone https://github.com/raspberrypi/pico-sdk.git
    git clone https://github.com/raspberrypi/pico-examples.git
    cd pico-sdk
    git submodule update --init
```
