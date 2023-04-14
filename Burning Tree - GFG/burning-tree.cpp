//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    Node* createMapping(Node* root, int target,map<Node*,Node*>&par)
    {
        Node *res=NULL;
        
        queue<Node*>q;
        q.push(root);
        par[root]=NULL;
        while(!q.empty())
        {
            Node* t =q.front();
            q.pop();
            if(t->data==target)
            {
                res=t;
            }
            if(t->left)
            {
                q.push(t->left);
                par[t->left]=t;
            }
            if(t->right)
            {
                q.push(t->right);
                par[t->right]=t;
            }
        }
        return res;
    }
    int burnTree(Node *root,map<Node*,Node*>par)
    {
        map<Node*,bool>vis;
        queue<Node*>q;
        q.push(root);
        vis[root]=true;
        int ans=0;
        while(!q.empty())
        {
            int sz=q.size();
            bool flag=0;
            while(sz--)
            {
                Node *t=q.front();
                q.pop();
                if(t->left and !vis[t->left])
                {
                    q.push(t->left);
                    vis[t->left]=1;
                    flag=1;
                }
                if(t->right and !vis[t->right])
                {
                    q.push(t->right);
                    vis[t->right]=1;
                    flag=1;
                }
                if(par[t] and !vis[par[t]])
                {
                    q.push(par[t]);
                    vis[par[t]]=1;
                    flag=1;
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        int ans=0;
        map<Node*,Node*>par;
        Node* targetNode=createMapping(root,target,par);
        ans=burnTree(targetNode,par);
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends