#pragma once

#include <functional>
#include <map>
#include <memory>
#include <string>
#include <vector>


class Algorithm;

class AlgorithmRegistry {
public:
    using AlgorithmFactory = std::function<std::unique_ptr<Algorithm>()>;

    static AlgorithmRegistry& instance() {
        static AlgorithmRegistry registryInstance;
        return registryInstance;
    }

    void registerAlgorithm(const std::string& name, AlgorithmFactory factory) {
        factories[name] = std::move(factory);
    }

    std::unique_ptr<Algorithm> createAlgorithm(const std::string& name) {
        return factories[name]();
    }

    std::vector<std::string> getAvailableAlgorithms() {
        std::vector<std::string> names;
        for (const auto& pair : factories) {
            names.push_back(pair.first);
        }
        return names;
    }

private:
    std::map<std::string, AlgorithmFactory> factories{};
    AlgorithmRegistry() = default;
};
