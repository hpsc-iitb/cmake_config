# CMake setup for compiling project

## Dependencies (Windows)
  - Install [CMake](https://cmake.org/) or use Chocolatey
  - Add CMake to path (test if the command `cmake` works in shell)
  - Install [SFML](https://www.sfml-dev.org/download/sfml/2.5.1/)
    - Minimum version 2.5 required 
    - Download the correct version of `mingw` or Visual Studio (Community) as mentioned on the SFML download page
    - If using `mingw`, make sure `g++` works in shell
  - Install OpenCL
    - For Nvidia users, download the CUDA SDK, this installs OpenCL as well
    - AMD people download [OpenCL SDK](https://github.com/GPUOpen-LibrariesAndSDKs/OCL-SDK/releases)

## Compiling

  - Clone this repository (or download zip)
  - Edit `CMakeLists.txt` line `26` to point to correct SFML root directory, example `F:/libs/SFML-2.5.1/lib/cmake/SFML`, note the forward slashes
  - Configure this directory using CMake-gui and generate build files, choose correct compiler when configuring
  - Go inside build directory, build the project using the `Makefile` (for `mingw`) or open the Visual Studio project and build it
  - Should build successfully