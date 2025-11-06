#include "helper.h"
#include <iostream>
#include <utility>

Helper::Helper(std::string name)
    : m_name(std::move(name))
{
}

// The following member functions are defined to match the declarations in
// the header. Note that both `call()` and `name()` are marked `const` in the
// class declaration. That qualifier appears here as well to ensure the
// definition matches the declared signature.
//
// A `const` member function promises not to modify the observable state of
// the object. The compiler enforces this at call sites and inside the body
// of the function (you cannot modify non-mutable members or call non-const
// methods without a cast). Keeping methods `const` when possible is good
// API hygiene and enables use on `const` instances.
void Helper::call() const {
    std::cout << "Helper '" << m_name << "' called from helper.cpp!" << std::endl;
}

std::string Helper::name() const {
    return m_name;
}