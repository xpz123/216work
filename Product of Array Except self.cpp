//Product of Array Except self
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int front = 1;
		int rear = 1;
		vector<int> res(nums.size(), 1);
		for (int i = 0; i < nums.size(); i++){
			res[i] *= front;
			front *= nums[i];
			res[nums.size() - i - 1] *= rear;
			rear *= nums[nums.size() - i - 1];
		}
		return res;
	}
};