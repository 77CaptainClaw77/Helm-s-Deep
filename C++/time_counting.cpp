#include <iostream>
#include <chrono>
int main(){
    auto start=std::chrono::high_resolution_clock::now();
    for(long i=1000000;i>0;i--);
    auto end=std::chrono::high_resolution_clock::now(); 
    long time_diff=std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
    std::cout<<time_diff;
}
