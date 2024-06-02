// Include necessary libraries
#include <dlib/clustering.h>
#include <dlib/rand.h>
#include <iostream>
#include <fstream>
#include <csv-parser/csv.hpp>

using namespace std;
using namespace dlib;

int main() {
    // Define the type of data we are dealing with
    typedef matrix<double,2,1> sample_type;

    // Define the type of the kernel
    typedef radial_basis_kernel<sample_type> kernel_type;

    // Now we make objects to contain our samples and their respective labels
    std::vector<sample_type> samples;
    std::vector<double> labels;

    // Read the CSV file and populate the samples vector
    io::CSVReader<2> in("Mall_Customers.csv");
    double annualIncome, spendingScore;
    while(in.read_row(annualIncome, spendingScore)){
        sample_type m;
        m(0) = annualIncome;
        m(1) = spendingScore;
        samples.push_back(m);
    }

    // Now we are making a typedef for the kind of clustering algorithm we are going to use.
    typedef kkmeans<kernel_type> test_type_kkmeans;

    // We are doing 5-means clustering in this example. So the second argument to the 
    // kkmeans object is 5. This algorithm will run the k-means clustering algorithm 
    // and determine the best set of 5 cluster centers to match our data.
    test_type_kkmeans test(5);

    // Run the k-means algorithm on our set of samples. 
    pick_initial_centers(5, initial_centers, samples, test.get_kernel());
    test.train(samples, initial_centers);

    // Now we output the result
    for (unsigned long i = 0; i < samples.size(); ++i)
    {
        cout << "Sample " << i << " is in cluster " << test(samples[i]) << endl;
    }

    return 0;
}