#include <iostream>
#include <fstream>
#include <string>
class NumberLinesReader
{
public:
	enum class ReadResult
	{
		OK,
		EndOfFile,
		NotANumber
	};
	bool Open(const std::string& fileName);
	ReadResult ReadNextNumber(int& number);
private:
	std::ifstream Stream;
};


int main()
{
	NumberLinesReader reader;

	try
	{
		if (!reader.Open("numbers.txt")) throw std::exception("Could not open file");
		else
		{
			int sum = 0;
			bool error = false;
			while (true)
			{
				int number;
				const auto result = reader.ReadNextNumber(number);
				if (result == NumberLinesReader::ReadResult::OK)
					sum += number;
				else if (result == NumberLinesReader::ReadResult::NotANumber)
				{
					throw std::exception("not a number found");
					error = true;
					break;
				} else
					break;
			}
			if (!error)
				std::cout << "sum=" << sum << std::endl;
		}

	} catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}