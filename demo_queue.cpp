#ifndef QUEUE_HPP
#include "queue.hpp"
#endif

using namespace std;

int main(void)
{
  Queue *file;
  int *data1;
  int *data2;
  int *data3;
  int *data4;

  file=new Queue();
  data1=new int(1);
  data2=new int(2);
  data3=new int(3);
  data4=new int(4);

  cout << "- file->enqueue(data1)" << endl;
  file->enqueue(data1);
  file->display();
  cout << endl;

  cout << "- file->enqueue(data2)" << endl;
  file->enqueue(data2);
  file->display();
  cout << endl;

  cout << "- file->dequeue((void**)&data1)" << endl;
  file->dequeue((void**)&data1);
  file->display();
  cout << endl;

  cout << "- file->enqueue(data3)" << endl;
  file->enqueue(data3);
  file->display();
  cout << endl;

  cout << "- file->enqueue(data4)" << endl;
  file->enqueue(data4);
  file->display();
  cout << endl;

  cout << "- file->dequeue((void**)&data2)" << endl;
  file->dequeue((void**)&data2);
  file->display();
  cout << endl;

  cout << "- file->dequeue((void**)&data3)" << endl;
  file->dequeue((void**)&data3);
  file->display();
  cout << endl;

  cout << "- file->dequeue((void**)&data4)" << endl;
  file->dequeue((void**)&data4);
  file->display();
  cout << endl;

  delete data1;
  delete data2;
  delete data3;
  delete data4;
  delete file;

  return 0;
}
