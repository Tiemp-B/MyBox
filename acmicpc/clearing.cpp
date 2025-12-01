#include <iostream>
#include <filesystem>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;
namespace fs = std::filesystem;

int main() {
    // 예외 파일 목록
    unordered_set<string> exceptionFiles = {
        "clearing.exe",
        "Makefile"
        // 필요한 예외 파일 추가
    };
    
    string currentPath = ".";
    
    // 1. .exe 파일 삭제 (예외 파일 제외)
    cout << "=== Deleting .exe files ===\n";
    for (const auto& entry : fs::directory_iterator(currentPath)) {
        if (entry.is_regular_file() && entry.path().extension() == ".exe") {
            string filename = entry.path().filename().string();
            
            if (exceptionFiles.find(filename) == exceptionFiles.end()) {
                cout << "Deleting: " << filename << "\n";
                fs::remove(entry.path());
            } else {
                cout << "Skipping: " << filename << " (exception)\n";
            }
        }
    }
    
    // 2. 5자리 숫자 파일 입력 받기
    cout << "\n=== Enter 5-digit file number ===\n";
    cout << "File number (00000-99999): ";
    string fileNum;
    cin >> fileNum;
    
    // 입력 검증
    if (fileNum.length() != 5 || !all_of(fileNum.begin(), fileNum.end(), ::isdigit)) {
        cout << "Error: Invalid input. Must be 5-digit number.\n";
        return 1;
    }
    
    // 3. 파일 찾기
    vector<fs::path> matchingFiles;
    for (const auto& entry : fs::directory_iterator(currentPath)) {
        if (entry.is_regular_file()) {
            string filename = entry.path().filename().string();
            // 파일명이 입력한 숫자로 시작하는지 확인
            if (filename.find(fileNum) == 0) {
                matchingFiles.push_back(entry.path());
            }
        }
    }
    
    if (matchingFiles.empty()) {
        cout << "No files found starting with " << fileNum << "\n";
        return 0;
    }
    
    // 4. 이동할 폴더 결정 (00000-09999 -> 00000, 10000-19999 -> 10000, ...)
    int num = stoi(fileNum);
    int folderNum = (num / 10000) * 10000;
    
    // 폴더 이름 생성 (5자리로 포맷)
    char folderName[10];
    sprintf(folderName, "%05d", folderNum);
    
    string destPath = "./Done/" + string(folderName);
    
    // 5. 목적지 폴더 생성 (없으면)
    try {
        if (!fs::exists(destPath)) {
            fs::create_directories(destPath);
            cout << "Created directory: " << destPath << "\n";
        }
    } catch (const exception& e) {
        cerr << "Failed to create directory: " << e.what() << "\n";
        return 1;
    }
    
    // 6. 파일 이동
    cout << "\n=== Moving files to " << destPath << " ===\n";
    for (const auto& file : matchingFiles) {
        try {
            fs::path destFile = fs::path(destPath) / file.filename();
            fs::rename(file, destFile);
            cout << "Moved: " << file.filename() << " -> " << destFile << "\n";
        } catch (const exception& e) {
            cerr << "Failed to move " << file << ": " << e.what() << "\n";
        }
    }
    
    cout << "\nTotal moved: " << matchingFiles.size() << " file(s)\n";
    cout << "Done!\n";
    
    return 0;
}