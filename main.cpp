#include <iostream>
#include <vector>
using namespace std;

vector<char> base;
vector<string> matrix;
vector<char> cipher;

void decipher() {
  vector<char> decipherMessage;
  vector<int> result1;
  vector<int> result2;
  for (int i = 0; i < cipher.size(); i++) {
    for (int j = 0; j < cipher.size(); j++) {
      if (base[i] == matrix[0][j]) result2.push_back(j);
    }
  }
  for (int i = 0; i < result2.size(); i++) {
    for (int j = 0; j < result2.size(); j++) {
      if(cipher[i] == matrix[result2[i]][j]) result1.push_back(j);
    }
  }
  for (int i = 0; i < result1.size(); i++) {
    decipherMessage.push_back(matrix[0][result1[i]]);
  }
  cout << "message: ";
  for (int i = 0; i < decipherMessage.size(); i++) {
    cout << decipherMessage[i] << "";
  }
  cout << endl;
}

void encryption(string message) {
  vector<int> indexOfRow;
  vector<int> indexOfColumn;
  for (int i = 0; i < message.size(); i++) {
    for (int j = 0; j < message.size(); j++) {
      if (message[i] == matrix[0][j]) indexOfRow.push_back(j);
      if (base[i] == matrix[0][j]) indexOfColumn.push_back(j);
    }
  }
  for (int i = 0; i < indexOfRow.size(); i++) {
    cipher.push_back(matrix[indexOfRow[i]][indexOfColumn[i]]);
  }
  cout << "cipher: ";
  for (int i = 0; i < cipher.size(); i++) cout << cipher[i] << "";
  cout << endl;
  decipher();
}

void createMatrix(string alphabet, string message) {
  matrix.push_back(alphabet);
  for (int i = 1; i < alphabet.size(); i++) {
    alphabet.push_back(alphabet[0]);
    alphabet.erase(alphabet.begin());
    matrix.push_back(alphabet);
  }
  for (int i = 0; i < matrix.size(); i++) cout << matrix[i] << endl;
  encryption(message);
}

void createBase(string key, string alphabet, string message) {
  for (int i = 0; i < key.size(); i++) {
    if (message.size() > base.size()) base.push_back(key[i]);
  }
  if (base.size() < message.size()) createBase(key, alphabet, message);
  else createMatrix(alphabet, message);
}

void read() {
  string key, alphabet, message;
  cout << "Enter your key: ";
  getline(cin, key);
  cout << "Enter your alphabet: ";
  getline(cin, alphabet);
  cout << "Enter your message: ";
  getline(cin, message);
  createBase(key, alphabet, message);
}

int main() {
  read();
  return 0;
}
