#include <iostream>
#include <memory>
#include <string>

class Trace
{
public:
    explicit Trace(std::string name)
        : name_{std::move(name)}
    {
        std::cout << "construiu " << name_ << '\n';
    }

    ~Trace()
    {
        std::cout << "destruiu " << name_ << '\n';
    }

    void use() const
    {
        std::cout << "usando " << name_ << '\n';
    }

private:
    std::string name_;
};

int main()
{
    Trace direct{"objeto direto"};
    direct.use();

    auto owned = std::make_unique<Trace>("unique_ptr");
    owned->use();

    Trace* observer = owned.get();
    observer->use();

    std::cout << "fim do escopo de main\n";
}

