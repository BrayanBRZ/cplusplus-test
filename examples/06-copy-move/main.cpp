#include <iostream>
#include <string>
#include <utility>

class Message
{
public:
    explicit Message(std::string text)
        : text_{std::move(text)}
    {
        std::cout << "construtor\n";
    }

    Message(const Message& other)
        : text_{other.text_}
    {
        std::cout << "copy constructor\n";
    }

    Message(Message&& other) noexcept
        : text_{std::move(other.text_)}
    {
        std::cout << "move constructor\n";
    }

    Message& operator=(const Message& other)
    {
        std::cout << "copy assignment\n";
        text_ = other.text_;
        return *this;
    }

    Message& operator=(Message&& other) noexcept
    {
        std::cout << "move assignment\n";
        text_ = std::move(other.text_);
        return *this;
    }

    const std::string& text() const
    {
        return text_;
    }

private:
    std::string text_;
};

int main()
{
    Message original{"conteudo"};
    Message copied{original};
    Message moved{std::move(original)};

    std::cout << "copied = " << copied.text() << '\n';
    std::cout << "moved = " << moved.text() << '\n';
}

