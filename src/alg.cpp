// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int res = 0;
  for (int o = 0; o < len - 1; o++) {
    for (int l = o+1; l < len; l++) {
      if (arr[o] + arr[l] == value)
        res+=1;
    }
  }
  return res;
}
int countPairs2(int *arr, int len, int value) {
  int res = 0;
  for (int o = 0; o < len - 1; o++) {
    for (int l = len -1; o < l; l--) {
      if (arr[o] + arr[l] == value)
        res+=1;
    }
  } 
  return res;
}
int countPairs3(int *arr, int len, int value) {
  int res = 0;
  for (int i = 0; i < len - 1; i++) {
    int left = i, right = len;
    while (1 < right - left) {
      int m = (left + right) / 2;
      if (arr[i] + arr[m] == value) {
          res++;
          int temp = m + 1;
        while (arr[i] + arr[t] == value && temp < right) {
          res++;
          temp++;
        }
        temp = m - 1;
        while (arr[i] + arr[t] == value && temp > left) {
          res++;
          temp--;
        }
        break;
      }
      if (arr[i] + arr[m] > value) {
        right = m;
      } else {
        left = m;
      }
    }
  }
