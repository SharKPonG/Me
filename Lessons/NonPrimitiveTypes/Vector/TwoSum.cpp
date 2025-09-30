#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
   vector<int> twoSum(vector<int> &nums, int target){
        for(int i = 0; i < nums.size() ; i++){
            // index x 
            int x = nums[i];
            for (int j = 0; j < nums.size(); j++){
                if(nums[i]+ nums[j] == target){
                    // index y
                    int y = nums[j];

                    if (i != j && x + y == target){
                        return {i,j};
                    }
                }                    
            }
        }
        return {};
    }
};


int main(){
    Solution s;
    int n;
    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; i++){
        cin >> input[i];
    }
    int target;
    cin >> target;
    vector<int> result = s.twoSum(input, target);
    for (int i = 0; i < result.size(); i++){
        cout << result[i] << endl;
    }
    return 0;
}
//Index 0 1 2 3 4 
//      2, 7 , 11 15
// x    
// 7 

// 1 loop i
// 2 loop j

// # loop Check i j for check sum index = target