#include <type_traits>

//// Constructors

// Uniform Initialization
// initializer list
Student::Student() : name{“”}, age{0}, state{“”} {}
Student::Student(string name, int age, string state) : name{name}, age{name}, state{state} {}



// The rule of 3 (
//   destructor, copy constructor, copy assignment operator defined together
//   )
//// Destructors

//// Copy constructor
Student(const Student& student) = delete; // disable copy constructor

//// Copy Assignment operator
shallow copy vs deep copy

// The rule of 5: steal the resource from the source
// Move contructor
// Move assignment operator

// friend function or friend class


// operator overloading
// operator+, operator<
// operator(): function call operator

// RAII (resource aqusition is initialization)


// The rule of 5 (
//   destructor, copy constructor, copy assignment operator defined together
//   )



// inheritance
// virtual function
// pure virtual function -> abstract class (interface)
virtual void Draw() = 0; // end with = 0;
void Draw() override {} // derived class


void ClassA::ClassA() = default; // default constrctor
void ClassA::ClassA() = delete; // do not alllow constructor by default


// initializer prevent narrowing for type conversion
// initializer_list
int a = 4;
int b(4);
int c{4};

// Value Initialization (Zero-Initialization of Member Variables)
vec3 v{}; //zero-initialization
// in-class initialier
struct Entity {
  std::string name;
  int x{4};
  int y{5};
  int* collection{nullptr};
};

// delegate the constructor
// call constructor in the constructor


// Class Data Layout (Optimizing for size)


// pIMPL (pointer to implementation)




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


