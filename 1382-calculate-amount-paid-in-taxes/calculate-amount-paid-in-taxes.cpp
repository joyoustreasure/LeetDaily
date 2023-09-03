#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 세금을 계산하는 함수
    double calculateTax(vector<vector<int>>& brackets, int income) 
    {    
        double tax = 0; 
        
        // 첫 번째 세율 구간 처리
        if(brackets[0][0] <= income) 
            tax = (brackets[0][0] * brackets[0][1] / 100.0);         
        else 
            return (income * brackets[0][1] / 100.0);
            
        // 나머지 세율 구간 처리
        for(int i = 1; i < brackets.size(); i++)
        {
            if(brackets[i][0] <= income)
                tax += ((brackets[i][0] - brackets[i-1][0]) * brackets[i][1] / 100.0);
            else 
            {
                tax += ((income - brackets[i-1][0]) * brackets[i][1] / 100.0);
                break;
            }
        }
        
        return tax;
    }
};

// int main() {
//     Solution solution;
//     vector<vector<int>> brackets;
//     int numBrackets, income;

//     cout << "세율 구간의 수를 입력하세요: ";
//     cin >> numBrackets;

//     cout << "세율 구간을 입력하세요 (예: 5000 10 은 5000까지 10%의 세금):\n";
//     for(int i = 0; i < numBrackets; i++) {
//         int limit, rate;
//         cin >> limit >> rate;
//         brackets.push_back({limit, rate});
//     }

//     cout << "소득을 입력하세요: ";
//     cin >> income;

//     double tax = solution.calculateTax(brackets, income);
//     cout << "세금은 " << tax << " 입니다." << endl;

//     return 0;
// }
