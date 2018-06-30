#include <iostream>
#include <map>
#include <string>
#include <iterator>

using namespace std;

//------Functions-------------

// Custom comparator for our map
struct cmp_string_length {
    bool operator()(const std::string& a, const std::string& b) const {
        return a.length() < b.length();
    }
};

void print_map(const map<string,int>& in_map);
void print_map_range(const map<string,int>& in_map);
void print_map_comp(const map<string,int,cmp_string_length>& in_map);

/*
 * std::map is an associative container which hold a key,value pair
 * Implemented using Red-Black Trees
 *
 * Insertion: O(log n)
 * Lookup   : O(log n)
 * Deletion : O(log n)
 *
 */

int main()
{

    // Creating a std::map and adding data to it
    std::map<string,int> map;
    map.insert(std::make_pair("First",1));
    map.insert(std::make_pair("Second",2));
    map.insert(std::make_pair("Third",2));
    map.insert(std::make_pair("Fourth",3));

    print_map_range(map);
    cout<<"Size of the map: "<<map.size()<<endl;
    cout<<endl;

    // finding the value using key in std::map
    // 'find' function gives the iterator to the given key.
    auto find = map.find("First");
    cout<<"Finding the key in the map : "<<find->first<<" "<<find->second<<endl;
    cout<<endl;

    // removing an item in the std::map using 'erase' function
    auto remove_iter = map.find("Third");
    map.erase(remove_iter);
    print_map_range(map);
    cout<<endl;

    // std::map doesn't hold data with same key
    std::map<string,int> same_key_map;
    same_key_map.insert(std::make_pair("First",1));
    same_key_map.insert(std::make_pair("First",2));

    print_map_range(same_key_map);
    cout<<"Size of the map: "<<same_key_map.size()<<endl;
    cout<<endl;

    // Using custom comparator for the map
    std::map<string,int,cmp_string_length> map_custom_sorted;

    map_custom_sorted.insert(std::make_pair("A",1));
    map_custom_sorted.insert(std::make_pair("BB",2));
    map_custom_sorted.insert(std::make_pair("CCC",2));
    map_custom_sorted.insert(std::make_pair("DDDD",3));

    print_map_comp(map_custom_sorted);

    return 0;
}

// Prints the value of a given map with custom comparator
void print_map_comp(const map<string,int,cmp_string_length>& in_map)
{
    auto iter = in_map.begin();
    while(iter != in_map.end())
    {
        cout<<iter->first<<" "<<iter->second<<endl;
        iter++ ;
    }

}

// Prints the value of a given map
void print_map(const map<string,int>& in_map)
{
    auto iter = in_map.begin();
    while(iter != in_map.end())
    {
        cout<<iter->first<<" "<<iter->second<<endl;
        iter++ ;
    }

}

// Using range based for loop for printing values of a map
void print_map_range(const map<string,int>& in_map)
{
    for(auto val : in_map)
    {
        cout<<val.first<<" "<<val.second<<endl;
    }
}
