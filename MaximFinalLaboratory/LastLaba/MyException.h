#ifndef MYEXCEPTION
#define MYEXCEPTION

class MyException : public std::exception {
    std::string message;
    public:
        MyException(std::string const &what_arg) : message(what_arg) {}
        MyException(char const * what_arg) : message(what_arg) {}
        virtual const char *what() const noexcept override {
            return message.c_str();
        }
};

#endif