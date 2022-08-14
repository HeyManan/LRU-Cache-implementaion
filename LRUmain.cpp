#include "LRU.hpp"

int choose()
{
  int option;
  cout << "Choose the Option : \n";
  cout << "1. Get\n2. Put\n3. Exit\n";
  cin >> option;
  return option;
}

int get_key()
{
  int key;
  cout << "Enter key: \n";
  cin >> key;
  return key;
}

int get_value()
{
  int value;
  cout << "Enter Value: \n";
  cin >> value;
  return value;
}

int main()
{
  LRUcache cache(3);
  int choice = choose(), k, v;

  while (choice != 3)
  {
    switch (choice)
    {
    case 1:
      k = get_key();
      cout << "Value is: " << cache.get(k) << "\n";
      break;
    case 2:
      k = get_key(), v = get_value();
      cache.put(k, v);
      break;
    default:
      cout << "Choose valid option\n";
      break;
    }

    choice = choose();
  }

  return 0;
}