#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>

std::string generate_random_string(size_t length) {
    static const std::string charset = "abcdefghijklmnopqrstuvwxyz";
    static std::mt19937 rng(std::random_device{}());
    static std::uniform_int_distribution<> dist(0, charset.size() - 1);

    std::string result;
    for (size_t i = 0; i < length; ++i)
        result += charset[dist(rng)];
    return result;
}

int main() {
    const int N = 1000;
    std::vector<std::string> random_strings;
    std::string sample = generate_random_string(10);
    for (int i = 0; i < N; ++i)
        random_strings.push_back(generate_random_string(10));  // 길이 10의 랜덤 문자열

    // Vector + sort()
    std::vector<std::string> v;
    auto start_vector = std::chrono::high_resolution_clock::now();
    for(auto str : random_strings)
        v.push_back(str);
    std::sort(v.begin(), v.end());
    auto end_vector = std::chrono::high_resolution_clock::now();
    auto duration_vector = std::chrono::duration_cast<std::chrono::microseconds>(end_vector - start_vector).count();
    std::cout << "Vector + sort() duration: " << duration_vector << " us" << std::endl;

    // Map 삽입
    std::map<std::string, int> m;
    auto start_map = std::chrono::high_resolution_clock::now();
    for (const auto& s : random_strings)
        m[s]=0;
    auto end_map = std::chrono::high_resolution_clock::now();
    auto duration_map = std::chrono::duration_cast<std::chrono::microseconds>(end_map - start_map).count();
    std::cout << "Map insert duration: " << duration_map << " us" << std::endl;

    int i=0;
    std::cout << random_strings.size()<<" "<<v.size() <<" "<< m.size()<<"\n";

    return 0;
}

