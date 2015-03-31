#include<iostream>
#include<list>

using namespace std;

void main()
{
  list<int> List;
  list<int>::iterator i_list;

  for(int i =0; i < 10 ; i++)
  {
	List.push_back(i);
  }
  
  for(i_list = List.begin(); i_list != List.end() ; i_list++)
  {
	cout << *i_list << endl;
  }
}
