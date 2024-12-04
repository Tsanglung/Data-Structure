//If S is a set of n element, the powerset of S is the set of all possible subsets of S.
#include <iostream>
#include <vector>
using namespace std;

// Generate powerset with subsets sorted by size
void powerset(const vector<char>& set, vector<char>& currentSubset, int index, bool& isFirst, int targetSize) {
    // ��e�l���F��ؼФj�p�ɿ�X
    if (currentSubset.size() == targetSize) {
        if (!isFirst) {
            cout << ", "; // ���O�Ĥ@�Ӥl���ɡA�e���[�r��
        }
        cout << '(';
        for (size_t i = 0; i < currentSubset.size(); i++) {
            cout << currentSubset[i];
            if (i < currentSubset.size() - 1) 
                cout << ","; // ���������[�r��
        }
        cout << ')';
        isFirst = false; // �аO�w�g��X�L�l��
        return;          // ��^�A�קK�~�򻼰j
    }
    // ��Ǳ��p�G�w�B�z���Ҧ������A������^
    if (index == set.size()) return;
    // 1. ��ܷ�e�����A�[�J�l���Ỽ�j�B�z�U�@�Ӥ���
    currentSubset.push_back(set[index]);
    powerset(set, currentSubset, index + 1, isFirst, targetSize);
    // 2. �^���G�������[�J�������H��^�W�@�h
    currentSubset.pop_back();
    // 3. ����ܷ�e�����A���j�B�z�U�@�Ӥ���
    powerset(set, currentSubset, index + 1, isFirst, targetSize);
}

int main() {
    vector<char> set = {'a', 'b', 'c'}; // ��l���X
    vector<char> currentSubset;        // ��e�l��
    bool isFirst = true;               // �Ω󱱨�O�_���Ĥ@�Ӥl��
    cout << '{';

    // �ھڤl���j�p�v�h��X
    for (int targetSize = 0; targetSize <= set.size(); targetSize++) {
        powerset(set, currentSubset, 0, isFirst, targetSize);
    }

    cout << '}' << endl;
    return 0;
}
