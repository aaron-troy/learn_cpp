#include <iostream>

const int num_stds = 7;
const long stdCode[num_stds] = {
    199711L, 
    201103L,
    201402L,
    201703L,
    202002L,
    202302L,
    202612L
};
const char* stdName[num_stds] = {
    "C++98",
    "C++11",
    "C++14",
    "C++17",
    "C++20",
    "C++23",
    "C++26"
};

long getcppstd()
{
    #if defined(_MSVC_LANG)
        return _MSVC_LANG;
    #elif defined(_MSVC_VER)
        return -1;
    #else
        return __cplusplus;
    #endif
}

int main()
{
    long cppstd = getcppstd();
    if (cppstd == -1)
    {
        std::cout << "Error: Standard Unknown";
        return 0;
    }
    
    for (int i = 0; i < num_stds; ++i)
    {
        if (cppstd == stdCode[i])
        {
            std::cout << "Your compiler is using C++ standard: " << stdName[i] << std::endl;
            break;
        }
        if (cppstd < stdCode[i])
        {
            std::cout << "Your compiler is using a preview/pre-release of " << stdName[i]
                << " (language standard code " << cppstd << "L)\n";
            break;
        }
    }
    return 0;    
}

