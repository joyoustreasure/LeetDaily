#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int n = sentences.size();
        int counter, ans = 0;
        // 모든 문장에 대해 반복
        for(int i = 0; i < n; i++) {
            int k = sentences[i].length();
            counter = 1;  // 단어의 개수를 세는 카운터. 하나의 문장에는 최소한 하나의 단어가 있으므로 시작값을 1로 설정
            // 각 문장의 모든 문자를 순회
            for(int j = 0; j < k; j++) {
                // 공백 문자를 발견하면 단어 카운터를 증가
                if(sentences[i][j] == ' ') {
                    counter++;
                }
            }
            // 현재 문장의 단어 개수와 이전까지의 최대 단어 개수를 비교하여 최대값 업데이트
            ans = (counter > ans) ? counter : ans;
        }
        return ans;
    }
};

// int main() {
//     Solution sol;
//     int n;
//     vector<string> sentences;

//     cout << "문장의 개수를 입력하세요: ";
//     cin >> n;
//     cin.ignore();  // 버퍼에서 남아 있는 개행 문자를 제거

//     cout << "문장들을 입력하세요:" << endl;
//     for(int i = 0; i < n; i++) {
//         string sentence;
//         getline(cin, sentence);  // 한 줄 전체를 입력받음
//         sentences.push_back(sentence);
//     }

//     int result = sol.mostWordsFound(sentences);
//     cout << "가장 많은 단어를 가진 문장의 단어 개수: " << result << endl;

//     return 0;
// }
