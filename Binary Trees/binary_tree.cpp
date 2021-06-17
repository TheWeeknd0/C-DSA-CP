#include<bits/stdc++.h>
using namespace std;

#define endl '\n';
using namespace std;
class node {
public:
  int data;
  node* left;
  node* right;
  node(int d) {
    data = d;
    left = right = NULL;
  }
};

node* buildTree() {
  int data; cin >> data;
  if (data == -1)
    return NULL;
  node* root = new node(data);
  root->left = buildTree();
  root->right = buildTree();
  return root;
}

void preorderprint(node* root) {
  if (root == NULL)
    return;
  cout << root->data << ' ';
  preorderprint(root->left);
  preorderprint(root->right);
}

void inorderprint(node*root) {
  if (root == NULL)
    return;
  inorderprint(root->left);
  cout << root->data << ' ';
  inorderprint(root->right);
}

void postOrderPrint(node *root) {
  if (root == NULL)
    return;
  postOrderPrint(root->left);
  postOrderPrint(root->right);
  cout << root->data << ' ';
}

int heightoftree(node* root) {
  if (root == NULL)
    return 0;
  int RS = heightoftree(root->right);
  int LS = heightoftree(root->left);
  return max(RS, LS) + 1;
}

void verticalorderprint(node* root, int d, map<int, vector<int> >&m) {
  if (root == NULL)
    return;
  m[d].push_back(root->data);
  verticalorderprint(root->left, d - 1, m);
  verticalorderprint(root->right, d + 1, m);
  return;
}

void printkthlevel(node* root, int k) {
  if (root == NULL)
    return;
  if (k == 1) {
    cout << root->data << ' ';
    return;
  }
  printkthlevel(root->left, k - 1);
  printkthlevel(root->right, k - 1);
}

void levelorderprint(node* root) {
  int H = heightoftree(root);
  for (int i = 1; i <= H; i++)
    printkthlevel(root, i);
  return;
}

int diameter(node *root) {
  if (root == NULL)
    return 0;
  int h1 = heightoftree(root->left);
  int h2 = heightoftree(root->right);
  int op1 = h1 + h2;
  int op2 = diameter(root->left);
  int op3 = diameter(root->right);
  return max({op1, op2, op3});
}
pair<int, int> fastdiameter(node *root) {
  pair<int, int> p;
  if (root == NULL) {
    p.first = p.second = 0;
    return p;
  }
  //otherwise
  pair<int, int> left = fastdiameter(root->left);
  pair <int, int>right = fastdiameter(root->right);
  p.first = max(left.first, right.first) + 1; //.first= height and .second=diameter
  p.second = max({left.first + right.first, left.second, right.second});
  return p;
}

void bfs(node* root) {
  queue<node*>q;
  q.push(root);
  while (!q.empty()) {
    node* t = q.front();
    cout << t->data << ' ';
    q.pop();
    if (t->left) {
      q.push(t->left);
    }

    if (t->right) {
      q.push(t->right);
    }

  }
}
void bfs1_by_me(node* root) {
  queue< pair<node*, int> >q;
  q.push(make_pair(root, 1));
  int i = 0, j = 2, k = 1, p = 1;
  while (!q.empty()) {
    node* t = q.front().first;
    if (q.front().second > p) {
      cout << '\n';                  //insertion of pair and everything by me
      p++;
    }
    cout << t->data << ' ';
    i += 2;      //to check every two children per step....
    q.pop();
    if (i == j) {
      j *= 2;  // whenever the i reaches j (meaning we have reached the another level)...increment j by *2
      k++;     // becuase each new level can hold at max j*2 children ...
    }
    if (t->left) {
      q.push(make_pair(t->left, k));
    }
    if (t->right) {
      q.push(make_pair(t->right, k));
    }
  }
}

void bfs2(node* root) {
  queue<node*> q;
  q.push(root);
  q.push(NULL);
  while (!q.empty()) {
    node *f = q.front();
    if (f == NULL) {
      cout << '\n';
      q.pop();
      if (!q.empty()) // very imp to check if the queue is not empty
        q.push(NULL);
    }
    else {
      cout << f->data << ' ';
      q.pop();
      if (f->left) {
        q.push(f->left);
      }
      if (f->right) {
        q.push(f->right);
      }
    }
  }
}
int countnodes(node *root) {
  if (root == NULL)
    return 0;
  return 1 + countnodes(root->left) + countnodes(root->right);
}
int sumofnodes(node * root) {
  if (root == NULL)
    return 0;
  return root->data + sumofnodes(root->left) + sumofnodes(root->right);
}
int sumofchildnodes(node *root) {
  if (root == NULL)  //to handle when we go to the right of a particular node
    return 0;
  if (root->left == NULL and root->right == NULL)
    return root->data;
  int data1 = sumofchildnodes(root->left);
  int data2 = sumofchildnodes(root->right);
  int temp = root->data;
  root->data =  data1 + data2;
  return temp + root->data;
}


