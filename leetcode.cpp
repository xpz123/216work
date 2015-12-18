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

//Combination sum II
class Solution {
public:
	vector<vector<int>> res;
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<int> tmp;
		com(candidates, target, 0, tmp);


		return res;
	}
private:
	void com(vector<int> c, int target, int j, vector<int> &tmp){
		if (target == 0){
			res.push_back(tmp);
		}
		else{
			for (int i = j; i < c.size() && c[i] <= target; i++){
				if (i == c.size() - 1 && target != c[i]) return;
				if (i && i > j && c[i] == c[i - 1]) continue;
				tmp.push_back(c[i]);
				com(c, target - c[i], i + 1, tmp);
				tmp.pop_back();

			}
		}
	}
};

//Combination Sum III
class Solution {
public:
	vector<vector<int>> res;
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<int> tmp;
		com(k, n, 1, tmp);
		return res;
	}
private:
	void com(int k, int target, int j, vector<int> &tmp){
		if (k == 0 && target == 0){
			res.push_back(tmp);
			return;
		}
		else{
			for (int i = j; i <= 9 && k > 0 && target >= i; i++){
				tmp.push_back(i);
				com(k - 1, target - i, i + 1, tmp);
				tmp.pop_back();
			}
		}
	}
};