#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

#define MAX_THREADS 1 

std::mutex mtx;

unsigned long long total=0;


long long add(unsigned long lim, unsigned long start){

	unsigned long i=start;
	unsigned long long sum=0;
	
	#pragma omp parallel while reduction(+: sum)	
	while(i<=lim){
		
		sum=sum+i;
		
		i=i+1;
	}

	return sum;
}

void multiAdd(long unsigned lim, long unsigned start){
		
		mtx.lock();
		
		total=total+add(lim,start);
		
		mtx.unlock();

		return;
	}

int main(){

	unsigned long var=500000000;
		
	std::vector<std::thread> threads;
	
	auto start = std::chrono::high_resolution_clock::now();

	for(int i=0;i<MAX_THREADS;i++){
		threads.push_back(std::thread(multiAdd, (var/MAX_THREADS)*(i+1), ((var/MAX_THREADS)*i)+1));
	}

	

	for (auto &th : threads) {
   		 th.join();
  		}

	auto finish = std::chrono::high_resolution_clock::now();

	printf("%lld\n",total);
	
	std::chrono::duration<double> elapsed = finish - start;

	std::cout << "Elapsed time: "<<elapsed.count()<<" s\n";

	return 0;

}
