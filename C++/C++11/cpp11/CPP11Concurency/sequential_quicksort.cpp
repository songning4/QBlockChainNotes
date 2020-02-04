
#include <iostream>
#include <list>
#include <random>
#include <algorithm>
#include <thread>
#include <chrono>


template<typename T>
std::list<T> sequential_quick_sort(std::list<T> input)
{
  if(input.empty())
  {
    return input;
  }
  std::list<T> result;
  result.splice(result.begin(),input,input.begin());  // 1
  T const& pivot=*result.begin();  // 2

  auto divide_point=std::partition(input.begin(),input.end(),
             [&](T const& t){return t<pivot;});  // 3

  std::list<T> lower_part;
  lower_part.splice(lower_part.end(),input,input.begin(), divide_point);  // 4
  auto new_lower( sequential_quick_sort(std::move(lower_part)));  // 5
  auto new_higher(sequential_quick_sort(std::move(input)));  // 6

  result.splice(result.end(),new_higher);  // 7
  result.splice(result.begin(),new_lower);  // 8
  return result;
}

#if 0
int main()
{
    //std::default_random_engine generator;
    std::mt19937  generator;
    //std::random_device generator;  //不确定的随机数生成器
    std::uniform_int_distribution<int> distribution(-10000, 10000);

    std::list<int> lstNumbers;
    for(int i = 0; i < 1000; i++)
    {
        lstNumbers.emplace_back( distribution(generator) );
    }

    auto startTime = std::chrono::high_resolution_clock::now();
    auto lstSorted = sequential_quick_sort<int>(lstNumbers);
    auto endTime  = std::chrono::high_resolution_clock::now();

    std::cout << "elasped time: " << (endTime - startTime).count() << std::endl;
    //std::cout << std::chrono::duration<double, std::chrono::seconds> (endTime - startTime).count()  << std::endl;

    for(auto &item : lstSorted)
    {
        std::cout << item << "\t";
    }
    std::cout << std::endl;
    
    return 0;
}
#endif