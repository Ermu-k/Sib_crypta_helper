#include <iostream>
#include "belazo.h"

int main()
{
    setlocale(LC_CTYPE, "");

    auto x = L"абвгдежзийклмноп_,рстуфхцчшщъыьэюя";
    Alphabet rus(x);

    Belazo belazo(rus, L"ястреб");
    std::wcout << belazo.decrypt(L"здью,пдввяхпреахушздэю") << std::endl;
	
    return 0;
}

