#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector <string> see(n);
    vector <string> hear(m);
    vector <string> res;
    
    
    for(int i = 0; i<n; i++) cin >> see[i];
    sort(see.begin(), see.end());
    for(int i = 0; i<m; i++) cin >> hear[i];
    sort(hear.begin(), hear.end());
    
    int i = 0; int j = 0;
    while(i < n && j < m){ //명단에 있는 이름을 한쪽이라도 다 훑었으면 끝
        if(see[i] == hear[j]){
            res.push_back(see[i]);
            i++; j++;
        }
        else if(see[i] < hear[j]) i++;
        else
            j++;
    }
    
    cout << res.size() << "\n";
    for(const string& name : res) cout << name << "\n";
    /*
     for(int i = 0; i<res.size(); i++) cout << res[i] << "\n";
     */
    
    return 0;
}

