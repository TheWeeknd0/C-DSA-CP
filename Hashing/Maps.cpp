#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  sync
  map<string, int> m;    // map < key , value >
  m.insert(make_pair("Banana", 100));
  m["Apple"] = 90;
  m["Apple"] = 100;
  cout << "For each loop \n";  //it automatically arranges the in ascending order acc to key
  for (auto i : m)
    cout << i.first << " : " << i.second << "\n";
  cout << "\n";
  cout << "For loop \n";
  for (auto it = m.begin(); it != m.end(); it++)
    cout << it->first << " : " << it->second << "\n";
  cout << "\n";
  cout << "Deleting Banana\n";
  m.erase("Banana");
  cout << m.size();
  cout << "\n" << "\n";
  if (m.count("Banana"))   //returns 1 if item is present and 0 if not
    cout << "Banana is present\n";
  else
    cout << "Banana is not present\n";
  cout << "\n";
  auto it = m.find("Banana");
  if ((it == m.end()))
    cout << "Iterartor have reached the last + 1 index\n";
  cout << "\n";
  //To print key of any element which is linked with the first key
  cout << m["Apple"] << "\n";
  // The element which is not present in the map have the second value as zero
  cout << m["Banana"];
}