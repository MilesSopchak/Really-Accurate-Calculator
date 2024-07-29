#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct NonNumericInput : std::exception
{
	const char* what() const noexcept
	{
		return "Please only use the symbols 0-9, put no more than 1 decimal point, and put negative signs at the beginning of the number.\n";
	}
};

struct DecimalPointNotFound : std::exception
{
	const char* what() const noexcept
	{
		return "This Number's decimal place was lost. Please try again.\n";
	}
};

struct DivideByZero : std::exception
{
	const char* what() const noexcept
	{
		return "Cannot divide by 0. Please use a number other than 0 for the divisor.\n";
	}
};

struct InsufficentSignificantFigures : std::exception
{
	const char* what() const noexcept
	{
		return "A number must have at least 1 significant figure. Please use a number larger than 0.\n";
	}
};

class Number
{
private:
	const char acceptedCharacters[11] = {'0','1','2','3','4','5','6','7','8','9'};
	static std::ofstream Numbers;
	static size_t GID;
	bool isNegative;
	size_t ID;
	void* number;
	void* dotLoc;
	void* size;
	

public:
	Number()
	{
		std::printf("eee");
		GID += 1;
		ID = GID;
		printf("eeeee%zu",GID);
	}

	Number(std::string n)
	{
		std::printf("eee");
		/*
		if (n.size() == 0)
		{
			number = "0.";
			isNegative = false;
			dotLoc = 1;
			return;
		}
		if (n == "." || n == "-" || n == "-.")
		{
			throw NonNumericInput();
		}
		isNegative = false;
		if (n[0] == '-')
		{
			n.erase(0, 1);
			isNegative = true;

		}
		bool hasDot = false;
		for (int i = 0; i < n.size(); i++)
		{
			bool accepted = false;
			for (char c : acceptedCharacters)
			{
				if (n[i] == c)
				{
					accepted = true;
					break;
				}
				else if (n[i] == '.' && !hasDot)
				{
					accepted = true;
					hasDot = true;
					break;
				}
				else if (n[i] == '.' && hasDot)
				{
					accepted = false;
					break;
				}
			}
			if (!accepted)
			{
				throw NonNumericInput();
			}
		}
		if ((number = cleanString(n, hasDot)) == "0.")
		{
			isNegative = false;
		}
		dotLoc = findDot();
		*/
	}

	std::string print()
	{
		/*
		std::string n = number;
		if (n[0] == '.')
		{
			n.insert(0, "0");
		}
		if (n[n.size() - 1] == '.')
		{
			n.erase(n.size() - 1, n.size());
		}
		if (isNegative)
		{
			n.insert(0, "-");
		}
		return n;
		*/
	}

	void copy(Number* n)
	{
		/*
		number = n->number;
		isNegative = n->isNegative;
		dotLoc = n->dotLoc;
		*/
	}

	int compare(Number* n)
	{
		/*
		if (isNegative ^ n->isNegative)
		{
			if (isNegative)
			{
				return -1;
			}
			return 1;
		}
		if ((int)dotLoc - (int)n->dotLoc > 0)
		{
			return 1;
		}
		if ((int)dotLoc - (int)n->dotLoc < 0)
		{
			return -1;
		}
		for (size_t i = 0; i < number.size(); i++)
		{
			if (number[i] == '.')
			{
				i++;
				if (i == number.size())
				{
					return 0;
				}
			}
			if (i == n->number.size())
			{
				return 1;
			}
			if (number[i] - n->number[i] > 0)
			{
				return 1;
			}
			if (number[i] - n->number[i] < 0)
			{
				return -1;
			}
		}
		return 0;
		*/
	}

	void add(Number* n)
	{
		/*
		if (isNegative ^ n->isNegative)
		{
			n->isNegative = !n->isNegative;
			subtract(n);
			n->isNegative = !n->isNegative;
			return;
		}
		evenSigFigs(this, n);
		bool carry = false;
		for (size_t i = number.size(); i > 0; i--)
		{
			if (number[i - 1] != '.')
			{
				int sum = (number[i - 1] + n->number[i - 1]) - (2 * '0') + carry;
				if (sum > 9)
				{
					carry = true;
					sum -= 10;
				}
				else
				{
					carry = false;
				}
				number[i - 1] = sum + '0';
			}
			if (i == 1 && carry == true)
			{
				number.insert(0, "1");
			}
		}
		number = cleanString(number,true);
		n->number = cleanString(n->number, true);
		dotLoc = findDot();
		*/
	}

