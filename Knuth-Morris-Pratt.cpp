#include <iostream>
#include <vector>
using namespace std;

// Function to compute the prefix function for the KMP algorithm
vector<int> computePrefixFunction(const string& pattern){

    int m = pattern.length();
    vector<int> prefix(m);

    prefix[0] = 0;
    int k = 0;
    for (int q = 1; q < m; q++)
    {
        while (k > 0 && pattern[k] != pattern[q])
            k = prefix[k - 1];

        if (pattern[k] == pattern[q])
            k++;

        prefix[q] = k;
    }

    return prefix;
}

// Function to find the occurrence of the pattern in the given string using the KMP algorithm
int KMP(const string& text, const string& pattern){

    int n = text.length();
    int m = pattern.length();

    vector<int> prefix = computePrefixFunction(pattern);

    int q = 0;
    for (int i = 0; i < n; i++)
    {
        while (q > 0 && pattern[q] != text[i])
            q = prefix[q - 1];

        if (pattern[q] == text[i])
            q++;

        if (q == m)
        {
            // Pattern occurs at position i - m + 1
            return i - m + 1;
        }
    }

    // Pattern does not occur in the text
    return -1;
}

void printEmptySpaces(int pos){
    for(int i = 0;i<pos;i++){
        cout << " ";
    }
}

void printOccuredPattern(string text,string pattern, int pos){

    
    cout << text << endl;
    
    printEmptySpaces(pos); cout << "↑"<<endl;
    
    printEmptySpaces(pos); cout << pattern << endl;
    
}


void find(string text, string pattern){

    cout << endl;

    int pos = KMP(text, pattern);

        printOccuredPattern(text,pattern,pos);

    if (pos != -1)
        cout << "Pattern found at position: " << pos << endl;
    else
        cout << "Pattern not found" << endl;

    cout << "--------------------------------------------------------"<< endl;
    
}

void demo(){

    find("60Zlt7GC7vOmwbgxb7fP27y5HH1ZtsrXrdG3tKm9SsBZWPjAA0","27y");
    find("0pgka7ZqslK3SFNvB7yI2Ha1gtgLukyvLgvu28qqpRQTflJHnl","qqp");
    find("hfL4sh0Dl3737N1cpMmBzVRnr0PJTWwai6dWqlbpMn5ds0jaQP","Mn5");
    find("6Oaagq9IRz5l4um6eS6HVXl2luXGVtUaVfyeowBV2BE2YLVPs0","luX");
    find("XiFPYDARWRc2Qsv9FwWwc5yXAOnbKgJPb30mrP8uZk0z2enZb5","mrP");

}

int main(){

    demo();

    return 0;
}
