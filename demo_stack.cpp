#ifndef STACK_HPP
#include "stack.hpp"
#endif

using namespace std;

int main(void)
{
  Stack *pile;
  int *data1;
  int *data2;
  int *data3;
  int *data4;

  pile=new Stack();
  data1=new int(1);
  data2=new int(2);
  data3=new int(3);
  data4=new int(4);

  cout << "- pile->push(data1)" << endl;
  pile->push(data1);
  pile->display();
  cout << endl;

  cout << "- pile->push(data2)" << endl;
  pile->push(data2);
  pile->display();
  cout << endl;

  cout << "- pile->pop((void**)&data2)" << endl;
  pile->pop((void**)&data2);
  pile->display();
  cout << endl;

  cout << "- pile->push(data3)" << endl;
  pile->push(data3);
  pile->display();
  cout << endl;

  cout << "- pile->push(data4)" << endl;
  pile->push(data4);
  pile->display();
  cout << endl;

  cout << "- pile->pop((void**)&data4)" << endl;
  pile->pop((void**)&data4);
  pile->display();
  cout << endl;

  cout << "- pile->pop((void**)&data3)" << endl;
  pile->pop((void**)&data3);
  pile->display();
  cout << endl;

  cout << "- pile->pop((void**)&data1)" << endl;
  pile->pop((void**)&data1);
  pile->display();
  cout << endl;

  delete data1;
  delete data2;
  delete data3;
  delete data4;
  delete pile;

  return 0;
}
