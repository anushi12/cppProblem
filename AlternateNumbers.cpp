vector<int> alternateNumbers(vector<int>& a) {
    // Create two vectors to hold the positive and negative integers respectively.
    vector<int> pos, neg;

    // Iterate over each integer in the input vector and add it to the appropriate vector.
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > 0) {
            pos.push_back(a[i]); // Add positive integers to the 'pos' vector.
        } else {
            neg.push_back(a[i]); // Add negative integers to the 'neg' vector.
        }
    }

    // If there are more positive integers than negative integers...
    if (pos.size() > neg.size()) {
        // Iterate over the negative integers and alternate them with the positive integers.
        for (int i = 0; i < neg.size(); i++) {
            a[2 * i] = pos[i]; // Place the positive integer at even indices.
            a[2 * i + 1] = neg[i]; // Place the negative integer at odd indices.
        }

        // If there are any remaining positive integers, append them to the end of the vector.
        int index = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++) {
            a[index] = pos[i];
            index++;
        }
    }
    // If there are more negative integers than positive integers...
    else {
        // Iterate over the positive integers and alternate them with the negative integers.
        for (int i = 0; i < pos.size(); i++) {
            a[2 * i] = pos[i]; // Place the positive integer at even indices.
            a[2 * i + 1] = neg[i]; // Place the negative integer at odd indices.
        }

        // If there are any remaining negative integers, append them to the end of the vector.
        int index = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++) {
            a[index] = neg[i];
            index++;
        }
    }

    // Return the modified input vector.
    return a;
}
