//
// Created by aftom on 18/09/2024.
//

#include "SortingAlgorithm.h"

#include <imgui.h>
#include <iostream>
#include <random>
#include <sstream>
#include <GL/glew.h>

void SortingAlgorithm::reset() {
        i = 0;
        j = 0;
        complete = false;
        // Reinitialize the data set to its original unsorted state
        data = {50, 30, 20, 10, 60, 80, 70, 40, 90, 100};

        setVisualizationType(VisualizationType::renderBars);
}

void SortingAlgorithm::render()  {
switch (visualizationType) {
        case VisualizationType::renderBars:
                renderBars();
                break;
        case VisualizationType::renderCircles:

                break;
        default:
        renderBars();
}
}

void SortingAlgorithm::setVisualizationType(VisualizationType Type) {
        visualizationType = Type;
}

void SortingAlgorithm::randomizeData(std::vector<int> &data, int size) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(10, 100);  // Values between 10 and 100

        data.clear();
        for (int i = 0; i < size; ++i) {
                data.push_back(dis(gen));
        }
}

void SortingAlgorithm::setData(const std::vector<int> &_data) {
      data = _data;
}

void SortingAlgorithm::renderBars() {


        float barWidth = 1.6875f / data.size();

        ImDrawList* draw_list = ImGui::GetForegroundDrawList();
      //  std::cout <<static_cast<float>(data.size()) << std::endl;
        for (int k = 0; k < data.size(); ++k) {

                float height = static_cast<float>(data[k]) / 100.0f;
                float x = -1.0f + k * barWidth;

                float t = static_cast<float>(data[k]) / 100.0f;
                ImVec4 color = interpolateColor(t);
                std::cout <<static_cast<float>(data[k]) << std::endl;
                glBegin(GL_QUADS);
                glColor3f(color.x, color.y, color.z);
                glVertex2f(x, -1.0f);
                glVertex2f(x + barWidth, -1.0f);
                glVertex2f(x + barWidth, height - 1.0f);
                glVertex2f(x, height - 1.0f);
                glEnd();

                std::ostringstream ss;
                ss << data[k];

                float screen_x = (x + barWidth / 2.0f + 1.0f) * (1280.0f / 2.0f);
                float screen_y = (1.0f - (height - 1.0f) + 0.05f) * (720.0f / 2.0f);

                ImU32 strokeColor = IM_COL32(0, 0, 0, 255);  // Black stroke color
                draw_list->AddText(ImVec2(screen_x - 1, screen_y), strokeColor, ss.str().c_str());  // Left
                draw_list->AddText(ImVec2(screen_x + 1, screen_y), strokeColor, ss.str().c_str());  // Right
                draw_list->AddText(ImVec2(screen_x, screen_y - 1), strokeColor, ss.str().c_str());  // Up
                draw_list->AddText(ImVec2(screen_x, screen_y + 1), strokeColor, ss.str().c_str());  // Down
                draw_list->AddText(ImVec2(screen_x - 1, screen_y - 1), strokeColor, ss.str().c_str());  // Top-left
                draw_list->AddText(ImVec2(screen_x + 1, screen_y - 1), strokeColor, ss.str().c_str());  // Top-right
                draw_list->AddText(ImVec2(screen_x - 1, screen_y + 1), strokeColor, ss.str().c_str());  // Bottom-left
                draw_list->AddText(ImVec2(screen_x + 1, screen_y + 1), strokeColor, ss.str().c_str());  // Bottom-right

                ImU32 textColor = IM_COL32(255, 255, 255, 255);
                draw_list->AddText(ImVec2(screen_x, screen_y), IM_COL32(255, 255, 255, 255), ss.str().c_str());
        }
}

void SortingAlgorithm::renderCircles() const {
}

ImVec4 SortingAlgorithm::interpolateColor(float t) {
        float r = t;
        float g = 0.0f;
        float b = 1.0f - t;
        return ImVec4(r, g, b, 1.0f);
}
