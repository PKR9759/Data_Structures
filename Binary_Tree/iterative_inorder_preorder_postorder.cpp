#include <iostream>
#include <stack>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<int> preorderTraversal(TreeNode* root) {
    std::vector<int> result;
    std::stack<TreeNode*> stack;
    TreeNode* current = root;

    while (current != nullptr || !stack.empty()) {
        while (current != nullptr) {
            result.push_back(current->val); // Process current node
            stack.push(current);
            current = current->left; // Move to left subtree
        }

        // Move to the right subtree or backtrack
        current = stack.top();
        stack.pop();
        current = current->right;
    }

    return result;
}






std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> result;
    std::stack<TreeNode*> stack;
    TreeNode* current = root;

    while (current != nullptr || !stack.empty()) {
        while (current != nullptr) {
            stack.push(current);
            current = current->left; // Move to left subtree
        }

        // Process current node
        current = stack.top();
        stack.pop();
        result.push_back(current->val);

        // Move to the right subtree
        current = current->right;
    }

    return result;
}












std::vector<int> postorderTraversal(TreeNode* root) {
    std::vector<int> result;
    std::stack<TreeNode*> stack;
    TreeNode* current = root;
    TreeNode* lastVisited = nullptr;

    while (current != nullptr || !stack.empty()) {
        while (current != nullptr) {
            stack.push(current);
            current = current->left; // Move to left subtree
        }

        current = stack.top();

        // If the right subtree is not processed yet
        if (current->right != nullptr && current->right != lastVisited) {
            current = current->right; // Move to right subtree
        } else {
            // Process current node
            result.push_back(current->val);
            stack.pop();
            lastVisited = current;
            current = nullptr; // To backtrack to the parent node
        }
    }

    return result;
}
