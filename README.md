# vehicle-MPC-CasADi-CPP
Vehicle tracking simulation using CasADi and C++

## Issues

1. Currently, linking CasADi to C++ in Visual Studio projects failed. `LNK2019` error codes flooded the compilation process. Possible action: instead of Visual Studio, use terminal and g++ to compile and link with CasADi binary package (in Windows / Unbuntu). The support on CasADi C++ is apparently limited. But since CasADi is mainly built using C++, it will be easier to debug any issue directly using C++ based code rather than using the Python or MATLAB API.