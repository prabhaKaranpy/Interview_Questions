#include<bits/stdc++.h>    // a graph problem 
using namespace std;    
struct Node{
    string name; 
    int age; 
    Node(){
        this->name = ""; 
        this->age = 0; 
    }
    Node(string name, int age){
        this->name = name; 
        this->age = age; 
    }
    vector<Node*> friends; 
};
bool dfs(Node* &profile, string &target, vector<string> &ds, map<string, int> &visited){
    cout<<"\nVisiting Profile : "<<profile->name; 
    // cout<<endl; 
    if(visited[profile->name] == 1){
        // cout<<"\nvisited : "<<profile->name<<endl; 
        return false;
    } 
    if(profile->name == target){
        // ds.push_back(profile->name); 
        return true; 
    } 
    visited[profile->name] = 1; 
    // cout<<"\nFriends : "; 
    // for(Node* i : profile->friends){
    //     cout<<i->name<<"  "; 
    // }
    // cout<<endl; 
    for(Node* i : profile->friends){
         
        //   cout<<i.name<<"   "; 
        ds.push_back(i->name);
        if(dfs(i, target, ds, visited) == true){
            return true; 
        } 
        ds.pop_back(); 
    } 
    // ds.pop_back(); 
    // cout<<"\nafter for : "<<profile->name<<endl; 
    return false; 

}
// logic 
vector<string> solution(Node* &gordon, string target){
    vector<string> ds; 
    map<string, int> visited; 
    dfs(gordon, target, ds, visited); 
    return ds; 
}
int main(void){
    // Node gordon("Gordon", 18); 
    Node* gordon = new Node("Gordon", 18); 
    Node* sam = new Node("Sam", 18);
    Node* harry = new Node("Harry", 18);
    Node* tom = new Node("Tom", 18);
    Node* stephen = new Node("Stephen", 18);
    // Node stephen("Stephen", 17); 
    // Node sam("Sam", 18); 
    // Node tom("Tom", 17); 
    // Node harry("Harry", 18); 
    // Node ben("Ben", 17); 
    gordon->friends.push_back(sam); 
    gordon->friends.push_back(harry); 
    harry->friends.push_back(tom); 
    sam->friends.push_back(gordon); 
    tom->friends.push_back(harry); 
    harry->friends.push_back(gordon); 
    tom->friends.push_back(stephen); 
    stephen->friends.push_back(tom); 
    // for(Node &it : gordon->friends){
    //     cout<<it.name<<"  "; 
    // } cout<<endl; 
    // for(Node* &it : sam->friends){
    //     cout<<it->name<<"  "; 
    // } cout<<endl;
    // for(Node* &it : harry->friends){
    //     cout<<it->name<<"  "; 
    // } cout<<endl;
    // for(Node &it : ben->friends){
    //     cout<<it.name<<"  "; 
    // } cout<<endl;
    // for(Node &it : tom->friends){
    //     cout<<it.name<<"  "; 
    // } cout<<endl;
    // for(Node &it : stephen->friends){
    //     cout<<it.name<<"  "; 
    // } cout<<endl;
    // cout<<"\n\n"; 
    string target = "Stephen"; 
    
    vector<string> ans = {gordon->name}; 
    vector<string> ans2 = solution(gordon, target);  
    for(string &it : ans2){
        ans.push_back(it); 
    }
    int pathsize = ans.size(); 
  
    cout<<"\n\nPath"<<endl; 
    for(int i = 0; i < pathsize; i++){
        cout<<ans[i]; 
        if(i < pathsize-1) cout<<"->"; 
    }
    cout<<endl; 
}
