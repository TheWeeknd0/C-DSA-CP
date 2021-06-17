#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n';
#define ll  long long
using namespace std;

class Student {
public:
	string firstname, lastname, rollno;

	Student(string f, string l, string r) {
		firstname = f;
		lastname = l;
		rollno = r;
	}

	bool operator==(const Student &s)const {
		return rollno == s.rollno ; //s.rollno is the one we are searching for
		//rollno left to == is the roll of any student that is present in the hashtable
	}

};
class customHashFn {
public:
	size_t operator()(const Student & s)const {
		return s.firstname.length() + s.lastname.length(); //not so good hashFn..as many collisions
	}                                               //will happen
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	unordered_map<Student, int, customHashFn> mp;
	Student s1("Prateek", "Naranag", "01");
	Student s2("Chaitanya", "Sanmotra", "02");
	Student s3("Kishan", "Sharma", "03");
	Student s4("Archit", "Bubna", "04");
	mp[s1] = 100;
	mp[s2] = 200;
	mp[s3] = 300;
	mp[s4] = 400;
	for (auto i : mp) {
		cout << i.first.firstname << ' ' << i.first.lastname << " Marks " << i.second << endl;
	}


}