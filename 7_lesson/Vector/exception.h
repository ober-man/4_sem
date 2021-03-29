using std::string;

class Exception
{
    private:
        string error;

    public:
        Exception(string s);
        string what() const noexcept;
};

Exception::Exception(string s)
{
    error = s;
}

string Exception::what() const noexcept
{
    return error;
}

