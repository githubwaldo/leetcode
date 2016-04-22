/*************************************************************************
	> File Name: TwoSum.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月24日 星期二 17时03分07秒
 ************************************************************************/

#include<iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> TwoSum(vector<int> &nums, int target)
    {
        map<int,int> mapping;
        vector<int> result;

        mapping.clear();
        result.clear();

        /*用一个哈希表，存储每一个数对应的下标*/
        for (int i = 0; i < nums.size(); i++)
        {
            mapping[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            const int gap = target - nums[i];

            if (mapping.find(gap) != mapping.end())
            {
                result.push_back(i+1);
                result.push_back(mapping[gap] + 1);
                break;
            }
        }
        
        return result;
    }
};

void testInput(vector<int> &nums)
{
    cout << "the input is : ";
    for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;
}

int main(int argc, char **argv)
{
    int target = 0;
    int temp;
    char c;
    vector<int> nums;
    vector<int> result;
    Solution solution;

    cout << "please input a array : ";
    while((c=cin.get()) != '\n')
    {
        cin.unget();
        cin >> temp;
        nums.push_back(temp);   
    }

    cout << "please input target : ";
    cin >> target;

    result = solution.TwoSum(nums,target);
    cout << "the index1 is ; " << result[0] << "\nthe index2 is ; " << result[1] << endl;
//    cout << "the index2 is : " << result.pop_back() << endl;

//    testInput(nums);

    return 0;
}


