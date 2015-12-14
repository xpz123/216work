//Remove duplicate num in sorted array II
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int count = 1;
		int s = 0;
		for (int i = 1; i < nums.size(); i++){
			if (nums[i] != nums[i - 1]){
				nums[count] = nums[i];
				count++;
				s = 0;
			}
			else if (s < 1){
				nums[count] = nums[i];
				count++;
				s++;
			}
		}
		return count;
	}
};