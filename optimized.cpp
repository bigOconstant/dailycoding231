#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;

struct Compare{
     bool operator()(
        pair<string,int> const & a,
        pair<string,int> const & b) 
        {
            return a.second < b.second;
        }
};
std::string calculateresult(std::string const & input);
int main(){
    
    auto output = string("bb");
    cout<<"result:"<<calculateresult(output)<<endl;;

}

std::string calculateresult(std::string const & input){
    

    map<std::string, int> mapOfSet;

    for(auto it = input.begin(); it < input.end(); ++it){
        if(mapOfSet.find(std::string(1,*it)) == mapOfSet.end() ){
            //not found
            mapOfSet.insert({std::string(1,*it),1});
        }else{
            mapOfSet[std::string(1,*it)] +=1;
        }
    };
    std::priority_queue<std::pair<std::string,int>, std::vector<std::pair<std::string,int>>,  Compare> Q;

    for(auto itr = mapOfSet.begin(); itr != mapOfSet.end(); itr++){
        Q.push((*itr));
    }
    auto t = Q.top();

    std::string builder = "";
    pair<string,int> prev{"-1",-1}; // Throw away

    while(!Q.empty()){
        std::priority_queue<std::pair<std::string,int>, std::vector<std::pair<std::string,int>>,  Compare> cp = Q;
        auto top = Q.top();
        Q.pop();
        builder += top.first;

        if(prev.second > 0){
            Q.push(prev);
        }
        top.second -=1;
        prev = top;
    }

    if(builder.size() != input.size()){
        return "None";
    }else{
        return builder;
    }
}
 

