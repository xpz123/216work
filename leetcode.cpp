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


//Maximum Product Subarray
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int lmax = nums[0];
		int lmin = nums[0];
		int tmax = lmax;
		int tmin = lmin;
		int gmax = nums[0];
		for (int i = 1; i < nums.size(); i++){
			lmax = max(max(tmax * nums[i], nums[i]), tmin * nums[i]);
			lmin = min(min(tmin * nums[i], nums[i]), tmax * nums[i]);
			tmax = lmax;
			tmin = lmin;
			gmax = max(lmax, gmax);
		}
		return gmax;
	}
};

//Construct Binary Tree from Preorder and Inorder Traversal
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};
class Solution{
public:
	TreeNode *buildTree(vector<int>& preorder, vector<int>& inorder){
		if (inorder.size() == 0) return NULL;
		int countp = 1;
		int counti = 0;
		stack<TreeNode *> s;
		TreeNode *root;
		TreeNode *tmp;
		root = new TreeNode(preorder[0]);
		s.push(root);
		while (true){
			if (inorder[counti] == s.top()->val){
				auto t = s.top();
				counti++;
				s.pop();
				if (counti == inorder.size()) break;
				if (s.size() && s.top()->val == inorder[counti]) continue;
				tmp = new TreeNode(preorder[countp]);
				t->right = tmp;
				s.push(tmp);
				countp++;
			}
			else{
				tmp = new TreeNode(preorder[countp]);
				s.top()->left = tmp;
				s.push(tmp);
				countp++;
			}
		}
		return root;
	}
};

//Jump Game
class Solution {
public:
	bool canJump(vector<int>& nums) {
		if (nums.size() == 0) return false;
		if (nums.size() == 1) return true;
		if (findjump(nums, 0)) return true;
		else return false;
	}
private:
	int findmax(vector<int>& nums, int pos){
		int max = nums[pos];
		int res = pos;
		for (int i = 1; i <= nums[pos]; i++){
			if (max <= (i + nums[pos + i])){
				max = nums[pos + i] + i;
				res = pos + i;
			}
		}
		return res;
	}
	bool findjump(vector<int>& nums, int pos){
		if (nums[pos] == 0) return false;
		if ((nums[pos] + pos) >= (nums.size() - 1)) return true;
		int tmp = findmax(nums, pos);
		if (findjump(nums, tmp)) return true;
		else return false;
	}
};
bool canJump(vector<int>& nums) {
	int size = nums.size();
	int step = nums[0];
	for (int i = 1; i<size; ++i){
		step--;
		if (step<0)
			return false;
		if (nums[i]>step)
			step = nums[i];
	}
	return true;
}

//Word Search(unfinished)
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		//unordered_map<pair<int, int>, int> used;
		
		bool res = false;
		if (word.size() == 0) return false;
		for (int i = 0; i < board.size(); i++){
			for (int j = 0; j < board[0].size(); j++){
				if (res == true) return res;
				if (word[0] == board[i][j]) findword(i, j, 1);
			}
		}
		return res;
	}
private:
	bool findword(int i, int j, int pos){
		if (i == 0){
			if (j == 0){
				return true;
			}
		}
	}
};

//Subsets
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int c = pow(2, nums.size());
		sort(nums.begin(), nums.end());
		vector<int> tmp;
		vector<vector<int> > res(c, tmp);
		for (int i = 1; i < c; i++){
			for (int j = 0; j < nums.size(); j++){
				if ((i >> j) & 1)
					res[i].push_back(nums[j]);
			}
		}
		return res;
	}
};

//Subsets II
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int> > res;
		vector<int> a;
		res.push_back(a);
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size();){
			int count = 0;
			while (count + i < nums.size() && nums[count + i] == nums[i]) count++;
			int ori_size = res.size();
			for (int j = 0; j < ori_size; j++){
				auto tmp = res[j];
				for (int k = 0; k < count; k++){
					tmp.push_back(nums[i]);
					res.push_back(tmp);
				}
			}
			i += count;
		}
		return res;
	}
};

//sort colors(==0 必须放在下边因为是从头开始进行判断的，因此《i的项中，不会存在==2的）
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int l = 0, r = nums.size() - 1;
		for (int i = 0; i <= r; i++){

			while (nums[i] == 2 && i < r) swap(nums[i], nums[r--]);
			while (nums[i] == 0 && i > l){
				swap(nums[i], nums[l++]);
			}
		}
	}
};

//Container with most water
class Solution {
public:
	int maxArea(vector<int>& height) {
		int res = 0;
		int i = 0, j = height.size() - 1;
		int hi = height[i], hj = height[j];
		while (i < j){
			int h = min(hei);
			res = max(res, min(height[i], height[j]) * (j - i));
			while (height[i] <= h && i < j) i++;
			while (height[j] <= h && i < j) j++;
		}
		return max;
	}
};

//Trapping rain water
class Solution {
public:
	int trap(vector<int>& height) {
		if (height.size() == 0) return 0;
		int max = 0, index = 0;
		for (int i = 0; i < height.size(); i++){
			if (max <= height[i]){
				max = height[i];
				index = i;
			}
		}
		max = 0;
		int res = 0;
		for (int i = 0; i <= index; i++){
			if (max <= height[i]) max = height[i];
			else{
				res += (max - height[i]);
			}
		}
		max = 0;
		for (int i = height.size() - 1; i >= index; i--){
			if (max <= height[i]) max = height[i];
			else res += (max - height[i]);
		}
		return res;
	}
};