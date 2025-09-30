#include <iostream>
#include <string>
using namespace std;

void testSentence() {
  string word1;
  cout << "Ord 1: ";
  cin >> word1;
  cout << "> " << word1 << endl;
  string word2;
  cout << "Ord 2: ";
  cin >> word2;
  cout << "> " << word2 << endl;
  string word3;
  cout << "Ord 3: ";
  cin >> word3;
  cout << "> " << word3 << endl;
  
  string sentence = word1 + " " + word2 + " " + word3;
  cout << "Settningen ble: " << sentence << endl;
  
  cout << "Lengden på ordene er "
    << word1.length() << " "
    << word2.length() << " "
    << word3.length() << endl;
  cout << "Lengden på settningen er " << sentence.length() << endl;
  
  string sentence2(sentence);
  if (sentence.size() >= 12) {
    sentence2.replace(9, 3, "xxx");
    cout
      << "Settningene 1 og 2:" << endl
      << sentence << endl
      << sentence2 << endl;
  }
  
  if (sentence.size() >= 5) {
    string sentence_start = sentence.substr(0, 5);
    cout << "Setning: " << sentence << endl;
    cout << "Start på setning: " << sentence_start << endl;
  }
  
  if (sentence.find("hallo") != string::npos) {
    cout << "Setningen inneholder 'hallo'" << endl;
  } else {
    cout << "Setningen inneholder ikke 'hallo'" << endl;
  }
  
  size_t pos = sentence.find("er");
  while (pos != string::npos) {
    cout << "Fant 'er' på posisjon " << pos << endl;
    pos = sentence.find("er", pos + 2);
  }
}
