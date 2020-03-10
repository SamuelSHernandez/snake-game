#include "Type.h"

bool operator==(Point lhs, Point rhs) {
    return (lhs.x == rhs.x) && (lhs.y == rhs.y);
}
