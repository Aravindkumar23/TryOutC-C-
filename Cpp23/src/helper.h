#pragma once

#include <string>

class Helper {
public:
	Helper() = default;
	explicit Helper(std::string name);

	// call() is marked `const` because it does not modify any observable
	// state of the Helper object. Marking member functions `const`:
	//  - Documents the API contract: callers know this won't change the object.
	//  - Allows the method to be called on `const` instances:
	//      const Helper h("x"); h.call(); // OK
	//  - Enables certain compiler optimizations and stronger static checks.
	void call() const;

	// Accessor that returns the stored name. It's `const` for the same reason
	// as above: observing state does not modify it.
	std::string name() const;

private:
	// The object's state. Non-const because it is owned mutable state.
	std::string m_name;
};