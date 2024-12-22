#include<bits/stdc++.h>
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
void bfs(Node* &profile, string &target, vector<string> &ds, map<string, int> &visited){
    queue<Node*> qu; 
    qu.push(profile); 
    map<string, string> mp; // to remember the path :)
    mp[profile->name] = ""; 
    visited[profile->name] = 1; 
    while(!qu.empty()){
        Node* cur = qu.front(); 
        cout<<"\nVisiting Names in BFS order : "<<cur->name; 
        qu.pop(); 
        if(cur->name == target){
            string temp = target; 
            ds.push_back(target); 
            while(temp != ""){
                ds.push_back(mp[temp]); 
                temp = mp[temp]; 
            }
            return; 
        }
        for(Node* &i : cur->friends){
            if(visited[i->name] == 0){
                qu.push(i); 
                mp[i->name] = cur->name; 
            }
            visited[i->name] = 1; 
        }
    }
    return; 
}
vector<string> solution(Node* &gordon, string target){
    vector<string> ds; 
    map<string, int> visited; 
    bfs(gordon, target, ds, visited); 
    return ds; 
}
int main(void){
    Node* gordon = new Node("Gordon", 18); 
    Node* sam = new Node("Sam", 18);
    Node* harry = new Node("Harry", 18);
    Node* tom = new Node("Tom", 18);
    Node* stephen = new Node("Stephen", 18);

    gordon->friends.push_back(sam); 
    gordon->friends.push_back(harry); 
    harry->friends.push_back(tom); 
    sam->friends.push_back(gordon); 
    tom->friends.push_back(harry); 
    harry->friends.push_back(gordon); 
    tom->friends.push_back(stephen); 
    stephen->friends.push_back(tom); 

    string target = "Stephen"; 
    
    vector<string> ans = solution(gordon, target); 
    ans.pop_back(); // because the empty string also getting added in path, so remove it as well as possible! 
    reverse(ans.begin(), ans.end()); 
    int pathsize = ans.size(); 
    // cout<<pathsize<<endl; 
    cout<<"\n\nPath"<<endl; 
    for(int i = 0; i < pathsize; i++){
        cout<<ans[i]; 
        if(i < pathsize-1) cout<<"->"; 
    }
    cout<<endl; 
}
