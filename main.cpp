#include <iostream>
#include <vector>

using namespace std;

int main()
{
    size_t number_count = 0;


    cerr << "\nEnter number_count "<< endl;
    cin >> number_count;

    vector<double> numbers;
    numbers.resize(number_count);

    cerr << "Enter massiv:\n";
    for (size_t i=0; i<number_count; i++)
    {
        cin >> numbers[i];
    }

    size_t bins_count = 0;
    cerr <<"Enter bins_count\n";
    cin >> bins_count;

    double max = numbers[0],min = numbers[0] ;
    vector<size_t> bins (bins_count,0);
    for(double x : numbers )
    {
        if (x < min)
        {
            min = x;
        }
        else if ( x > max)
        {
            max = x;
        }
    }
    for(double number : numbers)
    {

        size_t bin_index = (number-min)*bins_count /(max-min);
        if(bin_index==bins_count)
        {
            bin_index--;
        }
        bins[bin_index]++;
    }
    const size_t MAX=80-4;
    double bin_max = bins[0];

    for(size_t bin :bins)
    {
        if(bin>bin_max)
            bin_max = bin;
    }
    double factor = 1.0;
    if (bin_max>MAX)
    {
        factor = static_cast<double>(MAX)/bin_max;
    }
    for(size_t bin :bins)
    {
        size_t height= bin *factor;

        if(bin>99)
            cout<<bin;

        else
        {
            if (bin>9)
                cout<<" "<<bin;

            else
                cout<<"  "<<bin;

        }

        cout<<'|';

        for(size_t i = 0; i < height; i++)
        {
            cout<< '*';
        }
        cout<<'\n';
    }


    return 0;
}
