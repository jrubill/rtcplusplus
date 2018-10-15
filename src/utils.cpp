#include "utils.h"

namespace utils {
float clamp(const float &val, const float &low, const float &high) {
    if (val < low) return low;
    if (val > high) return high;
    return val;
} 
}
