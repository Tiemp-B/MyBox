#include <thread>

#ifdef _WIN32
    #include <winsock2.h>
    #define OS_NAME "Windows"
    #pragma comment(lib, "ws2_32.lib")
    using SocketType = SOCKET;
#elif defined(__APPLE__) && defined(__MACH__)
    #include <TargetConditionals.h> 
    #if TARGET_OS_MAC
        #include <unistd.h>
        #define OS_NAME "macOS"
    #endif
#elif defined(__linux__)
    #include <unistd.h>
    #include <sys/socket.h>
    #define OS_NAME "Linux"
#elif defined(__unix__)
    #include <unistd.h>
    #include <sys/socket.h>
    #define OS_NAME "Unix"
#elif defined(__POSIX_VERSION)
    #include <unistd.h>
    #include <sys/socket.h>
    #define OS_NAME "POSIX"
#else
    #define OS_NAME "Unknown OS"
#endif


class winSocket{
    public:
        WSADATA wsaData;
}