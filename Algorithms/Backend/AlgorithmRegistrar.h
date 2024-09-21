#pragma once
#include "../Algorithm.h"

template <typename AlgorithmType>
class AlgorithmRegistrar {
public:
    explicit AlgorithmRegistrar(const std::string& name) {
        Algorithm::registerAlgorithm(name, []() {
            return std::make_unique<AlgorithmType>();
        });
    }
};
