
//////////////////////////////////////////////////////////////////////////
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "[]";

        string ser = "[";

        queue<TreeNode*> que;
        que.push(root);

        int cntNull = 0;
        while (!que.empty()) {
            auto q = que.front();
            que.pop();

            if (q == nullptr) {
                cntNull++;
            }
            else {
                for (; cntNull > 0; cntNull--) {
                    ser += "null,";
                }
                ser += to_string(q->val);
                ser += ",";

                que.push(q->left);
                que.push(q->right);
            }
        }

        while (ser.back() == 'n' || ser.back() == 'u' || ser.back() == 'l' || ser.back() == ',') {
            ser.pop_back();
        }
        ser += "]";

        //cout << ser << endl;
        return ser;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() < 2) return nullptr;
        if (data.front() != '[' && data.back() != ']') return nullptr;
        if (data == "[]") return nullptr;

        data = data.substr(1, data.size() - 2);
        //data.erase(remove_if(data.begin(), data.end(), isspace), data.end());
        for (auto& c : data) {
            c = (c == ',') ? ' ' : c;
        }
        //cout << data << endl;

        stringstream ss(data);
        string temp;
        ss >> temp;
        TreeNode* head = new TreeNode(stoi(temp));

        queue<TreeNode*> que;
        que.push(head);

        while (!que.empty()) {
            for (size_t i = que.size(); i > 0; i--) {
                auto q = que.front();
                que.pop();
                //cout << "q = " << q->val << endl;

                if (ss >> temp) {
                    //cout << "left -> " << temp << endl;
                    if (temp != "null") {
                        q->left = new TreeNode(stoi(temp));
                        que.push(q->left);
                    }
                }
                if (ss >> temp) {
                    //cout << "right -> " << temp << endl;
                    if (temp != "null") {
                        q->right = new TreeNode(stoi(temp));
                        que.push(q->right);
                    }
                }
            }
        }


        return head;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

//////////////////////////////////////////////////////////////////////////
//string _solution_run(TreeNode* root)
//{
//	return serialize(root);
//}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases& tc)
{
    TreeNode* root = tc.get<TreeNode*>();
    Codec codec;
    string ans = codec.serialize(root);
    cout << "serialize -> " << ans << endl;
    TreeNode* root2 = codec.deserialize(ans);
    ans = TreeNodeToString(root2);
    cout << "deserialize -> " << ans << endl;
    return ans;
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