	void subtract(Number* n)
	{
		/*
		if (this->compare(n) == 0)
		{
			number = "0.";
			isNegative = false;
			dotLoc = 1;
		}
		n->isNegative = !n->isNegative;
		if (!(isNegative ^ n->isNegative))
		{
			add(n);
			n->isNegative = !n->isNegative;
			return;
		}
		n->isNegative = !n->isNegative;
		evenSigFigs(this, n);
		Number n1,* n2;
		int comp = compare(n);
		if (comp == 1)
		{
			n1.copy(this);
			n2 = n;
		}
		else if (comp == -1)
		{
			n1.copy(n);
			n2 = this;
		}
		else
		{
			number = "0.";
			isNegative = false;
			dotLoc = 1;
			return;
		}
		bool borrow = false;
		for (size_t i = number.size(); i > 0; i--)
		{
			if (n1.number[i - 1] != '.')
			{
				int diff = (n1.number[i - 1] - n2->number[i - 1]) - borrow;
				if (diff < 0)
				{
					borrow = true;
					diff += 10;
				}
				else
				{
					borrow = false;
				}
				n1.number[i - 1] = diff + '0';
			}
		}
		copy(&n1);
		if (comp == -1)
		{
			isNegative = !isNegative;
		}
		number = cleanString(number, true);
		n->number = cleanString(n->number, true);
		dotLoc = findDot();
		*/
	}

	void multiply(Number* n)
	{
		/*
		if (number == "0." || n->number == "0.")
		{
			number = "0.";
			return;
		}
		isNegative = isNegative ^ n->isNegative;
		Number product;
		for (size_t i = n->number.size(); i > 0; i--)
		{
			if (n->number[i - 1] != '.')
			{
				Number sum;
				sum.copy(this);
				sum.isNegative = false;
				size_t carry = 0;
				for (size_t j = number.size(); j > 0; j--)
				{
					if (number[j - 1] != '.')
					{
						size_t Cproduct = (size_t)(sum.number[j - 1] - '0') * (size_t)(n->number[i - 1] - '0') + carry;
						carry = Cproduct / 10;
						Cproduct -= carry * 10;
						sum.number[j - 1] = Cproduct + '0';
					}
					if (j - 1 == 0)
					{
						sum.number.insert(0, "0");
						sum.number[0] = carry + '0';
					}
				}
				sum.dotLoc = sum.findDot();
				if (i - 1 < n->dotLoc)
				{
					for (size_t j = 0; j < n->dotLoc - i; j++)
					{
						if (sum.number[sum.number.size() - 1] == '.')
						{
							sum.number.insert(sum.number.size() - 1, "0");
						}
						else
						{
							sum.number[sum.dotLoc] = sum.number[sum.dotLoc + 1];
							sum.number[sum.dotLoc + 1] = '.';
						}
						sum.dotLoc += 1;
					}
				}
				else
				{
					for (size_t j = 0; j < i - n->dotLoc - 1; j++)
					{
						if (sum.number[0] == '.')
						{
							sum.number.insert(1, "0");
						}
						else
						{
							sum.number[sum.dotLoc] = sum.number[sum.dotLoc - 1];
							sum.number[sum.dotLoc - 1] = '.';
							sum.dotLoc -= 1;
						}
					}
				}
				product.add(&sum);
			}
		}
		copy(&product);
		number = cleanString(number, true);
		dotLoc = findDot();
		*/
	}

