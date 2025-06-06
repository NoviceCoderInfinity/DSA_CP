// Insertion Sort
// Time Complexity: O(n log n)
// Space Complexity: O(n)
class MedianFinder {
    vector<int> elements;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (elements.empty()) {elements.push_back(num);}
        else {elements.insert(elements.begin() + findInsertPosition(num), num);}
    }

    int findInsertPosition(int val) {
        int l = 0, r = elements.size() - 1; int m;
        while(l <= r) {
            m = (r - l) / 2 + l;
            if (elements[m] == val) {return m;}
            else if (elements[m] > val) {r = m - 1;}
            else {l = m + 1;}
        }
        return (elements[m] > val ? m : m + 1);
    }
    
    double findMedian() {
        int n = elements.size();
        return (n & 1  ?  elements[n/2]  :  ((double)(elements[n/2 - 1] + elements[n/2])*0.5));
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
