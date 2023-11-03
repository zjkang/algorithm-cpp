// https://cplusplus.com/reference/iterator/

// Input (Read)    <-- Forward   <-- Bidirectional  <-- Random Access

// Output (Write)

// begin, end, prev, next, back_inserter
int foo[] = {10,20,30,40,50};
std::vector<int> bar;
// iterate foo: inserting into bar
for (auto it = std::begin(foo); it!=std::end(foo); ++it) {
    bar.push_back(*it);
}

// distance

// adv(iterator, step);

