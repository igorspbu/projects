#include<iostream>
#include<fstream>

using namespace std;

bool isConsonant(int b)
{
	if (b == 'b' || b == 'c' || b == 'd' || b == 'f' || b == 'g' || b == 'h' || b == 'j' || b == 'k' || b == 'l' || b == 'm' || b == 'n' || b == 'p' || b == 'q' || b == 'r' || b == 's' || b == 't' || b == 'v' || b == 'w' || b == 'x' || b == 'y' || b == 'z')
	{
		return true;
	}
	return false;
}

int main()
{
	fstream fbin;

	char b = '0';

	fbin.open("in.bin", ios::binary | ios::in | ios::out);
	while (!fbin.eof())
	{
		fbin.read((char*)&b, sizeof(int));
		cout << "read : " << b;
		if (isConsonant(b))
		{
			fbin.seekg(-(int)sizeof(int), ios::cur);
			b = '#';
			fbin.write((char*)&b, sizeof(int));
			cout << " changed to #";
			fbin.seekg(fbin.tellg(), ios::beg);
		}
		cout << endl;
	}
	fbin.close();

	return 0;
}