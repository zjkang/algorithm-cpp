Constructors

// Uniform Initialization
Student::Student() : name{“”}, age{0}, state{“”} {}
Student::Student(string name, int age, string state) : name{name}, age{name}, state{state} {}


Destructors


Template Class
template<typename First, typename Second>
struct MyPair { 
  First first;
  Second second;
};

Templates don’t emit code until instantiated, so include the .cpp in the .h instead of the other way around!
template<class First, typename Second>
First MyPair<First, Second>::getFirst(){
  return first; 
}

// using type_name = type