pair<int, bool> isheightbalance(node*root) {
  pair<int, bool> p;
  if (root == NULL) {
    p.first = 0;
    p.second = true;
    return p;
  }
  ///Recursive cases
  pair<int, bool> left = isheightbalance(root->left);
  pair<int, bool> right = isheightbalance(root->right);
  p.first = max(left.first, right.first) + 1;
  if (abs(left.first - right.first) <= 1 and left.second and right.second)
    p.second = true;
  else {
    p.second = false;
  }
  return p;
}

node* buildfromArray(int *a, int s, int e) {
  if (s > e)
    return NULL;
  int mid = (s + e) / 2;
  node* root = new node(a[mid]);
  root->left = buildfromArray(a, s, mid - 1);
  root->right = buildfromArray(a, mid + 1, e);
  return root;
}

node* createTreefromTrav(int *in, int* pre, int s, int e) {
  if (s > e)
    return NULL;
  static int i = 0;
  node *root = new node(pre[i]);
  int index = -1;
  for (int j = s; j <= e; j++) {
    if (in[j] == pre[i]) {
      index = j;
      break;
    }
  }
  i++;
  root->left = createTreefromTrav(in, pre, s, index - 1);
  root->right = createTreefromTrav(in, pre, index + 1, e);
  return root;
}

void rightview(node *root, int level) {
  static int max_level = 0;
  if (root == NULL)
    return;
  if (level > max_level) {
    cout << root->data << '\n';
    max_level = level;
  }
  rightview(root->right, level + 1);
  rightview(root->left, level + 1);
}

void printAtKDown(node*root, int k) {
  if (root == NULL)
    return;
  if (k == 0)
    cout << root->data << " ";
  printAtKDown(root->left, k - 1);
  printAtKDown(root->right, k - 1);
}

int printAtKDistance(node* root, int target, int k) {
  if (root == NULL)
    return -1;
  if (root->data == target) {
    printAtKDown(root, k);
    return 0;
  }
  int dl = printAtKDistance(root -> left, target, k);
  if (dl != -1) {
    if (k == dl + 1)
      cout << root->data << " ";
    else
      printAtKDown(root -> right, k - dl - 2);
    return dl + 1;
  }
  int dr = printAtKDistance(root -> right, target, k);
  if (dr != -1) {
    if (k == dr + 1)
      cout << root->data << " ";
    else
      printAtKDown(root -> left, k - dr - 2);
    return dr + 1;
  }
  return -1;
}

bool findpath(node*root, vector<int> &path, int k) {
  if (root == NULL)
    return false;
  path.push_back(root->data);
  if (root->data == k)
    return true;
  bool checkleft = findpath(root->left, path, k);
  bool checkright = findpath(root->right, path, k);
  if ((checkright) or (checkleft))
    return true;
  path.pop_back();
  return false;
}

int lca1(node* root, int a, int b) {
  vector<int> path1, path2;
  if (!findpath(root, path1, a) or !findpath(root, path2, b))
    return -1;
  int i;
  for (i = 0; i < path1.size() && i < path2.size() ; i++)
    if (path1[i] != path2[i])
      break;
  return path1[i - 1];
}


class custom {
public:
  bool q ;
  bool p ;
  node* LCAnode ;
};


custom* calcLCA(node* root, int p, int q) {
  if (root == NULL) {
    return NULL;
  }

  custom* ls = calcLCA(root->left, p, q);
  if (ls != NULL && ls->LCAnode != NULL) {
    return ls;
  }

  custom* rs = calcLCA(root->right, p, q);
  if (rs != NULL && rs->LCAnode != NULL) {
    return rs;
  }

  custom* result = new custom();

  if (ls != NULL && rs != NULL) {
    result->LCAnode = root;
    result->p = true;
    result->q = true;
    return result;
  }

  if (root->data == p) {
    result->p = true;
    result->q = (ls) ? ls->q : false or (rs) ? rs->q : false;

    if (result->p == true && result->q == true) {
      result->LCAnode = root;
    }
    return result;
  }

  if (root->data == q) {
    result->q = true;
    result->p = (ls) ? ls->p : false or (rs) ? rs->p : false;

    if (result->p == true && result->q == true) {
      result->LCAnode = root;
    }
    return result;
  }

  if (ls != NULL) {
    return ls;
  }

  if (rs != NULL) {
    return rs;
  }

  return NULL;
}


