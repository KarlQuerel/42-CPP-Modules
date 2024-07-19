# include "Serializer.hpp"

// Constructors & Destructors
Serializer::Serializer()
{
	std::cout << BGR SERIALIZER D_CONS;
	return ;
}

Serializer::Serializer(Serializer const & src)
{
	std::cout << BYE SERIALIZER C_CONS;
	(void) src;
	return ;
}

// Operators Overloads
Serializer &	Serializer::operator=(Serializer const & rhs)
{
	std::cout << BMA SERIALIZER ASSIGN_OP;
	(void) rhs;
	return *this;
}

Serializer::~Serializer()
{
	std::cout << BRED SERIALIZER D_DES;
	return ;
}

std::ostream & operator<<(std::ostream & output, Serializer const & rhs)
{
	std::cout << BMA SERIALIZER OUTPUT_OP;
	(void) rhs;
	return output;
}

// Non-member functions

// Methods
uintptr_t	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}