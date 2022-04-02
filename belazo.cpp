#include "belazo.h"

//-------------------------------------------------------------
//Alphabet

Alphabet::Alphabet()
{
}

Alphabet::Alphabet(std::wstring str)
{
	std::copy(str.begin(), str.end(), std::back_inserter(this->mAlphabet));
}

Alphabet::Alphabet(std::vector<wchar_t> vec)
{
	std::copy(vec.begin(), vec.end(), std::back_inserter(this->mAlphabet));
}

//--------------------------------------------------------------
//Belazo

Belazo::Belazo(Alphabet base, std::wstring key)
{
    this->mAlphabet = base;
	this->makeKey(key);
	this->makeTable();
}

Belazo::~Belazo()
{
}

std::wstring Belazo::encrypt(std::wstring data)
{
    std::wstring answ{};
	auto alpLen = this->mAlphabet.mAlphabet.size();
	auto keyLen = this->mKey.size();
	auto dataLen = data.size();
	uint32_t x{}, y{};

	for (uint32_t i = 0; i < dataLen; i++)
	{
		for (uint32_t j = 0; j < alpLen; j++)
		{
			if (data[i] == this->mTable[0][j])
			{
				x = j;
			}
		}

		y = this->mKey[(i % keyLen)];

		answ += this->mTable[y][x];
	}

	return answ;
}

std::wstring Belazo::decrypt(std::wstring cod)
{
    std::wstring answ{};
	auto alpLen = this->mAlphabet.mAlphabet.size();
	auto keyLen = this->mKey.size();
	auto dataLen = cod.size();
	uint32_t x{}, y{};

	for (uint32_t i = 0; i < dataLen; i++)
	{
		for (uint32_t j = 0; j < alpLen; j++)
		{
			if (cod[i] == this->mTable[this->mKey[(i%keyLen)]][j])
			{
				x = j;
			}
		}

		answ += this->mTable[0][x];
	}

	return answ;
}

void Belazo::makeTable(void)
{
	//узнаеам длину алфавита
	auto len = this->mAlphabet.mAlphabet.size();

	//создаем квадраную матрицу размером с длину алфавита
	this->mTable.resize(len);
	for (uint32_t i = 0; i < len; i++)
	{
		this->mTable[i].resize(len, '0');
	}

	//заполняем матрицу алфавитом
	for (uint32_t i = 0; i < len; i++)
	{
		std::copy(this->mAlphabet.mAlphabet.begin() + i, this->mAlphabet.mAlphabet.end(), this->mTable[i].begin());
		std::copy(this->mAlphabet.mAlphabet.begin(), this->mAlphabet.mAlphabet.begin() + i, this->mTable[i].end() - i);
	}
}

void Belazo::makeKey(std::wstring x)
{
	auto len = this->mAlphabet.mAlphabet.size();
	for (auto i : x)
	{
		for (uint32_t j = 0; j < len; j++)
		{
			if (i == this->mAlphabet.mAlphabet[j])
			{
				this->mKey.push_back(j);
			}
		}
	}
}
