#ifndef DE_UNISTUTTGART_FRAMEWORK_SIMPLEOBJECTCONTAINMENTLISTPROPERTY_H
#define DE_UNISTUTTGART_FRAMEWORK_SIMPLEOBJECTCONTAINMENTLISTPROPERTY_H

#include <algorithm>
#include <list>
#include <memory>
#include <functional>
#include "ObjectListView.hpp"
#include "iterators/ObjectIterator.hpp"
#include "iterators/SharedPointerListIterator.hpp"

namespace framework {

template<typename T>
class SimpleObjectContainmentListProperty final : public ObjectListView<T> {
    static constexpr bool useConstTrue = true;
    static constexpr bool useConstFalse = false;

    using iterator = ObjectIterator<T, useConstFalse>;
    using const_iterator = ObjectIterator<T, useConstTrue>;

private:

    std::list<std::shared_ptr<T>> elements;

public:

    using ListIteratorNonConst = SharedPointerListIterator<T, decltype(elements.begin()), useConstFalse>;
    using ListIteratorConst = SharedPointerListIterator<T, decltype(elements.cbegin()), useConstTrue>;
    using ListIteratorReverseNonConst = SharedPointerListIterator<T, decltype(elements.rbegin()), useConstFalse>;

    using size_type = size_t;

    std::list<std::shared_ptr<T>>& get() {
        return elements;
    }
    const std::list<std::shared_ptr<T>>& get() const {
        return elements;
    }

    bool empty() const override {
        return elements.empty();
    }

    size_t size() const override {
        return elements.size();
    }

    std::shared_ptr<T> front() override {
        if (elements.empty()) {
            return {};
        }
        return elements.front();
    }

    std::shared_ptr<T> back() override {
        if (elements.empty()) {
            return {};
        }
        return elements.back();
    }

    void push_back(std::shared_ptr<T> element) {
        elements.push_back(element);
    }

    void remove(std::shared_ptr<T> element) {
        elements.remove(element);
    }

    iterator begin() override {
        return iterator(std::make_unique<ListIteratorNonConst>(elements, elements.begin()));
    }

    iterator end() override {
        return iterator(std::make_unique<ListIteratorNonConst>(elements, elements.end()));
    }

    const_iterator cbegin() const override {
        return const_iterator(std::make_unique<ListIteratorConst>(elements, elements.cbegin()));
    }

    const_iterator cend() const override {
        return const_iterator(std::make_unique<ListIteratorConst>(elements, elements.cend()));
    }

    iterator rbegin() override {
        return iterator(std::make_unique<ListIteratorReverseNonConst>(elements, elements.rbegin()));
    }

    iterator rend() override {
        return iterator(std::make_unique<ListIteratorReverseNonConst>(elements, elements.rend()));
    }

};

}

#endif //DE_UNISTUTTGART_FRAMEWORK_SIMPLEOBJECTCONTAINMENTLISTPROPERTY_H
