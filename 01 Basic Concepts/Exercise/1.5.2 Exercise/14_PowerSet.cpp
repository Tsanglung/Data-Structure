//If S is a set of n element, the powerset of S is the set of all possible subsets of S.
#include <iostream>
#include <vector>
using namespace std;

// Generate powerset with subsets sorted by size
void powerset(const vector<char>& set, vector<char>& currentSubset, int index, bool& isFirst, int targetSize) {
    // 當前子集達到目標大小時輸出
    if (currentSubset.size() == targetSize) {
        if (!isFirst) {
            cout << ", "; // 不是第一個子集時，前面加逗號
        }
        cout << '(';
        for (size_t i = 0; i < currentSubset.size(); i++) {
            cout << currentSubset[i];
            if (i < currentSubset.size() - 1) 
                cout << ","; // 元素之間加逗號
        }
        cout << ')';
        isFirst = false; // 標記已經輸出過子集
        return;          // 返回，避免繼續遞迴
    }
    // 基準情況：已處理完所有元素，直接返回
    if (index == set.size()) return;
    // 1. 選擇當前元素，加入子集後遞迴處理下一個元素
    currentSubset.push_back(set[index]);
    powerset(set, currentSubset, index + 1, isFirst, targetSize);
    // 2. 回溯：移除剛剛加入的元素以返回上一層
    currentSubset.pop_back();
    // 3. 不選擇當前元素，遞迴處理下一個元素
    powerset(set, currentSubset, index + 1, isFirst, targetSize);
}

int main() {
    vector<char> set = {'a', 'b', 'c'}; // 原始集合
    vector<char> currentSubset;        // 當前子集
    bool isFirst = true;               // 用於控制是否為第一個子集
    cout << '{';

    // 根據子集大小逐層輸出
    for (int targetSize = 0; targetSize <= set.size(); targetSize++) {
        powerset(set, currentSubset, 0, isFirst, targetSize);
    }

    cout << '}' << endl;
    return 0;
}
