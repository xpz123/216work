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

//Missing num

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int result = nums.size();
		int i = 0;

		for (int num : nums){
			result ^= num;
			result ^= i;
			i++;
		}

		return result;
	}
};

//Minimum Path Sum
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		vector<int> tmp(grid[0].size(), 0);
		vector<vector<int>> res(grid.size(), tmp);
		if (grid.size() == 0) return 0;
		res[0][0] = grid[0][0];
		for (int i = 1; i < grid[0].size(); i++){
			res[0][i] = grid[0][i] + res[0][i - 1];
		}
		for (int i = 1; i < grid.size(); i++){
			res[i][0] = grid[i][0] + res[i - 1][0];
		}
		for (int i = 1; i < grid.size(); i++)
			for (int j = 1; j < grid[0].size(); j++){
				//res[i][j] = grid[i][j] + (res[i - 1][j] < res[i][j - 1]) ? res[i - 1][j] : res[i][j - 1];
				if (res[i - 1][j] < res[i][j - 1]){
					res[i][j] = grid[i][j] + res[i - 1][j];
				}
				else res[i][j] = grid[i][j] + res[i][j - 1];
			}
		return res[grid.size() - 1][grid[0].size() - 1];
	}
};

//Two sum
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> tmp;
		vector<int> res(2, 0);
		for (int i = 0; i < nums.size(); i++){
			int numfind = target - nums[i];
			if (tmp.find(numfind) != tmp.end()){
				res[0] = tmp[numfind] + 1;
				res[1] = i + 1;
				return res;
			}
			tmp[nums[i]] = i;
		}

	}
};

//Construct Binary Tree from Inorder and Postorder Traversal
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.size() == 0) return NULL;
		TreeNode *tmp;
		TreeNode *root;
		stack<TreeNode *> a;
		root = new TreeNode(postorder.back());
		a.push(root);
		postorder.pop_back();
		while (true){
			if (a.top()->val == inorder.back()){
				inorder.pop_back();
				tmp = a.top();
				a.pop();
				if (inorder.size() == 0) break;
				if (a.size() && inorder.back() == a.top()->val)
					continue;
				tmp->left = new TreeNode(postorder.back());
				postorder.pop_back();
				a.push(tmp->left);

			}
			else{
				tmp = new TreeNode(postorder.back());
				postorder.pop_back();
				a.top()->right = tmp;
				a.push(tmp);
			}
		}
	}
};

// Maximum Subarray
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int sum = nums[0];
		int res = sum;
		for (int i = 1; i < nums.size(); i++){
			if (sum <= 0) sum = nums[i];
			else{
				sum += nums[i];
			}
			if (res < sum) res = sum;
		}
		return res;
	}
};

//Triangle
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		vector<vector<int>> res;
		res = triangle;
		for (int i = 1; i < triangle.size(); i++){
			for (int j = 0; j <= i; j++){
				if (j == 0) res[i][j] = res[i - 1][j] + triangle[i][j];
				else if (j == i) res[i][j] = res[i - 1][j - 1] + triangle[i][j];
				else res[i][j] = min(res[i - 1][j - 1] + triangle[i][j], res[i - 1][j] + triangle[i][j]);
			}
		}
		int minnum = (*(res.end() - 1))[0];
		for (int i = 0; i < res.size(); i++){
			if ((*(res.end() - 1))[i] < minnum) minnum = (*(res.end() - 1))[i];
		}
		return minnum;
	}
};

int minimumTotal(vector<vector<int> > &triangle) {
	int n = triangle.size();
	vector<int> minlen(triangle.back());
	for (int layer = n - 2; layer >= 0; layer--) // For each layer
	{
		for (int i = 0; i <= layer; i++) // Check its every 'node'
		{
			// Find the lesser of its two children, and sum the current value in the triangle with it.
			minlen[i] = min(minlen[i], minlen[i + 1]) + triangle[layer][i];
		}
	}
	return minlen[0];
}