node* lca2(node* root, int p, int q) {
  custom* result = calcLCA(root, p, q);
  if (result == NULL)
    return NULL;
  else {
    return result->LCAnode;
  }
}
int globalmax = INT_MIN;
int maxPathNode2Node(node* root) {
  if (root == NULL)
    return 0;
  int ls = maxPathNode2Node(root->left);
  int rs = maxPathNode2Node(root->right);
  int case1 = root->data;
  int case2 = ls + root->data;
  int case3 = rs + root->data;
  int case4 = rs + ls + root->data;
  //cout << "root-data" << root -> data << " ls " << ls << " RS " << rs << endl;
  globalmax = max({case1, case2, case3, case4, globalmax});
  //cout << max({ls, rs, 0}) + root->data << endl;
  return max({ls, rs, 0}) + root->data;
}

int finddistance(node*root, int k) {
  if (root == NULL)
    return -1;
  static int dist = -1;
  if (root -> data == k or  (dist = finddistance(root->left, k)) >= 0 or
      (dist = finddistance(root->right, k)) >= 0 ) {
    return dist + 1;
  }
}

int distance2nodes(node*root, int p, int q) {
  int lcapq = lca2(root, p, q)->data;
  int dist_lca = finddistance(root, lcapq);
  int distrp = finddistance(root, p);
  int distrq = finddistance(root, q);
// cout << distrq << ' ' << distrp << ' ' << dist_lca << endl;
  int ans = (distrq + distrp) - (2 * dist_lca);
// cout << ans << endl;
  return ans;
}

node* head;

void B2LL(node* root) {
  static node* prev = NULL;
  if (root == NULL)
    return;
  B2LL(root->left);
  if (prev == NULL)
    head = root;
  else {
    root->left = prev;
    prev->right = root;
  }
  prev = root;
  B2LL(root->right);
}

void printlist(node* head) {
  while (head != NULL) {
    cout << head->data << ' ';
    head = head->right;
  }
}

int main() {


  node* root = buildTree();
  map<int, vector<int>> m;
  int d = 0;
  verticalorderprint(root, d, m);
  for (auto p : m) {
    for (auto i : p.second)
      cout << i << ' ';
    cout << endl;
  }
  cout << "Inorderprint\n";
  inorderprint(root);
  cout << "\nPostorderprint\n";
  postOrderPrint(root);
  cout << "\nPreorderprint\n";
  preorderprint(root);
  cout << "\nThe height of the tree is\n";
  cout << heightoftree(root);
  cout << "\n3rd level of the tree\n";
  printkthlevel(root, 3);
  cout << "\nLevelorderprint\n";
  levelorderprint(root);
  cout << "\nBFS (Breadth first travesal) i.e levelorderprint in O(N)\n";
  bfs(root);
  cout << "\nbfs1\n";
  bfs1_by_me(root);
  cout << "\nbfs2\n";
  bfs2(root);
  cout << "Count of nodes are\n";
  cout << countnodes(root);
  cout << "\nSum of all the nodes are\n";
  cout << sumofnodes(root);
  cout << "\nDiameter of the tree\n";
  cout << diameter(root);
  cout << "\nFast Diameter of the tree\n";
  pair<int, int> p = fastdiameter(root);
  cout << max(p.first, p.second) ;    //p.first=heightoftree and p.second=diameter of tree
  //sumofchildnodes(root);
  cout << "\nThe sum of child nodes in the tree\n";
  bfs2(root);
  if (isheightbalance(root).second) {
    cout << "Tree is Height balanced\n";
  }
  else {
    cout << "Tree is not Height balanced\n";
  }
  int a[] = {1, 2, 3, 4, 5, 6, 7};
  node *t = buildfromArray(a, 0, 6);
  bfs2(t);
  int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
  int in[] = {3, 2, 8, 4, 1, 6, 7, 5};
  node*q = createTreefromTrav(in, pre, 0, 7);
  bfs2(q);
  cout << "\nRight View" << endl;
  //rightview(root, 1);
  cout << "Nodes at a distance k from a given node\n";
  //printAtKDistance(root, 3, 2);
  cout << "LCA \n";
  cout << lca1(root, 0, 4) << endl;
  cout << "LCA 2 (Optimized)\n";
  node* ok = lca2(root, 0, 4);
  if (ok != NULL)
    cout << ok->data;
  cout << "\nMaximum path from node to node is\n";
  maxPathNode2Node(root);
  cout << globalmax << endl;
  cout << "distance between any 2 nodes is\n";
  cout << distance2nodes(root, 8, 0) << endl;
  cout << "Converting Tree to Doubly linkedlist\n";
  B2LL(root);
  printlist(head);

}

