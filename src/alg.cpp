// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int res = 0;
  for (int k = 0; k < len - 1; k++) {
    for (int l = k+1; l < len; l++) {
      if (arr[k] + arr[l] == value)
        res+=1;
    }
  }
  return res;
}
int countPairs2(int *arr, int len, int value) {
  int res = 0;
  for (int k = 0; k < len - 1; k++) {
    for (int l = len -1; k < l; l--) {
      if (arr[k] + arr[l] == value)
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
        while (arr[i] + arr[temp] == value && temp < right) {
          res++;
          temp++;
        }
        temp = m - 1;
        while (arr[i] + arr[temp] == value && temp > left) {
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
  return res;
}

