#include <stdio.h>

/* Counts no. of page faults */
int pageFaults(int n, int c, int pages[]) {
    // Initialise count to 0
    int count = 0;

    // To store elements in memory of size c
    int v[c];

    // To store frequency of pages
    int mp[100];  // Assuming the maximum page number is 100

    int i, j, k;

    for (i = 0; i < 100; i++) {
        mp[i] = 0;
    }

    for (i = 0; i < c; i++) {
        v[i] = -1;
    }

    for (i = 0; i <= n - 1; i++) {
        // Find if element is present in memory or not
        int found = 0;
        for (j = 0; j < c; j++) {
            if (v[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // If element is not present
        if (!found) {
            // If memory is full
            if (k == c) {
                int min_freq = mp[v[0]];
                int min_index = 0;

                // Find the least frequently used page
                for (k = 1; k < c; k++) {
                    if (mp[v[k]] < min_freq) {
                        min_freq = mp[v[k]];
                        min_index = k;
                    }
                }

                // Decrease the frequency
                mp[v[min_index]]--;

                // Remove the least frequently used page
                v[min_index] = pages[i];
                mp[pages[i]]++;

                // Increment the count
                count++;
            } else {
                // Add the element at the end of memory
                v[c++] = pages[i];
                // Increase its frequency
                mp[pages[i]]++;

                // Increment the count
                count++;
            }
        } else {
            // If element is present
            // Increase its frequency
            mp[pages[i]]++;

            // Move the element to the end
            for (k = j; k < c - 1; k++) {
                v[k] = v[k + 1];
            }

            v[c - 1] = pages[i];
        }

        // Compare frequency with other pages
        // starting from the 2nd last page
        k = c - 2;

        // Sort the pages based on their frequency
        // And time at which they arrive
        // if frequency is same
        // then, the page arriving first must be placed
        // first
        while (mp[v[k]] > mp[v[k + 1]] && k > -1) {
            // Swap pages
            int temp = v[k];
            v[k] = v[k + 1];
            v[k + 1] = temp;

            k--;
        }
    }

    // Return total page faults
    return count;
}

/* Driver program to test pageFaults function*/
int main() {
    int pages[] = {1, 2, 3, 4, 2, 1, 5};
    int n = 7, c = 3;

    printf("Page Faults = %d\n", pageFaults(n, c, pages));
    printf("Page Hits = %d\n", n - pageFaults(n, c, pages));

    return 0;
}
