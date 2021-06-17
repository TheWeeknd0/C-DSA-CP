/* Tell me... where should I go? To the left, where nothing is right?
 Or to the right, where nothing is left*/
#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n';
#define ll  long long
using namespace std;

class Graph1 {
	int v;
	list<int> *l;
public:
	Graph1(int v) {
		this->v = v;
		l = new list<int>[v];
	}
	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void printAdjList() {
		for (int i = 0; i < v; i++) {
			cout << "Vertex " << i << " -> ";
			for (auto p : l[i]) {
				cout << p << ' ';
			}
			cout << endl;
		}
	}
};
class Graph2 {
	int v;
	unordered_map<string, list <pair<string, int> > > l;
public:
	Graph2(int v) {
		this->v = v;
	}
	void addEdge(string x, string y, bool bidr, int wt) {
		l[x].push_back(make_pair(y, wt));
		if (bidr) {
			l[y].push_back(make_pair(x, wt));
		}
	}
	void printAdjList() {
		for (auto i : l) {
			string vertex = i.first;
			list<pair<string, int>> nbrs = i.second;
			cout << vertex << "-> ";
			for (auto nbr : nbrs) {
				string vert = nbr.first;
				int wt = nbr.second;
				cout << vert << "->" << wt << ' ';
			}
			cout << endl;
		}
	}
};


//Templated Graph(non weighted)
template<typename T>
class Graph {
	map<T, list<T>> l;
public:
	void addEdge(T x, T y) {
		l[x].push_back(y);
		//l[y].push_back(x); // Not Bidirectional
	}
	void bfs(T start) {
		map<T, bool> visited;
		queue<T> q;
		q.push(start);
		visited[start] = true;
		while (!q.empty()) {
			cout << q.front() << ' ';
			T temp = q.front();
			q.pop();
			for (auto nbrs : l[temp]) {

				if (!visited[nbrs]) {
					q.push(nbrs);
					visited[nbrs] = true;
				}

			}
		}
	}

	void dfs_helper(T src, map<T, bool> &visited) {
		cout << src << ' ';
		visited[src] = true;
		for (T i : l[src]) {
			if (!visited[i]) {
				dfs_helper(i, visited);
			}
		}
	}

	void dfs_helper2(T src, map<T, bool> &visited) {
		visited[src] = true;
		for (T i : l[src]) {
			if (!visited[i]) {
				dfs_helper2(i, visited);
			}
		}
	}


	void dfs(T src) {
		map<T, bool> visited;

		for (auto i : l)
			visited[i.first] = false;

		dfs_helper(src, visited);
	}

	void dfs2() {
		map<T, bool> visited;

		for (auto i : l)
			visited[i.first] = false;
		int cnt = 0;
		for (auto i : l) {
			if (visited[i.first] != true) {
				cnt++;
				dfs_helper2(i.first, visited);
			}
		}
		cout << cnt;
	}

	void printAdjList() {
		for (auto i : l) {
			cout << "Vertex " << i.first << " -> "; f
			for (auto p : i.second) {
				cout << p << ' ';
			}
			cout << endl;
		}
	}

	void NoOfCompleteGraph() {
		map<T, bool> visited;
		int cnt = 0;
		for (auto i : l) {
			visited[i.first] = false;
		}

		dfs2();
	}


	void snakeBFS(T src, T dest) {
		map<T, int> dist;
		queue<T> q;
		for (auto i : l) {
			dist[i.first] = INT_MAX;
		}
		dist[src] = 0;
		q.push(src);
		while (!q.empty()) {
			for (auto j : l[q.front()]) {
				if (dist[j] == INT_MAX) {
					q.push(j);
					dist[j] = dist[q.front()] + 1;
				}
			}
			q.pop();
		}
		cout << dist[dest] << endl;
	}

};


int main() {

	Graph <int>g;
	/*g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(1, 3);
	g.bfs(2);
	cout << endl;
	g.printAdjList();
	cout << endl;
	Graph2 g2(4);
	g2.addEdge("a", "b", false, 40);
	g2.addEdge("c", "d", true, 50);
	g2.addEdge("c", "b", false, 505);
	g2.addEdge("c", "a", true, 4000);
	g2.printAdjList();*/
	int board[50] = {0};
	//Snakes //Ladders
	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[17] = -13;   //These are the jumps from the particular index
	board[20] = -14; //and not the final destination landed by the snake or ladder
	board[24] = -8;
	board[25] = 10;
	board[32] = -2;
	board[34] = -22;
//	for (int i = 1; i <= 36; i++) {
	//	for (int j = 1; j <= 6; j++) {
	//	int k = i + j + board[i + j];
	//if (k <= 36) {
	//g.addEdge(i, k);
	//}
	//}
	//}
	//g.addEdge(36, 36);
	g.printAdjList();
//	g.snakeBFS(1, 36);
//	g.dfs(1);
	cout << endl;
	//g.bfs(1);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(0, 3);
	g.addEdge(0, 4);
	g.addEdge(5, 6);
	g.addEdge(6, 7);
	g.addEdge(8, 8);

	g.NoOfCompleteGraph();
}