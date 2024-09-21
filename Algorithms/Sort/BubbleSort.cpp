//
// Created by aftom on 18/09/2024.
//

#include "BubbleSort.h"

#include <iostream>

void BubbleSort::step() {
    if (i >= data.size()) {
        complete = true;
        return;
    }
    if (j < data.size() - i - 1) {
        std::cout << "Swapping: " << data[j] << " and " << data[j + 1] << std::endl;
        if (data[j] > data[j + 1]) {
            std::swap(data[j], data[j + 1]);
        }
        j++;
    } else {
        j = 0;
        i++;
    }
}

bool BubbleSort::isComplete() const {
    return complete;
}
