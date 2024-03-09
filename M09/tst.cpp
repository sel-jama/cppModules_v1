#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Split into pairs
vector<pair<int, int>> create_pairs(vector<int> &a) {
    vector<pair<int, int>> split_array;
    pair<int, int> temp_pair;

    for (size_t i = 0; i < a.size(); ++i) {
        if (!temp_pair.first) {
            temp_pair.first = a[i];
        } else if (!temp_pair.second) {
            temp_pair.second = a[i];
            split_array.push_back(temp_pair);
            temp_pair.first = 0;
            temp_pair.second = 0;
        } else {
            temp_pair.first = a[i];
        }
    }

    return split_array;
}

// Sort all the pairs
vector<pair<int, int>> sort_each_pair(vector<pair<int, int>> &split_array) {
    for (auto &pair : split_array) {
        if (pair.first > pair.second) {
            swap(pair.first, pair.second);
        }
    }
    return split_array;
}

// Entry function to recursively sort pairs by their higher value
void insertion_sort_pairs(vector<vector<int> > &A, int n) {
    if (n < 1) return;
    insertion_sort_pairs(A, n - 1);
    vector<int> element = A[n];
    int j = n - 1;
    while (j >= 0 && element[1] < A[j][1]) {
        A[j + 1] = A[j];
        j--;
    }
    A[j + 1] = element;
}

// Recursive function to generate nth Jacobsthal number
int jacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

// Built a sequence of valid Jacobsthal numbers, given an array length
vector<int> build_jacob_insertion_sequence(int array_len) {
    vector<int> end_sequence;
    int jacob_index = 3;

    while (jacobsthal(jacob_index) < array_len - 1) {
        end_sequence.push_back(jacobsthal(jacob_index));
        jacob_index++;
    }

    return end_sequence;
}

// Recursively sort the larger set of elements into a sorted set
void sort_by_larger_value(vector<pair<int, int>> &sorted_split_array) {
    insertion_sort_pairs(sorted_split_array, sorted_split_array.size() - 1);
}

// Create Sequence
vector<int> create_s(vector<pair<int, int>> &sorted_split_array, int straggler, bool print_comparison_estimation) {
    vector<int> S, pend;
    int comparisons_made = 0;

    for (auto &pair : sorted_split_array) {
        S.push_back(pair.second);
        pend.push_back(pair.first);
    }

    S.insert(S.begin(), pend[0]);

    int iterator = 0;
    int jacobindex = 3;
    vector<int> indexSequence = {1};
    string last = "default";

    vector<int> jacob_insertion_sequence = build_jacob_insertion_sequence(pend.size());

    while (iterator <= pend.size()) {
        if (!jacob_insertion_sequence.empty() && last != "jacob") {
            indexSequence.push_back(jacob_insertion_sequence[0]);
            int item = pend[jacob_insertion_sequence[0] - 1];
            jacob_insertion_sequence.erase(jacob_insertion_sequence.begin());
            last = "jacob";
        } else {
            if (iterator == 0 || find(indexSequence.begin(), indexSequence.end(), iterator) != indexSequence.end()) {
                iterator++;
            }
            int item = pend[iterator - 1];
            indexSequence.push_back(iterator);
            last = "not-jacob";
        }
        auto insertion_point = lower_bound(S.begin(), S.end(), item);
        S.insert(insertion_point, item);
        iterator++;
        jacobindex++;
        comparisons_made += 2;
    }

    if (straggler != -1) {
        auto insertion_point = lower_bound(S.begin(), S.end(), straggler);
        S.insert(insertion_point, straggler);
        comparisons_made += 2;
    }

    if (print_comparison_estimation) {
        cout << "Approximate Comparisons Made:" << endl;
        cout << comparisons_made << endl;
    }

    return S;
}

// Ford-Johnson Merge-Insertion Sort
vector<int> merge_insertion_sort(vector<int> &A) {
    cout << "Starting Array:" << endl;
    for (auto num : A) {
        cout << num << " ";
    }
    cout << endl;

    bool hasStraggler = A.size() % 2 != 0;
    int straggler = hasStraggler ? A[A.size() - 1] : -1;

    vector<pair<int, int>> split_array = create_pairs(A);
    vector<pair<int, int>> sorted_split_array = sort_each_pair(split_array);
    sort_by_larger_value(sorted_split_array);

    vector<int> S = create_s(sorted_split_array, straggler, true);

    cout << "Sorted Array:" << endl;
    for (auto num : S) {
        cout << num << " ";
    }
    cout << endl;

    return S;
}

int main() {
    vector<int> array = {5, 2, 6, 3, 1, 4};
    merge_insertion_sort(array);
    return 0;
}
