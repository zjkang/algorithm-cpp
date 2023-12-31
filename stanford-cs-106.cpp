stanford cs 106B & 106L courses


// -------------------------------------------------------
// streams

// stream state bits

// convert strings to integers
int stringToInteger(const string& str) {
  istringstream iss(str);
  int result; char remain;
  if (!(iss >> result) || (iss >> remain)) {
    throw domain_error();
  }
  return result;
}

// reason why >> cout is nightmare
// 
string name;
getline(cin, name);


// -------------------------------------------------------
// types
unsigned_int: using size_t
string str = "hello world";
for (size_t i = 0; i < str.size(); i++) {
  cout << str[i] << endl;
}

// TODO: !!!bugs, what's the best way to fix it?
// str.size() - 1 is negative for unsigned int, causing an unpreditable & large number as unsigned int
for (size_t i = 1; i < str.size() - 1; i++) {
  result += str[i];
}


// using type alias
// when a type name is too long and simple alias makes code more readable. 
// common name within each class; e.g., 
// vector::iterator, map::iterator, string::iterator
// vector::reference, map::reference, string::reference
// e.g.,
using map_iterator = std::unordered_map<forward_list<Student>, unordered_set>::const_iteraotr;
map_iterator begin = studentMap.cbegin();
map_iterator end = studentMap.cbegin();


// auto: tricky auto gotchas
auto begin = studentMap.cbegin();

// return type: string, notice can't use auto for parameter
auto calculateSum(const vector<string>& v) {
  // TODO: c string vs c++ string
  auto name = "Avery"; // char* (c string)
  string name = "Avery"; // convert c string to c++ string
  auto betterName1 = string{"Avery"}; // string
  const auto$ betterName2 = string{"Avery"}; // const string&
  auto copy = v; // vector<string>
  auto& refMul = mutiplier; // double&
  auto func = [](auto i) {return i*2}; // lambda function

  return betterName;
}

// make_pair/tuple (c++11) automatically deduces the type!
pair<int, int> findPriceRange(int dist) {
  int min = static_cast<int>(dist * 0.08 + 100);
  int max = static_cast<int>(dist * 0.36 + 750);
  return make_pair(min, max);
}
pair<int, int> p = findPriceRange(dist);
p.first; p.second;
// c++ 17 allows structured bindings, unpack the variables in a pair
auto [min, max] = findPriceRange(dist);

// initializer constructor
// initializer list


// std::vector
vector<int> arr;
arr.push_back(1);
// arr[100] does not throw out_of_range exception, whereas it returns unexpected value (0)

deque<int> deque;

map<string, int> freqMap;
freqMap[k]; // not exist: defalut initialize it 
freqMap.get(k); // not exist: throw an exception

freqMap.count(response); // return 0, 1 or multiple duplicated keys
freqMap.containsKey(response); // C++20

































