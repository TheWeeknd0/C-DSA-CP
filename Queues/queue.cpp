#include<bits/stdc++.h>
using namespace std;
class Queue {
	int *arr;
	int ms;
	int cs;
	int front;
	int rear;
public:
	Queue(int default_size = 2) {
		front = 0;
		rear = default_size - 1;
		ms = default_size;
		arr = new int[ms];
		cs = 0;
	}
	bool isempty() {
		return cs == 0;
	}
	int maxsize() {
		return ms;
	}
	bool isFull() {
		return cs == ms;
	}
	int currsize() {
		return cs;
	}
	void enqueue(int data) {
		if (!isFull()) {
			rear = (rear + 1) % ms;  //dont use the isFull fucntion if u want to circularly add more data
			arr[rear] = data;
			cs++;
		}
	}
	void dequeue() {
		if (!isempty()) {
			front = (front + 1) % ms;
			cs--;
		}
	}
	void show() {
		if (!isempty()) {
			for (int i = front; i <= rear; i++)
				cout << arr[i] << ' ';
		}
	}
	int getfront() {
		return arr[front];
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Queue q;
	q.enqueue(1);
	q.enqueue(3);
	q.show();
	cout << endl;
	cout << "Deleting!!!!!!!\n";
	q.show();
	cout << endl;
	cout << "Adding!!!!!!!!!\n";
	q.enqueue(3);
	q.enqueue(4);

	q.show();
	q.dequeue();
	cout << "\n" << q.getfront();
}