#pragma once
#include "SortingAlgorithm.h"
#include "../Backend/AlgorithmRegistrar.h"

class BubbleSort : public SortingAlgorithm {
    public:

    BubbleSort() : SortingAlgorithm({50, 30, 20, 10, 60, 80, 70, 40, 90, 100}) {}
    void step() override;

    bool isComplete() const override;

    private:
    static AlgorithmRegistrar<BubbleSort> registrar;

};

AlgorithmRegistrar<BubbleSort> BubbleSort::registrar("Bubble Sort");