class MyClass {
private:
    ~MyClass() {
        // Destructor code
    }

public:
    static void destroyObject(MyClass* obj) {
        delete obj; // Controlled deletion
    }
};

int main() {
    MyClass* obj = new MyClass();
    MyClass::destroyObject(obj); // Use static method to delete the object
    return 0;
}
