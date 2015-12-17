//combination sum

class Solution {
public:
	vector<vector<int>> res;
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<int> tmp;
		com(candidates, target, 0, tmp);
		return res;
	}
private:
	void com(vector<int> c, int target, int i, vector<int> &tmp){
		if (target == 0){
			res.push_back(tmp);
		}
		else{
			for (int j = i; j < c.size() && target >= c[j]; j++){
				tmp.push_back(c[j]);
				com(c, target - c[j], j, tmp);
				tmp.pop_back();
			}
		}
	}
};