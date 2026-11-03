#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    int len = arr.size();
    vector<int> res;
        
    for(int i = 0; i<len; i++){
        int cur = arr[i];
        if(i == 0 || arr[i] != arr[i-1] ) res.push_back(arr[i]);
    }
    
    return res;
}