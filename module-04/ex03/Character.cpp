# include "Character.hpp"

Character::Character() : _name("Default")
{
	std::cout << BGR CHARACTER D_CONS;
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
	return ;
}

Character::Character(Character const & src) : _name(src.getName())
{
	std::cout << BYE CHARACTER C_CONS;
	for (int i = 0; i < 4; i++)
	{
		if (src._materias[i] == NULL)
			this->_materias[i] = NULL;
		else
			this->_materias[i] = src._materias[i]->clone();
	}
	return ;
}

Character::~Character()
{
	std::cout << BRED CHARACTER D_DES;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] != NULL)
			delete this->_materias[i];
	}
	return ;
}

Character & Character::operator=(const Character &rhs)
{
	std::cout << BMA CHARACTER ASSIGN_OP;
	this->_name = rhs.getName();
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

Character::Character(std::string name) : _name(name)
{
	std::cout << BCY CHARACTER PARAM_CONS;
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
	return ;
}


std::string const & Character::getName() const
{
	return this->_name;
}

void	Character::equip(AMateria* m)
{
	if (m == NULL)
	{
		std::cout << BWHT << this->_name << MATERIA_EMP;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] == NULL)
		{
			this->_materias[i] = m;
			std::cout << BWHT << this->_name << ": A(n) " << m->getType() << MAT_EQU << i << STR_END;
			return ;
		}
	}
	std::cout << BWHT << this->_name << FULL_INV;
	delete m;
	return ;
}

void	Character::unequip(int idx)
{
	if (isValidIndex(idx) == false)
		return ;
	if (this->_materias[idx] == NULL)
		std::cout << BWHT << this->_name << UNEQU_MAT_FAIL << idx << ". It surely must be empty..." STR_END;
	else if (this->_materias[idx] != NULL)
	{
		std::cout << BWHT << this->_name << ": A " << _materias[idx]->getType() << UNEQU_MAT_SUCC << idx << STR_END;
		this->_materias[idx] = NULL;
	}
	return ;
}

void	Character::use(int idx, ICharacter& target)
{
	if (isValidIndex(idx) == false)
		return ;
	if (this->_materias[idx] == NULL)
		std::cout << BWHT << this->_name << EMP_INV;
	else if (this->_materias[idx] != NULL)
		this->_materias[idx]->use(target);
	return ;
}

bool	Character::isValidIndex(int index) const
{
	if (index < 0 || index > 3)
	{
		ERROR_INDEX;
		return false;
	}
	return true;
}

AMateria*	Character::getMateria(int index) const
{
	if (isValidIndex(index) == false)
		return NULL;
	if (this->_materias[index] != NULL)
		return this->_materias[index];
	return NULL;
}