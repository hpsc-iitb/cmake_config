#include <example.hpp>
#include <iostream>
#include <vector>


int main()
{
    std::vector<cl::Platform> platforms;

    cl::Platform::get(&platforms);
    for(auto pl : platforms)
    {
        std::vector<cl::Device> devices;
        std::cout << pl.getInfo<CL_PLATFORM_NAME>() << "\n";
        pl.getDevices(CL_DEVICE_TYPE_GPU, &devices);
        for(auto dev : devices)
        {
            std::cout << dev.getInfo<CL_DEVICE_NAME>() << "\n";
        }
    }
    return 0;
}