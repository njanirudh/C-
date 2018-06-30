#include <iostream>
#include <map>
#include <iterator>
#include <string>

using namespace std;


//--------------Functions-----------------
void print_map_range(const multimap<int,string>& in_map);


/*
 * std::multimap are special types of associative containers which can hold
 * multiple keys of same value.
 * Internally their elements sorted by key following the criterion specified
 * in the comparator Obj
 */

int main()
{

    // Simple initialization of a std::multimap and adding data to it
    std::multimap<int,string> multimap_basic;
    multimap_basic.insert(std::make_pair<int,string>(2,"B"));
    multimap_basic.insert(std::make_pair<int,string>(2,"C"));
    multimap_basic.insert(std::make_pair<int,string>(1,"A"));
    multimap_basic.insert(std::make_pair<int,string>(3,"D"));

    print_map_range(multimap_basic);
    cout<<endl;

    // Finding a value for given key in the multimap
    // https://stackoverflow.com/questions/12495243/c-stl-multimap-equal-range
    auto find_iters = multimap_basic.equal_range(2);

    auto beginning_iter = find_iters.first; // First iterator where key is found
    auto end_iter = find_iters.second; // Last iterator of the given key

    while(beginning_iter != end_iter)
    {
        cout<<beginning_iter->second<<endl;
        beginning_iter++;
    }
    cout<<endl;

    // Deleting a specific key from a multimap
    // 'erase' function can be used to remove a single key , multiple keys or iterator range
    multimap_basic.erase(2);
    print_map_range(multimap_basic);
    cout<<endl;

    return 0;
}


// Using range based for loop for printing values of a multimap
void print_map_range(const multimap<int,string>& in_map)
{
    for(auto val : in_map)
    {
        cout<<val.first<<" "<<val.second<<endl;
    }
}
