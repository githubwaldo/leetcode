/*************************************************************************
	> File Name: AddTwoNumbers.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年11月25日 星期三 17时09分41秒
 ************************************************************************/

#include<iostream>
#include <vector>
#include <utility>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(NULL){}
};

class Solution
{
public:
    Solution() : List1(NULL), List2(NULL){}

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {

    }

    void vectorToList(vector<int>& obj1, vector<int>& obj2)
    {
        ListNode *temp;

        while (obj1.size() != 0)
        {
            if (List1 == NULL)
            {
                temp = new ListNode(obj1[obj1.size()-1]);
                obj1.pop_back();
                this->List1 = temp;
            }
            else
            {
                temp->next = new ListNode(obj1[obj1.size()-1]);
                obj1.pop_back();
                temp = temp->next;
            }
        }

        while (obj2.size() != 0)
        {
            if (List2 == NULL)
            {
                temp = new ListNode(obj2[obj2.size()-1]);
                obj2.pop_back();
                this->List2 = temp;
            }
            else
            {
                temp->next = new ListNode(obj2[obj2.size()-1]);
                obj2.pop_back();
                temp = temp->next;
            }
        }
    }

    pair<ListNode*,ListNode*> getListHead()
    {
        pair<ListNode*,ListNode*> result;

        result = make_pair(List1,List2);
        return result;
    }
private:
    ListNode *List1,*List2;
};

void visitList(ListNode* obj)
{
    cout << "the list is : ";
 
    while(obj != NULL)
    {
        cout << obj->val << " ";
        obj = obj->next;
    }
    cout << endl;
}

void visitVector(vector<int>& vec)
{
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    char c;
    int temp;
    vector<int> List1,List2;
    Solution solution;
    pair<ListNode*,ListNode*> result;

    cout << "please input List1 : ";
    while(cin.get() != '\n')
    {
        cin.unget();
        cin >> temp;
        List1.push_back(temp);
    }

    cout << "please input List2 : ";
    while(cin.get() != '\n')
    {
        cin.unget();
        cin >> temp;
        List2.push_back(temp);
    }

    solution.vectorToList(List1,List2);
    result = solution.getListHead();

    visitList(result.first);
    visitList(result.second);
//    visitVector(List1);
//    visitVector(List2);

    return 0;
}
