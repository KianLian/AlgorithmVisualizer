//
// Created by aftom on 20/09/2024.
//

#include "AlgorithmVisualizer.h"

#include <imgui.h>
#include <iostream>
#include <GLFW/glfw3.h>

#include "AlgorithmRegistry.h"
#include "../Algorithm.h"
#include "../Sort/SortingAlgorithm.h"

void AlgorithmVisualizer::initializeAlgorithms() {

}

void AlgorithmVisualizer::renderUi() {
    ImGui::SetNextWindowPos(ImVec2(1280 - 200, 0));  // Right side, adjust window width as needed
    ImGui::SetNextWindowSize(ImVec2(200, 720));

    ImGui::Begin("Control Panel", nullptr, ImGuiWindowFlags_NoResize );

    std::vector<std::string> algorithms = AlgorithmRegistry::instance().getAvailableAlgorithms();
    for (const auto& algorithmName : algorithms) {
        if (ImGui::Button(algorithmName.c_str())) {
            currentAlgorithm = AlgorithmRegistry::instance().createAlgorithm(algorithmName);
            std::cout << "Selected Algorithm: " << algorithmName << std::endl;  // Debug output
        }
    }

    if (ImGui::Button("Start")) {
        _isRunning = true;
    }

    if (ImGui::Button("Pause")) {
        _isRunning = false;
    }

    if (ImGui::Button("Reset")) {
        if (currentAlgorithm) {
            currentAlgorithm->reset();
        }
        _isRunning = false;
    }

    if(ImGui::SliderFloat("Speed", &_speedSlider, 1.f, 550.0f, "Speed = %.1f")){
        _speed = _speedSlider / 10.0f;
    }

    if (currentAlgorithm && dynamic_cast<SortingAlgorithm*>(currentAlgorithm.get())) {
        // Handle sorting-specific settings
        static bool manualEntry = false;
        static int numElements = 10;
        static std::vector<int> data(numElements);

        ImGui::SliderInt("Number of Elements", &numElements, 5, 100);

        if (ImGui::Button("Randomize Data")) {
           currentAlgorithm->randomizeData(data, numElements);
            // Assign the data to the algorithm
            if (auto* sortingAlgo = dynamic_cast<SortingAlgorithm*>(currentAlgorithm.get())) {
                sortingAlgo->setData(data);
            }
        }

        ImGui::Checkbox("Manual Entry", &manualEntry);
        if (manualEntry) {
            for (int i = 0; i < numElements; ++i) {
                std::string label = "Element " + std::to_string(i);
                ImGui::InputInt(label.c_str(), &data[i]);
            }
        }


    }

    if (currentAlgorithm) {
        currentAlgorithm->render();
    }

    ImGui::End();
}

void AlgorithmVisualizer::runStep() {
    if (_isRunning && currentAlgorithm && !currentAlgorithm->isComplete()) {
        double _currentTime = glfwGetTime();
        double _deltaTime = _currentTime - _lastStepTime;

        if (_deltaTime >= (1.0f / _speed)) {
            currentAlgorithm->step();
            _lastStepTime = _currentTime;
        }
    }
}
