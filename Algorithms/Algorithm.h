
#pragma once
#include "Backend/AlgorithmRegistry.h"

enum class  VisualizationType : uint8_t {
    renderBars,
    renderCircles,
};

class Algorithm {
public:
    virtual ~Algorithm() = default;

    virtual void step() = 0;
    virtual void render() = 0;
    virtual bool isComplete() const = 0;
    virtual void reset() = 0;
    virtual void randomizeData(std::vector<int>& data, int size)=0;
    static void registerAlgorithm(const std::string& name, std::function<std::unique_ptr<Algorithm>()> func) {
        AlgorithmRegistry::instance().registerAlgorithm(name, std::move(func));}
};

