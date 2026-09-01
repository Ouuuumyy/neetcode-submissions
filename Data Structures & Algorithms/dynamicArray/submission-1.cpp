class DynamicArray {
private:
    std::vector<int> arr;
public:

    DynamicArray(int capacity) {
        arr.reserve(capacity);
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        arr.push_back(n);
    }

    int popback() {
        int end = arr[arr.size() - 1];
        arr.pop_back();
        return end;
    }

    void resize() {
        arr.reserve(arr.capacity() * 2);
    }

    int getSize() {
        return arr.size();
    }

    int getCapacity() {
        return arr.capacity();
    }
};
