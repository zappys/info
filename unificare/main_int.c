#include <stdio.h>

int get_number_of_digits(int n);
long long get_unified(int nums[], int size, int start_at);

int main() {
  FILE *file_input = fopen("unificare.in", "r");
  FILE *file_output = fopen("unificare.out", "w");

  int c, n, k;
  fscanf(file_input, "%d %d %d", &c, &n, &k);

  // find the biggest number from the list of max k digits
  if (c == 1) {
    long long biggest_number = 0;
    int x;

    for (int i = 0; i < n; i++) {
      fscanf(file_input, "%d", &x);
      int digit_count = get_number_of_digits(x);
      if (x > biggest_number && digit_count == k) {
        biggest_number = x;
      }
    }
    fprintf(file_output, "%lld\n", biggest_number);
  }

  // find the biggest unified number but only unifying 2 neighboring numbers
  if (c == 2) {
    long long biggest_unified = 0;
    int nums[n];
    for (int i = 0; i < n; i++) {
      fscanf(file_input, "%d", &nums[i]);
    }

    for (int i = 0; i < n - 1; i++) {
      long long unified = get_unified(nums, i, i + 2);
      if (unified > biggest_unified) {
        biggest_unified = unified;
      }
    }
    // printf("biggest_unified=%lld\n", biggest_unified);
    fprintf(file_output, "%lld\n", biggest_unified);
  }

  if (c == 3) {
    long long biggest_unified = 0;
    int nums[n];
    for (int i = 0; i < n; i++) {
      fscanf(file_input, "%d", &nums[i]);
    }

    for (int i = 0; i <= n - k; i++) {
      long long unified = get_unified(nums, i, i + k);
      if (unified > biggest_unified) {
        biggest_unified = unified;
      }
    }
    // printf("biggest_unified=%lld\n", biggest_unified);
    fprintf(file_output, "%lld\n", biggest_unified);
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

long long get_unified(int nums[], int start_at, int stop_at) {
  int digits_unified[10] = {0}; // To track the presence of digits 0-9
  long long result = 0;

  // Extract digits from all numbers and mark their presence
  for (int i = start_at; i < stop_at; i++) {
    int num = nums[i];
    int digits_in_num[10] = {0};
    while (num > 0) {
      digits_in_num[num % 10] = 1; // Mark digit as present
      num = num / 10;
    }

    for (int j = 0; j < 10; j++) {
      if (digits_in_num[j]) {
        digits_unified[j] += 1;
      }
    }
  }

  // Construct the unified number from the digits in reverse order
  for (int i = 9; i >= 0; i--) {
    for (int j = 0; j < digits_unified[i]; j++) {
      result = result * 10 + i;
    }
  }

  return result;
}