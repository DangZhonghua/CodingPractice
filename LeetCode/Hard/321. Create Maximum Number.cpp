#include<vector>
#include<stack>
#include<iostream>
using namespace std;



class Solution
{
public:
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k)
	{
		vector<int> vselect1;
		vector<int> vselect2;
		vector<int> vr;

		int N1 = nums1.size();
		int N2 = nums2.size();


		for (int s = 0; s <= N1 && s <= k; ++s)
		{
			vselect1.clear();
			vselect2.clear();

			if ((k - s) <= N2)
			{
				SelectMaximumNumber(nums1, vselect1, s);
				SelectMaximumNumber(nums2, vselect2, k - s);
				vector<int> vc;
				CombineMaximumNumber(vselect1, vselect2, vc);
				AcquireMaxinumNumber(vc, vr);
				for (auto e : vr)
				{
					cout << e << " ";
				}
				cout << endl;
			}
		}

		for (auto e : vr)
		{
			cout << e << " ";
		}
		cout << endl;

		return vr;
	}

private:

	void SelectMaximumNumber(vector<int> & nums, vector<int> & vselect, int k)
	{
		int N = nums.size();
		int nDrop = N - k;

		for (int i = 0; i < N; ++i)
		{
			while (!vselect.empty() && nDrop > 0)
			{
				if (vselect.back() < nums[i])
				{
					vselect.pop_back();
					--nDrop;
				}
				else
				{
					break;
				}
			}
			vselect.push_back(nums[i]);
		}
		
		while (!vselect.empty() && nDrop > 0)
		{
			vselect.pop_back();
			--nDrop;
		}

		return;
	}

	void CombineMaximumNumber(vector<int> & vselect1, vector<int> & vselect2, vector<int> & vc)
	{
		int i = 0;
		int j = 0;
		int si = 0;
		int sj = 0;

		while (i < vselect1.size() && j < vselect2.size())
		{
			if (vselect1[i] == vselect2[j])
			{
				++i;
				++j;
			}
			else if (vselect1[i] > vselect2[j])
			{
				for (; si <= i; ++si)
				{
					vc.push_back(vselect1[si]);
				}
				++i;
			}
			else
			{
				for (; sj <= j; ++sj)
				{
					vc.push_back(vselect2[sj]);
				}
				++j;
			}
		}

		while (si < vselect1.size())
		{
			vc.push_back(vselect1[si++]);
		}
		while (sj < vselect2.size())
		{
			vc.push_back(vselect2[sj++]);
		}
	}

	void AcquireMaxinumNumber(vector<int> & vc, vector<int> & vr)
	{
		if (LargerThan(vc, vr))
		{
			vr = vc;
		}
	}
	bool LargerThan(vector<int>& vc, vector<int>& vr)
	{
		return vc > vr;
	}
};
