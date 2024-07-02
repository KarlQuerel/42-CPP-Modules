# include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << BGR MAT_SOURCE D_CONS;
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	std::cout << BYE MAT_SOURCE C_CONS;
	for (int i = 0; i < 4; i++)
	{
		if (src._materias[i] == NULL)
			this->_materias[i] = NULL;
		else
			this->_materias[i] = src._materias[i]->clone();
	}
	return ;
}

MateriaSource::~MateriaSource()
{
	std::cout << BRED MAT_SOURCE D_DES;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] != NULL)
			delete this->_materias[i];
	}
	return ;
}

MateriaSource & MateriaSource::operator=(const MateriaSource &rhs)
{
	std::cout << BMA MAT_SOURCE ASSIGN_OP;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] != NULL)
		{
			delete this->_materias[i];
			this->_materias[i] = NULL;
		}
		if (rhs._materias[i] != NULL)
			this->_materias[i] = rhs._materias[i]->clone();
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (m == NULL)
	{
		MAT_NULL;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] == NULL)
		{
			this->_materias[i] = m;
			std::cout << BWHT << "A(n) " << m->getType() << MAT_LEARNT;
			return ;
		}
	}
	MAT_FULL;
	delete m;
	return ;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] != NULL && this->_materias[i]->getType() == type)
			return (this->_materias[i]->clone());
	}
	MAT_NOT_FOUND << type << STR_END;
	return NULL;
}
