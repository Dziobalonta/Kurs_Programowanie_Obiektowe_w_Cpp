#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>

void forEachNExample()
{
  std::vector<int> vec(1'000'000, 1);

  std::for_each_n(std::execution::par, vec.begin(), 500'000, [](int& x) { x *= 2; });

  std::cout << "First element: " << vec[0] << std::endl;
  std::cout << "500000th element: " << vec[499'999] << std::endl;
}

void exclusiveScanExample()
{
  std::vector<int> vec(1'000'000, 1);
  std::vector<int> result(vec.size());

  std::exclusive_scan(std::execution::par, vec.begin(), vec.end(), result.begin(), 0);

  std::cout << "First element: " << result[0] << std::endl;
  std::cout << "Last element: " << result[999'999] << std::endl;
}

void inclusiveScanExample()
{
  std::vector<int> vec(1'000'000, 1);
  std::vector<int> result(vec.size());

  std::inclusive_scan(std::execution::par, vec.begin(), vec.end(), result.begin());

  std::cout << "First element: " << result[0] << std::endl;
  std::cout << "Last element: " << result[999'999] << std::endl;
}

void transformExclusiveScanExample()
{
  std::vector<int> vec(1'000'000, 1);
  std::vector<int> result(vec.size());

  std::transform_exclusive_scan(std::execution::par, vec.begin(), vec.end(), result.begin(), 0, std::plus<>(), [](int x) { return x * 2; });

  std::cout << "First element: " << result[0] << std::endl;
  std::cout << "Last element: " << result[999'999] << std::endl;
}

void transformInclusiveScanExample()
{
  std::vector<int> vec(1'000'000, 1);
  std::vector<int> result(vec.size());

  std::transform_inclusive_scan(std::execution::par, vec.begin(), vec.end(), result.begin(), std::plus<>(), [](int x) { return x * 2; });

  std::cout << "First element: " << result[0] << std::endl;
  std::cout << "Last element: " << result[999'999] << std::endl;
}

void reduceExample()
{
  std::vector<std::string> vec(1'000, "hello");

  auto result = std::reduce(std::execution::par, vec.begin(), vec.end(), std::string(),
  // Sposob definiowania operacji binarnej, która jest wykonywana w funkcji redukcji.
  // Jest to rodzaj funkcji lambda, która przyjmuje dwa argumenty i zwraca wynik tej operacji.
  [](auto fir, auto sec) 
  {
    return fir + ":" + sec;
  });

  std::cout << "Result: " << result.substr(0, 50) << "..." << std::endl;
}

void transformReduceExample()
{
  std::vector<std::string> vec(100'000, "hello");

  auto result = std::transform_reduce(std::execution::par, vec.begin(), vec.end(), std::string(),
  [](auto fir, auto sec) 
  {
    return fir + ":" + sec;
  },
  [](const std::string& x) 
  {
    return x + " world";
  });

  std::cout << "Result: " << result.substr(0, 50) << "..." << std::endl;
}

void forEachExample()
{
  std::vector<int> vec(1'000'000, 1);

  std::for_each(std::execution::par, vec.begin(), vec.end(), [](int& x) { x *= 2; });

  std::cout << "First element: " << vec[0] << std::endl;
  std::cout << "Last element: " << vec[999'999] << std::endl;
}

int main()
{ 
  forEachNExample();
  std::cout << std::endl;

  exclusiveScanExample();
  std::cout << std::endl;

  inclusiveScanExample();
  std::cout << std::endl;

  transformExclusiveScanExample();
  std::cout << std::endl;

  transformExclusiveScanExample();
  std::cout << std::endl;

  reduceExample();
  std::cout << std::endl;

  transformReduceExample();
  std::cout << std::endl;

  forEachExample();
  std::cout << std::endl;
  return 0;
}