class MedianFinder {
    public:
        /** initialize your data structure here. */
        priority_queue <int> left;
        priority_queue <int, vector<int>, greater<int>> right;
        MedianFinder() {
            
        }
        
        void addNum(int val) {
            if(size() == 0) {
                left.push(val);
            }
            else if(left.size() > 0 && val <= left.top()) {
                left.push(val);
            }
            else {
                right.push(val);
            }
            
            // balance
            if(left.size() + 2 == right.size()) { // left is small
                left.push(right.top());
                right.pop();
            }
            else if(right.size() + 2 == left.size()) { // right is small
                right.push(left.top());
                left.pop();
            }
        }
        
        double findMedian() {
            if(size() == 0) {
                cout<<"Underflow"<<endl;
                return -1;
            }
            
            if(left.size() > right.size()) {
                return left.top()*1.0;
            }
            else if(left.size() == right.size()){
                return (left.top()*1.0+right.top()*1.0)/2;
            }
            else {
                return right.top()*1.0;
            }
            
        }
        int size() {
            return left.size() + right.size();
        }
    };
    
    /**
     * Your MedianFinder object will be instantiated and called as such:
     * MedianFinder* obj = new MedianFinder();
     * obj->addNum(num);
     * double param_2 = obj->findMedian();
     */