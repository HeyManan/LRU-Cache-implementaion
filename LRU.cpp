#include "LRU.hpp"

bool DoublyLL::isEmpty()
{
  return rear == NULL;
}

void DoublyLL::move_page_forward(Node *page)
{
  if (front == page)
  {
    return;
  }

  if (page == rear)
  {
    rear = rear->prev;
    rear->next = NULL;
  }
  else
  {
    page->prev->next = page->next;
    page->next->prev = page->prev;
  }
  page->prev = NULL;
  page->next = front;
  front->prev = page;
  front = page;
}

void DoublyLL::remove_rear_page()
{
  if (isEmpty())
  {
    return;
  }

  if (front == rear)
  {
    delete rear;
    front = rear = NULL;
  }
  else
  {
    Node *rexr = rear;
    rear = rear->prev;
    rear->next = NULL;
    delete rexr;
  }
}

Node *DoublyLL::add_page_to_head(int key, int value)
{
  Node *page = new Node(key, value);

  if (front == NULL && rear == NULL)
  {
    front = rear = page;
  }
  else
  {
    front->prev = page;
    page->next = front;
    front = page;
  }
  return page;
}

Node *DoublyLL::rear_page()
{
  return rear;
}

int LRUcache::get(int key)
{
  if (page_map.find(key) == page_map.end())
  {
    return -1;
  }

  int val = page_map[key]->value;

  page_list->move_page_forward(page_map[key]);

  return val;
}

void LRUcache::put(int key, int value)
{
  if (page_map.find(key) != page_map.end())
  {
    cout << "Key value updated!\n";
    page_map[key]->value = value;
    page_list->move_page_forward(page_map[key]);
    return;
  }

  if (size == capacity)
  {
    int k = page_list->rear_page()->key;
    cout << "Deleting " << k << " from cache......\n";
    page_map.erase(key);
    page_list->remove_rear_page();
    size--;
  }

  Node *page = page_list->add_page_to_head(key, value);
  size++;
  page_map[key] = page;

  cout << "Value added to cache successfully\n";
}