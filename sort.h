#ifndef SORT_H_
#define SORT_H_

#include <vector>
#include <algorithm>
#include "DLinkedList.h"

namespace sort {
    template <typename T>
    void bubbleSort(std::vector<T>* arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
            std::swap(arr[j], arr[j + 1]);
        }
        }
    }
    }

    template <typename T>
    void bubbleSort(T arr[], int size) {
    bool flag;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
        flag = false;
        if (arr[j] > arr[j + 1]) {
            std::swap(arr[j], arr[j + 1]);
            flag = true;
        }
        }
        if (flag == false) break;
    }
    }


    /* literally monkey seal clapping arf arf wrote this   */
    template <typename T>
    void RecurBubbleSort(Node<T>* curHead, Node<T>* node) {
    if (node->next == nullptr) {
        if (curHead->next == nullptr) {
        return;
        }
        else {
        RecurBubbleSort(curHead->next, curHead->next);
        }
    }
    else {
        if (node > node->next) {
        /* Manual monkey swap. 🐒🐒🐒🐒🐒🐒🐒🐒🐒🐒🐒🐒🐒🐒🐒 */
        T temp = node->data;
        node->data = node->next->data;
        node->next->data = node->data; // Shouldn't it be node->next->data = temp ?
        }
        RecurBubbleSort(curHead, node->next);
    }
    }
};

#endif // SORT_H_