	void divide(Number* n, size_t SigFigs)
	{
		/*
		if (SigFigs == 0)
		{
			throw InsufficentSignificantFigures();
		}
		SigFigs++;
		if (number == "0.")
		{
			return;
		}
		if (n->number == "0.")
		{
			throw DivideByZero();
		}
		isNegative = isNegative ^ n->isNegative;
		Number offset("1");
		size_t ii = 1;
		size_t iii = 1;
		switch (compare(n))
		{
		case 1:
		{
			for (size_t i = 0; i < dotLoc - n->dotLoc; i++)
			{
				offset.number.insert(1, "0");
			}
			while (n->number[0] == '.' && n->number[iii] == '0')
			{
				offset.number.insert(1, "0");
				iii++;
			}
			while (number[0] == '.' && number[ii] == '0')
			{
				offset.number.erase(1, 1);
				ii++;
			}
			break;
		}
		case -1:
		{
			for (size_t i = 0; i < n->dotLoc - dotLoc; i++)
			{
				if (offset.number[0] == '1')
				{
					offset.number = ".1";
				}
				else
				{
					offset.number.insert(1, "0");
				}
			}
			while (number[0] == '.' && number[ii] == '0')
			{
				if (offset.number[0] == '1')
				{
					offset.number = ".1";
				}
				else
				{
					offset.number.insert(1, "0");
				}
				ii++;
			}
			while (n->number[0] == '.' && n->number[iii] == '0')
			{
				offset.number.erase(1, 1);
				iii++;
			}
			break;
		}
		default:
		{
			number = "1.";
			return;
		}
		}
		offset.dotLoc = offset.findDot();
		Number divisor(".1");
		if (number[0] != '.')
		{
			ii = 0;
		}
		if (n->number[0] != '.')
		{
			iii = 0;
		}
		if (n->number[iii] > number[ii])
		{
			offset.multiply(&divisor);
			offset.dotLoc = offset.findDot();
		}
		divisor.copy(n);
		Number quotient;
		quotient.copy(&offset);
		if (offset.number[0] == '.')
		{
			for (size_t i = 0; i < SigFigs - 1; i++)
			{
				quotient.number.append("0");
			}
		}
		else
		{
			if (SigFigs > offset.number.size() - 1)
			{
				for (size_t i = 0; i < SigFigs + 1 - offset.number.size(); i++)
				{
					quotient.number.append("0");
				}
			}
		}
		for (size_t i = 0; i < SigFigs; i++)
		{

		}
		*/
	}

	void round(size_t places, bool left)
	{
		/*
		if (places == 0)
		{
			throw InsufficentSignificantFigures();
		}
		if (number == "0.")
		{
			return;
		}
		if (left)
		{
			for (size_t i = 0; i < places - 1; i++)
			{
				if (dotLoc == 0)
				{
					number = "0.";
					dotLoc = 1;
					return;
				}
				number[dotLoc] = number[dotLoc - 1];
				number[dotLoc - 1] = '.';
				dotLoc--;
				if (number.size() - dotLoc > 2)
				{
					number.erase(dotLoc + 2, number.size() - dotLoc - 2);
				}
			}
			if (dotLoc != number.size() - 1 && number[dotLoc + 1] >= '5')
			{
				if (isNegative)
				{
					Number n("-1");
					add(&n);
				}
				else
				{
					Number n("1");
					add(&n);
				}
			}
			number.erase(dotLoc + 1, number.size() - dotLoc - 1);
			for (size_t i = 0; i < places - 1; i++)
			{
				number.insert(dotLoc, "0");
				dotLoc++;
			}
		}
		cleanString(number, true);
		dotLoc = findDot();
		*/
	}

	void power(Number* n)
	{

	}

	void root(Number* n)
	{

	}

private:

	std::string cleanString(std::string n, bool hasDot)
	{
		if (hasDot)
		{
			n = reverse(n);
			while (n[0] == '0')
			{
				n.erase(0, 1);
				if (n.size() == 1)
				{
					break;
				}
			}
			n = reverse(n);
		}
		else
		{
			n.append(".");
		}
		while (n[0] == '0')
		{
			n.erase(0, 1);
		}
		if (n.size() <= 1)
		{
			n = "0.";
		}
		return n;
	}

	std::string reverse(std::string n)
	{
		/*
		for (int i = 0; i < (n.size() / 2); i++)
		{
			char t = n[i];
			n[i] = n[n.size() - (i + 1)];
			n[n.size() - (i + 1)] = t;
		}
		return n;
		*/
	}

	size_t findDot()
	{
		/*
		for (size_t i = 0; i < number.size(); i++)
		{
			if (number[i] == '.')
			{
				return i;
			}
		}
		throw DecimalPointNotFound();
		*/
	}

	void evenSigFigs(Number* N1, Number* N2)
	{
		/*
		int N1Size = N1->number.size();
		int N2Size = N2->number.size();
		for (int i = 0; i < ((int)(N2->dotLoc) - (int)N1->dotLoc); i++)
		{
			N1->number.insert(0, "0");
		}
		for (int i = 0; i < ((int)N1->dotLoc - (int)N2->dotLoc); i++)
		{
			N2->number.insert(0, "0");
		}
		for (int i = 0; i < ((N2Size - (int)N2->dotLoc - 1) - (N1Size - (int)N1->dotLoc - 1)); i++)
		{
			N1->number.append("0");
		}
		for (int i = 0; i < ((N1Size - (int)N1->dotLoc - 1) - (N2Size - (int)N2->dotLoc - 1)); i++)
		{
			N2->number.append("0");
		}
		*/
	}
};

