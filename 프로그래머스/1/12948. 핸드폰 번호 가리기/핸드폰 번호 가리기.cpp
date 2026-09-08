#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int len = phone_number.length();
    
    for(char c : phone_number){
        
        len--;
        if (len >= 4) answer += "*";
        else answer += c;
    }
    return answer;
}
