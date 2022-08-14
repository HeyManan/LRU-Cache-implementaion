#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int key, value;
  Node *prev, *next;
  Node(int k, int v) : key(k), value(v), prev(NULL), next(NULL) {}
};

class DoublyLL
{
  Node *front, *rear;

  bool isEmpty();

public:
  DoublyLL() : front(NULL), rear(NULL) {}

  void move_page_forward(Node *page);

  void remove_rear_page();

  Node *add_page_to_head(int key, int value);

  Node *rear_page();
};

class LRUcache
{
  int capacity, size;
  DoublyLL *page_list;
  map<int, Node *> page_map;

public:
  LRUcache(int cap)
  {
    capacity = cap;
    size = 0;
    page_map = map<int, Node *>();
    page_list = new DoublyLL();
  }

  int get(int key);

  void put(int key, int value);

  ~LRUcache()
  {
    for (auto i = page_map.begin(); i != page_map.end(); i++)
    {
      delete i->second;
    }

    delete page_list;
  }
};