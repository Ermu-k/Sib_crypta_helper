#ifndef BELAZO_CHIPERS
#define BELAZO_CHIPERS

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <iterator>
#include <locale>


//Alphabet
struct Alphabet
{
	Alphabet();
    Alphabet(std::wstring str);
    Alphabet(std::vector<wchar_t> vec);
    std::vector<wchar_t> mAlphabet{};
}; 

//Interface
struct Chipers
{
	virtual ~Chipers() = default;
    virtual std::wstring encrypt(std::wstring data) = 0;
    virtual std::wstring decrypt(std::wstring cod) = 0;
};

//Belazo
struct Belazo : Chipers
{
    Belazo( Alphabet base, std::wstring key );
	~Belazo();
    std::wstring encrypt(std::wstring data) override;
    std::wstring decrypt(std::wstring cod) override;

private:
	void makeTable(void);
    void makeKey(std::wstring x);
	Alphabet mAlphabet{};
    std::vector<std::vector<wchar_t>> mTable{};
	std::vector<uint32_t> mKey{};
};

#endif // !BELAZO_CHIPERS

