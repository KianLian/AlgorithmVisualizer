#pragma once
#include <imgui.h>
#include <utility>
#include <vector>
#include "../Algorithm.h"

class SortingAlgorithm : public Algorithm {
public:
    explicit SortingAlgorithm(std::vector<int> data) : data(std::move(data)), i(0), j(0), complete(false) {}

    void reset() override;

    void render() override ;

    void setVisualizationType(VisualizationType Type);
    void randomizeData(std::vector<int>& data, int size) override;

    void setData(const std::vector<int> &_data);

protected:
    std::vector<int> data {50, 30, 20, 10, 60, 80, 70, 40, 90, 100};;
    int i, j;
    bool complete = false;
    VisualizationType visualizationType;

    void renderBars();
    void renderCircles()const;

    ImVec4 interpolateColor(float t) ;
};
