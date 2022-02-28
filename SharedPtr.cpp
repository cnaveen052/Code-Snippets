#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(...) for(auto& i:__VA_ARGS__) cout<<i<<" "; cout<<'\n';
#define read(...) for(auto& i:__VA_ARGS__) cin>>i;
#define int long long
const int mod=1e9+7;

template<typename T>
class SharedPtr{
private:
    T* data = nullptr;
    int* cnt = nullptr;

    void cleanup(){
        (*cnt)--;
        if(*cnt == 0){
            delete data;
            delete cnt;
        }
    }
public:
    SharedPtr() : data(nullptr), cnt(new int(0)) {}
    SharedPtr(T* ptr) : data(ptr), cnt(new int(1)) {}
    
    //Copy constructor
    SharedPtr(const SharedPtr& obj){
        data = obj.data;
        cnt = obj.cnt;
        if(obj.data) (*cnt)++;
    }
    
    //Copy assignment
    SharedPtr& operator=(const SharedPtr& obj){
        cleanup();
        data = obj.data;
        cnt = obj.cnt;
        if(obj.data) (*cnt)++;
        return *this;
    }
    
    //Move constructor
    SharedPtr(SharedPtr&& obj){
        data = obj.data;
        cnt = obj.cnt;
        obj.data = obj.cnt = nullptr;
    }
    
    //Move assignment
    SharedPtr& operator=(SharedPtr&& obj){
        cleanup();
        data = obj.data;
        cnt = obj.cnt;
        obj.data = obj.cnt = nullptr;
        return *this;
    }
    
    T* operator->(){
        return data;
    }
    
    T& operator*(){
        return *data;
    }
    
    T& getData(){
        return *data;
    }
    
    int getCount(){
        return *cnt;
    }
    
    ~SharedPtr(){
        cleanup();
    }
};

#undef int
int main() {
    SharedPtr x = new int(4);
    cout<<x.getCount()<<endl;
    cout<<x.getData()<<endl;
}
