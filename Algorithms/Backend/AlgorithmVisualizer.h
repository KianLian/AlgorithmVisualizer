#pragma once
#include <memory>
#include "../Algorithm.h"

class AlgorithmRegistry;

class AlgorithmVisualizer {
public:
    void initializeAlgorithms();
    void renderUi();

    void runStep() ;
    private:
  std::unique_ptr<Algorithm>  currentAlgorithm;
    float _speed = 1;
    float _speedSlider = 1;
    double _lastStepTime = 0;

    bool _isRunning;
};
