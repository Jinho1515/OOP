


int array_min(int integers[], int length) {
  if (length <= 0) {
    return -1;
  }
  int min_value=integers[0];
  for (int i = 0; i < length; i++) {
    if (min_value>integers[i]) {
        min_value= integers[i];
    }    
  }
  return min_value;
}

int array_max(int integers[], int length) {
  if (length <= 0) {
    return -1;
  }
  int max_value=integers[0];
  for (int i = 0; i < length; i++) {
    if (max_value<integers[i]) {
        max_value = integers[i];
    }    
  }
  return max_value;
}


int sum_min_max(int integers[], int length) {
  if (length <= 0) {
    return -1;
  }
    int min_value = array_min(integers, length);
    int max_value = array_max(integers, length);
    return min_value + max_value;
}
