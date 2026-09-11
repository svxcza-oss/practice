/*
 1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ... -> 1~5 반복 --> 5번 간격
 2번 수포자가 찍는 방식: 2, 1, / 2, 3, / 2, 4, /2, 5, -> 2고정하고 1->5 반복 --> 8번 간격
 3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, -> 3고정하고 1부터 반복 --> 일단 2번씩 반복하면 무조건 3번은 그냥 중복 2개만 있으면 됨 아 뭔말인지 알겠어그러면 반복되는 텀
 --> 10번 간격
 
 시험은 최대 10,000 문제로 구성되어있습니다.
 문제의 정답은 1, 2, 3, 4, 5중 하나입니다.
 가장 높은 점수를 받은 사람이 여럿일 경우, return하는 값을 오름차순 정렬해주세요.
 
 answers    return
 [1,2,3,4,5]    [1]
 [1,3,2,4,2]    [1,2,3]
 
 답은 최대 10,000 만번을 받음....
 이건 어떻게 푸나...
 
 그러면은 이게 최대 10개씩 반복이 되니까...
 그러면 하나씩 검사하면 되는거니까.... 음 이걸 어떻게 하면 좋을까...... 일단 한번에 정답지를 받아
 사이즈를 재
 그다음에 음 그 일단 아니야 정해져 있는거잖아 학생들이 찍은 방법들은 그러면.....
 
 
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> solution(vector<int> answers) {
    
    vector<vector<int>> student = {
        {1,2,3,4,5},
        {2,1,2,3,2,4,2,5},
        {3,3,1,1,2,2,4,4,5,5}
    };
    
    vector<int> scores(3,0);
    
    for(int i = 0; i<answers.size(); i++){
        for(int j = 0; j<3; j++){
            int student_len = student[j].size(); // 라인별 열 사이즈 타겟팅
            
            if(answers[i] == student[j][i%student_len]){ // 그리고 해당 열에 가서 학생들 답과 비교. 
                scores[j]++;
            }
            
            //ex) answers = [1,2,3,4,5]라면, j = 0, i%student_len == 0 j = 1  --> 행으로 비교. 세로로 비교. 
        }
    }
    
    vector<int> res;
    int max_res = max({scores[0], scores[1], scores[2]});
    for(int i = 0; i<3; i++){
        if(scores[i] == max_res) res.push_back(i+1); // 이건 학생번호를 집어 넣는것. 출력에는 몇점인지가 중요하지 않음
    }
    
    return res;
}
