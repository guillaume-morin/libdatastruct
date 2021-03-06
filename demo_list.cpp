#ifndef LIST_HPP
#include "list.hpp"
#endif

using namespace std;

int main(void)
{
  List *liste;
  int *data1;
  int *data2;
  int *data3;
  int *data4;

  liste=new List();
  data1=new int(1);
  data2=new int(2);
  data3=new int(3);
  data4=new int(4);

  cout << "- liste->insert_next(NULL,data1)" << endl;
  liste->insert_next(NULL,data1);
  liste->display();
  cout << endl;

  cout << "- liste->insert_next(NULL,data2)" << endl;
  liste->insert_next(NULL,data2);
  liste->display();
  cout << endl;

  cout << "- liste->remove_next(NULL,(void**)&data1)" << endl;
  liste->remove_next(NULL,(void**)&data1);
  liste->display();
  cout << endl;

  cout << "- liste->insert_next(NULL,data3)" << endl;
  liste->insert_next(NULL,data3);
  liste->display();
  cout << endl;

  cout << "- liste->insert_next(liste->head(),data4)" << endl;
  liste->insert_next(liste->head(),data4);
  liste->display();
  cout << endl;

  cout << "- liste->remove_next(liste->head(),(void**)&data2)" << endl;
  liste->remove_next(liste->head(),(void**)&data2);
  liste->display();
  cout << endl;

  cout << "- liste->remove_next(NULL,(void**)&data3)" << endl;
  liste->remove_next(NULL,(void**)&data3);
  liste->display();
  cout << endl;

  cout << "- liste->remove_next(NULL,(void**)&data4)" << endl;
  liste->remove_next(NULL,(void**)&data4);
  liste->display();
  cout << endl;

  delete data1;
  delete data2;
  delete data3;
  delete data3;
  delete liste;

  return 0;
}
