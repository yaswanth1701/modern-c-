#include <iostream>
#include <random>
#include <cstdlib>
using namespace std;
int main()
{
  random_device rnd;

  uniform_int_distribution<int> dist(0, 99);
  int guess;

  bool correct_guess = false;
  const int random_no = dist(rnd);

  while (!(correct_guess))
  {
    cin >> guess;
    if (cin.fail())
    {
      cout << "Error encountered, exiting..." << endl;
      cout << random_no << endl;
      exit(EXIT_FAILURE);
    }
    else if (guess < 0 || guess > 99)
    {
      cerr << "[WARNING] : Number must be between 0 and 99" << endl;
    }

    else
    {
      if (random_no < guess)
      {
        cout << "number is smaller" << endl;
      }
      else if (random_no > guess)
      {
        cout << "number is larger" << endl;
      }
      else
      {
        cout << "you won" << endl;
        cout << random_no << endl;
        correct_guess = true;
      }
    }
  }

  exit(EXIT_SUCCESS);
}