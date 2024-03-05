#include <vector>
#include <functional>
#include <iostream>

// Define a type for a condition and its associated callable action
using ConditionActionPair = std::pair<std::function<bool()>, std::function<void()>>;

class ContinuationDispatchVector {
public:
    // Constructor that accepts a list of condition-action pairs
    ContinuationDispatchVector(const std::vector<ConditionActionPair>& pairs)
        : dispatchVector(pairs), executionPtr(0) {}

    // Adds a new condition and its associated callable sequence to the dispatch vector
    void add(const std::function<bool()>& condition, const std::function<void()>& action) {
        dispatchVector.push_back({condition, action});
    }


    // Executes the current condition's associated callable action if the condition is true
    void execute() {
        if (executionPtr < dispatchVector.size() && dispatchVector[executionPtr].first()) {
            dispatchVector[executionPtr].second();
            advance();
        }
    }

    // Advances the execution pointer to the next condition
    void advance() {
        executionPtr++;
        if (executionPtr >= dispatchVector.size()) {
            reset();
        }
    }

    // Resets the execution pointer to the beginning
    void reset() {
        executionPtr = 0;
    }

private:
    std::vector<ConditionActionPair> dispatchVector; // Vector of conditions and callable actions
    size_t executionPtr; // Current execution pointer
};