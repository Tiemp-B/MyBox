#include <iostream>

using namespace std;

class Con{
private:
    Con* _inst = NULL;
    int count=0;
public:
    Con* get(){
        if(_inst == NULL){
            _inst = new Con();
            return _inst
        }
        return _inst;
    }

    void count(){
        count++;
    }

    int getCount(){
        return count;
    }
};

int main(){
    Con* c1 = Con.get();

    return 0;
}
