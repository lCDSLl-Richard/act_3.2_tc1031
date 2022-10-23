#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>

using namespace std;

typedef unsigned int uint;

template <class T>
class Priority_queue
{
private:
  uint current = 0;
  vector<T> data;

public:
  Priority_queue();
  ~Priority_queue();

  uint left(uint);
  uint right(uint);
  uint parent(uint);

  bool empty();
  uint size();

  void push(T val);
  T top();
  T pop();
};

template <class T>
uint Priority_queue<T>::left(uint parent)
{
  return parent * 2 + 1;
}

template <class T>
uint Priority_queue<T>::right(uint parent)
{
  return parent * 2 + 2;
}

template <class T>
uint Priority_queue<T>::parent(uint child)
{
  return (child - 1) / 2;
}

template <class T>
bool Priority_queue<T>::empty()
{
  return current == 0;
}

template <class T>
uint Priority_queue<T>::size()
{
  return data.size();
}

template <class T>
T Priority_queue<T>::top()
{
  return data[0];
}

template <class T>
void Priority_queue<T>::push(T val)
{
  uint pos = ++current;
  uint currParent = parent(current);

  while (pos > 0 && val > data[currParent])
  {
    data[pos] = data[currParent];
    pos = currParent;
    currParent = parent(pos);
  }

  data[pos] = val;
}

#endif
