#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>
#include <chrono>

void countIf()
{
  std::vector<int> vec1(1'000'000, 1), vec2(1'000'000, 1);
  for (int i = 0; i < vec1.size(); i += 100) {
    vec1[i] = 2; // Dodanie wiekszej liczby elementow spelniajacych warunek
    vec2[i] = 2;
  }

  auto start_seq = std::chrono::high_resolution_clock::now();
  std::count_if(std::execution::seq, vec1.begin(), vec1.end(), [](int x) { return x == 2; });
  auto end_seq = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration_seq = end_seq - start_seq;

  auto start_par = std::chrono::high_resolution_clock::now();
  std::count_if(std::execution::par, vec2.begin(), vec2.end(), [](int x) { return x == 2; });
  auto end_par = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration_par = end_par - start_par;

  std::cout << "\033[1mstd::count_if\033[0m" << std::endl;
  std::cout << "Sequential Execution time: " << duration_seq.count() << " seconds" << std::endl;
  std::cout << "Parallel Execution time: " << duration_par.count() << " seconds" << std::endl;
}

void Transform()
{
  std::vector<int> vec1(1'000'000, 1), vec2(1'000'000, 1);
  std::vector<int> output1(vec1.size()), output2(vec2.size());

  auto start_seq = std::chrono::high_resolution_clock::now();
  std::transform(std::execution::seq, vec1.begin(), vec1.end(), output1.begin(), [](int x) {
    int result = x;
    for (int i = 0; i < 100; ++i) {
      result = result * 2 / 2;
    }
    return result;
  });
  auto end_seq = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration_seq = end_seq - start_seq;

  auto start_par = std::chrono::high_resolution_clock::now();
  std::transform(std::execution::par, vec2.begin(), vec2.end(), output2.begin(), [](int x) {
    int result = x;
    for (int i = 0; i < 100; ++i) {
      result = result * 2 / 2;
    }
    return result;
  });
  auto end_par = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration_par = end_par - start_par;

  std::cout << "\033[1mstd::transform\033[0m" << std::endl;
  std::cout << "Sequential Execution time: " << duration_seq.count() << " seconds" << std::endl;
  std::cout << "Parallel Execution time: " << duration_par.count() << " seconds" << std::endl;
}

void Fill()
{
  std::vector<int> vec1(1'000'000), vec2(1'000'000);

  auto start_seq = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < 100; ++i) {
    std::fill(std::execution::seq, vec1.begin(), vec1.end(), 42);
  }
  auto end_seq = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration_seq = end_seq - start_seq;

  auto start_par = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < 100; ++i) {
    std::fill(std::execution::par, vec2.begin(), vec2.end(), 42);
  }
  auto end_par = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration_par = end_par - start_par;

  std::cout << "\033[1mstd::fill\033[0m" << std::endl;
  std::cout << "Sequential Execution time: " << duration_seq.count() << " seconds" << std::endl;
  std::cout << "Parallel Execution time: " << duration_par.count() << " seconds" << std::endl;
}

void Generate()
{
  std::vector<int> vec1(1'000'000), vec2(1'000'000);

  auto start_seq = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < 100; ++i) {
    std::generate(std::execution::seq, vec1.begin(), vec1.end(), []() { return rand() % 100; });
  }
  auto end_seq = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration_seq = end_seq - start_seq;

  auto start_par = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < 100; ++i) {
    std::generate(std::execution::par, vec2.begin(), vec2.end(), []() { return rand() % 100; });
  }
  auto end_par = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration_par = end_par - start_par;

  std::cout << "\033[1mstd::generate\033[0m" << std::endl;
  std::cout << "Sequential Execution time: " << duration_seq.count() << " seconds" << std::endl;
  std::cout << "Parallel Execution time: " << duration_par.count() << " seconds" << std::endl;
}

void replaceIf()
{
  std::vector<int> vec1(1'000'000), vec2(1'000'000);
  std::generate(vec1.begin(), vec1.end(), []() { return rand() % 100; });
  std::copy(vec1.begin(), vec1.end(), vec2.begin());

  auto start_seq = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < 100; ++i) {
    std::replace_if(std::execution::seq, vec1.begin(), vec1.end(), [](int x) { return x < 50; }, 100);
  }
  auto end_seq = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration_seq = end_seq - start_seq;

  auto start_par = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < 100; ++i) {
    std::replace_if(std::execution::par, vec2.begin(), vec2.end(), [](int x) { return x < 50; }, 100);
  }
  auto end_par = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration_par = end_par - start_par;

  std::cout << "\033[1mstd::replace_if\033[0m" << std::endl;
  std::cout << "Sequential Execution time: " << duration_seq.count() << " seconds" << std::endl;
  std::cout << "Parallel Execution time: " << duration_par.count() << " seconds" << std::endl;
}

int main()
{
  countIf();
  std::cout << std::endl;
  Transform();
  std::cout << std::endl;
  Fill();
  std::cout << std::endl;
  Generate();
  std::cout << std::endl;
  replaceIf();
  std::cout << std::endl;
  return 0;
}
