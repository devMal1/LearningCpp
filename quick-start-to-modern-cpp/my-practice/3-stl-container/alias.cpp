#include <cstdint>
#include <vector>

// C-style
typedef std::vector<std::int8_t> ByteVectorCstyle;

// C++ Style
using ByteVectorCpp = std::vector<std::int8_t>;

// With C++ can use templates (this cannot be done with C)
template <typename T>
using VecOfInts = std::vector<T>;
