/*
  Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/

TreeNode *build(const vector<int>& nums, int start, int end)
{
	int mid = start + (end + 1 - start) / 2;
	TreeNode *root = new TreeNode(nums[mid]);
	if(start <= mid - 1)
		root->left = build(nums, start, mid - 1);
	if(mid + 1 <= end)
		root->right = build(nums, mid + 1, end);
	return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty())
		return NULL;

	return build(nums, 0, nums.size() - 1);
}
