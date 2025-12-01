#include <iostream>
#include <filesystem>
#include <string>
#include <algorithm>

using namespace std;
namespace fs = std::filesystem;

int main(){
    string currentPath = ".";

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
