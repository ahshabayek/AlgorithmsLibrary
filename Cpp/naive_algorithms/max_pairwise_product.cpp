///@file max_pairwise_product.cpp
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
namespace naive_algo {

int NaiveMaxPairwiseProduct(const vector<int> &numbers)
{
  int result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (numbers[i] * numbers[j] > result) {
        result = numbers[i] * numbers[j];
      }
    }
  }
  return result;
}

int MaxPairwiseProductFast(const vector<int> &numbers) {
  int result = 0;
  int n = numbers.size();
  auto max_one = numbers[0];
  int max_two = 0;
  int max_index = 0;
  for (int index = 1; index < n; ++index) {
    if (max_one < numbers[index]) {
      max_one = numbers[index];
    }
  }
  for (int index = 1; index < n; ++index) {
    if (index != max_index) {
      if (max_two < numbers[index]) {
        max_two = numbers[index];
      }
    }
  }
  result = max_one * max_two;
  return result;
}

int64_t MaxPairwiseProduct(const vector<int64_t> &numbers) {
  int64_t result = 0;
  int n = numbers.size();
  // create max 1 and max 2, max 1  > max 2
  // int max_one,max_two = ( (numbers[0]>numbers[1])?
  // (numbers[0], numbers[1]) : (numbers[1], numbers[0]));
  int64_t max_one, max_two;
  if (numbers[0] > numbers[1]) {
    max_one = numbers[0], max_two = numbers[1];
  } else {
    max_one = numbers[1], max_two = numbers[0];
  }

  for (int i = 2; i < n; ++i) {
    if (numbers[i] > max_two) {
      if (numbers[i] >= max_one) {
        max_two = max_one;
        max_one = numbers[i];
      } else {
        { max_two = numbers[i]; }
      }
    }
  }
  result = max_one * max_two;
  return result;
}

int main() {
  int n;
  cin >> n;
  vector<int64_t> numbers(n);
  for (int i = 0; i < n; ++i) {
    cin >> numbers[i];
  }

  int64_t result = MaxPairwiseProduct(numbers);
  cout << result << "\n";
  return 0;
}

} // namespace naive_algo
