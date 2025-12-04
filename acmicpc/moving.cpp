#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <algorithm>
#include <unordered_map>

#include "json.hpp"

using json = nlohmann::json;
using namespace std;
namespace fs = std::filesystem;

unordered_map<string, int> extensionType ={
    {"c", 0},
    {"cpp", 1},
    {"python", 2},
    {"java", 3},
    {"rust", 4}
};

string readme = "./README.md";
string jsonFile = "./files_data.json";
string currentPath = ".";

json jsonData;

int main(){
    ifstream inpJson(jsonFile);
    if(inpJson.is_open()){
        inpJson >> jsonData;
        inpJson.close();
        cout <<"json file loaded\n";
    }else{
        cout <<"error while opening json file. Creating new file\n";
        jsonData = json::object();
    }


    for(const auto& entry : fs::directory_iterator(currentPath)){
        if(!entry.is_directory()) continue; // 폴더 한정
        for(const auto& entry2 : fs::directory_iterator(entry.path().filename().string())) { // 분류 폴더 진입 entry2 : 문제 폴더'
            if(!entry.is_directory()) continue;
            string problemPath = "./"+ entry.path().filename().string() +"/"+ entry2.path().filename().string();
            for(const auto& entry3 : fs::directory_iterator(problemPath)){ // 문제 폴더 진입. entry3 : 문제 파일
                string fileName = entry3.path().filename().string().substr();
                fileName = fileName.substr(0, fileName.find('.', 0));
                jsonData[fileName]={
                    {".c", false},
                    {".cpp", false},
                    {".python", false},
                    {".java", false},
                    {".rust", false}
                };
                jsonData[fileName][entry3.path().extension().string()] = true;
                ofstream outJson(jsonFile);
                outJson << jsonData;
                outJson.close();
            }
        }
    }
}


int main2(){
    for(const auto& entry : fs::directory_iterator(currentPath)){
        if(!entry.is_regular_file()) continue;
        string filename = entry.path().filename().string();
        if(filename[0]-'0' >= 10) continue;

        string fileNum = filename.substr(0, filename.find('.', 0));
        int num;
        try{
            num = stoi(fileNum);
        }catch(const exception& e){
            continue;
        }

        char folderName[10];
        sprintf(folderName, "%05d", (num/10000)*10000);
        string destPath = "./" + string(folderName);
        try{
            fs::path destFile = fs::path(destPath) / entry.path().filename();
            fs::rename(entry, destFile);
        }catch(const exception& e){
            cerr<<"failed to move : "<< e.what()<<"\n";
        }
    }


    return 0;
}
