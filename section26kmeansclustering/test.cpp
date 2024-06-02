#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator
    std::srand(std::time(nullptr));

    // Generate a large vector of random integers
    std::vector<int> random_vector(1000000);
    for (int& num : random_vector) {
        num = std::rand() % 1000000;
    }

    // Measure the time taken by std::sort()
    clock_t start_time = std::clock();
    std::sort(random_vector.begin(), random_vector.end());
    clock_t end_time = std::clock();
    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
    std::cout << "Time taken by std::sort(): " << time_taken << " seconds" << std::endl;

    return 0;
}
