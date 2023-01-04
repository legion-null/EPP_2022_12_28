#pragma once

#include <base/Interface/Interface.h>

namespace Epp {
namespace usefulInterface {

template<class E>
class OptionalImplementation: virtual public base::Interface {

EPP_CLASS_INFO
/*
#define EPP_INTERFACE_OPTIONALIMPLEMENTATION
public:

#ifdef EPP_INTERFACE_OPTIONALIMPLEMENTATION
	enum ImplementationType : i8 {
		x
	};
#endif

protected:
	static const i32 NumberOfImplementation = 2;
	static const bool ValidityOfImplementation[NumberOfImplementation];

public:
	static bool IsAvailable(ImplementationType im) {
		return ValidityOfImplementation[im];
	}

protected:
	static ImplementationType DefaultImplementationType;
	static ImplementationType InitDefaultImplementationType();

public:
	static ImplementationType GetDefaultImplementationType();
	static void SetDefaultImplementationType(ImplementationType im);

public:
	static E* GetImplementation(ImplementationType im);
	static E* GetDefaultImplementation();
*/
};

template<class E>
const base::Class *OptionalImplementation<E>::ClassInfo = base::Class::Register<OptionalImplementation<E>, base::Interface>(
		"Epp::usefulInterface::OptionalImplementation<?>:后面加上E的类型（递归方式添加）", nullptr);

}
}
