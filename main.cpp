#include <iostream>

using namespace std;

int findMax(int wallSize, int beauty[]);

int main() {
  //get inputs
  int testCases;
  int wallSize[101];
  char beauty[101][101];
  cin >> testCases;
  for(int i = 0; i < testCases; i++){
    cin >> wallSize[i];
    for(int j = 0; j < wallSize[i]; j++){
      cin >> beauty[i][j];
    }
  }

  //calculate answers
  for(int i = 0; i < testCases; i++){
    int currWall[wallSize[i]];
    for(int j = 0; j < wallSize[i]; j++){
      currWall[j] = beauty[i][j] - '0';
    }
    cout << "Case #" << i + 1 << ": " << findMax(wallSize[i], currWall) << endl;
  }
  return 0;
}

int findMax(int wallSize, int beauty[]){
  int paintableSize;
  int odd = wallSize % 2;
  paintableSize = (wallSize + odd) / 2;

  int maxBeauty = 0;
  int currBeauty;

  for(int i = 0; i < paintableSize + 1 - odd; i++){
    currBeauty = 0;
    for(int j = i; j < paintableSize + i; j++){
      currBeauty += beauty[j];
    }
    if(maxBeauty < currBeauty){
      maxBeauty = currBeauty;
    }
  }
  return maxBeauty;
}
