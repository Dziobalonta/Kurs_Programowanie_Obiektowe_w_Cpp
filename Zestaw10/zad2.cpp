#include <iostream>
#include <vector>  
#include <algorithm>  
#include <execution>  
#include <mutex>  
#include <chrono>

int main() 
{  
  std::vector<int> vec1(10'000'000), vec2(10'000'000);
  std::iota(vec1.begin(), vec1.end(), 0); // Fills the range [first, last) with sequentially increasing values, 
  std::iota(vec2.begin(), vec2.end(), 0); // starting with value and repetitively evaluating ++value
  std::vector<int> output1, output2;
  std::mutex mtx;

  auto start_par = std::chrono::high_resolution_clock::now();
  std::for_each(std::execution::par, vec1.begin(), vec1.end(),  
  [&output1, &mtx](int& elem) 
  {
    if (elem % 2 == 0) 
    {
      std::lock_guard<std::mutex> lock(mtx);
      output1.push_back(elem);
    }
  });
  auto end_par = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration_par = end_par - start_par;

  auto start_seq = std::chrono::high_resolution_clock::now();
  std::for_each(std::execution::seq, vec2.begin(), vec2.end(),  
  [&output2, &mtx](int& elem) 
  {
    if (elem % 2 == 0) 
    {
      std::lock_guard<std::mutex> lock(mtx);
      output2.push_back(elem);
    }
  });
  auto end_seq = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration_seq = end_seq - start_seq;


  std::cout << "\033[1mSequential: \033[0m" << std::endl;
  std::cout << "Execution time: " << duration_seq.count() << " seconds\n" << std::endl;

  std::cout << "\033[1mParallel: \033[0m" << std::endl;
  std::cout << "Execution time: " << duration_par.count() << " seconds\n" << std::endl;


}  