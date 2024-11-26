class Singleton {
private:
    // Private constructor to prevent instantiation from outside the class
    Singleton() {}

    // Delete copy constructor and assignment operator to prevent copying
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Static instance of the class
    static Singleton* instance;

public:
    // Static method to provide access to the single instance
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
};

// Initialize the static member variable
Singleton* Singleton::instance = nullptr;
