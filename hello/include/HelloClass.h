

class HelloClass final {
private:
    int id = 0;

public:
    HelloClass() = default;
    ~HelloClass() = default;

    void SayHello(void) const;
};
