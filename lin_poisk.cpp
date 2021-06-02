#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int linPoisk(int arr[], int key, int size);
void showArr(int arr[], int size);

int main(){
  const int arrSize = 50;
  int arr[arrSize];
  int key = 0;
  int nElem = 0;
  srand(time(NULL));

  for (int i = 0; i < arrSize; i++){
    arr[i] = 1 + rand() % 50;
  }

  showArr(arr, arrSize);

  cout << "Какое число искать?";
  cin >>key;

  nElem = linPoisk(arr, key, arrSize);

  if (nElem != -1){
    cout << "Значение " << key << " находится в ячейке" << nElem << endl;
  }
  else{
    cout << "Нет такого значения";
  }
  return 0;
}

void showArr(int arr[], int arrSize){
  for (int i = 0; i < arrSize; i++){
    cout << setw(4) << arr[i];
    if ((i + 1) % 10 == 0){
      cout << endl;
    }
  }
  cout << endl;
}

int linPoisk(int arr[], int key, int arrSize){
  for (int i = 0; i < arrSize; i++){
    if (arr[i] == key){
      return i;
    }
  }
  return -1;
}