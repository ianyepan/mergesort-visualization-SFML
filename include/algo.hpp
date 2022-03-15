#pragma once

#include <unistd.h>
#include "constants.hpp"

#include <algorithm>
#include <utility>

namespace algo {

inline void merge(std::vector<int> &arr, int l, int m, int r) {
  const int leftSize = m - l + 1;
  const int rightSize = r - m;

  std::vector<int> leftVec(leftSize), rightVec(rightSize);

  for (int i = 0; i < leftSize; i++)
    leftVec[i] = arr[l + i];
  for (int j = 0; j < rightSize; j++)
    rightVec[j] = arr[m + 1 + j];

  int i = 0, j = 0, k = l;
  while (i < leftSize && j < rightSize) {
    if (leftVec[i] <= rightVec[j]) {
      arr[k] = leftVec[i];
      ++i;
    } else {
      arr[k] = rightVec[j];
      ++j;
    }
    usleep(constants::delay);
    ++k;
  }

  // remaining of left
  while (i < leftSize) {
    arr[k] = leftVec[i];
    usleep(constants::delay);
    ++i, ++k;
  }

  // remaining of right
  while (j < rightSize) {
    arr[k] = rightVec[j];
    usleep(constants::delay);
    ++j, ++k;
  }
}

inline void mergeSort(std::vector<int> &arr, int l, int r) {
  if (l < r) {
    auto m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

}  // namespace algo
