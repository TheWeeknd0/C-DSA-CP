#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n';
#define ll long long
using namespace std;
class Heap {
	vector<int> v;
	bool minheap;
	bool compare(int a, int b) {
		if (minheap)
			return a < b;
		else
			return a > b;
	}
	void downheapify(int idx) {
		int min_idx = idx;
		int last = v.size() - 1;
		int left = 2 * idx;
		int right = left + 1;
		if (left <= last and compare(v[left], v[idx]))
			min_idx = left;
		if (right <= last and compare(v[right], v[min_idx]))
			min_idx = right;
		if (min_idx != idx) {
			swap(v[min_idx], v[idx]);
			downheapify(min_idx);
		}
	}

public:
	Heap(int default_size = 10, bool type = true) {
		v.reserve(default_size);
		v.push_back(-1);
		minheap = type;
	}
	void push(int d) {
		v.push_back(d);
		int idx = v.size() - 1;
		int parent = idx / 2;
		while (idx > 1 and compare(v[idx], v[parent])) {
			swap(v[idx], v[parent]);
			idx = parent;
			parent /= 2;
		}
	}
	void pop() {
		int last = v.size() - 1;
		swap(v[last], v[1]);
		v.pop_back();
		downheapify(1);
	}
	bool empty() {
		return v.size() == 1; // 0th is reserved;
	}
	int top() {
		return v[1];  // always print the top
	}

	void buildheap(vector<int> &v) {
		for (int i = 1; i < v.size(); i++) {
			int idx = i;
			int parent = i / 2;
			while (idx > 1 and v[idx] < v[parent]) {  // for min heap ..change the comaprison for max
				swap(v[idx], v[parent]);
				idx = parent;
				parent /= 2;
			}
		}
	}

	//for buildheapoptimised
	void heapifythevector(vector<int> &v, int idx) {   //O(NlogN)
		int min_idx = idx;
		int last = v.size() - 1;   //we pass the vector because we are performing heapify on a
		int left = 2 * idx;        //particular array inside a function call and THIS VECTOR
		int right = left + 1;      //IS OUT OF THE SCOPE OF THE CLASS
		if (left <= last and compare(v[left], v[idx]))
			min_idx = left;
		if (right <= last and compare(v[right], v[min_idx]))
			min_idx = right;
		if (min_idx != idx) {
			swap(v[min_idx], v[idx]);
			heapifythevector(v, min_idx);
		}
	}
	void buildheapoptimized(vector<int> &v) {    //O(N)
		for (int i = (v.size() - 1) / 2; i >= 1; i--) {
			heapifythevector(v, i);
		}
	}

	void deleteanynode(int idx) {
		int last = v.size() - 1;
		swap(v[last], v[idx]);
		v.pop_back();
		downheapify(idx);
		cout << v.size() << endl;
	}

	void downheapifyHeapSort(vector<int> &v, int idx, int heapsize) {
		int min_idx = idx;
		int last = heapsize;
		int left = 2 * idx;
		int right = left + 1;
		if (left <= last and compare(v[left], v[idx]))
			min_idx = left;
		if (right <= last and compare(v[right], v[min_idx]))
			min_idx = right;
		if (min_idx != idx) {
			swap(v[min_idx], v[idx]);
			downheapifyHeapSort(v, min_idx, heapsize);
		}
	}

	void heapsort(vector<int> &v) {
		int heapsize = v.size();
		buildheapoptimized(v);
		for (int i = v.size() - 1; i >= 1; i--) {
			swap(v[0], v[i]);
			heapsize--;
			downheapifyHeapSort(v, 1, heapsize);
		}
	}

	void printheap(vector<int> v) {
		for (auto i = 1; i < v.size(); i++)
			cout << v[i] << ' ';
		cout << endl;
	}
};
class Person {
public:
	string name;
	int age;
	Person() {

	}
	Person(string a, int b) {
		name = a;
		age = b;
	}
};

class personcompare {
public:
	bool operator()(Person a, Person b) {
		return a.age < b.age;
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	sync;
	Heap h(10, false);
	vector<int> v = { -1, 10, 220, 23, 13, 12424};
	Heap q(10, false);   // minheap=true is the default case
	q.heapsort(v);
	//q.printheap(v);
	//int n; cin >> n;
	//for (int i = 0; i < n; i++) {
	//	int no; cin >> no;
	//	h.push(no);
//}
//	h.deleteanynode(5);
//for (int i = 0; i < n - 1; i++) { // -1 because i deleted a node
//	cout << h.top() << " ";
//h.pop();
//}
	priority_queue<Person, vector<Person>, personcompare> pq;
	for (int i = 0; i < 4; i++) {
		string a;
		int b;
		cin >> a >> b;
		Person p(a, b);
		pq.push(p);
	}
	for (int i = 0; i < 2; i++) {
		Person p = pq.top();
		cout << p.name << ' ' << p.age << endl;
		pq.pop();
	}

}





