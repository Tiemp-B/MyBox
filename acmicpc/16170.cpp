#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;  
    
int main(){

    const system_clock::time_point now = system_clock::now();
    time_t now_t = chrono::system_clock::to_time_t(now);
    
    tm* utc = gmtime(&now_t);

    cout <<std::put_time(utc, "%Y\n%m\n%d");

    return 0;
}