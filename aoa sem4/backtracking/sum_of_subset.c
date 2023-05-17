// #include <stdio.h>
// #include <stdbool.h>

// bool isSubsetSum(int set[], int n, int sum)
// {
// 	if (sum == 0)
// 		return true;
// 	if (n == 0 && sum != 0)
// 		return false;

// 	if (set[n - 1] > sum)
// 		return isSubsetSum(set, n - 1, sum);

// 	return isSubsetSum(set, n - 1, sum) || isSubsetSum(set, n - 1, sum - set[n - 1]);
// }

// int main()
// {
// 	int set[] = { 3, 34, 4, 12, 5, 2 };
// 	int sum = 9;
// 	int n = sizeof(set) / sizeof(set[0]);
// 	if (isSubsetSum(set, n, sum) == true)
// 		printf("Found a subset with given sum");
// 	else
// 		printf("No subset with given sum");
// 	return 0;
// }

#include <stdio.h>

void subsetSum(int set[], int n, int target, int subset[], int subsetSize, int sum) {
    if (sum == target) {
        // Print the subset
        printf("Subset found: ");
        for (int i = 0; i < subsetSize; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }

    if (sum > target || n == 0) {
        return;
    }

    // Exclude the current element and move to the next one
    subsetSum(set, n - 1, target, subset, subsetSize, sum);

    // Include the current element and move to the next one
    subset[subsetSize] = set[n - 1];
    subsetSum(set, n - 1, target, subset, subsetSize + 1, sum + set[n - 1]);
}

void findSubsets(int set[], int n, int target) {
    int subset[n];
    subsetSum(set, n, target, subset, 0, 0);
}

int main() {
    int set[] = {1, 2, 3, 4, 5};
    int n = sizeof(set) / sizeof(set[0]);
    int target = 7;

    printf("Subsets with sum %d:\n", target);
    findSubsets(set, n, target);

    return 0;
}
