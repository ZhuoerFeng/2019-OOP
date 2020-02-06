#include "friday.h"

void Friday::print_extra_info() {
    if (!get_size()) {
        std::cout << "Friday is Free :)\n";
    } else {
        std::cout << "Friday is Busy :(\n";
    }
}