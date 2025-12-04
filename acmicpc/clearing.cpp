#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <windows.h>


#include "json.hpp"

using json = nlohmann::json;
using namespace std;
namespace fs = std::filesystem;

string readmePath = "./Done/README.md";

string readmeTemplate1 = "|[";
string readmeTemplate2 = "](https://www.acmicpc.net/problem/";
string readmeTemplate3 = ")|"; // 난이도
string readmeTemplate4 = "|"; // 문제명
string readmeTemplate5 = "|"; // 카테고리
string readmeTemplate6 = "|☐|☐|☐|☐|☐|";
// ☑

string jsonPath = "./Done/files_data.json";

json solvedData;

string inp;
int probNum=-1;
string probPath="./Done/";
string probCate;
string fileName;
fs::__cxx11::directory_entry solvedFile;

void deletingExe(){
    // 예외 파일 목록
    unordered_set<string> exceptionFiles = {
        "clearing.exe",
        "Makefile",
        "json.hpp",
        "moving.cpp"
        // 필요한 예외 파일 추가
    };
    
    string currentPath = ".";
    
    // .exe 파일 삭제 (예외 파일 제외)
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
}

void jsonInit(){
    ifstream inpJson(jsonPath);
    if(inpJson.is_open()){
        inpJson >> solvedData;
        inpJson.close();
    }else{
        solvedData = json::object();
    }
}

void nowSolve(){
    cout << "Solved number: ";
    cin >> inp;
    probNum = stoi(inp);
    int temp;
    if(inp.size()==4){
        char buf[10];
        sprintf(buf, "%05d", probNum);
        inp = string(buf);
    }
    char buf2[10];
    temp = (probNum/10000)*10000;
    sprintf(buf2, "%05d", temp);
    probCate = string(buf2);
    probPath += probCate +"/"+inp;

    // 풀은 파일 찾기
    for(const auto& entry : fs::directory_iterator(".")){
        if(entry.is_regular_file()){
            string filename = entry.path().filename().string();
            if(filename.find(inp)==0){
                solvedFile = entry;
                break;
            }
        }
    }
}

void moveFile(){
    if(!fs::exists(probPath)){
        fs::create_directories(probPath);
    }
    
    try{
        fs::path destFile = fs::path(probPath)/ solvedFile.path().filename();
        fs::rename(solvedFile.path(), destFile);
        cout <<"Move Done\n";
    }catch (const exception& e){
        cerr<< "Move failed\n";
    }
}

void jsonUpdate(){
    if(solvedData.find(inp) == solvedData.end()){ // 없는 항목이다.
        solvedData[inp][".c"] = false;
        solvedData[inp][".cpp"] = false;
        solvedData[inp][".py"] = false;
        solvedData[inp][".java"] = false;
        solvedData[inp][".rs"] = false;
        solvedData[inp]={
            {".c", false},
            {".cpp", false},
            {".py", false},
            {".java", false},
            {".rs", false}
        };
    }
    solvedData[inp][solvedFile.path().extension().string()] = true;
    ofstream outJson(jsonPath);
    outJson << solvedData;
    outJson.close();
}

void readmeUpdate(){
    vector<string> lines;
    string probTitle, probLevel, probCategories, line;
    string probLine="|[";
    bool done=false;
    string trash;
    // 파일 정보
    while(true){
        cout <<"===Problem Info===\n";
        cout << "Title: ";
        getline(cin, trash);
        getline(cin, probTitle);
        cout << "Level: ";
        cin >> probLevel;
        cout << "Categories: ";
        getline(cin, trash);
        getline(cin, probCategories);

        cout << "\n===Confirm===\n";
        cout << "Title: "<< probTitle<<"\n";
        cout << "Level: "<< probLevel<<"\n";
        cout << "Categories: " << probCategories<<"\n";
        cout << "Proceed? [y/n]  ";
        cin >> line;
        if(line[0] =='y'||line[0]=='Y') break;
    }
    line.clear();
    
    probLine += to_string(probNum) + readmeTemplate2;
    probLine += to_string(probNum) + readmeTemplate3 + ")|";
    probLine += probLevel + "|";
    probLine += probTitle + "|";
    probLine += probCategories + "|";

    for(auto& v : solvedData[inp]){
        if(v){
            probLine += " ☑ |";
        }else{
            probLine += " ☐ |";
        }
    }

    // README에서의 위치 찾기
    ifstream readmeFile(readmePath);
    int cnt=5;
    while(getline(readmeFile, line)){
        if(cnt-->0){
            lines.push_back(line);
            continue;
        }
        int num = stoi(line.substr(2, line.find(']',0)-2));
        if(!done){
            if(num==probNum){//갱신
                lines.push_back(probLine);
            }else if(num <probNum){ // 현재 라인은 목표번호보다 이르다
                lines.push_back(line);
            }else{ // 추가
                lines.push_back(probLine);
                lines.push_back(line);
                done = true;
            }
        }else{
            lines.push_back(line);
        }
    }
    if(!done){
        lines.push_back(probLine);
    }
    readmeFile.close();

    // 저장
    ofstream outFile(readmePath);
    for(const auto& lin: lines){
        outFile << lin <<"\n";
    }
    outFile.close();
}

int main(){
    // deletingExe();

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    jsonInit();
    nowSolve();
    jsonUpdate();
    readmeUpdate();
    moveFile();

    return 0;
}