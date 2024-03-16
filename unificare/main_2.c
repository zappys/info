#include <stdio.h>

int get_number_of_digits(int n);

int main() {
  int c, n, k;
  int numbers[100000 + 1] = {0};
  int numbers_digits[100000 + 1][10] = {0};

  FILE *file_input = fopen("unificare.in", "r");
  FILE *file_output = fopen("unificare.out", "w");
  fscanf(file_input, "%d %d %d", &c, &n, &k);

  for (int i = 0; i < n; i++) {
    fscanf(file_input, "%d", &numbers[i]);
    int x = numbers[i];
    while (x > 0) {
      numbers_digits[i][x % 10] = 1;
      x = x / 10;
    }
  }

  // find the biggest number from the list of max k digits
  if (c == 1) {
    long long biggest_number = 0;

    for (int i = 0; i < n; i++) {
      int digit_count = get_number_of_digits(numbers[i]);
      if (numbers[i] > biggest_number && digit_count == k) {
        biggest_number = numbers[i];
      }
    }
    printf("biggest_number=%lld\n", biggest_number);
    fprintf(file_output, "%lld\n", biggest_number);
  }

  // find the biggest unified number but only unifying 2 neighboring numbers
  if (c == 2) {
    long long biggest_unified = 0;

    for (int i = 0; i < n - 1; i++) {
      long long current_unified = 0;
      for (int j = 9; j >= 0; j--) {
        if (numbers_digits[i + 1][j]) {
          current_unified = current_unified * 10 + j;
        }
        if (numbers_digits[i][j]) {
          current_unified = current_unified * 10 + j;
        }
      }
      if (current_unified > biggest_unified) {
        biggest_unified = current_unified;
      }
    }
    printf("biggest_unified=%lld\n", biggest_unified);
    fprintf(file_output, "%lld\n", biggest_unified);
  }

  if (c == 3) {
    int current_unified[10] = {0};
    int unified_max[10] = {0};
    int sum = 0, summax = 0;

    // go from 0 to k-1 and add the digits to the current_unified
    for (int i = 1; i < k; i++) {
      for (int j = 0; j < 10; j++) {
        current_unified[9 - j] += numbers_digits[i][j];
        sum += numbers_digits[i][j];
      }
    }

    // we will continue to add the digits to the current_unified and compare the
    // sum with summax, but at the same time we will remove the digits from the
    // current_unified and the sum that are not part of the current k numbers
    for (int i = k; i <= n; ++i) {
      for (int j = 0; j < 10; ++j) {
        current_unified[9 - j] += numbers_digits[i][j];
        sum += numbers_digits[i][j];
      }

      if (sum > summax) {
        summax = sum;
        for (int j = 0; j < 10; ++j) {
          unified_max[j] = current_unified[j];
        }
      } else if (sum == summax) {
        // if the sum is equal we compare the current_unified with the
        // unified_max and if it's bigger we update the unified_max
        // in C++ this is a bit easier to do with the > operator
        for (int j = 0; j < 10; ++j) {
          if (current_unified[j] > unified_max[j]) {
            for (int l = 0; l < 10; ++l) {
              unified_max[l] = current_unified[l];
            }
            break;
          } else if (current_unified[j] < unified_max[j]) {
            break;
          }
        }
      }

      // remove the digits from the current_unified and the sum that are not
      // part of the current k numbers
      for (int j = 0; j < 10; j++) {
        current_unified[9 - j] -= numbers_digits[i - k + 1][j];
        sum -= numbers_digits[i - k + 1][j];
      }
    }

    // print the unified_max
    for (int i = 9; i >= 0; --i) {
      for (int j = 0; j < unified_max[9 - i]; ++j) {
        fprintf(file_output, "%d", i);
      }
    }
  }

  fclose(file_input);
  fclose(file_output);
  return 0;
}

// UTIL FUNCTIONS
int get_number_of_digits(int n) {
  if (n == 0) {
    return 1;
  }

  int result = 0;
  while (n > 0) {
    n = n / 10;
    result += 1;
  }

  return result;
}
