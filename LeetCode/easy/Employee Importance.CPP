/*
https://leetcode-cn.com/problems/employee-importance/

给定一个保存员工信息的数据结构，它包含了员工唯一的id，重要度 和 直系下属的id。
比如，员工1是员工2的领导，员工2是员工3的领导。他们相应的重要度为15, 10, 5。那么员工1的数据结构是[1, 15, [2]]，
员工2的数据结构是[2, 10, [3]]，员工3的数据结构是[3, 5, []]。
注意虽然员工3也是员工1的一个下属，但是由于并不是直系下属，因此没有体现在员工1的数据结构中。
现在输入一个公司的所有员工信息，以及单个员工id，返回这个员工和他所有下属的重要度之和。
示例 1:
输入: [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
输出: 11
解释:
员工1自身的重要度是5，他有两个直系下属2和3，而且2和3的重要度均为3。因此员工1的总重要度是 5 + 3 + 3 = 11。
注意:
一个员工最多有一个直系领导，但是可以有多个直系下属
员工数量不超过2000。

*/

/*
// Employee info
class Employee {
public:
	// It's the unique ID of each node.
	// unique id of this employee
	int id;
	// the importance value of this employee
	int importance;
	// the id of direct subordinates
	vector<int> subordinates;
};
*/


#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;


class Employee
{
public:
	// It's the unique ID of each node.
	// unique id of this employee
	int id;
	// the importance value of this employee
	int importance;
	// the id of direct subordinates
	vector<int> subordinates;
};

class Solution
{

	struct dfsElement
	{
		int m_Index{ 0 };
		int m_Sum{ 0 };
		int m_Start{ 0 };
		int m_Parent{ -1 };
	};

public:
	int getImportance(vector<Employee *> employees, int id)
	{
		stack<dfsElement> dfsStack;
		unordered_map<int, int> mapID2Important;
		unordered_map<int, Employee*> mapID2Employee;
		
		for (int i = 0; i < employees.size(); ++i)
		{
			mapID2Employee[employees[i]->id] = employees[i];
		}

		dfsElement vStart;
		vStart.m_Index = id;
		vStart.m_Sum = mapID2Employee[id]->importance;
		vStart.m_Start = 0;
		mapID2Important.insert(std::make_pair(id, mapID2Employee[id]->importance));
		dfsStack.push(vStart);

		while (!dfsStack.empty())
		{
			dfsElement& tp = dfsStack.top();
			if (tp.m_Start >= mapID2Employee[tp.m_Index]->subordinates.size())
			{
				if (-1 != tp.m_Parent)
				{
					auto it = mapID2Important.find(tp.m_Parent);
					if (it != mapID2Important.end())
					{
						it->second += mapID2Important[tp.m_Index];
					}
					else
					{
						cout << "Error!" << endl;
					}
				}

				dfsStack.pop();
			}
			else
			{
				dfsElement vNext;
				vNext.m_Parent = tp.m_Index;
				vNext.m_Index  = mapID2Employee[tp.m_Index]->subordinates[tp.m_Start];
				vNext.m_Start  = 0;
				vNext.m_Sum    = mapID2Employee[vNext.m_Index]->importance;
				mapID2Important[vNext.m_Index] = vNext.m_Sum;
				++tp.m_Start;
				dfsStack.push(vNext);
			}
		}

		return mapID2Important[id];
	}
};

int main()
{
	Solution sol;
	vector<Employee *> employees;
	Employee* e1 = new Employee;
	e1->id = 1;
	e1->importance = 5;
	e1->subordinates.push_back(2);
	e1->subordinates.push_back(3);


	Employee* e2 = new Employee;
	e2->id = 2;
	e2->importance = 3;

	Employee* e3 = new Employee;
	e3->id = 3;
	e3->importance = 3;

	employees.push_back(e1);
	employees.push_back(e2);
	employees.push_back(e3);

	
	cout << sol.getImportance(employees, 1) << endl;

	
	return 0;
	
}

[[1,5,[2,3]],[2,3,[4]],[3,4,[]],[4,1,[]]]
1

5 + 3 + 1 + 4