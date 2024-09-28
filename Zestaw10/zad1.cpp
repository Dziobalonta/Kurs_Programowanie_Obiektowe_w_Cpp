#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>
#include <chrono>

int main()
{
  // std::execution::sequenced_policy: 
  // Ta polityka wykonania gwarantuje, ze algorytm bedzie wykonywany sekwencyjnie. 
  // Oznacza to, ze operacje beda wykonywane jedna po drugiej.
  std::vector<int> v1 = {1, 2, 3, 4, 5};
  auto start_seq = std::chrono::high_resolution_clock::now();
  std::for_each(std::execution::seq, v1.begin(), v1.end(),  [](int &n){ n *= 2; });
  auto end_seq = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration_seq = end_seq - start_seq;

  // std::execution::parallel_policy:
  // Ta polityka wykonania pozwala na rownolegle wykonywanie algorytmu. 
  // Operacje moga byc wykonywane jednoczesnie na roznych rdzeniach procesora.
  std::vector<int> v2 = {1, 2, 3, 4, 5};
  auto start_par = std::chrono::high_resolution_clock::now();
  std::for_each(std::execution::par, v2.begin(), v2.end(),  [](int &n){ n *= 2; });
  auto end_par = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration_par = end_par - start_par;

  // std::execution::parallel_unsequenced_policy:
  // Ta polityka wykonania pozwala na rownolegle i nieuporzadkowane wykonywanie algorytmu.
  // Operacje moga byc wykonywane jednoczesnie i w dowolnej kolejnosci.
  std::vector<int> v3 = {1, 2, 3, 4, 5};
  auto start_par_unseq = std::chrono::high_resolution_clock::now();
  std::for_each(std::execution::par_unseq, v3.begin(), v3.end(),  [](int &n){ n *= 2; });
  auto end_par_unseq = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration_par_unseq = end_par_unseq - start_par_unseq;

  std::cout << "\033[1mSequential: \033[0m" << std::endl;
  for (auto &&i : v1)
  {
    std::cout << i << " ";
  } std::cout << std::endl;
  std::cout << "Execution time: " << duration_seq.count() << " seconds\n" << std::endl;

  std::cout << "\033[1mParallel: \033[0m" << std::endl;
  for (auto &&i : v2)
  {
    std::cout << i << " ";
  } std::cout << std::endl;
  std::cout << "Execution time: " << duration_par.count() << " seconds\n" << std::endl;

  
  std::cout << "\033[1mParallel Unsequenced: \033[0m" << std::endl;
  for (auto &&i : v3)
  {
    std::cout << i << " ";
  } std::cout << std::endl;
  std::cout << "Execution time: " << duration_par_unseq.count() << " seconds\n" << std::endl;

  return 0;
}