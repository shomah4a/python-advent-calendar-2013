#include <string>
#include <iostream>
#include <boost/python.hpp>


#define self (*this) // !important


const std::string output(const std::string str)
{
    std::cout << str << std::endl;

    return str;
}



class SomeObject
{
private:
    int value;

public:
    SomeObject(const int x) : value(x) {}
    SomeObject(const SomeObject& r) : value(r.value) {}

    const int get_value() const
    {
        return self.value;
    }

    void set_value(const int x)
    {
        self.value = x;
    }
};


BOOST_PYTHON_MODULE(hello)
{
    namespace python = boost::python;

    python::def("output", output);

    python::class_<SomeObject>("SomeObject", python::init<const int>())
        .def("get_value", &SomeObject::get_value)
        .def("set_value", &SomeObject::set_value);

}
